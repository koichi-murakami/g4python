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
#include "G4ParticleTable.hh"
#include "G4IonTable.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

// GetParticleList (returning python list)
py::list GetParticleList(G4ParticleTable* particleTable)
{
  py::list particleList;

  auto theParticleIterator = particleTable-> GetIterator();

  theParticleIterator-> reset();

  while( (*theParticleIterator)() ){
    auto particle= theParticleIterator-> value();
    particleList.append(particle);
  }

  return particleList;
}

}

namespace py = pybind11;

// ==========================================================================
void export_G4ParticleTable(py::module& m)
{
  py::class_<G4ParticleTable>(m, "G4ParticleTable")
  // ---
  .def_static("GetParticleTable",  &G4ParticleTable::GetParticleTable,
                                   py::return_value_policy::reference)
  // ---
  .def("contain", py::overload_cast<const G4ParticleDefinition*>(
                                   &G4ParticleTable::contains, py::const_))
  .def("contain", py::overload_cast<const G4String&>(
                                   &G4ParticleTable::contains, py::const_))
  .def("entries",                  &G4ParticleTable::entries)
  .def("size",                     &G4ParticleTable::size)
  // ---
  .def("GetParticle",              &G4ParticleTable::GetParticle,
                                   py::return_value_policy::reference)
  .def("GetParticleName",          &G4ParticleTable::GetParticleName)
  .def("FindParticle", py::overload_cast<G4int>(
                                   &G4ParticleTable::FindParticle),
                                   py::return_value_policy::reference)
  .def("FindParticle", py::overload_cast<const G4String&>(
                                   &G4ParticleTable::FindParticle),
                                   py::return_value_policy::reference)
  .def("FindParticle", py::overload_cast<const G4ParticleDefinition*>(
                                   &G4ParticleTable::FindParticle),
                                   py::return_value_policy::reference)
  .def("FindAntiParticle", py::overload_cast<G4int>(
                                   &G4ParticleTable::FindAntiParticle),
                                   py::return_value_policy::reference)
  .def("FindAntiParticle", py::overload_cast<const G4String&>(
                                   &G4ParticleTable::FindAntiParticle),
                                   py::return_value_policy::reference)
  .def("FindAntiParticle", py::overload_cast<const G4ParticleDefinition*>(
                                   &G4ParticleTable::FindAntiParticle),
                                   py::return_value_policy::reference)
  // ---
  .def("DumpTable",                &G4ParticleTable::DumpTable,
                                   py::arg("particle_name") = "ALL")
  .def("GetIonTable",              &G4ParticleTable::GetIonTable,
                                   py::return_value_policy::reference)
  .def("SetVerboseLevel",          &G4ParticleTable::SetVerboseLevel)
  .def("GetVerboseLevel",          &G4ParticleTable::GetVerboseLevel)
  .def("GetParticleList",          &::GetParticleList)
  ;
}
