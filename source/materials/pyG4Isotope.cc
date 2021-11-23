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
#include "G4Isotope.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

void Print(G4Isotope* iso)
{
  G4cout << iso << G4endl;
}

}

PYBIND11_MAKE_OPAQUE(std::vector<G4Isotope*>);

// ==========================================================================
void export_G4Isotope(py::module& m)
{
  py::class_<G4Isotope>(m, "G4Isotope")
  // constructors
  .def(py::init<const G4String&, G4int, G4int>())
  .def(py::init<const G4String&, G4int, G4int, G4double>())
  .def(py::init<const G4String&, G4int, G4int, G4int>())
  // ---
  .def("GetName",             &G4Isotope::GetName)
  .def("GetZ",                &G4Isotope::GetZ)
  .def("GetN",                &G4Isotope::GetN)
  .def("GetA",                &G4Isotope::GetA)
  .def("Getm",                &G4Isotope::Getm)
  // ---
  .def_static("GetIsotope",   &G4Isotope::GetIsotope,
                              py::arg("name"), py::arg("warning") = false,
                              py::return_value_policy::reference)
  .def("GetIsotopeTable",     &G4Isotope::GetIsotopeTable,
                              py::return_value_policy::reference)
  // ---
  .def_static("GetNumberOfIsotopes", &G4Isotope::GetNumberOfIsotopes)
  .def("GetIndex",            &G4Isotope::GetIndex)
  // ---
  .def("SetName",             &G4Isotope::SetName)
  .def("Print",               &::Print)
  ;

  // ---
  py::bind_vector<std::vector<G4Isotope*>>(m, "G4IsotopeTable");

}