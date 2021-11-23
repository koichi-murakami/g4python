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
#include "G4NistManager.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4NistManager(py::module& m)
{
  py::class_<G4NistManager>(m, "G4NistManager")
  // ---
  .def_static("Instance",    &G4NistManager::Instance,
                             py::return_value_policy::reference)
  // ---
  .def("GetElement",         &G4NistManager::GetElement,
                             py::return_value_policy::reference)
  .def("FindElement",        &G4NistManager::FindElement,
                             py::return_value_policy::reference)
  .def("FindOrBuildElement",
       py::overload_cast<G4int, G4bool>(&G4NistManager::FindOrBuildElement),
       py::arg("Z"), py::arg("isotopes") = true,
       py::return_value_policy::reference)
  .def("FindOrBuildElement",
       py::overload_cast<const G4String&, G4bool>
       (&G4NistManager::FindOrBuildElement),
       py::arg("symbol"), py::arg("isotopes") = true,
       py::return_value_policy::reference)
  .def("GetNumberOfElements", &G4NistManager::GetNumberOfElements)
  .def("GetZ",                &G4NistManager::GetZ)
  .def("GetAtomicMassAmu",
        py::overload_cast<const G4String&>
        (&G4NistManager::GetAtomicMassAmu, py::const_))
  .def("GetAtomicMassAmu",
        py::overload_cast<G4int>
        (&G4NistManager::GetAtomicMassAmu, py::const_))
  // ---
  .def("GetIsotopeMass",        &G4NistManager::GetIsotopeMass)
  .def("GetAtomicMass",         &G4NistManager::GetAtomicMass)
  .def("GetTotalElectronBindingEnergy",
                                &G4NistManager::GetTotalElectronBindingEnergy)
  .def("GetNistFirstIsotopeN",  &G4NistManager::GetNistFirstIsotopeN)
  .def("GetNumberOfNistIsotopes", &G4NistManager::GetNumberOfNistIsotopes)
  .def("GetIsotopeAbundance",   &G4NistManager::GetIsotopeAbundance)
  // ---
  .def("PrintElement", py::overload_cast<G4int>
                       (&G4NistManager::PrintElement, py::const_))
  .def("PrintElement", py::overload_cast<const G4String&>
                       (&G4NistManager::PrintElement, py::const_))
  .def("PrintG4Element",          &G4NistManager::PrintG4Element)
  .def("GetNistElementNames",     &G4NistManager::GetNistElementNames)
  .def("GetMeanIonisationEnergy", &G4NistManager::GetMeanIonisationEnergy)
  .def("GetNominalDensity",       &G4NistManager::GetNominalDensity)
  // ---
  .def("GetMaterial",             &G4NistManager::GetMaterial,
                                  py::return_value_policy::reference)
  .def("FindMaterial",            &G4NistManager::FindMaterial,
                                  py::return_value_policy::reference)
  .def("FindOrBuildMaterial",     &G4NistManager::FindOrBuildMaterial,
                                  py::arg("name"),
                                  py::arg("isotopes") = true,
                                  py::arg("warning")=false,
                                  py::return_value_policy::reference)
  .def("FindSimpleMaterial",      &G4NistManager::FindSimpleMaterial,
                                  py::return_value_policy::reference)
  .def("FindOrBuildSimpleMaterial",
       py::overload_cast<G4int, G4bool>
       (&G4NistManager::FindOrBuildSimpleMaterial),
       py::arg("Z"), py::arg("warning") = false,
       py::return_value_policy::reference)
  .def("BuildMaterialWithNewDensity",
       &G4NistManager::BuildMaterialWithNewDensity,
       py::arg("name"), py::arg("basename"), py::arg("density") = 0.0,
       py::arg("temp") = NTP_Temperature,
       py::arg("pres") = CLHEP::STP_Pressure)
  // ---
  .def("ConstructNewMaterial",
       py::overload_cast<const G4String&,
                         const std::vector<G4String>&,
                         const std::vector<G4int>&,
                         G4double, G4bool, G4State, G4double, G4double>
       (&G4NistManager::ConstructNewMaterial),
       py::arg("name"), py::arg("elm"), py::arg("nAtoms"), py::arg("dens"),
       py::arg("isotops") = true, py::arg("state") = kStateSolid,
       py::arg("tmp") = NTP_Temperature,
       py::arg("pressure") = CLHEP::STP_Pressure,
       py::return_value_policy::reference)
  .def("ConstructNewMaterial",
       py::overload_cast<const G4String&,
                         const std::vector<G4String>&,
                         const std::vector<G4double>&,
                         G4double, G4bool, G4State, G4double, G4double>
       (&G4NistManager::ConstructNewMaterial),
       py::arg("name"), py::arg("elm"), py::arg("weight"), py::arg("dens"),
       py::arg("isotops") = true, py::arg("state") = kStateSolid,
       py::arg("tmp") = NTP_Temperature,
       py::arg("pressure") = CLHEP::STP_Pressure,
       py::return_value_policy::reference)
  // ---
  .def("ConstructNewGasMaterial",
        &G4NistManager::ConstructNewGasMaterial,
        py::arg("name"), py::arg("nameNist"), py::arg("temp"),
        py::arg("pres"), py::arg("isotopes") = true,
        py::return_value_policy::reference)

  .def("ConstructNewIdealGasMaterial",
       py::overload_cast<const G4String&,
                         const std::vector<G4String>&,
                         const std::vector<G4int>&,
                         G4bool, G4double, G4double>
       (&G4NistManager::ConstructNewIdealGasMaterial),
       py::arg("name"), py::arg("elm"), py::arg("nAtoms"),
       py::arg("isotops") = true,
       py::arg("tmp") = NTP_Temperature,
       py::arg("pressure") = CLHEP::STP_Pressure,
       py::return_value_policy::reference)
  // ---
  .def("SetDensityEffectCalculatorFlag",
       py::overload_cast<const G4String&, G4bool>
       (&G4NistManager::SetDensityEffectCalculatorFlag))
  .def("SetDensityEffectCalculatorFlag",
       py::overload_cast<G4Material*, G4bool>
       (&G4NistManager::SetDensityEffectCalculatorFlag))
  // ---
  .def("GetNumberOfMaterials",    &G4NistManager::GetNumberOfMaterials)
  .def("SetVerbose",              &G4NistManager::SetVerbose)
  .def("GetVerbose",              &G4NistManager::GetVerbose)
  .def("PrintG4Material",         &G4NistManager::PrintG4Material)
  .def("ListG4Material",          &G4NistManager::ListMaterials)
  .def("GetNistMaterialNames",    &G4NistManager::GetNistMaterialNames)
  // ---
  .def("GetZ13", py::overload_cast<G4double>
                 (&G4NistManager::GetZ13, py::const_))
  .def("GetZ13", py::overload_cast<G4int>
                 (&G4NistManager::GetZ13, py::const_))
  .def("GetA27",                  &G4NistManager::GetA27)
  .def("GetLOGZ",                 &G4NistManager::GetA27)
  .def("GetLOGAMU",               &G4NistManager::GetA27)
  // ---
  //.def("GetICRU90StoppingData",   &G4NistManager::GetICRU90StoppingData,
  //     py::return_value_policy::reference)
  ;
}
