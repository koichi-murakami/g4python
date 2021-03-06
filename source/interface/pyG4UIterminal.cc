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
#include "G4UIterminal.hh"
#include "G4UItcsh.hh"
#include "G4UIcsh.hh"

namespace py = pybind11;

static G4UIterminal* session = nullptr;

// --------------------------------------------------------------------------
namespace {

void StartUISession()
{
  if (session == nullptr ) {
    auto tcsh = new G4UItcsh("geant4(%s)[%/]:");

    session = new G4UIterminal(tcsh, false);
  }

  session-> SessionStart();
}

}

// ==========================================================================
void export_G4UIterminal(py::module& m)
{
  m.def("StartUISession", &::StartUISession);
}
