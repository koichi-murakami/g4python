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
#include "G4EmCalculator.hh"
#include "G4Element.hh"
#include "G4Material.hh"
#include "G4MaterialCutsCouple.hh"
#include "G4ParticleDefinition.hh"
#include "G4Region.hh"
#include "G4VProcess.hh"

namespace py = pybind11;

// ==========================================================================
void export_G4EmCalculator(py::module& m)
{
  py::class_<G4EmCalculator,
             std::unique_ptr<G4EmCalculator, py::nodelete>>(m, "G4EmCalculator")
  // --
  .def(py::init<>())
  // ---
  .def("GetDEDX", py::overload_cast<G4double, const G4ParticleDefinition*,
                                    const G4Material*, const G4Region*>
                  (&G4EmCalculator::GetDEDX),
                  py::arg("kinE"), py::arg("particle"),
                  py::arg("material"), py::arg("region") = nullptr)
  .def("GetDEDX", py::overload_cast<G4double, const G4String&,
                                    const G4String&, const G4String&>
                  (&G4EmCalculator::GetDEDX),
                  py::arg("kinE"), py::arg("particle"),
                  py::arg("material"), py::arg("region") = "world")
  // ---
  .def("GetRangeFromRestricteDEDX",
        py::overload_cast<G4double, const G4ParticleDefinition*,
                                    const G4Material*, const G4Region*>
                  (&G4EmCalculator::GetRangeFromRestricteDEDX),
                  py::arg("kinE"), py::arg("particle"),
                  py::arg("material"), py::arg("region") = nullptr)
  .def("GetRangeFromRestricteDEDX",
        py::overload_cast<G4double, const G4String&, const G4String&,
                          const G4String&>
                  (&G4EmCalculator::GetDEDX),
                  py::arg("kinE"), py::arg("particle"),
                  py::arg("material"), py::arg("region") = "world")
  // ---
  .def("GetCSDARange",
        py::overload_cast<G4double, const G4ParticleDefinition*,
                                    const G4Material*, const G4Region*>
                  (&G4EmCalculator::GetCSDARange),
                  py::arg("kinE"), py::arg("particle"),
                  py::arg("material"), py::arg("region") = nullptr)
  .def("GetCSDARange",
        py::overload_cast<G4double, const G4String&, const G4String&,
                          const G4String&>
                  (&G4EmCalculator::GetCSDARange),
                  py::arg("kinE"), py::arg("particle"),
                  py::arg("material"), py::arg("region") = "world")
  // ---
  .def("GetRange",
        py::overload_cast<G4double, const G4ParticleDefinition*,
                                    const G4Material*, const G4Region*>
                  (&G4EmCalculator::GetRange),
                  py::arg("kinE"), py::arg("particle"),
                  py::arg("material"), py::arg("region") = nullptr)
  .def("GetRange",
        py::overload_cast<G4double, const G4String&, const G4String&,
                          const G4String&>
                  (&G4EmCalculator::GetRange),
                  py::arg("kinE"), py::arg("particle"),
                  py::arg("material"), py::arg("region") = "world")
  // ---
  .def("GetKineEnergy",
        py::overload_cast<G4double, const G4ParticleDefinition*,
                                    const G4Material*, const G4Region*>
                  (&G4EmCalculator::GetKinEnergy),
                  py::arg("kinE"), py::arg("particle"),
                  py::arg("material"), py::arg("region") = nullptr)
  .def("GetKinEnergy",
        py::overload_cast<G4double, const G4String&, const G4String&,
                          const G4String&>
                  (&G4EmCalculator::GetKinEnergy),
                  py::arg("kinE"), py::arg("particle"),
                  py::arg("material"), py::arg("region") = "world")
  // ---
  .def("GetCrossSectionPerVolume",
        py::overload_cast<G4double, const G4ParticleDefinition*,
                                    const G4String&, const G4Material*,
                                    const G4Region*>
                  (&G4EmCalculator::GetCrossSectionPerVolume),
                  py::arg("kinE"), py::arg("particle"), py::arg("proc_name"),
                  py::arg("material"), py::arg("region") = nullptr)
  .def("GetCrossSectionPerVolume",
        py::overload_cast<G4double, const G4String&, const G4String&,
                                    const G4String&, const G4String&>
                  (&G4EmCalculator::GetCrossSectionPerVolume),
                  py::arg("kinE"), py::arg("particle"), py::arg("proc_name"),
                  py::arg("material"), py::arg("region") = "world")
  // ---
  .def("GetShellIonisationCrossSectionPerAtom",
                  &G4EmCalculator::GetShellIonisationCrossSectionPerAtom)
  // ---
  .def("GetMeanFreePath",
        py::overload_cast<G4double, const G4ParticleDefinition*,
                                    const G4String&, const G4Material*,
                                    const G4Region*>
                  (&G4EmCalculator::GetMeanFreePath),
                  py::arg("kinE"), py::arg("particle"), py::arg("proc_name"),
                  py::arg("material"), py::arg("region") = nullptr)
  .def("GetMeanFreePath",
        py::overload_cast<G4double, const G4String&, const G4String&,
                                    const G4String&, const G4String&>
                  (&G4EmCalculator::GetMeanFreePath),
                  py::arg("kinE"), py::arg("particle"), py::arg("proc_name"),
                  py::arg("material"), py::arg("region") = "world")
  // ---
  .def("PrintDEDXTable",          &G4EmCalculator::PrintDEDXTable)
  .def("PrintRangeTable",         &G4EmCalculator::PrintRangeTable)
  .def("PrintInverseRangeTable",  &G4EmCalculator::PrintInverseRangeTable)
  // ---
 .def("ComputeDEDX",
        py::overload_cast<G4double, const G4ParticleDefinition*,
                                    const G4String&, const G4Material*,
                                    const G4double>
                  (&G4EmCalculator::ComputeDEDX),
                  py::arg("kinE"), py::arg("particle"), py::arg("proc_name"),
                  py::arg("material"), py::arg("cut") = DBL_MAX)
  .def("ComputeDEDX",
        py::overload_cast<G4double, const G4String&, const G4String&,
                                    const G4String&, G4double>
                  (&G4EmCalculator::ComputeDEDX),
                  py::arg("kinE"), py::arg("particle"), py::arg("proc_name"),
                  py::arg("material"), py::arg("cut") = DBL_MAX)
  // ---
 .def("ComputeElectronicDEDX",
        py::overload_cast<G4double, const G4ParticleDefinition*,
                                    const G4Material*, const G4double>
                  (&G4EmCalculator::ComputeElectronicDEDX),
                  py::arg("kinE"), py::arg("particle"),
                  py::arg("material"), py::arg("cut") = DBL_MAX)
  .def("ComputeElectronicDEDX",
        py::overload_cast<G4double, const G4String&, const G4String&, G4double>
                  (&G4EmCalculator::ComputeElectronicDEDX),
                  py::arg("kinE"), py::arg("particle"),
                  py::arg("material"), py::arg("cut") = DBL_MAX)
  // ---
 .def("ComputeDEDXForCutInRange",
        py::overload_cast<G4double, const G4ParticleDefinition*,
                                    const G4Material*, const G4double>
                  (&G4EmCalculator::ComputeDEDXForCutInRange),
                  py::arg("kinE"), py::arg("particle"),
                  py::arg("material"), py::arg("cut") = DBL_MAX)
  .def("ComputeDEDXForCutInRange",
        py::overload_cast<G4double, const G4String&, const G4String&, G4double>
                  (&G4EmCalculator::ComputeDEDXForCutInRange),
                  py::arg("kinE"), py::arg("particle"),
                  py::arg("material"), py::arg("cut") = DBL_MAX)
  // ---
 .def("ComputeNuclearDEDX",
        py::overload_cast<G4double, const G4ParticleDefinition*,
                          const G4Material*>
                  (&G4EmCalculator::ComputeNuclearDEDX))
  .def("ComputeNuclearDEDX",
        py::overload_cast<G4double, const G4String&, const G4String&>
                  (&G4EmCalculator::ComputeNuclearDEDX))
  // ---
 .def("ComputeTotalDEDX",
        py::overload_cast<G4double, const G4ParticleDefinition*,
                                    const G4Material*, const G4double>
                  (&G4EmCalculator::ComputeTotalDEDX),
                  py::arg("kinE"), py::arg("particle"),
                  py::arg("material"), py::arg("cut") = DBL_MAX)
  .def("ComputeTotalDEDX",
        py::overload_cast<G4double, const G4String&, const G4String&, G4double>
                  (&G4EmCalculator::ComputeTotalDEDX),
                  py::arg("kinE"), py::arg("particle"),
                  py::arg("material"), py::arg("cut") = DBL_MAX)
  // ---
 .def("ComputeCrossSectionPerVolume",
        py::overload_cast<G4double, const G4ParticleDefinition*,
                          const G4String&, const G4Material*, G4double>
                  (&G4EmCalculator::ComputeCrossSectionPerVolume),
                  py::arg("kinE"), py::arg("particle"), py::arg("proc"),
                  py::arg("material"), py::arg("cut") = 0.0)
  .def("ComputeCrossSectionPerVolume",
        py::overload_cast<G4double, const G4String&,
                          const G4String&, const G4String&, G4double>
                  (&G4EmCalculator::ComputeCrossSectionPerVolume),
                  py::arg("kinE"), py::arg("particle"), py::arg("proc"),
                  py::arg("material"), py::arg("cut") = 0.0)
  // ---
  .def("ComputeCrossSectionPerAtom",
        py::overload_cast<G4double, const G4ParticleDefinition*,
                          const G4String&, G4double, G4double, G4double>
                  (&G4EmCalculator::ComputeCrossSectionPerAtom),
                  py::arg("kinE"), py::arg("particle"),
                  py::arg("proc"), py::arg("Z"), py::arg("A"),
                  py::arg("cut") = 0.0)
  .def("ComputeCrossSectionPerAtom",
        py::overload_cast<G4double, const G4String&, const G4String&,
                          const G4Element*, G4double>
                  (&G4EmCalculator::ComputeCrossSectionPerAtom),
                  py::arg("kinE"), py::arg("particle"),
                  py::arg("proc"), py::arg("element"),
                  py::arg("cut") = 0.0)
  // ---
  .def("ComputeCrossSectionPerShell",
        py::overload_cast<G4double, const G4ParticleDefinition*,
                          const G4String&, G4int, G4int, G4double>
                  (&G4EmCalculator::ComputeCrossSectionPerShell),
                  py::arg("kinE"), py::arg("particle"),
                  py::arg("proc"), py::arg("Z"), py::arg("shellIdx"),
                  py::arg("cut") = 0.0)
  .def("ComputeCrossSectionPerShell",
        py::overload_cast<G4double, const G4String&, const G4String&,
                          const G4Element*, G4int, G4double>
                  (&G4EmCalculator::ComputeCrossSectionPerShell),
                  py::arg("kinE"), py::arg("particle"),
                  py::arg("proc"), py::arg("element"), py::arg("shellIdx"),
                  py::arg("cut") = 0.0)
  // ---
  .def("ComputeGammaAttenuationLength",
                         &G4EmCalculator::ComputeGammaAttenuationLength)
  .def("ComputeShellIonisationCrossSectionPerAtom",
                         &G4EmCalculator::ComputeShellIonisationCrossSectionPerAtom,
                         py::arg("particle"), py::arg("Z"),
                         py::arg("shell"), py::arg("kE"),
                         py::arg("material") = nullptr)
  // ---
  .def("ComputeMeanFreePath",
        py::overload_cast<G4double, const G4ParticleDefinition*,
                          const G4String&, const G4Material*, G4double>
                  (&G4EmCalculator::ComputeMeanFreePath),
                  py::arg("kinE"), py::arg("particle"),
                  py::arg("proc"), py::arg("material"), py::arg("cut") = 0.0)

  .def("ComputeMeanFreePath",
        py::overload_cast<G4double, const G4String&, const G4String&,
                          const G4String&, G4double>
                  (&G4EmCalculator::ComputeMeanFreePath),
                  py::arg("kinE"), py::arg("particle"),
                  py::arg("material"), py::arg("proc"), py::arg("cut") = 0.0)
  // ---
  .def("ComputeEnergyCutFromRangeCut",
        py::overload_cast<G4double, const G4ParticleDefinition*,
                                    const G4Material*>
                  (&G4EmCalculator::ComputeEnergyCutFromRangeCut),
                  py::arg("range"), py::arg("particle"), py::arg("material"))
  .def("ComputeEnergyCutFromRangeCut",
        py::overload_cast<G4double, const G4String&, const G4String&>
                  (&G4EmCalculator::ComputeEnergyCutFromRangeCut),
                  py::arg("range"), py::arg("particle"), py::arg("material"))
  // ---
  .def("FindParticle",  &G4EmCalculator::FindParticle,
                        py::return_value_policy::reference)
  .def("FindIon",       &G4EmCalculator::FindIon,
                        py::return_value_policy::reference)
  .def("FindMaterial",  &G4EmCalculator::FindMaterial,
                        py::return_value_policy::reference)
  .def("FindRegion",    &G4EmCalculator::FindRegion,
                        py::return_value_policy::reference)
  .def("FindCouple",    &G4EmCalculator::FindCouple,
                        py::arg("material"), py::arg("region") = nullptr,
                        py::return_value_policy::reference)
  .def("FindProcess",   &G4EmCalculator::FindProcess,
                        py::return_value_policy::reference)
  // ---
  .def("SetupMaterial", py::overload_cast<const G4Material*>
                        (&G4EmCalculator::SetupMaterial))
  .def("SetupMaterial", py::overload_cast<const G4String&>
                        (&G4EmCalculator::SetupMaterial))
  .def("SetVerbose",    &G4EmCalculator::SetVerbose)
  ;
}
