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
#include "G4Ellipsoid.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

G4Ellipsoid* CreateEllipsoid(const G4String& name,
                             G4double  pxSemiAxis,
                             G4double  pySemiAxis,
                             G4double  pzSemiAxis,
                             G4double  pzBottomCut = 0.,
                             G4double  pzTopCut = 0.)
{
  return new G4Ellipsoid(name, pxSemiAxis, pySemiAxis, pzSemiAxis,
                         pzBottomCut, pzTopCut);
}

}

// ==========================================================================
void export_G4Ellipsoid(py::module& m)
{
  py::class_<G4Ellipsoid, G4VSolid,
             std::unique_ptr<G4Ellipsoid, py::nodelete>>(m, "G4Ellipsoid")
  // ---
  .def(py::init<const G4String&, G4double, G4double, G4double>())
  .def(py::init<const G4String&, G4double, G4double, G4double, G4double>())
  .def(py::init<const G4String&, G4double, G4double, G4double,
                                 G4double, G4double>())
  // ---
  .def("GetSemiAxisMax", &G4Ellipsoid::GetSemiAxisMax)
  .def("GetZBottomCut",  &G4Ellipsoid::GetZBottomCut)
  .def("GetZTopCut",     &G4Ellipsoid::GetZTopCut)
  .def("SetSemiAxis",    &G4Ellipsoid::SetSemiAxis)
  .def("SetZCuts",       &G4Ellipsoid::SetZCuts)
  ;

  // ---
  m.def("CreateEllipsoid", &::CreateEllipsoid,
                           py::arg("name"),
                           py::arg("px"), py::arg("py"), py::arg("pz"),
                           py::arg("bottom_cut") = 0.,
                           py::arg("top_cut") = 0.,
                           py::return_value_policy::reference);
}
