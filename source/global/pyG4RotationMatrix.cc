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
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"

namespace py = pybind11;
using c = G4RotationMatrix;

// --------------------------------------------------------------------------
namespace {

// --------------------------------------------------------------------------
std::string to_string(const G4RotationMatrix& rot)
{
  std::stringstream ss;
  ss << rot;
  return ss.str();
}

// --------------------------------------------------------------------------
void print(G4RotationMatrix* rot)
{
  G4cout << *rot << G4endl;
}

}

// ==========================================================================
void export_G4RotationMatrix(py::module& m)
{
  py::class_<G4RotationMatrix>(m, "G4RotationMatrix")
  // ---
  .def(py::init<>())
  .def(py::init<const c&>())
  // ---
  .def("rotateX",  &c::rotateX)
  .def("rotateY",  &c::rotateY)
  .def("rotateZ",  &c::rotateZ)
  .def("rotate",   py::overload_cast<double, const G4ThreeVector&>
                   (&c::rotate),
                   py::return_value_policy::take_ownership)
  .def("inverse",  &c::inverse)
  .def("invert",   &c::invert,
                   py::return_value_policy::take_ownership)
  .def("print",    &::print)

  // operators
  .def(py::self == py::self)
  .def(py::self != py::self)
  .def(py::self >  py::self)
  .def(py::self <  py::self)
  .def(py::self >= py::self)
  .def(py::self <= py::self)
  .def(py::self *  py::self)
  .def(py::self *  G4ThreeVector())
  .def(py::self *= py::self)

  // ---
  .def("__str__",   [](const c&v) {return ::to_string(v);})
  .def("__repr__",  [](const c&v) {return ::to_string(v);})
  ;
}
