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
#include "G4VSensitiveDetector.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

class PyG4VSensitiveDetector : public G4VSensitiveDetector {
public:
  using G4VSensitiveDetector::G4VSensitiveDetector;

  PyG4VSensitiveDetector(G4String name)
    : G4VSensitiveDetector(name) { }

  void Initialize(G4HCofThisEvent* hc) override {
    PYBIND11_OVERLOAD(void, G4VSensitiveDetector, Initialize, hc);
  }

  void EndOfEvent(G4HCofThisEvent* hc) override {
    PYBIND11_OVERLOAD(void, G4VSensitiveDetector, EndOfEvent, hc);
  }

  void clear() override {
    PYBIND11_OVERLOAD(void, G4VSensitiveDetector, clear, );
  }

  void DrawAll() override {
    PYBIND11_OVERLOAD(void, G4VSensitiveDetector, DrawAll, );
  }

  void PrintAll() override {
    PYBIND11_OVERLOAD(void, G4VSensitiveDetector, PrintAll, );
  }

  G4bool ProcessHits(G4Step* step, G4TouchableHistory* ro_hist) override {
    PYBIND11_OVERLOAD_PURE(G4bool, G4VSensitiveDetector, ProcessHits,
                           step, ro_hist);
  }
};

class PubG4VSensitiveDetector : public G4VSensitiveDetector {
public:
  using G4VSensitiveDetector::ProcessHits;
};

}

// ==========================================================================
void export_G4VSensitiveDetector(py::module& m)
{
  py::class_<G4VSensitiveDetector, PyG4VSensitiveDetector>
    (m, "G4VSensitiveDetector")
    // ---
    .def(py::init<G4String>())
    // ---
    .def("Hit",             &G4VSensitiveDetector::Hit)
    // ---
    .def("Initialize",      &G4VSensitiveDetector::Initialize)
    .def("EndOfEvent",      &G4VSensitiveDetector::EndOfEvent)
    .def("clear",           &G4VSensitiveDetector::clear)
    .def("DrawAll",         &G4VSensitiveDetector::DrawAll)
    .def("PrintAll",        &G4VSensitiveDetector::PrintAll)
    .def("ProcessHits",     &PubG4VSensitiveDetector::ProcessHits)
    // ---
    .def("GetNumberOfCollections",
                            &G4VSensitiveDetector::GetNumberOfCollections)
    .def("GetCollectionName", &G4VSensitiveDetector::GetCollectionName)
    .def("SetVerboseLevel", &G4VSensitiveDetector::SetVerboseLevel)
    .def("Activate",        &G4VSensitiveDetector::Activate)
    .def("isActive",        &G4VSensitiveDetector::isActive)
    .def("GetName",         &G4VSensitiveDetector::GetName)
    .def("GetPathName",     &G4VSensitiveDetector::GetPathName)
    .def("GetFullPathName", &G4VSensitiveDetector::GetFullPathName)
    ;
}
