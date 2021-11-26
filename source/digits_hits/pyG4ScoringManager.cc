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
#include "G4ScoringManager.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4ScoringManager(py::module& m)
{
  py::class_<G4ScoringManager>(m, "G4ScoringManager")
  // ---
  .def_static("GetScoringManager",  &G4ScoringManager::GetScoringManager,
                                     py::return_value_policy::reference)
  // ---
  .def("SetReplicaLevel",     &G4ScoringManager::SetReplicaLevel)
  .def("GetReplicaLevel",     &G4ScoringManager::GetReplicaLevel)
  // ---
  .def("List",                &G4ScoringManager::List)
  .def("Dump",                &G4ScoringManager::Dump)
  .def("ListScoreColorMaps",  &G4ScoringManager::ListScoreColorMaps)
  .def("DrawMesh",
        py::overload_cast<const G4String&, const G4String&,
                          const G4String&, G4int>
        (&G4ScoringManager::DrawMesh),
        py::arg("meshName"), py::arg("psName"), py::arg("colmap"),
        py::arg("flg") = 111)
  .def("DrawMesh",
        py::overload_cast<const G4String&, const G4String&,
                          G4int, G4int, const G4String&>
        (&G4ScoringManager::DrawMesh),
        py::arg("meshName"), py::arg("psName"), py::arg("idxPlane"),
        py::arg("icol"), py::arg("colmap"))
  .def("DumpQuantityToFile",    &G4ScoringManager::DumpQuantityToFile,
                                py::arg("meshName"), py::arg("psName"),
                                py::arg("filename"), py::arg("option") = "")
  .def("DumpAllQuantityToFile", &G4ScoringManager::DumpAllQuantitiesToFile,
                                py::arg("meshName"), py::arg("filename"),
                                py::arg("option") = "")
  // ---
  .def("SetCurrentMesh",        &G4ScoringManager::SetCurrentMesh)
  .def("GetCurrentMesh",        &G4ScoringManager::GetCurrentMesh,
                                py::return_value_policy::reference)
  .def("CloseCurrentMesh",      &G4ScoringManager::CloseCurrentMesh)
  // ---
  .def("SetVerboseLevel",       &G4ScoringManager::SetVerboseLevel)
  .def("GetVerboseLevel",       &G4ScoringManager::GetVerboseLevel)
  // ---
  .def("GetNumberOfMesh",       &G4ScoringManager::GetNumberOfMesh)
  .def("RegisterScoringMesh",   &G4ScoringManager::RegisterScoringMesh)
  .def("GetMesh",               &G4ScoringManager::GetMesh,
                                py::return_value_policy::reference)
  .def("GetWorldName",          &G4ScoringManager::GetWorldName)
  ;
}
