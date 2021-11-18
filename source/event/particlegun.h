/*============================================================================
Copyright 2017-2021 Koichi Murakami

Distributed under the OSI-approved BSD License (the "License");
see accompanying file LICENSE for details.

This software is distributed WITHOUT ANY WARRANTY; without even the
implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the License for more information.
============================================================================*/
#ifndef PARTICLE_GUN_H_
#define PARTICLE_GUN_H_

#include "G4VUserPrimaryGeneratorAction.hh"

class G4ParticleGun;

class ParticleGun : public G4VUserPrimaryGeneratorAction {
public:
  ParticleGun();
  ~ParticleGun();

  ParticleGun(const ParticleGun&) = delete;
  void operator=(const ParticleGun&) = delete;

  G4ParticleGun* GetGun() const;

  virtual void GeneratePrimaries(G4Event* event);

private:
  G4ParticleGun* gun_;

};

// ==========================================================================
inline G4ParticleGun* ParticleGun::GetGun() const
{
  return gun_;
}

#endif
