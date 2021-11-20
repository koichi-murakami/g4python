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
#include "G4VProcess.hh"
#include "G4StepPoint.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4StepPoint(py::module& m)
{
  py::class_<G4StepPoint>(m, "G4StepPoint")
  // ---
  .def("GetPosition",           &G4StepPoint::GetPosition)
  .def("GetLocalTime",          &G4StepPoint::GetLocalTime)
  .def("GetGlobalTime",         &G4StepPoint::GetGlobalTime)
  .def("GetProperTime",         &G4StepPoint::GetProperTime)
  .def("GetMomentumDirection",  &G4StepPoint::GetMomentumDirection)
  .def("GetMomentum",           &G4StepPoint::GetMomentum)
  .def("GetTotalEnergy",        &G4StepPoint::GetTotalEnergy)
  .def("GetKineticEnergy",      &G4StepPoint::GetKineticEnergy)
  .def("GetVelocity",           &G4StepPoint::GetVelocity)
  .def("GetBeta",               &G4StepPoint::GetBeta)
  .def("GetGamma",              &G4StepPoint::GetGamma)
  .def("GetTouchable",          &G4StepPoint::GetTouchable,
                                py::return_value_policy::reference)
  .def("GetMaterial",           &G4StepPoint::GetMaterial,
                                py::return_value_policy::reference)
  .def("GetPolarization",       &G4StepPoint::GetPolarization)
  .def("GetStepStatus",         &G4StepPoint::GetStepStatus)
  .def("GetProcessDefinedStep", &G4StepPoint::GetProcessDefinedStep,
                                py::return_value_policy::reference)
  .def("GetMass",               &G4StepPoint::GetMass)
  .def("GetCharge",             &G4StepPoint::GetCharge)
  .def("GetMagneticMoment",     &G4StepPoint::GetMagneticMoment)
  .def("GetWeight",             &G4StepPoint::GetWeight)
  ;
}
