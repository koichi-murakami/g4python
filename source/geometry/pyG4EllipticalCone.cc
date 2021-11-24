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
#include "G4EllipticalCone.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

G4EllipticalCone* CreateEllipticalCone(const G4String& name,
                                       G4double  pxSemiAxis,
                                       G4double  pySemiAxis,
                                       G4double  zMax,
                                       G4double  pzTopCut)
{
  return new G4EllipticalCone(name, pxSemiAxis,pySemiAxis, zMax, pzTopCut);
}

}

// ==========================================================================
void export_G4EllipticalCone(py::module& m)
{
  py::class_<G4EllipticalCone, G4VSolid>(m, "G4EllipticalCone")
  // ---
  .def(py::init<const G4String&, G4double, G4double, G4double, G4double>())
  // ---
  .def("GetSimiAxisMax",  &G4EllipticalCone::GetSemiAxisMax)
  .def("GetZTopCut",      &G4EllipticalCone::GetZTopCut)
  .def("SetSemiAxis",     &G4EllipticalCone::SetSemiAxis)
  .def("SetZCut",         &G4EllipticalCone::SetZCut)
  ;

  // ---
  m.def("CreateEllipticalCone", &::CreateEllipticalCone,
                              py::return_value_policy::reference);

}
