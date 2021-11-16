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
void export_G4VisManager(py::module&);
void export_G4VGraphicsSystem(py::module&);
void export_G4VRML1File(py::module&);
void export_G4VRML2File(py::module&);
void export_G4DAWNFILE(py::module&);
void export_G4HepRep(py::module&);
void export_G4HepRepFile(py::module&);
void export_G4ASCIITree(py::module&);
void export_G4RayTracer(py::module&);

#ifdef G4VIS_USE_OPENGLX
void export_G4OpenGLStoredX(py::module&);
void export_G4OpenGLImmediateX(py::module&);
#endif

// --------------------------------------------------------------------------
PYBIND11_MODULE(G4visualization, m)
{
  /*
  export_G4VisManager(m);
  export_G4VGraphicsSystem(m);
  export_G4VRML1File(m);
  export_G4VRML2File(m);
  export_G4DAWNFILE(m);
  export_G4HepRep(m);
  export_G4HepRepFile(m);
  export_G4ASCIITree(m);
  export_G4RayTracer(m);

#ifdef G4VIS_USE_OPENGLX
  export_G4OpenGLStoredX(m);
  export_G4OpenGLImmediateX(m);
#endif
*/
}
