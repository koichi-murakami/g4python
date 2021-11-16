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
#include "G4VSolid.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4VSolid(py::module& m)
{
  py::class_<G4VSolid>(m, "G4VSolid")
   // ---
  .def("GetName",            &G4VSolid::GetName)
  .def("SetName",            &G4VSolid::SetName)
  .def("DumpInfo",           &G4VSolid::DumpInfo)
  .def("GetCubicVolume",     &G4VSolid::GetCubicVolume)
  .def("GetSurfaceArea",     &G4VSolid::GetSurfaceArea)
  .def("GetPointOnSurface",  &G4VSolid::GetPointOnSurface)
  ;
}
