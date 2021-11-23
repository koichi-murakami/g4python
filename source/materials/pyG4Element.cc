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
#include <pybind11/stl_bind.h>
#include "G4Element.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

// --------------------------------------------------------------------------
// GetRelativeAbundanceVector
py::list f_GetRelativeAbundanceVector(const G4Element* element)
{
  py::list pylist;

  auto vec= element-> GetRelativeAbundanceVector();

  auto niso= element-> GetNumberOfIsotopes();

  for( auto i = 0; i < niso; i++ ) {
    pylist.append(vec[i]);
  }

  return pylist;
}

// --------------------------------------------------------------------------
void Print(G4Element* ele)
{
  std::cout << ele << G4endl;
}

}

PYBIND11_MAKE_OPAQUE(std::vector<G4Element*>);

// ==========================================================================
void export_G4Element(py::module& m)
{
  py::class_<G4Element>(m, "G4Element")
  // ---
  .def(py::init<const G4String&, const G4String&, G4double, G4double>())
  .def(py::init<const G4String&, const G4String&, G4int>())
  // ---
  .def("AddIsotope",          &G4Element::AddIsotope)
  // ---
  .def("GetName",             &G4Element::GetName)
  .def("GetSymbol",           &G4Element::GetSymbol)
  .def("GetZ",                &G4Element::GetZ)
  .def("GetZasInt",           &G4Element::GetZasInt)
  .def("GetN",                &G4Element::GetN)
  .def("GetAtomicMassAmu",    &G4Element::GetAtomicMassAmu)
  .def("GetA",                &G4Element::GetA)
  // ---
  .def("GetNaturalAbundanceFlag", &G4Element::GetNaturalAbundanceFlag)
  .def("SetNaturalAbundanceFlag", &G4Element::SetNaturalAbundanceFlag)
  // ---
  .def("GetNbOfAtomicShells", &G4Element::GetNbOfAtomicShells)
  .def("GetAtomicShell",      &G4Element::GetAtomicShell)
  .def("GetNbOfShellElectrons", &G4Element::GetNbOfShellElectrons)
  // ---
  .def("GetNumberOfIsotopes", &G4Element::GetNumberOfIsotopes)
  .def("GetIsotopeVector",    &G4Element::GetIsotopeVector,
                              py::return_value_policy::reference)
  .def("GetRelativeAbundanceVector", &::f_GetRelativeAbundanceVector)
  .def("GetIsotope",          &G4Element::GetIsotope,
                              py::return_value_policy::reference)
  // ---
  .def_static("GetElementTable", &G4Element::GetElementTable,
                                 py::return_value_policy::reference)
  .def("GetNumberOfElements", &G4Element::GetNumberOfElements)
  .def("GetIndex",            &G4Element::GetIndex)
  // ---
  .def_static("GetElement",   &G4Element::GetElement,
                              py::arg("name"), py::arg("warning") = true,
                              py::return_value_policy::reference)
  .def("GetfCoulomb",         &G4Element::GetfCoulomb)
  .def("GetfRadTsai",         &G4Element::GetfRadTsai)
   // ---
  .def("SetName",             &G4Element::SetName)
  .def("Print",               &::Print)
  .def("__str__",   [](const G4Element&v) {return v.GetName().data();})
  .def("__repr__",  [](const G4Element&v) {return v.GetName().data();})
  ;

  // ---
  py::bind_vector<std::vector<G4Element*>>(m, "G4ElementTable");

}
