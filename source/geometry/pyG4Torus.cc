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
#include "G4Torus.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

G4Torus* CreateTorus(const G4String& name, G4double pRmin, G4double pRmax,
                     G4double pRtor, G4double pSPhi, G4double pDPhi)
{
  return new G4Torus(name, pRmin, pRmax, pRtor, pSPhi, pDPhi);
}

}

// ==========================================================================
void export_G4Torus(py::module& m)
{
  py::class_<G4Torus, G4VSolid, std::unique_ptr<G4Torus, py::nodelete>>
  (m, "G4Torus")
  // ---
  .def(py::init<const G4String&, G4double, G4double, G4double,
                                G4double, G4double>())
  // ---
  .def("GetRmin", &G4Torus::GetRmin)
  .def("GetRmax", &G4Torus::GetRmax)
  .def("GetRtor", &G4Torus::GetRtor)
  .def("GetSPhi", &G4Torus::GetSPhi)
  .def("GetDPhi", &G4Torus::GetDPhi)
  ;

  // ---
  m.def("CreateTorus", &::CreateTorus, py::return_value_policy::reference);
}
