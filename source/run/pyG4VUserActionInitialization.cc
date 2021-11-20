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
#include "G4VUserActionInitialization.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4UserRunAction.hh"
#include "G4UserEventAction.hh"
#include "G4UserStackingAction.hh"
#include "G4UserTrackingAction.hh"
#include "G4UserSteppingAction.hh"
#include "G4VSteppingVerbose.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

class PyG4VUserActionInitialization : public G4VUserActionInitialization {
public:
  using G4VUserActionInitialization::G4VUserActionInitialization;

  void Build() const override {
    PYBIND11_OVERLOAD_PURE(void, G4VUserActionInitialization, Build,);
  }

  void BuildForMaster() const override {
    PYBIND11_OVERLOAD(void, G4VUserActionInitialization, BuildForMaster,);
  }

  G4VSteppingVerbose* InitializeSteppingVerbose() const override {
    PYBIND11_OVERLOAD(G4VSteppingVerbose*, G4VUserActionInitialization,
                      InitializeSteppingVerbose,);
  }
};

class PubG4VUserActionInitialization : public G4VUserActionInitialization {
public:
  using G4VUserActionInitialization::SetUserAction;
};

}

// ==========================================================================
void export_G4VUserActionInitialization(py::module& m)
{
  py::class_<G4VUserActionInitialization, PyG4VUserActionInitialization>
  (m, "G4VUserActionInitialization")
  // ---
  .def(py::init<>())
  .def("Build",                   &G4VUserActionInitialization::Build)
  .def("BuildForMaster",          &G4VUserActionInitialization::BuildForMaster)
  .def("InitializeSteppingVerbose",
                       &G4VUserActionInitialization::InitializeSteppingVerbose)
  // ---
  .def("SetUserAction",
        py::overload_cast<G4VUserPrimaryGeneratorAction*>(
        &PubG4VUserActionInitialization::SetUserAction, py::const_))

  .def("SetUserAction",
        py::overload_cast<G4UserRunAction*>(
        &PubG4VUserActionInitialization::SetUserAction, py::const_))

  .def("SetUserAction",
        py::overload_cast<G4UserEventAction*>(
        &PubG4VUserActionInitialization::SetUserAction, py::const_))

  .def("SetUserAction",
        py::overload_cast<G4UserStackingAction*>(
        &PubG4VUserActionInitialization::SetUserAction, py::const_))

  .def("SetUserAction",
        py::overload_cast<G4UserTrackingAction*>(
        &PubG4VUserActionInitialization::SetUserAction, py::const_))

  .def("SetUserAction",
        py::overload_cast<G4UserSteppingAction*>(
        &PubG4VUserActionInitialization::SetUserAction, py::const_))
  ;
}
