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
#include "G4TouchableHistory.hh"
#include "G4VPhysicalVolume.hh"
#include "G4VSolid.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4TouchableHistory(py::module& m)
{
  py::class_<G4VTouchable>(m, "G4VTouchable");

  py::class_<G4TouchableHistory, G4VTouchable>(m, "G4TouchableHistory")
  // ---
  .def("GetVolume",           &G4TouchableHistory::GetVolume,
                              py::arg("depth") = 0,
                              py::return_value_policy::reference)
  .def("GetSolid",            &G4TouchableHistory::GetSolid,
                              py::arg("depth") = 0,
                              py::return_value_policy::reference)
  .def("GetTranslation",      &G4TouchableHistory::GetTranslation,
                              py::arg("depth") = 0,
                              py::return_value_policy::reference)
  .def("GetRotation",         &G4TouchableHistory::GetRotation,
                              py::arg("depth") = 0,
                              py::return_value_policy::reference)
  .def("GetReplicaNumber",    &G4TouchableHistory::GetReplicaNumber,
                              py::arg("depth") = 0,
                              py::return_value_policy::reference)
  .def("GetHistoryDepth",     &G4TouchableHistory::GetHistoryDepth)
  .def("MoveUpHistory",       &G4TouchableHistory::MoveUpHistory,
                              py::arg("level") = 1)
  ;
}
