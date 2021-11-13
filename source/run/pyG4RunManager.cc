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
#include "G4RunManagerFactory.hh"
#include "G4RunManager.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VUserPhysicsList.hh"
#include "G4VUserActionInitialization.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4UserWorkerInitialization.hh"
#include "G4UserWorkerThreadInitialization.hh"
#include "G4UserRunAction.hh"
#include "G4UserEventAction.hh"
#include "G4UserStackingAction.hh"
#include "G4UserTrackingAction.hh"
#include "G4UserSteppingAction.hh"
#include "G4Region.hh"
#include "G4Run.hh"
#include "G4Event.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

void CreateRunManager()
{
  G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default,
                                        nullptr, true, 1);
}

/*
// SetUserAction()
void (G4RunManager::*f1_SetUserAction)(G4UserRunAction*)
  = &G4RunManager::SetUserAction;
void (G4RunManager::*f2_SetUserAction)(G4VUserPrimaryGeneratorAction*)
  = &G4RunManager::SetUserAction;
void (G4RunManager::*f3_SetUserAction)(G4UserEventAction*)
  = &G4RunManager::SetUserAction;
void (G4RunManager::*f4_SetUserAction)(G4UserStackingAction*)
  = &G4RunManager::SetUserAction;
void (G4RunManager::*f5_SetUserAction)(G4UserTrackingAction*)
  = &G4RunManager::SetUserAction;
void (G4RunManager::*f6_SetUserAction)(G4UserSteppingAction*)
  = &G4RunManager::SetUserAction;

// DumpRegion
void (G4RunManager::*f1_DumpRegion)(const G4String&) const
  = &G4RunManager::DumpRegion;
void (G4RunManager::*f2_DumpRegion)(G4Region*) const
  = &G4RunManager::DumpRegion;

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(f_DumpRegion, DumpRegion, 0, 1)

// BeamOn()
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(f_BeamOn, BeamOn, 1, 3)

// AbortRun()
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(f_AbortRun, AbortRun, 0, 1)

// DefineWorldVolume()
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(f_DefineWorldVolume,
                                       DefineWorldVolume, 1, 2)

// GeometryHasBeenModified()
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(f_GeometryHasBeenModified,
                                       GeometryHasBeenModified, 0, 1)
*/

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
  // ---
  .def("Initialize",            &G4RunManager::Initialize)
  .def("BeamOn",                &G4RunManager::BeamOn,
       py::arg("n_event"),
       py::arg("macroFile") = nullptr, py::arg("n_select") = -1)
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

    ;

  /*
    // ---
    .def("SetUserInitialization", f1_SetUserInitialization)
    .def("SetUserInitialization", f2_SetUserInitialization)
    .def("SetUserAction",         f1_SetUserAction)
    .def("SetUserAction",         f2_SetUserAction)
    .def("SetUserAction",         f3_SetUserAction)
    .def("SetUserAction",         f4_SetUserAction)
    .def("SetUserAction",         f5_SetUserAction)
    .def("SetUserAction",         f6_SetUserAction)
    // ---
    .def("GetUserDetectorConstruction",
   &G4RunManager::GetUserDetectorConstruction,
   return_internal_reference<>())
    .def("GetUserPhysicsList",
   &G4RunManager::GetUserPhysicsList,
   return_internal_reference<>())
    .def("GetUserPrimaryGeneratorAction",
   &G4RunManager::GetUserPrimaryGeneratorAction,
   return_internal_reference<>())
    .def("GetUserRunAction",      &G4RunManager::GetUserRunAction,
   return_internal_reference<>())
    .def("GetUserEventAction",    &G4RunManager::GetUserEventAction,
   return_internal_reference<>())
    .def("GetUserStackingAction", &G4RunManager::GetUserStackingAction,
   return_internal_reference<>())
    .def("GetUserTrackingAction", &G4RunManager::GetUserTrackingAction,
   return_internal_reference<>())
    .def("GetUserSteppingAction", &G4RunManager::GetUserSteppingAction,
   return_internal_reference<>())
    // ---
    .def("AbortRun",             &G4RunManager::AbortRun,
   f_AbortRun((arg("soft_abort")=false),
        "Abort run (event loop)."))
    .def("AbortEvent",           &G4RunManager::AbortEvent)
    .def("DefineWorldVolume",    &G4RunManager::DefineWorldVolume,
                                 f_DefineWorldVolume())
    .def("DumpRegion",           f1_DumpRegion)
    .def("DumpRegion",           f2_DumpRegion, f_DumpRegion())
    .def("rndmSaveThisRun",      &G4RunManager::rndmSaveThisRun)
    .def("rndmSaveThisEvent",    &G4RunManager::rndmSaveThisEvent)
    .def("RestoreRandomNumberStatus",
                                 &G4RunManager::RestoreRandomNumberStatus)
    .def("SetRandomNumberStore", &G4RunManager::SetRandomNumberStore)
    .def("GetRandomNumberStore", &G4RunManager::GetRandomNumberStore)
    .def("SetRandomNumberStoreDir", &G4RunManager::SetRandomNumberStoreDir)
    .def("GeometryHasBeenModified", &G4RunManager::GeometryHasBeenModified,
         f_GeometryHasBeenModified())
    .def("PhysicsHasBeenModified",  &G4RunManager::PhysicsHasBeenModified)
    .def("GetGeometryToBeOptimized",&G4RunManager::GetGeometryToBeOptimized)
    .def("GetCurrentRun",  &G4RunManager::GetCurrentRun,
    return_value_policy<reference_existing_object>())
    .def("GetCurrentEvent", &G4RunManager::GetCurrentEvent,
    return_value_policy<reference_existing_object>())
    .def("SetRunIDCounter",        &G4RunManager::SetRunIDCounter)
    .def("GetVersionString",     &G4RunManager::GetVersionString,
    return_value_policy<reference_existing_object>())
    .def("GetRandomNumberStoreDir", &G4RunManager::GetRandomNumberStoreDir,
    return_internal_reference<>())
    ;
    */
}
