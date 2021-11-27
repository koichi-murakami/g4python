#!/usr/bin/env python3
# ==================================================================
#   gtest03
#   - check for reading a GDML file
# ==================================================================
from geant4 import *
import geant4.utils

# ==================================================================
# user actions in python
# ==================================================================
class MyDetectorConstruction(G4VUserDetectorConstruction):
    def __init__(self):
        G4VUserDetectorConstruction.__init__(self)
        self.world= None
        self.gdml_parser= G4GDMLParser()

    # -----------------------------------------------------------------
    def Construct(self):
        self.gdml_parser.Read("ecalgeom.gdml")
        self.world = self.gdml_parser.GetWorldVolume()

        return self.world

# ------------------------------------------------------------------
class AppBuilder(G4VUserActionInitialization):
    def Build(self):
        global particle_gun
        particle_gun = geant4.utils.ParticleGun()
        self.SetUserAction(particle_gun)

# ==================================================================
# main
# ==================================================================
def main():
    # geometry
    myDC = MyDetectorConstruction()
    gRunManager.SetUserInitialization(myDC)

    # physics list
    phys_list = FTFP_BERT()
    gRunManager.SetUserInitialization(phys_list)

    # initialize
    app_builder = AppBuilder()
    gRunManager.SetUserInitialization(app_builder)

    gRunManager.Initialize()

    # visualization
    from geant4.utils import VisControlPanel
    viscp = VisControlPanel()

# ==================================================================
if __name__ == '__main__':
    main()
