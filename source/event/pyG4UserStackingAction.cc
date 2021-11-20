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
#include "G4UserStackingAction.hh"
#include "G4Track.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

class PyG4UserStackingAction : public G4UserStackingAction {
public:
  using G4UserStackingAction::G4UserStackingAction;

  G4ClassificationOfNewTrack ClassifyNewTrack(const G4Track* track) override {

    PYBIND11_OVERLOAD(G4ClassificationOfNewTrack, G4UserStackingAction,
                      ClassifyNewTrack, track);
  }

  void NewStage() override {

    PYBIND11_OVERLOAD(void, G4UserStackingAction, NewStage,);

  }

  void PrepareNewEvent() override {

    PYBIND11_OVERLOAD(void, G4UserStackingAction, PrepareNewEvent,);

  }

};

}

// ==========================================================================
void export_G4UserStackingAction(py::module& m)
{
  py::class_<G4UserStackingAction, PyG4UserStackingAction>
  (m, "G4UserStackingAction")
  // ---
  .def("ClassifyNewTrack",    &G4UserStackingAction::ClassifyNewTrack)
  .def("NewStage",            &G4UserStackingAction::NewStage)
  .def("PrepareNewEvent",     &G4UserStackingAction::PrepareNewEvent)
  ;
}
