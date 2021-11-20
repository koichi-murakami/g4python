# ==================================================================
#   gtest01
#   - check basic control flow
# ==================================================================
from geant4 import *
import gtest01
import random

# ==================================================================
# user actions in python
# ==================================================================

class MyPrimaryGeneratorAction(G4VUserPrimaryGeneratorAction):
    def __init__(self):
        G4VUserPrimaryGeneratorAction.__init__(self)
        self.pg = G4ParticleGun(1)

    def GeneratePrimaries(self, event):
        dx= random.gauss(0., 0.1)
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
"""
# ------------------------------------------------------------------
class MySteppingAction(G4UserSteppingAction):
  "My Stepping Action"

  def UserSteppingAction(self, step):
    #print "*** dE/dx in current step=", step.GetTotalEnergyDeposit()
    track= step.GetTrack()
    touchable= track.GetTouchable()
    pv= touchable.GetVolume()
    #print pv.GetCopyNo()
    #print touchable.GetReplicaNumber(0)

# ------------------------------------------------------------------
class MyField(G4MagneticField):
  "My Magnetic Field"

  def GetFieldValue(self, pos, time):
    bfield= G4ThreeVector()
    bfield.x= 0.
    bfield.y= 5.*tesla
    bfield.z= 0.
    return bfield
"""

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

    #mySA= MySteppingAction()
    #gRunManager.SetUserAction(mySA)

# ==================================================================
# main
# ==================================================================
def main():
    global ecalgeom
    ecalgeom = gtest01.EcalGeom()
    gRunManager.SetUserInitialization(ecalgeom)

    global phys_list
    phys_list = FTFP_BERT()
    gRunManager.SetUserInitialization(phys_list)

    global app_builder
    app_builder = AppBuilder()
    gRunManager.SetUserInitialization(app_builder)

    # magnetic field
    #fieldMgr= gTransportationManager.GetFieldManager()
    #myField= G4UniformMagField(G4ThreeVector(0.,10.*tesla,0.))
    ##myField= MyField()
    #fieldMgr.SetDetectorField(myField)
    #fieldMgr.CreateChordFinder(myField)

    gRunManager.Initialize()

    # visualization
    gControlExecute("vis.mac")

    # beamOn
    gRunManager.BeamOn(100)

# ==================================================================
if __name__ == '__main__':
  main()
