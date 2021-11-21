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
#include "G4PrimaryParticle.hh"
#include "G4ParticleDefinition.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4PrimaryParticle(py::module& m)
{
  py::class_<G4PrimaryParticle>(m, "G4PrimaryParticle")
  // ---
  //.def(py::init<>())
  //.def(py::init<G4int>())
  //.def(py::init<G4int,G4double,G4double,G4double>())
  //.def(py::init<G4int,G4double,G4double,G4double,G4double>())
  //.def(py::init<const G4ParticleDefinition*>())
  //.def(py::init<const G4ParticleDefinition*,G4double,G4double,G4double>())
  //.def(py::init<const G4ParticleDefinition*,G4double,G4double,G4double,G4double>())
  // ---
  .def("Print",                 &G4PrimaryParticle::Print)
  .def("GetPDGcode",            &G4PrimaryParticle::GetPDGcode)
  .def("GetG4code",             &G4PrimaryParticle::GetG4code,
                                py::return_value_policy::reference)
  // ---
  .def("GetMass",               &G4PrimaryParticle::GetMass)
  .def("GetCharge",             &G4PrimaryParticle::GetCharge)
  .def("GetKineticEnergy",      &G4PrimaryParticle::GetKineticEnergy)
  .def("GetMomentunDirection",  &G4PrimaryParticle::GetMomentumDirection)
  .def("GetTotalMomentunDirection", &G4PrimaryParticle::GetTotalMomentum)
  .def("GetTotalEnergy",        &G4PrimaryParticle::GetTotalEnergy)
  .def("GetMomentun",           &G4PrimaryParticle::GetMomentum)
  .def("GetPx",                 &G4PrimaryParticle::GetPx)
  .def("GetPy",                 &G4PrimaryParticle::GetPy)
  .def("GetPz",                 &G4PrimaryParticle::GetPz)
  .def("GetNext",               &G4PrimaryParticle::GetNext,
                                py::return_value_policy::reference)
  .def("GetDaughter",           &G4PrimaryParticle::GetNext,
                                py::return_value_policy::reference)
  .def("GetTrackID",            &G4PrimaryParticle::GetTrackID)
  .def("GetPolarization",       &G4PrimaryParticle::GetPolarization)
  .def("GetPolX",               &G4PrimaryParticle::GetPolX)
  .def("GetPolY",               &G4PrimaryParticle::GetPolY)
  .def("GetPolZ",               &G4PrimaryParticle::GetPolZ)
  .def("GetWeight",             &G4PrimaryParticle::GetWeight)
  .def("GetProperTime",         &G4PrimaryParticle::GetProperTime)
  ;
}
