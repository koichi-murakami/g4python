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
#include <iostream>
#include "G4ThreeVector.hh"
#include "G4RotationMatrix.hh"

namespace py = pybind11;
using c = G4ThreeVector;
using namespace CLHEP;

namespace {

std::string vec_to_string(const G4ThreeVector& vec)
{
  std::string message = "(";
  message += std::to_string(vec.getX()) + ", ";
  message += std::to_string(vec.getY()) + ", ";
  message += std::to_string(vec.getZ()) + ")";

  return message;
}

}

// ==========================================================================
void export_G4ThreeVector(py::module& mod)
{
  double tolerance = c::getTolerance();

  py::class_<G4ThreeVector>(mod, "G4ThreeVector")
  .def(py::init<G4double>())
  .def(py::init<G4double, G4double>())
  .def(py::init<G4double, G4double, G4double>())
  .def(py::init<const G4ThreeVector&>())
  .def_property("x",   &c::getX, &c::setX)
  .def_property("y",   &c::getY, &c::setY)
  .def_property("z",   &c::getZ, &c::setZ)
  .def("setX",         &c::setX)
  .def("setY",         &c::setY)
  .def("setZ",         &c::setZ)
  .def("getX",         &c::getX)
  .def("getX",         &c::getY)
  .def("getX",         &c::getZ)
  // ---
  .def("set",          &c::set)
  .def("phi",          &c::phi)
  .def("mag",          &c::mag)
  .def("mag2",         &c::mag2)
  .def("setPhi",       &c::setPhi)
  .def("setTheta",     &c::setTheta)
  .def("setMag",       &c::setMag)
  .def("setPerp",      &c::setPerp)
  .def("setCylTheta",  &c::setCylTheta)
  .def("howNear",      &c::howNear)
  .def("deltaR",       &c::deltaR)
  .def("unit",         &c::unit)
  .def("orthogonal",   &c::orthogonal)
  .def("dot",          &c::dot)
  .def("cross",        &c::cross)
  .def("pseudoRapidity", &c::pseudoRapidity)
  .def("setEta",       &c::setEta)
  .def("setCylEta",    &c::setCylEta)
  .def("setRThetaPhi", &c::setRThetaPhi)
  .def("setREtaPhi",   &c::setREtaPhi)
  .def("setRhoPhiZ",   &c::setRhoPhiZ)
  .def("setRhoPhiEta", &c::setRhoPhiEta)
  .def("getR",         &c::getR)
  .def("getTheta",     &c::getTheta)
  .def("getPhi",       &c::getPhi)
  .def("r",            &c::r)
  .def("rho",          &c::rho)
  .def("getRho",       &c::getRho)
  .def("getEta",       &c::getEta)
  .def("setR",         &c::setR)
  .def("setRho",       &c::setRho)
  .def("compare",      &c::compare)
  .def("diff2",        &c::diff2)
  .def_static("setTolerance", &c::setTolerance)
  .def_static("getTolerance", &c::getTolerance)
  .def("isNear",       &c::isNear,
                       py::arg("vec"),
                       py::arg("epsilon")=tolerance)
  .def("isParallel",   &c::isParallel,
                       py::arg("vec"),
                       py::arg("epsilon")=tolerance)
  .def("isOrthogonal", &c::isOrthogonal,
                       py::arg("vec"),
                       py::arg("epsilon")=tolerance)
  .def("howParallel",  &c::howParallel)
  .def("howOrthogonal",&c::howOrthogonal)
  .def("beta",         &c::beta)
  .def("gamma",        &c::gamma)
  .def("deltaPhi",     &c::deltaPhi)
  .def("coLinearRapidity", &c::coLinearRapidity)
  // ---
  .def("theta", static_cast<double (c::*)() const>(&c::theta))
  .def("theta", static_cast<double (c::*)(const Hep3Vector&) const>(&c::theta))

  .def("cosTheta", static_cast<double (c::*)() const>(&c::cosTheta))
  .def("cosTheta", static_cast<double (c::*)(const Hep3Vector&) const>
                   (&c::cosTheta))

  .def("cos2Theta", static_cast<double (c::*)() const>(&c::cos2Theta))
  .def("cos2Theta", static_cast<double (c::*)(const Hep3Vector&) const>
                   (&c::cos2Theta))

  .def("perp2", static_cast<double (c::*)() const>(&c::perp2))
  .def("perp2", static_cast<double (c::*)(const Hep3Vector&) const>(&c::perp2))

  .def("angle", static_cast<double (c::*)() const>(&c::angle))
  .def("angle", static_cast<double (c::*)(const Hep3Vector&) const>(&c::angle))

  .def("eta", static_cast<double (c::*)() const>(&c::eta))
  .def("eta", static_cast<double (c::*)(const Hep3Vector&) const>(&c::eta))

  .def("rapidity", static_cast<double (c::*)() const>(&c::rapidity))
  .def("rapidity", static_cast<double (c::*)(const Hep3Vector&) const>
                   (&c::rapidity))

  .def("polarAngle", static_cast<double (c::*)(const Hep3Vector&) const>
                     (&c::polarAngle))
  .def("polarAngle", static_cast<double (c::*)(const Hep3Vector&,
                                               const Hep3Vector&) const>
                     (&c::polarAngle))

  .def("azimAngle", static_cast<double (c::*)(const Hep3Vector&) const>
                    (&c::azimAngle))
  .def("azimAngle", static_cast<double (c::*)(const Hep3Vector&,
                                              const Hep3Vector&) const>
                    (&c::azimAngle))

  .def("project", static_cast<Hep3Vector (c::*)() const>(&c::project))
  .def("project", static_cast<Hep3Vector (c::*)(const Hep3Vector&) const>
                  (&c::project))

  .def("perpPart", static_cast<Hep3Vector (c::*)() const>(&c::perpPart))
  .def("perpPart", static_cast<Hep3Vector (c::*)(const Hep3Vector&) const>
                   (&c::perpPart))

  // ---
  .def("rotateX",   &c::rotateX,   py::return_value_policy::reference)
  .def("rotateY",   &c::rotateY,   py::return_value_policy::reference)
  .def("rotateZ",   &c::rotateZ,   py::return_value_policy::reference)
  .def("rotateUz",  &c::rotateUz,  py::return_value_policy::reference)
  .def("transform", &c::transform, py::return_value_policy::reference)

  .def("rotate", static_cast<Hep3Vector& (c::*)(double, const Hep3Vector&)>
                 (&c::rotate),     py::return_value_policy::reference)

  .def("rotate", static_cast<Hep3Vector& (c::*)(const Hep3Vector&, double)>
                 (&c::rotate),     py::return_value_policy::reference)

  .def("rotate", static_cast<Hep3Vector& (c::*)(const HepAxisAngle&)>
                 (&c::rotate),     py::return_value_policy::reference)

  //.def("rotate", static_cast<Hep3Vector& (c::*)(const HepEulerAngles&)>
  //               (&c::rotate),     py::return_value_policy::reference)

  .def("rotate", static_cast<Hep3Vector& (c::*)(double, double, double)>
                 (&c::rotate),     py::return_value_policy::reference)

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
  .def(py::self /= double())
  .def(py::self >  py::self)
  .def(py::self <  py::self)
  .def(py::self >= py::self)
  .def(py::self <= py::self)

  // ---
  .def("__str__",   [](const c&v) {return ::vec_to_string(v);})
  .def("__repr__",   [](const c&v) {return ::vec_to_string(v);})
  ;
}
