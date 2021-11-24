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
#include "G4MagneticField.hh"
#include "G4ThreeVector.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

// --------------------------------------------------------------------------
class G4UserMagneticField : public G4MagneticField {
public:
  using G4MagneticField::G4MagneticField;

  virtual G4ThreeVector FieldValue(const G4ThreeVector& pos,
		 		                           G4double time) const = 0;

  void GetFieldValue(const G4double Point[4],
			               G4double* Bfield) const  override {
    auto bfield = FieldValue(G4ThreeVector(Point[0], Point[1],Point[2]),
                              Point[3]);

    Bfield[0] = bfield.x();
    Bfield[1] = bfield.y();
    Bfield[2] = bfield.z();
  }
};

// --------------------------------------------------------------------------
class PyG4UserMagneticField : public G4UserMagneticField {
public:
  using G4UserMagneticField::G4UserMagneticField;

  G4ThreeVector FieldValue(const G4ThreeVector& pos,
		 		                   G4double time) const override {
    PYBIND11_OVERLOAD_PURE(
      G4ThreeVector,
      G4UserMagneticField,
      FieldValue,
      pos, time
    );
  }
};

}

// ==========================================================================
void export_G4MagneticField(py::module& m)
{
  py::class_<G4MagneticField, G4Field>(m, "G4MagneticField");

  py::class_<G4UserMagneticField, PyG4UserMagneticField, G4MagneticField>
  (m, "G4UserMagneticField")
  // ---
  .def(py::init<>())
  // ---
  .def("DoesFieldChangeEnergy", &G4UserMagneticField::DoesFieldChangeEnergy)
  .def("GetFieldValue",         &G4UserMagneticField::FieldValue)
  ;

}
