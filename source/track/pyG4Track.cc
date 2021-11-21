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
#include "G4Track.hh"
#include "G4VProcess.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4Track(py::module& m)
{
  py::class_<G4Track>(m, "G4Track")
  // ---
  .def("GetTrackID",             &G4Track::GetTrackID)
  .def("GetParentID",            &G4Track::GetParentID)
  .def("GetDynamicParticle",     &G4Track::GetDynamicParticle,
                                 py::return_value_policy::reference)
  .def("GetDefinition",          &G4Track::GetDefinition,
                                 py::return_value_policy::reference)
  .def("GetParticleDefinition",  &G4Track::GetParticleDefinition,
                                 py::return_value_policy::reference)
  .def("GetPosition",            &G4Track::GetPosition)
  .def("GetGlobalTime",          &G4Track::GetGlobalTime)
  .def("GetLocalTime",           &G4Track::GetLocalTime)
  .def("GetProperTime",          &G4Track::GetProperTime)
  // ---
  .def("GetVolume",              &G4Track::GetVolume,
                                 py::return_value_policy::reference)
  .def("GetNextVolume",          &G4Track::GetNextVolume,
                                 py::return_value_policy::reference)
  .def("GetMaterial",            &G4Track::GetMaterial,
                                 py::return_value_policy::reference)
  .def("GetNextMaterial",        &G4Track::GetNextMaterial,
                                 py::return_value_policy::reference)
  .def("GetTouchable",           &G4Track::GetTouchable,
                                 py::return_value_policy::reference)
  .def("GetNextTouchable",       &G4Track::GetNextTouchable,
                                 py::return_value_policy::reference)
  .def("GetOriginTouchable",     &G4Track::GetOriginTouchable,
                                 py::return_value_policy::reference)
  // ---
  .def("GetKineticEnergy",       &G4Track::GetKineticEnergy)
  .def("GetTotalEnergy",         &G4Track::GetTotalEnergy)
  .def("GetMomentumDirection",   &G4Track::GetMomentumDirection)
  .def("GetMomentum",            &G4Track::GetMomentum)
  .def("GetVelocity",            &G4Track::GetVelocity)
  .def("CalculateVelocity",      &G4Track::CalculateVelocity)
  .def("CalculateVelocityForOpticalPhoton",
                                 &G4Track::CalculateVelocityForOpticalPhoton)
  .def("GetPolarization",        &G4Track::GetPolarization)
  // ---
  .def("GetTrackStatus",         &G4Track::GetTrackStatus)
  .def("IsBelowThreshold",       &G4Track::IsBelowThreshold)
  .def("IsGoodForTracking",      &G4Track::IsGoodForTracking)
  .def("GetTrackLength",         &G4Track::GetTrackLength)
  // ---
  .def("GetStep",                &G4Track::GetStep,
                                 py::return_value_policy::reference)
  .def("GetCurrentStepNumber",   &G4Track::GetCurrentStepNumber)
  .def("GetStepLength",          &G4Track::GetStepLength)

  // ---
  .def("GetVertexPosition",      &G4Track::GetVertexPosition)
  .def("GetVertexMomentumDirection", &G4Track::GetVertexMomentumDirection)
  .def("GetVertexKineticEnergy", &G4Track::GetVertexKineticEnergy)
  .def("GetLogicalVolumeAtVertex", &G4Track::GetLogicalVolumeAtVertex,
	                                 py::return_value_policy::reference)
  // ---
	.def("GetCreatorProcess",     &G4Track::GetCreatorProcess,
	                              py::return_value_policy::reference)
  .def("GetCreatorModelID",     &G4Track::GetCreatorModelID)
  .def("GetCreatorModelName",   &G4Track::GetCreatorModelName)
	.def("GetWeight",             &G4Track::GetWeight)
	.def("SetWeight",             &G4Track::SetWeight)
	;
 }
