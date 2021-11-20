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
#include <pybind11/stl.h>
#include "G4PhysListFactory.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4PhysListFactory(py::module& m)
{
  py::class_<G4PhysListFactory>(m, "G4PhysListFactory")
  // ---
  .def(py::init<>())
  .def(py::init<G4int>())
  // ---
  .def("GetReferencePhysList",  &G4PhysListFactory::GetReferencePhysList,
                                py::return_value_policy::reference)
  .def("ReferencePhysList",     &G4PhysListFactory::ReferencePhysList,
                                py::return_value_policy::reference)
  // ---
  .def("IsReferencePhysList",   &G4PhysListFactory::IsReferencePhysList)
  .def("AvailablePhysLists",    &G4PhysListFactory::AvailablePhysLists)
  .def("AvailablePhysListsEM",  &G4PhysListFactory::AvailablePhysListsEM)
  .def("SetVerbose",            &G4PhysListFactory::SetVerbose)
  ;
}
