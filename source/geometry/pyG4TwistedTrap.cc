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
#include "G4TwistedTrap.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

// --------------------------------------------------------------------------
G4TwistedTrap* f1_CreateTwistedTrap(const G4String& name,
                                    G4double  pPhiTwist,
                                    G4double  pDx1, G4double  pDx2,
                                    G4double  pDy, G4double  pDz)
{
  return new G4TwistedTrap(name, pPhiTwist, pDx1, pDx2, pDy, pDz);
}


// --------------------------------------------------------------------------
G4TwistedTrap* f2_CreateTwistedTrap(const G4String& name,
                                    G4double  pPhiTwist,
                                    G4double  pDz, G4double  pTheta,
                                    G4double  pPhi, G4double  pDy1,
                                    G4double  pDx1, G4double  pDx2,
                                    G4double  pDy2, G4double  pDx3,
                                    G4double  pDx4, G4double  pAlph)
{
  return new G4TwistedTrap(name, pPhiTwist, pDz, pTheta, pPhi,
                           pDy1, pDx1, pDx2, pDy2, pDx3, pDx4, pAlph);
}

}

// ==========================================================================
void export_G4TwistedTrap(py::module& m)
{
  py::class_<G4TwistedTrap, G4VSolid>(m, "G4TwistedTrap")
  // ---
  .def(py::init<const G4String&, G4double, G4double, G4double,
                                 G4double, G4double>())
  .def(py::init<const G4String&, G4double, G4double, G4double,
                                 G4double, G4double, G4double,
                                 G4double, G4double, G4double,
                                 G4double, G4double>())
  ;

  // ---
  m.def("CreateTwistedTap",  &::f1_CreateTwistedTrap,
                             py::return_value_policy::reference);
  m.def("CreateTwistedTap",  &::f2_CreateTwistedTrap,
                             py::return_value_policy::reference);
}
