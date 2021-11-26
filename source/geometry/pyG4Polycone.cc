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
#include "G4Polycone.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

// --------------------------------------------------------------------------
G4Polycone* f1_CreatePolycone(const G4String& name,
                              G4double phiStart, G4double phiTotal,
                              G4int numZPlanes,
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

  return new G4Polycone(name, phiStart, phiTotal, numZPlanes,
                        zlist, r0list, r1list);
}

// --------------------------------------------------------------------------
G4Polycone* f2_CreatePolycone(const G4String& name,
                              G4double phiStart, G4double phiTotal,
                              G4int numRZ,
                              const std::vector<G4double>& r,
                              const std::vector<G4double>& z)
{
  G4double zlist[numRZ];
  G4double rlist[numRZ];

  for (auto i = 0; i < numRZ; i++) {
    rlist[i] = r[i];
    zlist[i] = z[i];
  }

  return new G4Polycone(name, phiStart, phiTotal, numRZ, rlist, zlist);
}

}

// ==========================================================================
void export_G4Polycone(py::module& m)
{
  py::class_<G4Polycone, G4VSolid>(m, "G4Polycone")
  // ---
  .def("GetStartPhi",    &G4Polycone::GetStartPhi)
  .def("GetEndPhi",      &G4Polycone::GetEndPhi)
  .def("IsOpen",         &G4Polycone::IsOpen)
  .def("GetNumRZCorner", &G4Polycone::GetNumRZCorner)
  ;

  // ----
  m.def("CreatePolycone", &::f1_CreatePolycone,
                        py::return_value_policy::reference);
  m.def("CreatePolycone", &::f2_CreatePolycone,
                        py::return_value_policy::reference);
}
