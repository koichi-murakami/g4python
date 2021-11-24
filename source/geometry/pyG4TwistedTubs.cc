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
#include "G4TwistedTubs.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

// --------------------------------------------------------------------------
G4TwistedTubs* f1_CreateTwistedTubs(const G4String& name,
                                    G4double  twistedangle,
                                    G4double  endinnerrad,
                                    G4double  endouterrad,
                                    G4double  halfzlen,
                                    G4double  dphi)
{
  return new G4TwistedTubs(name, twistedangle, endinnerrad,
                           endouterrad, halfzlen, dphi);
}

// --------------------------------------------------------------------------
G4TwistedTubs* f2_CreateTwistedTubs(const G4String& name,
                                    G4double  twistedangle,
                                    G4double  endinnerrad,
                                    G4double  endouterrad,
                                    G4double  halfzlen,
                                    G4int     nseg,
                                    G4double  totphi)
{
  return new G4TwistedTubs(name, twistedangle, endinnerrad,
                           endouterrad, halfzlen, nseg, totphi);
}

// --------------------------------------------------------------------------
G4TwistedTubs* f3_CreateTwistedTubs(const G4String& name,
                                    G4double  twistedangle,
                                    G4double  innerrad,
                                    G4double  outerrad,
                                    G4double  negativeEndz,
                                    G4double  positiveEndz,
                                    G4double  dphi)
{
  return new G4TwistedTubs(name, twistedangle, innerrad, outerrad,
                           negativeEndz, positiveEndz, dphi);
}

// --------------------------------------------------------------------------
G4TwistedTubs* f4_CreateTwistedTubs(const G4String& name,
                                    G4double  twistedangle,
                                    G4double  innerrad,
                                    G4double  outerrad,
                                    G4double  negativeEndz,
                                    G4double  positiveEndz,
                                    G4int     nseg,
                                    G4double  totphi)
{
  return new G4TwistedTubs(name, twistedangle, innerrad, outerrad,
                           negativeEndz, positiveEndz, nseg, totphi);
}

}

// ==========================================================================
void export_G4TwistedTubs(py::module& m)
{
  py::class_<G4TwistedTubs, G4VSolid>(m, "G4TwistedTubs")
  // constructors
  .def(py::init<const G4String&, G4double, G4double, G4double,
                             G4double, G4double>())

  .def(py::init<const G4String&, G4double, G4double, G4double,
                             G4double, G4int, G4double>())

  .def(py::init<const G4String&, G4double, G4double, G4double,

                                 G4double, G4double, G4double>())
  .def(py::init<const G4String&, G4double, G4double, G4double,
                                 G4double, G4double, G4int, G4double>())
  // ---
  .def("GetDPhi",            &G4TwistedTubs::GetDPhi)
  .def("GetPhiTwist",        &G4TwistedTubs::GetPhiTwist)
  .def("GetInnerRadius",     &G4TwistedTubs::GetInnerRadius)
  .def("GetOuterRadius",     &G4TwistedTubs::GetOuterRadius)
  .def("GetInnerStereo",     &G4TwistedTubs::GetInnerStereo)
  .def("GetOuterStereo",     &G4TwistedTubs::GetOuterStereo)
  .def("GetZHalfLength",     &G4TwistedTubs::GetZHalfLength)
  .def("GetKappa",           &G4TwistedTubs::GetKappa)
  .def("GetTanInnerStereo",  &G4TwistedTubs::GetTanInnerStereo)
  .def("GetTanInnerStereo2", &G4TwistedTubs::GetTanInnerStereo2)
  .def("GetTanOuterStereo",  &G4TwistedTubs::GetTanOuterStereo)
  .def("GetTanOuterStereo2", &G4TwistedTubs::GetTanOuterStereo2)
  .def("GetEndZ",            &G4TwistedTubs::GetEndZ)
  .def("GetEndPhi",          &G4TwistedTubs::GetEndPhi)
  .def("GetEndInnerRadius",
       py::overload_cast<>(&G4TwistedTubs::GetEndInnerRadius, py::const_))
  .def("GetEndInnerRadius",
       py::overload_cast<G4int>(&G4TwistedTubs::GetEndInnerRadius, py::const_))
  .def("GetEndOuterRadius",
       py::overload_cast<>(&G4TwistedTubs::GetEndOuterRadius, py::const_))
  .def("GetEndOuterRadius",
       py::overload_cast<G4int>(&G4TwistedTubs::GetEndOuterRadius, py::const_))
  ;

  // ---
  m.def("CreateTwistedTubs",  &::f1_CreateTwistedTubs,
                              py::return_value_policy::reference);
  m.def("CreateTwistedTubs",  &::f2_CreateTwistedTubs,
                              py::return_value_policy::reference);
  m.def("CreateTwistedTubs",  &::f3_CreateTwistedTubs,
  py::return_value_policy::reference);
  m.def("CreateTwistedTubs",  &::f4_CreateTwistedTubs,
                              py::return_value_policy::reference);
}
