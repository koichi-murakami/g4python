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
#include "G4Tubs.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

G4Tubs* CreateTubs(const G4String& name,
                   G4double pRMin, G4double pRMax, G4double pDz,
                   G4double pSPhi, G4double pDPhi )
{
  return new G4Tubs(name, pRMin, pRMax, pDz, pSPhi, pDPhi);
}

}

// ==========================================================================
void export_G4Tubs(py::module& m)
{
  py::class_<G4Tubs, G4VSolid>(m, "G4Tubs")
  // ---
  .def(py::init<const G4String&, G4double, G4double, G4double,
                                 G4double, G4double>())
  // ---
  .def("GetInnerRadius",   &G4Tubs::GetInnerRadius)
  .def("GetOuterRadius",   &G4Tubs::GetOuterRadius)
  .def("GetZHalfLength",   &G4Tubs::GetZHalfLength)
  .def("GetStartPhiAngle", &G4Tubs::GetStartPhiAngle)
  .def("GetDeltaPhiAngle", &G4Tubs::GetDeltaPhiAngle)
  .def("SetInnerRadius",   &G4Tubs::SetInnerRadius)
  .def("SetOuterRadius",   &G4Tubs::SetOuterRadius)
  .def("SetZHalfLength",   &G4Tubs::SetZHalfLength)
  .def("SetStartPhiAngle", &G4Tubs::SetStartPhiAngle)
  .def("SetDeltaPhiAngle", &G4Tubs::SetDeltaPhiAngle)
  ;

  // ---
  m.def("CreateTubs", &::CreateTubs, py::return_value_policy::reference);

}
