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
#ifndef MEDICAL_BEAM_H
#define MEDICAL_BEAM_H

#include "G4VUserPrimaryGeneratorAction.hh"

class G4ParticleDefinition;

class MedicalBeam : public G4VUserPrimaryGeneratorAction {
public:
  MedicalBeam();
  ~MedicalBeam() override = default;

  MedicalBeam(const MedicalBeam&) = delete;
  void operator=(const MedicalBeam&) = delete;

  enum ParticleType { kElectron = 0, kPhoton, kProton};

  void SetParticle(ParticleType ptype);
  ParticleType GetParticle() const;

  void SetEnergy(double energy);
  double GetEnergy() const;

  void SetSSD(double val_ssd);
  double GetSSD() const;

  void SetFieldSize(double val_xy);
  double GetFieldSize() const;

  void SetSurfaceZ(double zpos);
  double GetSurfaceZ() const;

  void GeneratePrimaries(G4Event* event) override;

private:
  ParticleType particle_type_;
  double kinetic_energy_;

  double ssd_;
  double field_xy_;
  double surface_z_;
};

// ====================================================================
inline void MedicalBeam::SetParticle(MedicalBeam::ParticleType ptype)
{
  particle_type_ = ptype;
}

inline MedicalBeam::ParticleType MedicalBeam::GetParticle() const
{
  return particle_type_;
}

inline void MedicalBeam::SetEnergy(double energy)
{
  kinetic_energy_ = energy;
}

inline double MedicalBeam::GetEnergy() const
{
  return kinetic_energy_;
}

inline void MedicalBeam::SetSSD(double val_ssd)
{
  ssd_ = val_ssd;
}

inline double MedicalBeam::GetSSD() const
{
  return ssd_;
}

inline void MedicalBeam::SetFieldSize(double val_xy)
{
  field_xy_ = val_xy;
}

inline double MedicalBeam::GetFieldSize() const
{
  return field_xy_;
}

inline void MedicalBeam::SetSurfaceZ(double zpos)
{
  surface_z_ = zpos;
}

inline double MedicalBeam::GetSurfaceZ() const
{
  return surface_z_;
}

#endif
