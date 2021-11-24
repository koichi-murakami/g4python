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
#include "G4LogicalVolume.hh"
#include "G4Material.hh"
#include "G4VSolid.hh"
#include "G4FieldManager.hh"
#include "G4VSensitiveDetector.hh"
#include "G4UserLimits.hh"
#include "G4SmartVoxelHeader.hh"
#include "G4MaterialCutsCouple.hh"
#include "G4VisAttributes.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4LogicalVolume(py::module& m)
{
  py::class_<G4LogicalVolume>(m, "G4LogicalVolume")
  // ---
  .def(py::init<G4VSolid*, G4Material*, const G4String& >())
  .def(py::init<G4VSolid*, G4Material*, const G4String&, G4FieldManager* >())
  .def(py::init<G4VSolid*, G4Material*, const G4String&, G4FieldManager*,
                G4VSensitiveDetector* >())
  .def(py::init<G4VSolid*, G4Material*, const G4String&, G4FieldManager*,
                G4VSensitiveDetector*, G4UserLimits* >())
  .def(py::init<G4VSolid*, G4Material*, const G4String&, G4FieldManager*,
                G4VSensitiveDetector*, G4UserLimits*, G4bool >())
  // ---
  .def("GetName",         &G4LogicalVolume::GetName)
  .def("SetName",         &G4LogicalVolume::SetName)
  // ---
  .def("GetNoDaughters",  &G4LogicalVolume::GetNoDaughters)
  .def("GetDaughter",     &G4LogicalVolume::GetDaughter,
                          py::return_value_policy::reference)
  .def("AddDaughter",     &G4LogicalVolume::AddDaughter)
  .def("IsDaughter",      &G4LogicalVolume::IsDaughter)
  .def("IsAncestor",      &G4LogicalVolume::IsAncestor)
  .def("RemoveDaughter",  &G4LogicalVolume::RemoveDaughter)
  .def("ClearDaughters",  &G4LogicalVolume::ClearDaughters)
  .def("TotalVolumeEntities", &G4LogicalVolume::TotalVolumeEntities)
  // ----
  .def("GetSolid", static_cast<G4VSolid* (G4LogicalVolume::*)() const>
                         (&G4LogicalVolume::GetSolid),
                          py::return_value_policy::reference)
  .def("SetSolid", static_cast<void (G4LogicalVolume::*)(G4VSolid*)>
                         (&G4LogicalVolume::SetSolid))
  .def("GetMaterial",     &G4LogicalVolume::GetMaterial,
                          py::return_value_policy::reference)
  .def("SetMaterial",     &G4LogicalVolume::SetMaterial)
  .def("UpdateMaterial",  &G4LogicalVolume::UpdateMaterial)
  .def("GetMass",         &G4LogicalVolume::GetMass,
                          py::arg("forced") = false,
                          py::arg("propagate") = true,
                          py::arg("material") = nullptr)
  // ---
  .def("GetFieldManager", &G4LogicalVolume::GetFieldManager,
                          py::return_value_policy::reference)
  .def("SetFieldManager", &G4LogicalVolume::SetFieldManager)
  .def("GetSensitiveDetector", &G4LogicalVolume::GetSensitiveDetector,
                               py::return_value_policy::reference)
  .def("SetSensitiveDetector", &G4LogicalVolume::SetSensitiveDetector)
  .def("GetUserLimits",   &G4LogicalVolume::GetUserLimits,
                          py::return_value_policy::reference)
  .def("SetUserLimits",   &G4LogicalVolume::SetUserLimits)
  // ---
	.def("GetSmartless",    &G4LogicalVolume::GetSmartless)
	.def("SetSmartless",    &G4LogicalVolume::SetSmartless)
	.def("IsToOptimise",    &G4LogicalVolume::IsToOptimise)
	.def("SetOptimisation", &G4LogicalVolume::SetOptimisation)
	// ---
	.def("IsRootRegion",    &G4LogicalVolume::IsRootRegion)
	.def("SetRegionRootFlag", &G4LogicalVolume::SetRegionRootFlag)
	.def("IsRegion",        &G4LogicalVolume::IsRegion)
	.def("SetRegion",       &G4LogicalVolume::SetRegion)
	.def("GetRegion",       &G4LogicalVolume::GetRegion,
	                        py::return_value_policy::reference)
	.def("PropagateRegion", &G4LogicalVolume::PropagateRegion)
	.def("GetMaterialCutsCouple", &G4LogicalVolume::GetMaterialCutsCouple,
   	                            py::return_value_policy::reference)
	.def("SetMaterialCutsCouple", &G4LogicalVolume::SetMaterialCutsCouple)
	// ---
	.def("GetVisAttributes", &G4LogicalVolume::GetVisAttributes,
	                         py::return_value_policy::reference)
	.def("SetVisAttributes",
        static_cast<void (G4LogicalVolume::*)(const G4VisAttributes*)>
        (&G4LogicalVolume::SetVisAttributes))
	// ---
  .def("SetBiasWeight",  &G4LogicalVolume::SetBiasWeight)
  .def("GetBiasWeight",  &G4LogicalVolume::GetBiasWeight)
  ;
}
