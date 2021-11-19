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
#include "G4VGraphicsSystem.hh"
#include "G4VisManager.hh"
#include "G4TrajectoryModelFactories.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

class PyG4VisManager : public G4VisManager {
public:
  PyG4VisManager() { SetVerboseLevel(quiet); }
  ~PyG4VisManager() { }

  static PyG4VisManager* _get_concrete_instance() {
    return dynamic_cast<PyG4VisManager*>(fpConcreteInstance);
  }

  void RegisterGraphicsSystems() override { }

  void RegisterModelFactories() override {
    RegisterModelFactory(new G4TrajectoryDrawByChargeFactory());
    RegisterModelFactory(new G4TrajectoryDrawByParticleIDFactory());
  }
};

}

// ==========================================================================
void export_G4VisManager(py::module& m)
{
  py::class_<PyG4VisManager>vis_manager(m, "G4VisManager");
  vis_manager
  .def(py::init<>())
  .def_static("GetConcreteInstance", &PyG4VisManager::_get_concrete_instance,
                                     py::return_value_policy::reference)
  // ---
  .def_static("GetVerbosity",        &PyG4VisManager::GetVerbosity)
  .def("SetVerboseLevel",
       py::overload_cast<G4int>(&PyG4VisManager::SetVerboseLevel))
  .def("SetVerboseLevel",
       py::overload_cast<const G4String&>(&PyG4VisManager::SetVerboseLevel))
  .def("SetVerboseLevel",
       py::overload_cast<G4VisManager::Verbosity>
       (&PyG4VisManager::SetVerboseLevel))
  // ---
  .def("Initialize",               &PyG4VisManager::Initialize)
  .def("RegisterGraphicsSystem",   &PyG4VisManager::RegisterGraphicsSystem)
  ;

  py::enum_<G4VisManager::Verbosity>(vis_manager, "Verbosity")
  .value("quiet",             G4VisManager::quiet)
  .value("startup",           G4VisManager::startup)
  .value("errors",            G4VisManager::errors)
  .value("warnings",          G4VisManager::warnings)
  .value("confirmations",     G4VisManager::confirmations)
  .value("parameters",        G4VisManager::parameters)
  .value("all",               G4VisManager::all)
  ;

  py::class_<G4VGraphicsSystem>(m, "G4VGraphicSystem")
  ;
}
