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
#include "G4StackManager.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4StackManager(py::module& m)
{
  py::class_<G4StackManager>(m, "G4StackManager")
  // ---
  .def("ReClassify",               &G4StackManager::ReClassify)
  .def("SetNumberOfAdditionalWaitingStacks",
                     &G4StackManager::SetNumberOfAdditionalWaitingStacks)
  .def("TransferStackedTracks",    &G4StackManager::TransferStackedTracks)
  .def("TransferOneStackedTrack",  &G4StackManager::TransferOneStackedTrack)
  // ---
  .def("clear",                    &G4StackManager::clear)
  .def("ClearUrgentStack",         &G4StackManager::ClearUrgentStack)
  .def("ClearWaitingStack",        &G4StackManager::ClearWaitingStack,
                                   py::arg("i") = 0)
  .def("ClearPostponeStack",       &G4StackManager::ClearPostponeStack)
  .def("GetNTotalTrack",           &G4StackManager::GetNTotalTrack)
  .def("GetNUrgentTrack",          &G4StackManager::GetNUrgentTrack)
  .def("GetNWaitingTrack",         &G4StackManager::GetNWaitingTrack,
                                   py::arg("i") = 0)
  .def("SetVerboseLevel",          &G4StackManager::SetVerboseLevel)
  .def("SetUserStackingAction",    &G4StackManager::SetUserStackingAction)
  ;
}
