#!/usr/bin/env python3
# ==================================================================
#   gtest01
#   - check basic control flow
# ==================================================================
from geant4 import *
import gtest01

# ==================================================================
# user actions in python
# ==================================================================

class MyPrimaryGeneratorAction(G4VUserPrimaryGeneratorAction):
    def __init__(self):
        G4VUserPrimaryGeneratorAction.__init__(self)
        self.pg = G4ParticleGun(1)

    def GeneratePrimaries(self, event):
        dx= G4RandGauss.shoot(0., 0.1)
        self.pg.SetParticleMomentumDirection(G4ThreeVector(dx, 0., 1.))
        self.pg.GeneratePrimaryVertex(event)

# ------------------------------------------------------------------
class MyRunAction(G4UserRunAction):
    def BeginOfRunAction(self, run):
        print("*** (BRA) #event to be processed = ",
              run.GetNumberOfEventToBeProcessed())

    def EndOfRunAction(self, run):
      print ("*** (ERA) run ID = ", run.GetRunID())

# ------------------------------------------------------------------
class MyEventAction(G4UserEventAction):
    def BeginOfEventAction(self, event):
        pass
        #print("*** (BEA) current event =", event.GetEventID())

    def EndOfEventAction(self, event):
        ievt = event.GetEventID()
        if ievt % 100 == 0:
          print("*** (EEA) events processed =", ievt)

# ------------------------------------------------------------------
class MySteppingAction(G4UserSteppingAction):
    def UserSteppingAction(self, step):
        #print("*** (SA) dE/dx in current step=",
        #       step.GetTotalEnergyDeposit()/MeV, "MeV")
        track = step.GetTrack()
        touchable = track.GetTouchable()
        pv = touchable.GetVolume()
        print("*** (SA) volume copy# = ", pv.GetCopyNo(),
              ", rep# = ", touchable.GetReplicaNumber() )

# ------------------------------------------------------------------
class MyField(G4UserMagneticField):
    def FieldValue(self, pos, time):
        bfield= G4ThreeVector()
        bfield.x= 0.
        bfield.y= -0.5*tesla
        bfield.z= 0.
        return bfield

# ------------------------------------------------------------------
class AppBuilder(G4VUserActionInitialization):

  def Build(self):
    global particle_gun
    #particle_gun = ParticleGunGenerator()
    particle_gun = MyPrimaryGeneratorAction()
    self.SetUserAction(particle_gun)

    # setup particle gun
    #pg = particle_gun.GetGun()
    pg = particle_gun.pg
    pg.SetParticleByName("e-")
    pg.SetParticleEnergy(200.*MeV)
    pg.SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.))
    pg.SetParticlePosition(G4ThreeVector(0.,0.,-45.)*cm)

    global myRA
    myRA = MyRunAction()
    self.SetUserAction(myRA)

    global myEA
    myEA = MyEventAction()
    self.SetUserAction(myEA)

    global mySA
    mySA= MySteppingAction()
    #gRunManager.SetUserAction(mySA)

# ==================================================================
# main
# ==================================================================
def main(vis_enabled = False):
    global ecalgeom
    ecalgeom = gtest01.EcalGeom()
    gRunManager.SetUserInitialization(ecalgeom)

    global phys_list
    #phys_list = FTFP_BERT()
    pl_factory = G4PhysListFactory()
    phys_list = pl_factory.GetReferencePhysList("FTFP_BERT")
    gRunManager.SetUserInitialization(phys_list)

    global app_builder
    app_builder = AppBuilder()
    gRunManager.SetUserInitialization(app_builder)

    # magnetic field (sequential mode only)
    global myField
    #myField = G4UniformMagField(G4ThreeVector(0., 0.5*tesla, 0.))
    myField = MyField()
    field_mgr = gTransportationManager.GetFieldManager()
    field_mgr.SetDetectorField(myField)
    field_mgr.CreateChordFinder(myField)

    gRunManager.Initialize()

    # visualization
    if ( vis_enabled ):
      vis_cp = VisControlPanel()

    gControlExecute("vis.mac")

    # beamOn
    gRunManager.BeamOn(100)

# ==================================================================
if __name__ == '__main__':
    main()
