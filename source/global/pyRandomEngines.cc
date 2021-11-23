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
#include "CLHEP/Random/RandomEngine.h"
#include "CLHEP/Random/JamesRandom.h"
#include "CLHEP/Random/RanecuEngine.h"
#include "CLHEP/Random/Ranlux64Engine.h"
#include "CLHEP/Random/RanluxEngine.h"
#include "CLHEP/Random/MTwistEngine.h"

namespace py = pybind11;
using namespace CLHEP;

// ==========================================================================
void export_RandomEngines(py::module& m)
{
  py::class_<HepRandomEngine>(m, "HepRandomEngine");

  py::class_<HepJamesRandom>(m, "HepJamesRandom")
  .def(py::init<>())
  ;

  py::class_<RanecuEngine>(m,"RanecuEngine")
  .def(py::init<>())
  ;

  py::class_<RanluxEngine>(m, "RanluxEngine")
  .def(py::init<>())
  ;

  py::class_<Ranlux64Engine>(m, "Ranlux64Engine")
  .def(py::init<>())
  ;

  py::class_<MTwistEngine, HepRandomEngine>(m, "MTwistEngine")
  .def(py::init<>())
  .def(py::init<long>())
  // ---
  .def("flat",           &MTwistEngine::flat)
  .def("double",         &MTwistEngine::operator double)
  .def("setSeed",        &MTwistEngine::setSeed)
  .def("showStatus",     &MTwistEngine::showStatus)
  // ---
  .def("name",          &MTwistEngine::name)
  .def("engineName",    &MTwistEngine::engineName)
  ;

}
