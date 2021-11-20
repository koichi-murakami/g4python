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
#include "G4GeometryManager.hh"
#include "G4VPhysicalVolume.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4GeometryManager(py::module& m)
{
  py::class_<G4GeometryManager>(m, "G4GeometryManager")
  // ---
  .def_static("GetInstance",    &G4GeometryManager::GetInstance,
                                py::return_value_policy::reference)
  // ---
  .def("CloseGeometry",         &G4GeometryManager::CloseGeometry,
                                py::arg("pOptimise") = true,
                                py::arg("verbose") = false,
                                py::arg("vol") = nullptr )
  .def("OpenGeometry",          &G4GeometryManager::OpenGeometry,
                                py::arg("vol") = nullptr )
  .def("IsGeometryClosed",      &G4GeometryManager::IsGeometryClosed)
  .def("SetWorldMaximumExtent", &G4GeometryManager::SetWorldMaximumExtent)
  ;
}
