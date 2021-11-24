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
#include "G4Region.hh"
#include "G4LogicalVolume.hh"
#include "G4ProductionCuts.hh"
#include "G4VUserRegionInformation.hh"
#include "G4UserLimits.hh"
#include "G4MaterialCutsCouple.hh"
#include "G4FastSimulationManager.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4Region(py::module& m)
{
  py::class_<G4Region>(m, "G4Region")
  // ---
  .def(py::init<const G4String&>())
  // ---
  .def("AddRootLogicalVolume",    &G4Region::AddRootLogicalVolume)
  .def("RemoveRootLogicalVolume", &G4Region::RemoveRootLogicalVolume)
  .def("SetName",                 &G4Region::SetName)
  .def("GetName",                 &G4Region::GetName)
  .def("RegionModified",          &G4Region::RegionModified)
  .def("IsModified",              &G4Region::IsModified)
  .def("SetProductionCuts",       &G4Region::SetProductionCuts)
  .def("GetProductionCuts",       &G4Region::GetProductionCuts,
                                  py::return_value_policy::reference)
  .def("GetNumberOfMaterials",    &G4Region::GetNumberOfMaterials)
  .def("GetNumberOfRootVolumes",  &G4Region::GetNumberOfRootVolumes)
  .def("UpdateMaterialList",      &G4Region::UpdateMaterialList)
  .def("ClearMaterialList",       &G4Region::ClearMaterialList)
  .def("ScanVolumeTree",          &G4Region::ScanVolumeTree)
  .def("SetUserInformation",      &G4Region::SetUserInformation)
  .def("GetUserInformation",      &G4Region::GetUserInformation,
                                  py::return_value_policy::reference)
  .def("SetUserLimits",           &G4Region::SetUserLimits)
  .def("GetUserLimits",           &G4Region::GetUserLimits,
                                  py::return_value_policy::reference)
  .def("ClearMap",                &G4Region::ClearMap)
  .def("RegisterMaterialCouplePair", &G4Region::RegisterMaterialCouplePair)
  .def("FindCouple",              &G4Region::FindCouple,
                                  py::return_value_policy::reference)
  .def("GetWorldPhysical",        &G4Region::GetWorldPhysical,
                                  py::return_value_policy::reference)
  .def("SetWorld",                &G4Region::SetWorld)
  .def("BelongsTo",               &G4Region::BelongsTo)
  .def("GetParentRegion",         &G4Region::GetParentRegion,
                                  py::return_value_policy::reference)
  ;
 }
