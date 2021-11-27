#!/usr/bin/python3
# ==================================================================
#   gtest01
#   - check for writing a GDML file
# ==================================================================
from tests import *
#import gtest01

# ==================================================================
# main
# ==================================================================
def main():
    ecalgeom = gtest01.EcalGeom()
    gRunManager.SetUserInitialization(ecalgeom)

    phys_list = FTFP_BERT()
    gRunManager.SetUserInitialization(phys_list)

    app_builder = AppBuilder()
    gRunManager.SetUserInitialization(app_builder)

    # magnetic field (sequential mode only)
    #myField = G4UniformMagField(G4ThreeVector(0., 0.5*tesla, 0.))
    myField = MyField()
    field_mgr = gTransportationManager.GetFieldManager()
    field_mgr.SetDetectorField(myField)
    field_mgr.CreateChordFinder(myField)

    gRunManager.Initialize()

    # write to a GDML file
    print("\n*** write to a GDML file...")
    navigator = gTransportationManager.GetNavigatorForTracking()
    world_volume = navigator.GetWorldVolume()

    gdml_parser = G4GDMLParser()
    gdml_parser.Write("ecalgeom.gdml", world_volume)

# ==================================================================
if __name__ == '__main__':
    main()
