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
#include "G4Tet.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

G4Tet* CreateTet(const G4String& name, G4ThreeVector anchor, G4ThreeVector p2,
                                       G4ThreeVector p3, G4ThreeVector p4)
{
  return new G4Tet(name, anchor, p2, p3, p4);
}

}

// ==========================================================================
void export_G4Tet(py::module& m)
{
  py::class_<G4Tet, G4VSolid, std::unique_ptr<G4Tet, py::nodelete>>
  (m, "G4Tet")
  // ---
  .def(py::init<const G4String&, G4ThreeVector, G4ThreeVector,
                                 G4ThreeVector, G4ThreeVector>())
  ;

  // ---
  m.def("CreateTet", CreateTet, py::return_value_policy::reference);
}
