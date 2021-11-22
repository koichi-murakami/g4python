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
#include "G4ProductionCuts.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4ProductionCuts(py::module& m)
{
  py::class_<G4ProductionCuts>(m, "G4ProductionCuts")
  // ---
  .def("SetProductionCut", py::overload_cast<G4double,G4int>
                          (&G4ProductionCuts::SetProductionCut),
       py::arg("cut"), py::arg("index") = -1)
  .def("SetProductionCut", py::overload_cast<G4double,G4ParticleDefinition*>
                          (&G4ProductionCuts::SetProductionCut))
  .def("SetProductionCut", py::overload_cast<G4double,const G4String&>
                          (&G4ProductionCuts::SetProductionCut))
  .def("GetProductionCut", py::overload_cast<G4int>
                          (&G4ProductionCuts::GetProductionCut, py::const_))
  .def("GetProductionCut", py::overload_cast<const G4String&>
                          (&G4ProductionCuts::GetProductionCut, py::const_))
  .def("IsModified",       &G4ProductionCuts::IsModified)
  ;
}
