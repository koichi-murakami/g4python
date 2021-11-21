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
#include "G4ParticleDefinition.hh"
#include "G4ParticleTable.hh"
#include "G4DecayTable.hh"
#include "G4ProcessManager.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4ParticleDefinition(py::module& m)
{
  py::class_<G4ParticleDefinition>(m, "G4ParticleDefinition")
  // ---
  .def("GetParticleName",        &G4ParticleDefinition::GetParticleName)
  .def("GetPDGMass",             &G4ParticleDefinition::GetPDGMass)
  .def("GetPDGWidth",            &G4ParticleDefinition::GetPDGWidth)
  .def("GetPDGCharge",           &G4ParticleDefinition::GetPDGCharge)
  .def("GetPDGSpin",             &G4ParticleDefinition::GetPDGSpin)
  .def("GetPDGiSpin",            &G4ParticleDefinition::GetPDGiSpin)
  .def("GetPDGiParity",          &G4ParticleDefinition::GetPDGiParity)
  .def("GetPDGiConjugation",     &G4ParticleDefinition::GetPDGiConjugation)
  .def("GetPDGIsospin",          &G4ParticleDefinition::GetPDGIsospin)
  .def("GetPDGIsospin3",         &G4ParticleDefinition::GetPDGIsospin3)
  .def("GetPDGiIsospin",         &G4ParticleDefinition::GetPDGiIsospin)
  .def("GetPDGiIsospin3",        &G4ParticleDefinition::GetPDGiIsospin3)
  .def("GetPDGiGParity",         &G4ParticleDefinition::GetPDGiGParity)
  .def("GetParticleType",        &G4ParticleDefinition::GetParticleType)
  .def("GetParticleSubType",     &G4ParticleDefinition::GetParticleSubType)
  .def("GetLeptonNumber",        &G4ParticleDefinition::GetLeptonNumber)
  .def("GetBaryonNumber",        &G4ParticleDefinition::GetBaryonNumber)
  .def("GetPDGEncoding",         &G4ParticleDefinition::GetPDGEncoding)
  .def("GetAntiPDGEncoding",     &G4ParticleDefinition::GetAntiPDGEncoding)
  .def("GetQuarkContent",        &G4ParticleDefinition::GetQuarkContent)
  .def("GetAntiQuarkContent",    &G4ParticleDefinition::GetAntiQuarkContent)
  .def("IsShortLived",           &G4ParticleDefinition::IsShortLived)
  .def("GetPDGStable",           &G4ParticleDefinition::GetPDGStable)
  .def("SetPDGStable",           &G4ParticleDefinition::SetPDGStable)
  .def("GetPDGLifeTime",         &G4ParticleDefinition::GetPDGLifeTime)
  .def("SetPDGLifeTime",         &G4ParticleDefinition::SetPDGLifeTime)
  .def("GetDecayTable",          &G4ParticleDefinition::GetDecayTable,
                                 py::return_value_policy::reference)
  .def("GetProcessManager",      &G4ParticleDefinition::GetProcessManager,
                                 py::return_value_policy::reference)
  .def("GetParticleTable",       &G4ParticleDefinition::GetParticleTable,
                                 py::return_value_policy::reference)
  .def("DumpTable",              &G4ParticleDefinition::DumpTable)
  .def("GetAtomicNumber",        &G4ParticleDefinition::GetAtomicNumber)
  .def("GetAtomicMass",          &G4ParticleDefinition::GetAtomicMass)
  .def("SetVerboseLevel",        &G4ParticleDefinition::SetVerboseLevel)
  .def("GetVerboseLevel",        &G4ParticleDefinition::GetVerboseLevel)
  .def("SetApplyCutsFlag",       &G4ParticleDefinition::SetApplyCutsFlag)
  .def("GetApplyCutsFlag",       &G4ParticleDefinition::GetApplyCutsFlag)
  ;

  // --------------------------------------------------------------------------
  py::class_<G4DecayTable>(m, "G4DecayTable")
  .def("DumpInfo",   &G4DecayTable::DumpInfo)
  ;
}
