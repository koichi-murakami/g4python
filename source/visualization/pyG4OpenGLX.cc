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
#ifdef G4VIS_USE_OPENGLX
#include "G4OpenGLImmediateX.hh"
#include "G4OpenGLStoredX.hh"
#endif

namespace py = pybind11;

// ==========================================================================
void export_G4OpenGLX(py::module& m)
{
#ifdef G4VIS_USE_OPENGLX
  py::class_<G4OpenGLImmediateX, G4VGraphicsSystem>(m, "G4OpenGLImmediateX")
  .def(py::init<>())
  .def("AddNickname",    &G4OpenGLImmediateX::AddNickname)
  ;

  py::class_<G4OpenGLStoredX, G4VGraphicsSystem>(m, "G4OpenGLStoredX")
  .def(py::init<>())
  .def("AddNickname",    &G4OpenGLStoredX::AddNickname)
  ;
#endif
}
