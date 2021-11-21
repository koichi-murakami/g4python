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
#include "G4ParticleTable.hh"
#include "G4IonTable.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4IonTable(py::module& m)
{
  py::class_<G4IonTable>(m, "G4IonTable")
  // ---
  .def_static("GetIonTable",  &G4IonTable::GetIonTable,
                              py::return_value_policy::reference)
  .def_static("IsIon",        &G4IonTable::IsIon)
  .def_static("IsAntiIon",    &G4IonTable::IsIon)
  // ---
  .def("GetIon",  py::overload_cast<G4int>(&G4IonTable::GetIon),
                  py::return_value_policy::reference)
  .def("GetIon",  py::overload_cast<G4int,G4int,G4int>(&G4IonTable::GetIon),
                  py::arg("Z"), py::arg("A"), py::arg("lvl") = 0,
                  py::return_value_policy::reference)
  .def("GetIon",  py::overload_cast<G4int,G4int,G4int,G4int>
                  (&G4IonTable::GetIon), py::return_value_policy::reference)
  .def("FindIon", py::overload_cast<G4int,G4int,G4int>(&G4IonTable::FindIon),
                  py::arg("Z"), py::arg("A"), py::arg("lvl") = 0,
                  py::return_value_policy::reference)
  .def("FindIon", py::overload_cast<G4int,G4int,G4int,G4int>
                  (&G4IonTable::FindIon), py::return_value_policy::reference)

  .def("GetIonName", py::overload_cast<G4int,G4int,G4int>
                     (&G4IonTable::GetIonName, py::const_),
                     py::arg("Z"), py::arg("A"), py::arg("lvl") = 0)
  .def("GetIonName", py::overload_cast<G4int,G4int,G4int,G4int>
                     (&G4IonTable::GetIonName, py::const_))
  // ---
  .def("GetIonMass", py::overload_cast<G4int,G4int,G4int,G4int>
                     (&G4IonTable::GetIonMass, py::const_),
                     py::arg("Z"), py::arg("A"),
                     py::arg("nL") = 0, py::arg("lvl") = 0)
  .def("GetNucleusMass", py::overload_cast<G4int,G4int,G4int,G4int>
                     (&G4IonTable::GetNucleusMass, py::const_),
                     py::arg("Z"), py::arg("A"),
                     py::arg("nL") = 0, py::arg("lvl") = 0)
  .def("GetIsomerMass", py::overload_cast<G4int,G4int,G4int>
                     (&G4IonTable::GetIsomerMass, py::const_),
                     py::arg("Z"), py::arg("A"), py::arg("lvl") = 0)
  // ---
  .def("GetLifetime", py::overload_cast<const G4ParticleDefinition*>
                     (&G4IonTable::GetLifeTime, py::const_))
  .def("GetLifetime", py::overload_cast<G4int,G4int,G4double,char>
                     (&G4IonTable::GetLifeTime, py::const_))
  // ---
  .def("GetMuonicAtom", py::overload_cast<G4Ions const*>
                        (&G4IonTable::GetMuonicAtom),
                        py::return_value_policy::reference)
  .def("GetMuonicAtom", py::overload_cast<G4int, G4int>
                        (&G4IonTable::GetMuonicAtom),
                        py::return_value_policy::reference)
  // ---
  .def("Entries",     &G4IonTable::Entries)
  .def("GetParticle", &G4IonTable::GetParticle,
                      py::return_value_policy::reference)
  .def("Contains",    &G4IonTable::Contains)
  .def("size",        &G4IonTable::size)
  .def("DumpTable",   &G4IonTable::DumpTable, py::arg("name") = "ALL")
  ;
}
