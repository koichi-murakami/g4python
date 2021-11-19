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
"""
class MyPrimaryGeneratorAction(G4VUserPrimaryGeneratorAction):

    def __init__(self):
        G4VUserPrimaryGeneratorAction.__init__(self)
        self.particleGun= G4ParticleGun(1)

    def GeneratePrimaries(self, event):
        #dx= random.gauss(0., 0.1)
        dx=0.
        self.particleGun.SetParticleMomentumDirection(G4ThreeVector(dx, 0., 1.))
        self.particleGun.GeneratePrimaryVertex(event)
"""

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

    # set user actions...
    global particle_gun
    particle_gun = ParticleGun()
    gRunManager.SetUserAction(particle_gun)

    global myRA
    myRA = MyRunAction()
    gRunManager.SetUserAction(myRA)

    global myEA
    myEA = MyEventAction()
    gRunManager.SetUserAction(myEA)

    #mySA= MySteppingAction()
    #gRunManager.SetUserAction(mySA)

    # set particle gun
    #ApplyUICommand("/control/execute gun.mac")
    #pg= qPGA.GetParticleGun()
    #pg= myPGA.particleGun
    #pg.SetParticleByName("e-")
    #pg.SetParticleEnergy(200.*MeV)
    #pg.SetParticlePosition(G4ThreeVector(0.,0.,-14.9)*cm)

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
