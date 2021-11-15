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
#include "G4Event.hh"
#include "G4Region.hh"
#include "G4Run.hh"
#include "G4RunManagerFactory.hh"
#include "G4UserEventAction.hh"
#include "G4UserRunAction.hh"
#include "G4UserStackingAction.hh"
#include "G4UserSteppingAction.hh"
#include "G4UserTrackingAction.hh"
#include "G4UserWorkerInitialization.hh"
#include "G4UserWorkerThreadInitialization.hh"
#include "G4VUserActionInitialization.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VUserPhysicsList.hh"
#include "G4VUserPrimaryGeneratorAction.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

void CreateRunManager()
{
  G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default,
                                        nullptr, true, 1);
}

}

// ==========================================================================
void export_G4RunManager(py::module& m)
{
  m.def("CreateRunManager", &::CreateRunManager);

  py::class_<G4RunManager>(m, "G4RunManager")
  .def_static("GetRunManager",  &G4RunManager::GetRunManager,
                                py::return_value_policy::reference)
  .def_property("verboseLevel", &G4RunManager::GetVerboseLevel,
                                &G4RunManager::SetVerboseLevel)
  .def("SetVerboseLevel",       &G4RunManager::SetVerboseLevel)
  .def("GetVerboseLevel",       &G4RunManager::GetVerboseLevel)
  .def("GetVersionString",      &G4RunManager::GetVersionString,
                                py::return_value_policy::copy)
  // ---
  .def("Initialize",            &G4RunManager::Initialize)
  .def("BeamOn",                &G4RunManager::BeamOn,
                                py::arg("n_event"),
                                py::arg("macroFile") = nullptr,
                                py::arg("n_select") = -1)
  .def("AbortRun",              &G4RunManager::AbortRun,
                                py::arg("softAbort") = false)
  .def("AbortEvent",            &G4RunManager::AbortEvent)
  // ---
  .def("SetUserInitialization",
       py::overload_cast<G4VUserDetectorConstruction*>(
         &G4RunManager::SetUserInitialization))
  .def("SetUserInitialization",
       py::overload_cast<G4VUserPhysicsList*>(
         &G4RunManager::SetUserInitialization))
  .def("SetUserInitialization",
       py::overload_cast<G4VUserActionInitialization*>(
         &G4RunManager::SetUserInitialization))
  .def("SetUserInitialization",
       py::overload_cast<G4UserWorkerInitialization*>(
         &G4RunManager::SetUserInitialization))
  .def("SetUserInitialization",
       py::overload_cast<G4UserWorkerThreadInitialization*>(
         &G4RunManager::SetUserInitialization))
  // ---
  .def("SetUserAction",
       py::overload_cast<G4UserRunAction*>(&G4RunManager::SetUserAction))
  .def("SetUserAction",
       py::overload_cast<G4VUserPrimaryGeneratorAction*>(
         &G4RunManager::SetUserAction))
  .def("SetUserAction",
       py::overload_cast<G4UserEventAction*>(&G4RunManager::SetUserAction))
  .def("SetUserAction",
       py::overload_cast<G4UserStackingAction*>(&G4RunManager::SetUserAction))
  .def("SetUserAction",
       py::overload_cast<G4UserTrackingAction*>(&G4RunManager::SetUserAction))
  .def("SetUserAction",
       py::overload_cast<G4UserSteppingAction*>(&G4RunManager::SetUserAction))
  // ---
  .def("GetUserDetectorConstruction",
       &G4RunManager::GetUserDetectorConstruction,
       py::return_value_policy::reference)
  .def("GetUserPhysicsList",    &G4RunManager::GetUserPhysicsList,
       py::return_value_policy::reference)
  .def("GetUserPrimaryGeneratorAction",
       &G4RunManager::GetUserPrimaryGeneratorAction,
       py::return_value_policy::reference)
  .def("GetUserRunAction",      &G4RunManager::GetUserRunAction,
       py::return_value_policy::reference)
  .def("GetUserEventAction",    &G4RunManager::GetUserEventAction,
       py::return_value_policy::reference)
  .def("GetUserStackingAction", &G4RunManager::GetUserStackingAction,
       py::return_value_policy::reference)
  .def("GetUserTrackingAction", &G4RunManager::GetUserTrackingAction,
       py::return_value_policy::reference)
  .def("GetUserSteppingAction", &G4RunManager::GetUserSteppingAction,
       py::return_value_policy::reference)
  // ---
  .def("DefineWorldVolume",     &G4RunManager::DefineWorldVolume,
                                py::arg("worldVol"),
                                py::arg("topologyIsChanged") = true)
  .def("DumpRegion",
       static_cast<void (G4RunManager::*)(const G4String&) const>
       (&G4RunManager::DumpRegion))
  .def("DumpRegion",
        static_cast<void (G4RunManager::*)(G4Region*) const>
        (&G4RunManager::DumpRegion),
        py::arg("region") = nullptr)
  .def("GeometryHasBeenModified", &G4RunManager::GeometryHasBeenModified,
                                  py::arg("prop") = true)
  .def("CutOffHasBeenModiied",    &G4RunManager::CutOffHasBeenModified)
  .def("PhysicsHasBeenModified",  &G4RunManager::PhysicsHasBeenModified)
  .def("GetGeometryToBeOptimized",&G4RunManager::GetGeometryToBeOptimized)
  // ---
  .def("GetCurrentRun",           &G4RunManager::GetCurrentRun,
                                  py::return_value_policy::reference)
  .def("GetCurrentEvent",         &G4RunManager::GetCurrentEvent,
                                  py::return_value_policy::reference)
  // ---
  .def("SetRandomNumberStoreDir", &G4RunManager::SetRandomNumberStoreDir)
  .def("GetRandomNumberStoreDir", &G4RunManager::GetRandomNumberStoreDir,
                                  py::return_value_policy::copy)
  .def("rndmSaveThisRun",         &G4RunManager::rndmSaveThisRun)
  .def("rndmSaveThisEvent",       &G4RunManager::rndmSaveThisEvent)
  .def("RestoreRandomNumberStatus", &G4RunManager::RestoreRandomNumberStatus)
  .def("SetRandomNumberStore",    &G4RunManager::SetRandomNumberStore)
  .def("GetRandomNumberStore",    &G4RunManager::GetRandomNumberStore)
  ;

}
