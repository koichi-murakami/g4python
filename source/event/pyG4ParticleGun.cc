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
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4Event.hh"

namespace py = pybind11;

namespace {
// --------------------------------------------------------------------------
void SetParticleByName(G4ParticleGun* gun, const std::string& pname)
{
  G4ParticleTable* particleTable= G4ParticleTable::GetParticleTable();
  G4ParticleDefinition* pd= particleTable-> FindParticle(pname);
  if (pd != 0) {
    gun-> SetParticleDefinition(pd);
  } else {
    G4cout << "*** \"" << pname << "\" is not registered "
	   << "in available particle list" << G4endl;
  }
}

// --------------------------------------------------------------------------
std::string GetParticleByName(G4ParticleGun* gun)
{
  const G4ParticleDefinition* pd= gun-> GetParticleDefinition();
  return (pd-> GetParticleName()).c_str();
}

}

// ==========================================================================
void export_G4ParticleGun(py::module& m)
{
  py::class_<G4ParticleGun>(m, "G4ParticleGun")
  .def(py::init<>())
  .def(py::init<G4int>())
  .def(py::init<G4ParticleDefinition*>())
  .def(py::init<G4ParticleDefinition*, G4int>())
  // ---
  .def("GeneratePrimaryVertex", &G4ParticleGun::GeneratePrimaryVertex)
  .def_static("CheckVertexInsideWold",
                                &G4VPrimaryGenerator::CheckVertexInsideWorld)
  // ---
  .def("SetParticlePosition",   &G4ParticleGun::SetParticlePosition)
  .def("SetParticleTime",       &G4ParticleGun::SetParticleTime)
  .def("SetParticleDefinition", &G4ParticleGun::SetParticleDefinition)
  .def("SetParticleEnergy",     &G4ParticleGun::SetParticleEnergy)
  .def("SetParticleMomentum",
        py::overload_cast<G4double>(&G4ParticleGun::SetParticleMomentum))
  .def("SetParticleMomentum",
        py::overload_cast<G4ParticleMomentum>(
          &G4ParticleGun::SetParticleMomentum))
  .def("SetParticleMomentumDirection",
                                &G4ParticleGun::SetParticleMomentumDirection)
  .def("SetParticleCharge",     &G4ParticleGun::SetParticleCharge)
  .def("SetParticlePolarization", &G4ParticleGun::SetParticlePolarization)
  .def("SetNumberOfParticles",  &G4ParticleGun::SetNumberOfParticles)
  // ---
  .def("GetParticlePosition",   &G4ParticleGun::GetParticlePosition,
        py::return_value_policy::copy)
  .def("GetParticleTime",       &G4ParticleGun::GetParticleTime)
  .def("GetParticleDefinition", &G4ParticleGun::GetParticleDefinition,
       py::return_value_policy::reference)
  .def("GetParticleMomentumDirection",
                                &G4ParticleGun::GetParticleMomentumDirection,
                                py::return_value_policy::copy)
  .def("GetParticleEnergy",     &G4ParticleGun::GetParticleEnergy)
  .def("GetParticleMomentum",   &G4ParticleGun::GetParticleMomentum)
  .def("GetParticleCharge",     &G4ParticleGun::GetParticleCharge)
  .def("GetParticlePolarization", &G4ParticleGun::GetParticlePolarization)
  .def("GetNumberOfParticles",  &G4ParticleGun::GetNumberOfParticles)
  .def("SetParticleByName",     &::SetParticleByName)
  .def("GetParticleByName",     &::GetParticleByName)
  ;
}
