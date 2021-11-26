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
#include <sstream>
#include <string>
#include "G4UserEventAction.hh"
#include "G4Event.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
class EventCounter : public G4UserEventAction {
public:
  EventCounter();
  ~EventCounter() override = default;

  void SetCheckCounter(int val);

  virtual void BeginOfEventAction(const G4Event* event);
  virtual void EndOfEventAction(const G4Event* event);

private:
  int check_counter_;

};

// ==========================================================================
inline void EventCounter::SetCheckCounter(int val)
{
  check_counter_ = val;
}


// --------------------------------------------------------------------------
namespace {

// --------------------------------------------------------------------------
void ShowProgress(int nprocessed, const std::string& key)
{
  G4cout << "[MESSAGE] event-loop check point: "
         << nprocessed << " events processed." << G4endl;
}

} // end of namespace

// --------------------------------------------------------------------------
EventCounter::EventCounter()
  : check_counter_{1000}
{
}

// --------------------------------------------------------------------------
void EventCounter::BeginOfEventAction(const G4Event* event)
{
  int ievent = event-> GetEventID();
}

// --------------------------------------------------------------------------
void EventCounter::EndOfEventAction(const G4Event* event)
{
  int ievent = event-> GetEventID();
  constexpr int kKiloEvents = 1000;

  if ( ievent % check_counter_ == 0 && ievent != 0 ) {
    int event_in_kilo = ievent / kKiloEvents;
    std::stringstream key;
    key << "EventCheckPoint:" << event_in_kilo << "K";
    ::ShowProgress(ievent, key.str());
  }
}

// ==========================================================================
void export_EventCounter(py::module& m)
{
  py::class_<EventCounter, G4UserEventAction>(m, "EventCounter")
  .def(py::init<>())
  .def("SetCheckCounter",  &EventCounter::SetCheckCounter)
  ;
}
