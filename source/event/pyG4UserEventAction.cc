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
#include "G4UserEventAction.hh"
#include "G4Event.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

class PyG4UserEventAction : public G4UserEventAction {
public:
  using G4UserEventAction::G4UserEventAction;

  void BeginOfEventAction(const G4Event* event) override {
    PYBIND11_OVERLOAD(void, G4UserEventAction, BeginOfEventAction, event);
  }

  void EndOfEventAction(const G4Event* event) override {
    PYBIND11_OVERLOAD(void, G4UserEventAction, EndOfEventAction, event);
  }
};

}

// ==========================================================================
void export_G4UserEventAction(py::module& m)
{
  py::class_<G4UserEventAction, PyG4UserEventAction>(m, "G4UserEventAction")
  // ---
  .def(py::init<>())
  .def("BeginOfEventAction",   &G4UserEventAction::BeginOfEventAction)
  .def("EndOfEventAction",     &G4UserEventAction::EndOfEventAction)
  ;
}
