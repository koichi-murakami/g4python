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
#include <pybind11/operators.h>
#include "G4AttDef.hh"
#include "G4VisAttributes.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4VisAttributes(py::module& m)
{
  py::class_<G4VisAttributes>vis_attributes(m, "G4VisAttributes");
  vis_attributes
  // ---
  .def(py::init<>())
  .def(py::init<G4bool>())
  .def(py::init<const G4Colour&>())
  .def(py::init<G4bool, const G4Colour&>())
  // ---
  .def_static("GetInvisible",    &G4VisAttributes::GetInvisible,
                                 py::return_value_policy::copy)
  // ---
  .def("SetVisibility",          &G4VisAttributes::SetVisibility,
                                 py::arg("flag") = true )
  .def("SetDaughtersInvisible",  &G4VisAttributes::SetDaughtersInvisible,
                                 py::arg("flag") = true )
  .def("SetColor",
       py::overload_cast<const G4Colour&>(&G4VisAttributes::SetColor))
  .def("SetColor",
       py::overload_cast<G4double, G4double, G4double, G4double>
       (&G4VisAttributes::SetColor),
       py::arg("red"), py::arg("green"), py::arg("blue"),
       py::arg("alpha") = 1.)
  .def("SetLineStyle",           &G4VisAttributes::SetLineStyle)
  .def("SetLineWidth",           &G4VisAttributes::SetLineWidth)
  .def("SetForceWireframe",      &G4VisAttributes::SetForceWireframe,
                                 py::arg("flag") = true )
  .def("SetForceSolid",          &G4VisAttributes::SetForceSolid,
                                 py::arg("flag") = true )
  .def("SetForceCloud",          &G4VisAttributes::SetForceCloud,
                                 py::arg("flag") = true )
  .def("SetForceNumberOfCloudPoints",
                            &G4VisAttributes::SetForceNumberOfCloudPoints)
  .def("SetForceAuxEdgeVisible", &G4VisAttributes::SetForceAuxEdgeVisible,
                                 py::arg("flag") = true )
  .def("SetForceLineSegmentsPerCircle",
                            &G4VisAttributes::SetForceLineSegmentsPerCircle)
  .def("SetStartTime",           &G4VisAttributes::SetStartTime)
  .def("SetEndTime",             &G4VisAttributes::SetEndTime)
  .def("SetAttValues",           &G4VisAttributes::SetAttValues)
  .def("SetAttDefs",             &G4VisAttributes::SetAttDefs)
  // ---
  .def("IsVisible",              &G4VisAttributes::IsVisible)
  .def("IsDaughtersInvisible",   &G4VisAttributes::IsDaughtersInvisible)
  .def("GetColor",               &G4VisAttributes::GetColor)
  .def("GetLineStyle",           &G4VisAttributes::GetLineStyle)
  .def("GetLineWidth",           &G4VisAttributes::GetLineWidth)
  .def("IsForceDrawingStyle",    &G4VisAttributes::IsForceDrawingStyle)
  .def("GetForcedDrawingStyle",  &G4VisAttributes::GetForcedDrawingStyle)
  .def("GetForcedNumberOfCloudPoints",
                              &G4VisAttributes::GetForcedNumberOfCloudPoints)
  .def("IsForceAuxEdgeVisible",  &G4VisAttributes::IsForceAuxEdgeVisible)
  .def("IsForcedAuxEdgeVisible", &G4VisAttributes::IsForcedAuxEdgeVisible)
  .def("IsForceLineSegmentsPerCircle",
                              &G4VisAttributes::IsForceLineSegmentsPerCircle)
  .def("GetForcedLineSegmentsPerCircle",
                              &G4VisAttributes::GetForcedLineSegmentsPerCircle)
  .def("GetStartTime",           &G4VisAttributes::GetStartTime)
  .def("GetEndTime",             &G4VisAttributes::GetEndTime)

  // ---
  // operators
  .def(py::self == py::self)
  .def(py::self != py::self)
  ;

  py::enum_<G4VisAttributes::LineStyle>(vis_attributes, "LineStyle")
  .value("unbroken",   G4VisAttributes::unbroken)
  .value("dashed",     G4VisAttributes::dashed)
  .value("dotted",     G4VisAttributes::dotted)
  ;

  py::enum_<G4VisAttributes::ForcedDrawingStyle>
  (vis_attributes, "ForcedDrawingStyle")
  .value("wireframe",  G4VisAttributes::wireframe)
  .value("solid",      G4VisAttributes::solid)
  ;
}
