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
#include <pybind11/operators.h>
#include "G4Colour.hh"
#include "G4Color.hh"

namespace py = pybind11;

namespace {

std::string to_string(const G4Colour& v)
{
  std::string message = "(";
  message += std::to_string(v.GetRed())   +  ", ";
  message += std::to_string(v.GetGreen()) +  ", ";
  message += std::to_string(v.GetBlue())  +  ", ";
  message += std::to_string(v.GetAlpha()) +  ")";

  return message;
}

}

// ==========================================================================
void export_G4Colour(py::module& m)
{
  py::class_<G4Colour>(m, "G4Color")
  // ---
  .def(py::init<>())
  .def(py::init<G4double>())
  .def(py::init<G4double, G4double>())
  .def(py::init<G4double, G4double, G4double>())
  .def(py::init<G4double, G4double, G4double, G4double>())
  .def(py::init<G4ThreeVector>())
  // ---
  .def("GetColor",        &G4Colour::GetColour)
  // ---
  .def("GetRed",          &G4Colour::GetRed)
  .def("GetGreen",        &G4Colour::GetGreen)
  .def("GetBlue",         &G4Colour::GetBlue)
  .def("GetAlpha",        &G4Colour::GetAlpha)
  .def("SetAlpha",        &G4Colour::SetAlpha)
  // ---
  .def_static("White",    &G4Colour::White)
  .def_static("Gray",     &G4Colour::Gray)
  .def_static("Grey",     &G4Colour::Grey)
  .def_static("Black",    &G4Colour::Black)
  .def_static("Brown",    &G4Colour::Brown)
  .def_static("Red",      &G4Colour::Red)
  .def_static("Green",    &G4Colour::Green)
  .def_static("Blue",     &G4Colour::Blue)
  .def_static("Cyan",     &G4Colour::Cyan)
  .def_static("Magenta",  &G4Colour::Magenta)
  .def_static("Yellow",   &G4Colour::Yellow)

  // operators
  .def(py::self += py::self)
  .def(py::self == py::self)
  .def(py::self != py::self)
  // ---
  .def("__str__",   [](const G4Colour&v) {return ::to_string(v);})
  .def("__repr__",  [](const G4Colour&v) {return ::to_string(v);})
  ;
}
