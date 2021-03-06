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
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4VPVParameterisation.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4VPhysicalVolume(py::module& m)
{
  py::class_<G4VPhysicalVolume>(m, "G4VPhysicalVolume")
  // ---
  .def("SetTranslation",       &G4VPhysicalVolume::SetTranslation)
  .def("GetTranslation",       &G4VPhysicalVolume::GetTranslation)
  .def("GetObjectTranslation", &G4VPhysicalVolume::GetObjectTranslation)
  .def("GetFrameTranslation",  &G4VPhysicalVolume::GetObjectTranslation)
  // ---
  .def("SetRotation",          &G4VPhysicalVolume::SetRotation)
  .def("GetRotation",
       static_cast<G4RotationMatrix* (G4VPhysicalVolume::*)()>
       (&G4VPhysicalVolume::GetRotation),
       py::return_value_policy::reference)
  .def("GetObjectRotationValue", &G4VPhysicalVolume::GetObjectRotationValue)
  .def("GetFrameRotation",       &G4VPhysicalVolume::GetFrameRotation,
                                 py::return_value_policy::reference)
  // ---
  .def("SetLogicalVolume",     &G4VPhysicalVolume::SetLogicalVolume)
  .def("SetMotherLogical",     &G4VPhysicalVolume::SetMotherLogical)
  .def("GetLogicalVolume",     &G4VPhysicalVolume::GetLogicalVolume,
                               py::return_value_policy::reference)
  .def("GetMotherLogical",     &G4VPhysicalVolume::GetMotherLogical,
                               py::return_value_policy::reference)
  // ---
  .def("SetName",             &G4VPhysicalVolume::SetName)
  .def("GetName",             &G4VPhysicalVolume::GetName)
  .def("SetCopyNo",           &G4VPhysicalVolume::SetCopyNo)
  .def("GetCopyNo",           &G4VPhysicalVolume::GetCopyNo)
  // ---
  .def("IsMany",              &G4VPhysicalVolume::IsMany)
  .def("IsReplicated",        &G4VPhysicalVolume::IsReplicated)
  .def("IsParameterised",     &G4VPhysicalVolume::IsParameterised)
  .def("GetMultiplicity",     &G4VPhysicalVolume::GetMultiplicity)
  .def("GetParameterisation", &G4VPhysicalVolume::GetParameterisation,
                              py::return_value_policy::reference)
  ;
}
