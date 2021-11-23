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

namespace py = pybind11;

// --------------------------------------------------------------------------
void export_G4ApplicationState(py::module&);
void export_G4Exception(py::module&);
void export_G4ExceptionHandler(py::module&);
void export_G4ExceptionSeverity(py::module&);
void export_G4RandomDirection(py::module&);
void export_G4RotationMatrix(py::module&);
void export_G4StateManager(py::module&);
void export_G4String(py::module&);
void export_G4TwoVector(py::module&);
void export_G4ThreeVector(py::module&);
void export_G4Timer(py::module&);
void export_G4Transform3D(py::module&);
void export_G4UnitsTable(py::module&);
void export_G4UserLimits(py::module&);
void export_G4Version(py::module&);
void export_Randomize(py::module&);
void export_RandomEngines(py::module&);
void export_geomdefs(py::module&);
void export_globals(py::module&);

// ==========================================================================
PYBIND11_MODULE(G4global, m)
{
  export_G4ApplicationState(m);
  export_G4Exception(m);
  export_G4ExceptionHandler(m);
  export_G4ExceptionSeverity(m);
  export_G4RandomDirection(m);
  export_G4RotationMatrix(m);
  export_G4StateManager(m);
  export_G4String(m);
  export_G4TwoVector(m);
  export_G4ThreeVector(m);
  export_G4Timer(m);
  export_G4Transform3D(m);
  export_G4UnitsTable(m);
  export_G4UserLimits(m);
  export_G4Version(m);
  export_Randomize(m);
  export_RandomEngines(m);
  export_geomdefs(m);
  export_globals(m);
}
