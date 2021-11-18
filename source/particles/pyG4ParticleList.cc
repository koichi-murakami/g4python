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

namespace py = pybind11;

// --------------------------------------------------------------------------
class PyG4ParticleList {
public:
  using ParticleList = std::vector<G4ParticleDefinition*> ;
  using p_iterator = ParticleList::iterator;

  static ParticleList particleTableCache;

  p_iterator p_begin() {
    auto particleTable = G4ParticleTable::GetParticleTable();

    if(particleTableCache.size() != particleTable-> size() ) {
      particleTableCache.clear();
      auto theParticleIterator = particleTable-> GetIterator();
      theParticleIterator-> reset();
      while( (*theParticleIterator)() ) {
        auto particle= theParticleIterator-> value();
        particleTableCache.push_back(particle);
      }
    }
    return particleTableCache.begin();
  }

  p_iterator p_end() {
    auto particleTable= G4ParticleTable::GetParticleTable();
    if( particleTableCache.size() != particleTable-> size() ) {
      particleTableCache.clear();
      auto theParticleIterator = particleTable-> GetIterator();
      theParticleIterator-> reset();
      while( (*theParticleIterator)() ){
        auto particle = theParticleIterator-> value();
        particleTableCache.push_back(particle);
      }
    }
    return particleTableCache.end();
  }
};

PyG4ParticleList::ParticleList PyG4ParticleList::particleTableCache;

// ==========================================================================
void export_PyG4ParticleList(py::module& m)
{
  py::class_<PyG4ParticleList>(m, "PyG4ParticleList")
    .def("__iter__",  iterator<PyG4ParticleList::ParticleList>())
    .def_property("particles", range(&PyG4ParticleList::p_begin,
				                             &PyG4ParticleList::p_end))
    ;
}
