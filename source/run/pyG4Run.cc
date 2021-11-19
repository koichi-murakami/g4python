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
#include "G4Run.hh"
#include "G4HCtable.hh"
#include "G4DCtable.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4Run(py::module& m)
{
  py::class_<G4Run>(m, "G4Run")
  .def(py::init<>())
  .def("GetRunID",             &G4Run::GetRunID)
  .def("SetRunID",             &G4Run::SetRunID)
  .def("GetNumberOfEvent",     &G4Run::GetNumberOfEvent)
  .def("GetNumberOfEventToBeProcessed",
                               &G4Run::GetNumberOfEventToBeProcessed)
  .def("SetNumberOfEventToBeProcessed",
                               &G4Run::SetNumberOfEventToBeProcessed)
  ;
}
