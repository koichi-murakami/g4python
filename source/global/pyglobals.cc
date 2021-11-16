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
#include <vector>
#include <pybind11/pybind11.h>
#include "G4PyCoutDestination.hh"
#include "G4strstreambuf.hh"
#include "G4ThreeVector.hh"
#include "G4TwoVector.hh"
#include "G4UImanager.hh"
#include "G4Version.hh"
//#include "pyG4indexing.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

// G4cout/cerr are set to Python stdout
void SetG4PyCoutDestination()
{
  auto UImgr= G4UImanager::GetUIpointer();
  auto pycout= new G4PyCoutDestination();
  G4coutbuf.SetDestination(pycout);
  G4cerrbuf.SetDestination(pycout);
}

void ResetG4PyCoutDestination()
{
  auto UImgr= G4UImanager::GetUIpointer();
  UImgr-> SetCoutDestination(0);
}

using G4intVector = std::vector<G4int>;
using G4doubleVector = std::vector<G4double>;
using G4StringVector = std::vector<G4String>;
using G4ThreeVectorVector = std::vector<G4ThreeVector>;
using G4TwoVectorVector = std::vector<G4TwoVector>;

}

// ==========================================================================
void export_globals(py::module& m)
{
  m.def("SetG4PyCoutDestination",   &::SetG4PyCoutDestination);
  m.def("ResetG4PyCoutDestination", &::ResetG4PyCoutDestination);

  /*
  class_<G4intVector> ("G4intVector", "int vector")
    .def(vector_indexing_suite<G4intVector>())
    ;

  class_<G4doubleVector> ("G4doubleVector", "double vector")
    .def(vector_indexing_suite<G4doubleVector>())
    ;

  class_<G4StringVector> ("G4StringVector", "string vector")
    .def(vector_indexing_suite<G4StringVector>())
    ;

  class_<G4ThreeVectorVector> ("G4ThreeVectorVector", "3-vector vector")
    .def(vector_indexing_suite<G4ThreeVectorVector>())
    ;

  class_<G4TwoVectorVector> ("G4StringVector", "2-vector vector")
    .def(vector_indexing_suite<G4TwoVectorVector>())
    ;
  */
}
