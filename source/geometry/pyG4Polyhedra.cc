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
#include <pybind11/stl.h>
#include "G4Polyhedra.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

// --------------------------------------------------------------------------
G4Polyhedra* f1_CreatePolyhedra(const G4String& name,
                                G4double phiStart, G4double phiTotal,
                                G4int numSide, G4int numZPlanes,
                                const std::vector<G4double>& zPlane,
                                const std::vector<G4double>& rInner,
                                const std::vector<G4double>& rOuter)
{
  G4double zlist[numZPlanes];
  G4double r0list[numZPlanes];
  G4double r1list[numZPlanes];

  for ( auto i = 0; i < numZPlanes; i++ ) {
    zlist[i] = zPlane[i];
    r0list[i] = rInner[i];
    r1list[i] = rOuter[i];
  }

  return new G4Polyhedra(name, phiStart, phiTotal, numSide, numZPlanes,
                         zlist, r0list, r1list);
}

// --------------------------------------------------------------------------
G4Polyhedra* f2_CreatePolyhedra(const G4String& name,
                                G4double phiStart, G4double phiTotal,
                                G4int numSide, G4int numRZ,
                                const std::vector<G4double>& r,
                                const std::vector<G4double>& z)
{
  G4double zlist[numRZ];
  G4double rlist[numRZ];

  for ( auto i = 0; i < numRZ; i++ ) {
    zlist[i] = z[i];
    rlist[i] = r[i];
  }

  return new G4Polyhedra(name, phiStart, phiTotal, numSide, numRZ,
                         rlist, zlist);
}

}

// ==========================================================================
void export_G4Polyhedra(py::module& m)
{
  py::class_<G4Polyhedra, G4VSolid>(m, "G4Polyhedra")
  .def(py::init<const G4String&, G4double, G4double, G4int, G4int,
                const G4double*, const G4double*, const G4double*>())

  .def(py::init<const G4String&, G4double, G4double, G4int, G4int,
                const G4double*, const G4double*>())
  // ---
  .def("GetStartPhi",    &G4Polyhedra::GetStartPhi)
  .def("GetEndPhi",      &G4Polyhedra::GetEndPhi)
  .def("GetNumSide",     &G4Polyhedra::GetNumSide)
  .def("GetNumRZCorner", &G4Polyhedra::GetNumRZCorner)
  .def("IsOpen",         &G4Polyhedra::IsOpen)
  .def("IsGeneric",      &G4Polyhedra::IsGeneric)
  ;

  // Create solid
  m.def("CreatePolyhedra", &::f1_CreatePolyhedra,
                           py::return_value_policy::reference);
  m.def("CreatePolyhedra", &::f2_CreatePolyhedra,
                           py::return_value_policy::reference);
}
