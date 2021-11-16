//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
#include <pybind11/pybind11.h>

namespace py = pybind11;

// --------------------------------------------------------------------------
void export_G4GeometryManager(py::module&);
void export_G4VTouchable(py::module&);
void export_G4TouchableHistory(py::module&);
void export_G4VPhysicalVolume(py::module&);
void export_G4PVPlacement(py::module&);
void export_G4PVReplica(py::module&);
void export_G4LogicalVolume(py::module&);
void export_G4Region(py::module&);
void export_G4VSolid(py::module&);
void export_G4Box(py::module&);
void export_G4Cons(py::module&);
void export_G4Para(py::module&);
void export_G4Torus(py::module&);
void export_G4Trd(py::module&);
void export_G4Orb(py::module&);
void export_G4Sphere(py::module&);
void export_G4Trap(py::module&);
void export_G4Tubs(py::module&);
void export_G4Polycone(py::module&);
void export_G4Polyhedra(py::module&);
void export_G4EllipticalTube(py::module&);
void export_G4Ellipsoid(py::module&);
void export_G4EllipticalCone(py::module&);
void export_G4Hype(py::module&);
void export_G4Tet(py::module&);
void export_G4TwistedBox(py::module&);
void export_G4TwistedTrap(py::module&);
void export_G4TwistedTrd(py::module&);
void export_G4TwistedTubs(py::module&);
void export_G4BooleanSolid(py::module&);
void export_G4UnionSolid(py::module&);
void export_G4IntersectionSolid(py::module&);
void export_G4SubtractionSolid(py::module&);
void export_G4TransportationManager(py::module&);
void export_G4Navigator(py::module&);
void export_G4FieldManager(py::module&);
void export_G4Field(py::module&);
void export_G4MagneticField(py::module&);
void export_G4UniformMagField(py::module&);
void export_G4ChordFinder(py::module&);

// ==========================================================================
PYBIND11_MODULE(G4geometry, m)
{
  //export_G4GeometryManager(m);
  //export_G4VTouchable(m);
  //export_G4TouchableHistory(m);
  //export_G4VPhysicalVolume(m);
  //export_G4PVPlacement(m);
  //export_G4PVReplica(m);
  //export_G4LogicalVolume(m);
  //export_G4Region(m);
  export_G4VSolid(m);
  export_G4Box(m);
  //export_G4Cons(m);
  //export_G4Para(m);
  //export_G4Torus(m);
  //export_G4Trd(m);
  //export_G4Orb(m);
  //export_G4Sphere(m);
  //export_G4Trap(m);
  //export_G4Tubs(m);
  //export_G4Polycone(m);
  //export_G4Polyhedra(m);
  //export_G4EllipticalTube(m);
  //export_G4Ellipsoid(m);
  //export_G4EllipticalCone(m);
  //export_G4Hype(m);
  //export_G4Tet(m);
  //export_G4TwistedBox(m);
  //export_G4TwistedTrap(m);
  //export_G4TwistedTrd(m);
  //export_G4TwistedTubs(m);
  //export_G4BooleanSolid(m);
  //export_G4UnionSolid(m);
  //export_G4IntersectionSolid(m);
  //export_G4SubtractionSolid(m);
  //export_G4TransportationManager(m);
  //export_G4Navigator(m);
  //export_G4FieldManager(m);
  //export_G4Field(m);
  //export_G4MagneticField(m);
  //export_G4UniformMagField(m);
  //export_G4ChordFinder(m);
}
