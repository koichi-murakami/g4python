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
#ifdef ENABLE_GDML
#include "G4GDMLParser.hh"
#endif
#include "G4LogicalVolume.hh"
#include "G4Material.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4GDMLParser(py::module& m)
{
#ifdef ENABLE_GDML
  py::class_<G4GDMLParser>(m, "G4GDMLParser")
  // ---
  .def("Read",           &G4GDMLParser::Read,
                         py::arg("fname"), py::arg("validate") = true)

  .def("ReadModule",     &G4GDMLParser::ReadModule,
                         py::arg("fname"), py::arg("validae") = true)

  .def("Write",
       py::overload_cast<const G4String&, const G4VPhysicalVolume*,
                         G4bool, const G4String&>
      (&G4GDMLParser::Write),
       py::arg("fname"), py::arg("pvol") = nullptr, py::arg("ref") = true,
       py::arg("loc") = G4GDML_DEFAULT_SCHEMALOCATION)

  .def("Write",
       py::overload_cast<const G4String&, const G4LogicalVolume*,
                         G4bool, const G4String&>
      (&G4GDMLParser::Write),
       py::arg("fname"), py::arg("lvol") = nullptr, py::arg("ref") = true,
       py::arg("loc") = G4GDML_DEFAULT_SCHEMALOCATION)

  .def("ParseST",          &G4GDMLParser::ParseST,
                           py::return_value_policy::reference)

  .def("GetWorldVolume",   &G4GDMLParser::GetWorldVolume,
                           py::arg("setupname") = "Default",
                           py::return_value_policy::reference)
  ;
#endif
}