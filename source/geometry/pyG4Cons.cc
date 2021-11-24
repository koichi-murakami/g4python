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
#include "G4Cons.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

G4Cons* CreateCons(const G4String& name, G4double pRmin1, G4double pRmax1,
                                         G4double pRmin2, G4double pRmax2,
                                         G4double pDz,
                                         G4double pSPhi, G4double pDPhi)
{
  return new G4Cons(name, pRmin1, pRmax1, pRmin2, pRmax2, pDz, pSPhi, pDPhi);
}

}

// ==========================================================================
void export_G4Cons(py::module& m)
{
  py::class_<G4Cons, G4VSolid>(m, "G4Cons")
  // ---
  .def(py::init<const G4String&, G4double, G4double, G4double,
	                               G4double, G4double, G4double, G4double>())
	 // ---
	.def("GetInnerRadiusMinusZ", &G4Cons::GetInnerRadiusMinusZ)
	.def("GetOuterRadiusMinusZ", &G4Cons::GetOuterRadiusMinusZ)
	.def("GetInnerRadiusPlusZ",  &G4Cons::GetInnerRadiusPlusZ)
	.def("GetOuterRadiusPlusZ",  &G4Cons::GetOuterRadiusPlusZ)
	.def("GetZHalfLength",       &G4Cons::GetZHalfLength)
	.def("GetStartPhiAngle",     &G4Cons::GetStartPhiAngle)
	.def("GetDeltaPhiAngle",     &G4Cons::GetDeltaPhiAngle)
	.def("SetInnerRadiusMinusZ", &G4Cons::SetInnerRadiusMinusZ)
	.def("SetOuterRadiusMinusZ", &G4Cons::SetOuterRadiusMinusZ)
	.def("SetInnerRadiusPlusZ",  &G4Cons::SetInnerRadiusPlusZ)
	.def("SetOuterRadiusPlusZ",  &G4Cons::SetOuterRadiusPlusZ)
	.def("SetZHalfLength",       &G4Cons::SetZHalfLength)
	.def("SetStartPhiAngle",     &G4Cons::SetStartPhiAngle)
	.def("SetDeltaPhiAngle",     &G4Cons::SetDeltaPhiAngle)
	// ---
	.def("GetCubicVolume",       &G4Cons::GetCubicVolume)
	.def("GetSurfaceArea",       &G4Cons::GetSurfaceArea)
	;

	// ---
	m.def("CreateCons", &::CreateCons, py::return_value_policy::reference);

}
