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
#include "G4UIcommandTree.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4UIcommandTree(py::module& m)
{
  py::class_<G4UIcommandTree>(m, "G4UIcommandTree")
    .def(py::init<const char*>())
    // ---
    .def("FindPath",           &G4UIcommandTree::FindPath,
                               py::return_value_policy::reference)
    .def("List",               &G4UIcommandTree::List)
    .def("ListCurrent",        &G4UIcommandTree::ListCurrent)
    .def("ListCurrentWithNum", &G4UIcommandTree::ListCurrentWithNum)
    .def("CreateHTML",         &G4UIcommandTree::CreateHTML)
    .def("GetGuidance",        &G4UIcommandTree::GetGuidance,
                               py::return_value_policy::reference)
    .def("GetPathName",        &G4UIcommandTree::GetPathName)
    .def("GetTreeEntry",       &G4UIcommandTree::GetTreeEntry)
    .def("GetCommandEntry",    &G4UIcommandTree::GetCommandEntry)
    .def("GetTree",
         static_cast<G4UIcommandTree* (G4UIcommandTree::*)(G4int)>
         (&G4UIcommandTree::GetTree),
         py::return_value_policy::reference)
    .def("GetTree",
         static_cast<G4UIcommandTree* (G4UIcommandTree::*)(const char*)>
         (&G4UIcommandTree::GetTree),
         py::return_value_policy::reference)
    .def("GetCommand",         &G4UIcommandTree::GetCommand,
         py::return_value_policy::reference)
    .def("GetTitle",           &G4UIcommandTree::GetTitle)
    ;
}
