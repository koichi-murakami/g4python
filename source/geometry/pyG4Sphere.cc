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
#include "G4Sphere.hh"

namespace py = pybind11;

namespace {

// --------------------------------------------------------------------------
G4Sphere* CreateSphere(const G4String& name,
                       G4double pRmin, G4double pRmax,
                       G4double pSPhi, G4double pDPhi,
                       G4double pSTheta, G4double pDTheta)
{
  return new G4Sphere(name, pRmin, pRmax, pSPhi, pDPhi, pSTheta, pDTheta);
}

}

// ==========================================================================
void export_G4Sphere(py::module& m)
{
  py::class_<G4Sphere, G4VSolid>(m, "G4Sphere")
  // ---
  .def(py::init<const G4String&, G4double, G4double, G4double,
                                 G4double, G4double, G4double>())
  // ---
  .def("GetInsideRadius",     &G4Sphere::GetInnerRadius)
  .def("GetOuterRadius",      &G4Sphere::GetOuterRadius)
  .def("GetStartPhiAngle",    &G4Sphere::GetStartPhiAngle)
  .def("GetDeltaPhiAngle",    &G4Sphere::GetDeltaPhiAngle)
  .def("GetStartThetaAngle",  &G4Sphere::GetStartThetaAngle)
  .def("GetDeltaThetaAngle",  &G4Sphere::GetDeltaThetaAngle)
  .def("SetInsideRadius",     &G4Sphere::SetInnerRadius)
  .def("SetOuterRadius",      &G4Sphere::SetOuterRadius)
  .def("SetStartPhiAngle",    &G4Sphere::SetStartPhiAngle)
  .def("SetDeltaPhiAngle",    &G4Sphere::SetDeltaPhiAngle)
  .def("SetStartThetaAngle",  &G4Sphere::SetStartThetaAngle)
  .def("SetDeltaThetaAngle",  &G4Sphere::SetDeltaThetaAngle)
  ;

  // ---
  m.def("CreateSphere", &::CreateSphere, py::return_value_policy::reference);

}
