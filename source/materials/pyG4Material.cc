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
#include "G4Material.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

// --------------------------------------------------------------------------
// GetElementVector
py::list f_GetElementVector(G4Material* mate)
{
  py::list pylist;

  auto elevec = mate-> GetElementVector();

  for( auto ele : *elevec ) {
    pylist.append(ele);
  }

  return pylist;
}

// --------------------------------------------------------------------------
// GetFractionVector
py::list f_GetFractionVector(G4Material* material)
{
  py::list pylist;

  auto vec = material-> GetFractionVector();

  auto nele= material-> GetNumberOfElements();

  for( auto i = 0; i < nele; i++ ) {
    pylist.append(vec[i]);
  }

  return pylist;
}

// --------------------------------------------------------------------------
py::list f_GetAtomsVector(G4Material* material)
{
  py::list pylist;

  auto vec = material-> GetAtomsVector();

  auto nele= material-> GetNumberOfElements();

  for( auto i = 0; i < nele; i++ ) {
    pylist.append(vec[i]);
  }

  return pylist;
}

// --------------------------------------------------------------------------
py::list f_GetVecNbOfAtomsPerVolume(G4Material* material)
{
  py::list pylist;

  auto vec = material-> GetVecNbOfAtomsPerVolume();

  auto nele= material-> GetNumberOfElements();

  for( auto i = 0; i < nele; i++ ) {
    pylist.append(vec[i]);
  }

  return pylist;
}

// --------------------------------------------------------------------------
void Print(G4Material* mat)
{
  G4cout << mat << G4endl;
}

}


// ==========================================================================
void export_G4Material(py::module& m)
{
  py::class_<G4Material>(m, "G4Material")
  .def(py::init<const G4String&, G4double, G4double, G4double>())
  .def(py::init<const G4String&, G4double, G4int>())
  .def(py::init<const G4String&, G4double, const G4Material*>())
  // ---
  .def("AddElementByNumberOfAtoms", &G4Material::AddElementByNumberOfAtoms)
  .def("AddElementByMassFraction",  &G4Material::AddElementByMassFraction)
  .def("AddElement", py::overload_cast<G4Element*, G4int>
                     (&G4Material::AddElement))
  .def("AddElement", py::overload_cast<G4Element*, G4double>
                     (&G4Material::AddElement))
  .def("AddMaterial",               &G4Material::AddMaterial)
  .def("GetName",                   &G4Material::GetName)
  .def("GetChemicalFormula",        &G4Material::GetChemicalFormula)
  .def("GetFreeElectronDensity",    &G4Material::GetFreeElectronDensity)
  .def("GetDensity",                &G4Material::GetDensity)
  .def("GetState",                  &G4Material::GetState)
  .def("GetTemperature",            &G4Material::GetTemperature)
  .def("GetPressure",               &G4Material::GetPressure)
  // ---
  .def("GetNumberOfElements",       &G4Material::GetNumberOfElements)
  .def("GetElement",                &G4Material::GetElement,
                                    py::return_value_policy::reference)
  .def("GetTotNbOfAtomsPerVolume",  &G4Material::GetTotNbOfAtomsPerVolume)
  .def("GetTotNbOfElectPerVolume",  &G4Material::GetTotNbOfElectPerVolume)
  // ---
  .def("GetElementVector",          &::f_GetElementVector)
  .def("GetFractionVector",         &::f_GetFractionVector)
  .def("GetAtomsVector",            &::f_GetAtomsVector)
  .def("GetVecNbOfAtomsPerVolume",  &::f_GetVecNbOfAtomsPerVolume)
  // ---
  .def("GetElectronDensity",        &G4Material::GetElectronDensity)
  .def("GetRadlen",                 &G4Material::GetRadlen)
  .def("GetNuclearInterLength",     &G4Material::GetNuclearInterLength)
  // ---
  .def("GetBaseMaterial",           &G4Material::GetBaseMaterial,
                                    py::return_value_policy::reference)
  // ---
  .def("GetMassOfMolecule",         &G4Material::GetMassOfMolecule)
  .def("SetChemicalFormula",        &G4Material::SetChemicalFormula)
  .def("SetFreeElectronDensity",    &G4Material::SetFreeElectronDensity)
  .def("ComputeDensityEffectOnFly", &G4Material::ComputeDensityEffectOnFly)
  .def("GetZ",                      &G4Material::GetZ)
  .def("GetA",                      &G4Material::GetA)
  // ---
  .def("GetIndex",                  &G4Material::GetIndex)
  .def_static("GetMaterialTable",   &G4Material::GetMaterialTable,
                                    py::return_value_policy::reference)
  .def_static("GetNumberOfMaterials", &G4Material::GetNumberOfMaterials)
  // ---
  .def_static("GetMaterial",
              py::overload_cast<const G4String&, G4bool>
              (&G4Material::GetMaterial),
              py::arg("name"), py::arg("warning") = true,
              py::return_value_policy::reference)
  .def_static("GetMaterial",
              py::overload_cast<G4double, G4double, G4double>
              (&G4Material::GetMaterial),
              py::return_value_policy::reference)
  .def_static("GetMaterial",
              py::overload_cast<size_t, G4double>
              (&G4Material::GetMaterial),
              py::return_value_policy::reference)
  // ---
  .def("SetName",                    &G4Material::SetName)
  .def("IsExtended",                 &G4Material::IsExtended)
  // ---
  .def("Print",                      &::Print)
  .def("__str__",   [](const G4Material&v) {return v.GetName().data();})
  .def("__repr__",  [](const G4Material&v) {return v.GetName().data();})
  ;

  // ---
  py::class_<G4MaterialTable>(m, "G4MaterialTable");

  // ---
  py::enum_<G4State>(m, "G4State")
  .value("kStateUndefined", kStateUndefined)
  .value("kStateSolid",     kStateSolid)
  .value("kStateLiquid",    kStateLiquid)
  .value("kStateGas",       kStateGas)
  ;
}
