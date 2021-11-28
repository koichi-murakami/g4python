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
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4VUserDetectorConstruction.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
class SimpleBox : public G4VUserDetectorConstruction {
public:
  SimpleBox();
  ~SimpleBox() override = default;

  G4VPhysicalVolume* Construct() override;

  double boxXYZ;
  G4Material* material;
};

// --------------------------------------------------------------------------
SimpleBox::SimpleBox()
{
  boxXYZ = 1.*m;
  material = nullptr;
}

// --------------------------------------------------------------------------
G4VPhysicalVolume* SimpleBox::Construct()
{
  auto nist_manager = G4NistManager::Instance();

  auto world_box = new G4Box("world", boxXYZ/2., boxXYZ/2., boxXYZ/2.);

  if ( material == nullptr ) {
    material = nist_manager-> FindOrBuildMaterial("G4_WATER");
  }

  auto world_lv = new G4LogicalVolume(world_box, material, "world");

  auto world_pv = new G4PVPlacement(nullptr, G4ThreeVector(), "world",
                                    world_lv, nullptr, false, 0);

  return world_pv;
}


// ==========================================================================
using c = SimpleBox;

void export_SimpleBox(py::module& m)
{
  py::class_<SimpleBox, G4VUserDetectorConstruction,
             std::unique_ptr<SimpleBox, py::nodelete>>(m, "SimpleBox")
  .def(py::init<>())
  // ---
  .def_readwrite("boxXYZ",   &c::boxXYZ)
  .def_readwrite("material", &c::material, py::return_value_policy::reference)
  ;
}
