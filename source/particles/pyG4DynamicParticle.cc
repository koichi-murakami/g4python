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
#include "G4DynamicParticle.hh"
#include "G4PrimaryParticle.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4DynamicParticle(py::module& m)
{
  py::class_<G4DynamicParticle>(m, "G4DynamicParticle")
  // ---
  .def("GetMomentumDirection", &G4DynamicParticle::GetMomentumDirection)
  .def("GetMomentum",          &G4DynamicParticle::GetMomentum)
  .def("Get4Momentum",         &G4DynamicParticle::Get4Momentum)
  .def("GetTotalMomentum",     &G4DynamicParticle::GetTotalMomentum)
  .def("GetTotalEnergy",       &G4DynamicParticle::GetTotalEnergy)
  .def("GetKineticEnergy",     &G4DynamicParticle::GetKineticEnergy)
  .def("GetLogKineticEnergy",  &G4DynamicParticle::GetLogKineticEnergy)
  .def("GetBeta",              &G4DynamicParticle::GetBeta)
  .def("GetProperTime",        &G4DynamicParticle::GetProperTime)
  .def("GetPolarization",      &G4DynamicParticle::GetPolarization)
  .def("GetMass",              &G4DynamicParticle::GetMass)
  .def("GetCharge",            &G4DynamicParticle::GetCharge)
  .def("GetSpin",              &G4DynamicParticle::GetSpin)
  .def("GetMagneticMoment",    &G4DynamicParticle::GetMagneticMoment)
  .def("GetElectronOccupancy", &G4DynamicParticle::GetElectronOccupancy,
                               py::return_value_policy::reference)
  .def("GetTotalOccupancy",    &G4DynamicParticle::GetTotalOccupancy)
  .def("GetOccupancy",         &G4DynamicParticle::GetOccupancy)
  .def("GetParticleDefinition",   &G4DynamicParticle::GetParticleDefinition,
                                  py::return_value_policy::reference)
  .def("GetDefinition",        &G4DynamicParticle::GetDefinition,
                               py::return_value_policy::reference)
  .def("GetPreAssignedDecayProperTime",
                          &G4DynamicParticle::GetPreAssignedDecayProperTime)
  .def("DumpInfo",             &G4DynamicParticle::DumpInfo,
                               py::arg("mode") = 0)
  .def("SetVerboseLevel",      &G4DynamicParticle::SetVerboseLevel)
  .def("GetVerboseLevel",      &G4DynamicParticle::GetVerboseLevel)

  .def("GetPrimaryParticle",   &G4DynamicParticle::GetPrimaryParticle,
                               py::return_value_policy::reference)
  .def("GetPDGcode",           &G4DynamicParticle::GetPDGcode)
  ;
}
