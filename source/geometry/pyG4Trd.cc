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
#include "G4Trd.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

G4Trd* CreateTrd(const G4String& name, G4double pdx1, G4double pdx2,
                                       G4double pdy1, G4double pdy2,
                                       G4double pdz )
{
  return new G4Trd(name, pdx1, pdx2, pdy1, pdy2, pdz);
}

}

// ==========================================================================
void export_G4Trd(py::module& m)
{
  py::class_<G4Trd, G4VSolid>(m, "G4Trd")
  // ---
  .def(py::init<const G4String&, G4double, G4double, G4double,
                                 G4double, G4double>())
  // ---
  .def("GetXHalfLength1",  &G4Trd::GetXHalfLength1)
  .def("GetXHalfLength2",  &G4Trd::GetXHalfLength2)
  .def("GetYHalfLength1",  &G4Trd::GetYHalfLength1)
  .def("GetYHalfLength2",  &G4Trd::GetYHalfLength2)
  .def("GetZHalfLength",   &G4Trd::GetZHalfLength)
  .def("SetXHalfLength1",  &G4Trd::SetXHalfLength1)
  .def("SetXHalfLength2",  &G4Trd::SetXHalfLength2)
  .def("SetYHalfLength1",  &G4Trd::SetYHalfLength1)
  .def("SetYHalfLength2",  &G4Trd::SetYHalfLength2)
  .def("SetZHalfLength",   &G4Trd::SetZHalfLength)
  ;

  // ---
  m.def("CreateTrd", &::CreateTrd, py::return_value_policy::reference);

}
