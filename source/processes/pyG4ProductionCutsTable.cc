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
#include "G4ProductionCutsTable.hh"
#include "G4VPhysicalVolume.hh"
#include "G4Material.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4ProductionCutsTable(py::module& m)
{
  py::class_<G4ProductionCutsTable>(m, "G4ProductionCutsTable")
  .def_static("GetProductionCutsTable",
                             &G4ProductionCutsTable::GetProductionCutsTable,
                             py::return_value_policy::reference)
  // ---
  .def("UpdateCoupleTable",  &G4ProductionCutsTable::UpdateCoupleTable)
  .def("SetEnergyRange",     &G4ProductionCutsTable::SetEnergyRange)
  .def("GetLowEdgeEnergy",   &G4ProductionCutsTable::GetLowEdgeEnergy)
  .def("GetHighEdgeEnergy",  &G4ProductionCutsTable::GetHighEdgeEnergy)

  .def("GetMaxEnergyCut",    &G4ProductionCutsTable::GetMaxEnergyCut)
  .def("SetMaxEnergyCut",    &G4ProductionCutsTable::SetMaxEnergyCut)
  .def("DumpCouples",        &G4ProductionCutsTable::DumpCouples)
  .def("GetTableSize",       &G4ProductionCutsTable::GetTableSize)
  // ---
  .def("GetMaterialCutsCouple",
        py::overload_cast<G4int>
        (&G4ProductionCutsTable::GetMaterialCutsCouple, py::const_),
        py::return_value_policy::reference)
  .def("GetMaterialCutsCouple",
        py::overload_cast<const G4Material*, const G4ProductionCuts*>
        (&G4ProductionCutsTable::GetMaterialCutsCouple, py::const_),
        py::return_value_policy::reference)
  // ---
  .def("IsModified",         &G4ProductionCutsTable::IsModified)
  .def("GetDefaultProductionCuts",
                             &G4ProductionCutsTable::GetDefaultProductionCuts,
                             py::return_value_policy::reference)
  .def("ConvertRangeToEnergy",  &G4ProductionCutsTable::ConvertRangeToEnergy)
  .def("ResetConverters",    &G4ProductionCutsTable::ResetConverters)
  // ---
  .def("StoreCutsTable",     &G4ProductionCutsTable::StoreCutsTable,
                             py::arg("dir"), py::arg("ascii") = false)
    // ---
  .def("SetVerboseLevel",    &G4ProductionCutsTable::SetVerboseLevel)
  .def("GetVerboseLevel",    &G4ProductionCutsTable::GetVerboseLevel)
  ;
}
