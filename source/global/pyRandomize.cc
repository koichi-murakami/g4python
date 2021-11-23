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
#include "Randomize.hh"

namespace py = pybind11;
using namespace CLHEP;

// --------------------------------------------------------------------------
namespace {

// --------------------------------------------------------------------------
// getTheSeeds
py::list f_getTheSeeds()
{
  py::list seed_list;

  auto seeds = HepRandom::getTheSeeds();

  int idx = 0;
  while(1) {
    if( seeds[idx] == 0. ) break;
    seed_list.append(seeds[idx]);
    idx++;
  }

  return seed_list;
}

// --------------------------------------------------------------------------
// G4UniformRand
double f_G4UniformRand()
{
  return G4UniformRand();
}

}

// ==========================================================================
void export_Randomize(py::module& m)
{
  py::class_<HepRandom>(m, "HepRandom")
  // ---
  .def(py::init<>())
  .def(py::init<long>())
  .def(py::init<HepRandomEngine&>())
  .def(py::init<HepRandomEngine*>())
  .def_static("getTheGenerator",  &HepRandom::getTheGenerator,
                                  py::return_value_policy::reference)
  // ---
  .def("flat", py::overload_cast<>(&HepRandom::flat))
  .def("flat", py::overload_cast<HepRandomEngine*>(&HepRandom::flat))
  .def("name",                    &HepRandom::name)
  .def("engine",                  &HepRandom::engine,
                                  py::return_value_policy::reference)
  // ---
  .def_static("setTheSeed",       &HepRandom::setTheSeed,
                                  py::arg("seed"), py::arg("lxr") = 3)
  .def_static("getTheSeeds",      &::f_getTheSeeds)
  .def_static("setTheEngine",     &HepRandom::setTheEngine)
  .def_static("getTheEngine",     &HepRandom::getTheEngine,
                                  py::return_value_policy::reference)

  .def_static("saveEngineStatus", &HepRandom::saveEngineStatus,
                                  py::arg("filename")="Config.conf")
  .def_static("restoreEngineStatus",  &HepRandom::restoreEngineStatus,
                                      py::arg("filename")="Config.conf")
  .def_static("showEngineStatus", &HepRandom::showEngineStatus)
  .def_static("createInstance",   &HepRandom::createInstance)
  ;

  // ---
  py::class_<G4RandGauss>(m, "G4RandGauss")
  // ---
  .def_static("shoot", py::overload_cast<>(&G4RandGauss::shoot))
  .def_static("shoot", py::overload_cast<double, double>(&G4RandGauss::shoot))
  ;

  // ---
  m.def("G4UniformRand", &::f_G4UniformRand);
}
