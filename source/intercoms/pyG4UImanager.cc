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
#include "G4UIcommandTree.hh"
#include "G4UImanager.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

G4UIcommandStatus ApplyUICommand(const G4String& cmdstr)
{
  auto UImgr = G4UImanager::GetUIpointer();

  auto returnVal = UImgr-> ApplyCommand(cmdstr);
  if( returnVal == fCommandSucceeded ) {
    return fCommandSucceeded;
  }

  auto paramIndex = returnVal % 100;
  int commandStatus = returnVal - paramIndex;


  switch( commandStatus ) {
    case fCommandSucceeded:
      return fCommandSucceeded;
      break;

    case fCommandNotFound:
      G4cout << "command <" << UImgr-> SolveAlias(cmdstr)
             << "> not found" << G4endl;
      return fCommandNotFound;
      break;

    case fIllegalApplicationState:
      G4cout << "illegal application state -- command refused"
	           << G4endl;
      return fIllegalApplicationState;
      break;

    case fParameterOutOfRange:
      return fParameterOutOfRange;
      break;

    case fParameterOutOfCandidates:
      G4cout << "Parameter is out of candidate list (index "
	           << paramIndex << ")"
	           << G4endl;
      return fParameterOutOfCandidates;
      break;

    case fParameterUnreadable:
      G4cout << "Parameter is wrong type and/or is not omittable (index "
	           << paramIndex << ")" << G4endl;
      return fParameterUnreadable;
      break;

    case fAliasNotFound:
      return fAliasNotFound;
      break;

    default:
      G4cout << "command refused (" << commandStatus << ")" << G4endl;
      return fCommandNotFound;
      break;
  }

  return fCommandSucceeded;
}

}

// ==========================================================================
void export_G4UImanager(py::module& m)
{
 py::class_<G4UImanager>(m, "G4UImanager")
 .def_static("GetUIpointer",  &G4UImanager::GetUIpointer,
                              py::return_value_policy::reference)
 // ---
 .def("GetCurrentValues",     &G4UImanager::GetCurrentValues)
 .def("ExecuteMacroFile",     &G4UImanager::ExecuteMacroFile)
 .def("ApplyCommand",
       static_cast<int (G4UImanager::*)(const char*)>
       (&G4UImanager::ApplyCommand))
 .def("ApplyCommand",
       static_cast<int (G4UImanager::*)(const G4String&)>
      (&G4UImanager::ApplyCommand))
 .def("CreateHTML",           &G4UImanager::CreateHTML,
      py::arg("dir") = "/")
 .def("SetMacroSearchPath",   &G4UImanager::SetMacroSearchPath)
 .def("GetMacroSearchPath",   &G4UImanager::GetMacroSearchPath,
                              py::return_value_policy::copy)
  // ---
 .def("SetPauseAtBeginOfEvent", &G4UImanager::SetPauseAtBeginOfEvent)
 .def("GetPauseAtBeginOfEvent", &G4UImanager::GetPauseAtBeginOfEvent)
 .def("SetPauseAtEndOfEvent",   &G4UImanager::SetPauseAtEndOfEvent)
 .def("GetPauseAtEndOfEvent",   &G4UImanager::GetPauseAtEndOfEvent)
 .def("SetVerboseLevel",        &G4UImanager::SetVerboseLevel)
 .def("GetVerboseLevel",        &G4UImanager::GetVerboseLevel)
 // ---
 .def("GetTree",                &G4UImanager::GetTree,
                                 py::return_value_policy::reference)
  ;

  // ---
  m.def("ApplyUICommand",  &::ApplyUICommand);

  // ---
  py::enum_<G4UIcommandStatus>(m, "G4UIcommandStatus")
  .value("fCommandSucceeded",       G4UIcommandStatus::fCommandSucceeded)
  .value("fCommandNotFound",        G4UIcommandStatus::fCommandNotFound)
  .value("fIllegalApplicationState",G4UIcommandStatus::fIllegalApplicationState)
  .value("fParameterOutOfRange",    G4UIcommandStatus::fParameterOutOfRange)
  .value("fParameterUnreadable",    G4UIcommandStatus::fParameterUnreadable)
  .value("fParameterOutOfCandidates",G4UIcommandStatus::fParameterOutOfCandidates)
  .value("fAliasNotFound",          G4UIcommandStatus::fAliasNotFound)
  ;

}
