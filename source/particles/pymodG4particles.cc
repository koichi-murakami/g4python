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
void export_G4ParticleDefinition(py::module&);
void export_G4DynamicParticle(py::module&);
void export_G4ParticleTable(py::module&);
void export_G4DecayTable(py::module&);
void export_G4PrimaryParticle(py::module&);
void export_G4PrimaryVertex(py::module&);
void export_PyG4ParticleList(py::module&);

// --------------------------------------------------------------------------
PYBIND11_MODULE(G4particles, m)
{
  //export_G4ParticleDefinition(m);
  //export_G4DynamicParticle(m);
  export_G4ParticleTable(m);
  //export_G4DecayTable(m);
  //export_G4PrimaryParticle(m);
  //export_G4PrimaryVertex(m);
  //export_PyG4ParticleList(m);

}
