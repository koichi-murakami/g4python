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
class WaterPhantom : public G4VUserDetectorConstruction {
public:
  WaterPhantom();
  ~WaterPhantom() override = default;

  G4VPhysicalVolume* Construct() override;

  double phantomXY;
  double phantomZ;
};

// --------------------------------------------------------------------------
WaterPhantom::WaterPhantom()
{
  phantomXY = 30.5*cm;
  phantomZ = 30.*cm;
}

// --------------------------------------------------------------------------
G4VPhysicalVolume* WaterPhantom::Construct()
{
  auto nist_manager = G4NistManager::Instance();

  // world volume
  const double kDXY_World = 100.*cm;
  const double kDZ_World = 300.*cm;
  auto world_box = new G4Box("world", kDXY_World/2., kDXY_World/2.,
                                      kDZ_World/2.);
  auto air = nist_manager-> FindOrBuildMaterial("G4_AIR");
  auto world_lv = new G4LogicalVolume(world_box, air, "world");
  auto world_pv = new G4PVPlacement(nullptr, G4ThreeVector(), "world",
                                             world_lv, nullptr, false, 0);

  // phantom
  const double kDXY_Phantom = 30.5*cm;
  const double kDZ_Phantom = 30.*cm;

  auto phantom_box = new G4Box("phantom", phantomXY/2., phantomXY/2.,
                                          phantomZ/2.);
  auto water = nist_manager-> FindOrBuildMaterial("G4_WATER");
  auto phantom_lv = new G4LogicalVolume(phantom_box, water, "phantom");
  auto phantom = new G4PVPlacement(0, G4ThreeVector(),
                                   phantom_lv, "phantom", world_lv, false, 0);

  return world_pv;
}


// ==========================================================================
using c = WaterPhantom;

void export_WaterPhantom(py::module& m)
{
  py::class_<WaterPhantom, G4VUserDetectorConstruction>(m, "WaterPhantom")
  .def(py::init<>())
  // ---
  .def_readwrite("phantomXY", &c::phantomXY)
  .def_readwrite("phantomZ",  &c::phantomZ)
  ;
}
