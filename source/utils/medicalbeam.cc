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
#include <cmath>
#include "G4Event.hh"
#include "G4Electron.hh"
#include "G4Gamma.hh"
#include "G4PrimaryVertex.hh"
#include "G4Proton.hh"
#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "Randomize.hh"
#include "medicalbeam.h"

namespace py = pybind11;

namespace {

// --------------------------------------------------------------------------
G4ThreeVector GenerateBeamDirection(double ssd, double fxy)
{
  const double dr = std::sqrt(2.) * fxy / 2.;
  const double R = std::sqrt(sqr(ssd)+sqr(dr));
  const double cos0 = ssd/R;

  const double xymax = fxy/ssd/2.;
  double dx, dy, dz, dsin, dphi;

  do {
    dz = G4RandFlat::shoot(cos0, 1.);
    dsin = std::sqrt(1.-sqr(dz));
    dphi = G4RandFlat::shoot(0., twopi);

    dx = dsin * std::cos(dphi);
    dy = dsin * std::sin(dphi);
  } while(! (std::abs(dx) < xymax*dz && std::abs(dy) < xymax*dz) );

  return G4ThreeVector(dx, dy, dz);
}

} // end of namespace

// --------------------------------------------------------------------------
MedicalBeam::MedicalBeam()
  : kinetic_energy_(20.*MeV), ssd_(100.*cm), field_xy_(10.*cm)
{
  particle_type_ = kElectron;
  surface_z_ = -15.*cm;   // phantom DZ = 30 cm
}

// --------------------------------------------------------------------------
void MedicalBeam::GeneratePrimaries(G4Event* event)
{
  G4ParticleDefinition* particle = nullptr;
  switch ( particle_type_ ) {
    case kElectron :
      particle = G4Electron::Electron();
      break;
    case kProton :
      particle = G4Proton::Proton();
      break;
    case kPhoton :
      particle = G4Gamma::Gamma();
      break;
    default :
      particle = G4Electron::Electron();
      break;
  }

  auto mass = particle-> GetPDGMass();
  auto momemtum = std::sqrt(sqr(mass+kinetic_energy_) - sqr(mass));
  auto pvec = momemtum * ::GenerateBeamDirection(ssd_, field_xy_);

  auto primary = new G4PrimaryParticle(particle,
                                       pvec.x(), pvec.y(), pvec.z() );

  auto pos = G4ThreeVector(0., 0., surface_z_ - ssd_);
  auto vertex= new G4PrimaryVertex(pos, 0.*ns);
  vertex-> SetPrimary(primary);

  event-> AddPrimaryVertex(vertex);
}

// ==========================================================================
using c = MedicalBeam;

void export_MedicalBeam(py::module& m)
{
  py::class_<MedicalBeam, G4VUserPrimaryGeneratorAction,
             std::unique_ptr<MedicalBeam, py::nodelete>>
             medical_beam(m, "MedicalBeam");

  medical_beam
  .def(py::init<>())
  // ---
  .def_property("particleType", &c::GetParticle,   &c::SetParticle)
  .def_property("kineticE",     &c::GetEnergy,     &c::SetEnergy)
  .def_property("ssd",          &c::GetSSD,        &c::SetSSD)
  .def_property("fieldSize",    &c::GetFieldSize,  &c::SetFieldSize)
  .def_property("surfaceZ",     &c::GetSurfaceZ,   &c::SetSurfaceZ)
  ;

  py::enum_<MedicalBeam::ParticleType>(medical_beam, "ParticleType")
  .value("kElectron",   MedicalBeam::kElectron)
  .value("kPhoton",     MedicalBeam::kPhoton)
  .value("kProton",     MedicalBeam::kProton)
  ;
}
