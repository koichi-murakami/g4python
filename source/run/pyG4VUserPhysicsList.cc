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
#include "G4VUserPhysicsList.hh"

namespace py = pybind11;

// ==========================================================================

void export_G4VUserPhysicsList(py::module& m)
{
  py::class_<G4VUserPhysicsList>(m, "G4VUserPhysicsList")
  // ---
  .def("SetDefaultCutValue",    &G4VUserPhysicsList::SetDefaultCutValue)
  .def("GetDefaultCutValue",    &G4VUserPhysicsList::GetDefaultCutValue)
  // ---
  .def("SetVerboseLevel",       &G4VUserPhysicsList::SetVerboseLevel)
  .def("GetVerboseLevel",       &G4VUserPhysicsList::GetVerboseLevel)
  // ---
  .def("DumpList",              &G4VUserPhysicsList::DumpList)
  // ---
  .def("Construct",             &G4VUserPhysicsList::Construct)
  .def("ConstructParticle",     &G4VUserPhysicsList::ConstructParticle)
  .def("ConstructProcess",      &G4VUserPhysicsList::ConstructProcess)
    /*
    // ---
      .def("SetCuts",
	 pure_virtual(&G4VUserPhysicsList::SetCuts))
    // ---
    .def("StorePhysicsTable",     &G4VUserPhysicsList::StorePhysicsTable,
	 f_StorePhysicsTable())
    .def("IsPhysicsTableRetrieved",
         &G4VUserPhysicsList::IsPhysicsTableRetrieved)
    .def("IsStoredInAscii",       &G4VUserPhysicsList::IsStoredInAscii)
    .def("GetPhysicsTableDirectory",
         &G4VUserPhysicsList::GetPhysicsTableDirectory,
         return_value_policy<return_by_value>())
    .def("SetStoredInAscii",      &G4VUserPhysicsList::SetStoredInAscii)
    .def("ResetStoredInAscii",    &G4VUserPhysicsList::ResetStoredInAscii)
    // ---
    .def("DumpList",              &G4VUserPhysicsList::DumpList)

    .def("DumpCutValuesTable",    &G4VUserPhysicsList::DumpCutValuesTable)
    .def("DumpCutValuesTableIfRequested",
         &G4VUserPhysicsList::DumpCutValuesTableIfRequested)
    .def("SetCutValue",           f1_SetCutValue)
    .def("SetCutValue",           f2_SetCutValue)
    .def("SetParticleCuts",       f1_SetParticleCuts, f_SetParticleCuts())
    .def("SetParticleCuts",       f2_SetParticleCuts, f_SetParticleCuts())
    // ---

    .def("SetCutsWithDefault",    &G4VUserPhysicsList::SetCutsWithDefault)
    .def("SetCutsForRegion",      &G4VUserPhysicsList::SetCutsForRegion)
    .def("GetApplyCuts",          &G4VUserPhysicsList::GetApplyCuts)
    */
    ;
}
