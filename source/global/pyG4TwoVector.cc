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
//#include <iostream>
#include "G4TwoVector.hh"

namespace py = pybind11;
using c = G4TwoVector;
using namespace CLHEP;

// --------------------------------------------------------------------------
namespace {

std::string vec_to_string(const G4TwoVector& vec)
{
  std::string message = "(";
  message += std::to_string(vec.x()) + ", ";
  message += std::to_string(vec.y()) + ")";

  return message;
}

}

// ==========================================================================
void export_G4TwoVector(py::module& m)
{
  py::class_<G4TwoVector>(m, "G4TwoVector")
  // ---
  .def(py::init<>())
  .def(py::init<G4double>())
  .def(py::init<G4double, G4double>())
  .def(py::init<const G4TwoVector&>())
  // ---
  .def_property("x",   &c::x, &c::setX)
  .def_property("y",   &c::y, &c::setY)
  .def("setX",         &c::setX)
  .def("setY",         &c::setY)
  .def("getX",         &c::x)
  .def("getY",         &c::y)
  .def("set",          &c::set)
  // ---
  .def("phi",          &c::phi)
  .def("mag2",         &c::mag2)
  .def("mag",          &c::mag)
  .def("r",            &c::r)
  .def("setPhi",       &c::setPhi)
  .def("setMag",       &c::setMag)
  .def("setR",         &c::setR)
  .def("setPolar",     &c::setPolar)
  // ---
  .def_static("getTolerance",  &c::getTolerance)
  .def_static("setTolerance",  &c::setTolerance)
  // ---
  .def("howNear",       &c::howNear)
  .def("isNear",        &c::isNear,
                        py::arg("p"), py::arg("epsilon") = 2.2E-14)
  .def("howParallel",   &c::howParallel)
  .def("isParallel",    &c::isParallel,
                        py::arg("p"), py::arg("epsilon") = 2.2E-14)
  .def("howOrthogonal", &c::howOrthogonal)
  .def("isOrthogonal",  &c::isOrthogonal,
                        py::arg("p"), py::arg("epsilon") = 2.2E-14)
  .def("unit",          &c::unit)
  .def("orthogonal",    &c::orthogonal)
  .def("dot",           &c::dot)
  .def("angle",         &c::angle)
  .def("rotate",        &c::rotate)

  // operators
  .def(py::self == py::self)
  .def(py::self != py::self)
  .def(py::self += py::self)
  .def(py::self -= py::self)
  .def(py::self -  py::self)
  .def(py::self +  py::self)
  .def(py::self *  py::self)
  .def(py::self *  double())
  .def(py::self /  double())
  .def(double() * py::self)
  .def(py::self *= double())
  .def(py::self >  py::self)
  .def(py::self <  py::self)
  .def(py::self >= py::self)
  .def(py::self <= py::self)

  // ---
  .def("__str__",   [](const c&v) {return ::vec_to_string(v);})
  .def("__repr__",  [](const c&v) {return ::vec_to_string(v);})
  ;
}
