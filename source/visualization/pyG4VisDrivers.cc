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
#include "G4ASCIITree.hh"
#include "G4DAWNFILE.hh"
#include "G4RayTracer.hh"
#include "G4VRML2File.hh"
#include "G4GMocrenFile.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4VisDrivers(py::module& m)
{
  py::class_<G4ASCIITree, G4VGraphicsSystem>(m, "G4ASCIITree")
  .def(py::init<>())
  ;

  py::class_<G4DAWNFILE, G4VGraphicsSystem>(m, "G4DAWNFILE")
  .def(py::init<>())
  ;

  py::class_<G4RayTracer, G4VGraphicsSystem>(m, "G4RayTracer")
  .def(py::init<>())
  ;

  py::class_<G4VRML2File, G4VGraphicsSystem>(m, "G4VRML2File")
  .def(py::init<>())
  ;

  py::class_<G4GMocrenFile, G4VGraphicsSystem>(m, "G4GMocrenFile")
  .def(py::init<>())
  ;

}
