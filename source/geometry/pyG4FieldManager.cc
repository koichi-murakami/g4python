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
#include "G4FieldManager.hh"
#include "G4Field.hh"
#include "G4ChordFinder.hh"
#include "G4MagneticField.hh"
#include "G4Track.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4FieldManager(py::module& m)
{
  py::class_<G4FieldManager>(m, "G4FieldManager")
  // ---
  .def("SetDetectorField",      &G4FieldManager::SetDetectorField,
                                py::arg("field"), py::arg("mode") = 0)
  .def("ProposeDetectorField",  &G4FieldManager::ProposeDetectorField)
  .def("ChangeDetectorField",   &G4FieldManager::ChangeDetectorField)
  .def("GetDetectorField",      &G4FieldManager::GetDetectorField,
                                py::return_value_policy::reference)
  .def("DoesFieldExist",        &G4FieldManager::DoesFieldExist)
  .def("CreateChordFinder",     &G4FieldManager::CreateChordFinder)
  .def("SetChordFinder",        &G4FieldManager::SetChordFinder)

  .def("GetChordFinder", static_cast<G4ChordFinder* (G4FieldManager::*)()>
                               (&G4FieldManager::GetChordFinder))
  .def("ConfigureForTrack",     &G4FieldManager::ConfigureForTrack)
  // ---
  .def("GetDeltaIntersection",  &G4FieldManager::GetDeltaIntersection)
  .def("GetDeltaOneStep",       &G4FieldManager::GetDeltaOneStep)
  .def("SetAccuraciesWithDeltaOneStep",
                                &G4FieldManager::SetAccuraciesWithDeltaOneStep)
	.def("SetDeltaOneStep",       &G4FieldManager::SetDeltaOneStep)
	.def("SetDeltaIntersection",  &G4FieldManager::SetDeltaIntersection)
	.def("GetMinimumEpsilonStep", &G4FieldManager::GetMinimumEpsilonStep)
	.def("SetMinimumEpsilonStep", &G4FieldManager::SetMinimumEpsilonStep)
	.def("GetMaximumEpsilonStep", &G4FieldManager::GetMaximumEpsilonStep)
	.def("SetMaximumEpsilonStep", &G4FieldManager::SetMaximumEpsilonStep)
	.def("DoesFieldChangeEnergy", &G4FieldManager::DoesFieldChangeEnergy)
	.def("SetFieldChangesEnergy", &G4FieldManager::SetFieldChangesEnergy)
  .def("Clone",                 &G4FieldManager::Clone)
  ;
}
