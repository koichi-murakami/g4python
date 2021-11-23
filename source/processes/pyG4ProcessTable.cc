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
#include "G4ProcessTable.hh"

namespace py = pybind11;

// --------------------------------------------------------------------------
namespace {

py::list make_process_list(const G4ProcessVector* g4pvec)
{
  py::list pylist;

  auto nproc= g4pvec-> size();
  for( int i = 0; i < nproc; i++ ) {
    pylist.append((*g4pvec)[i]);
  }

  return pylist;
}

// --------------------------------------------------------------------------
// FindProcesses
py::list f1_FindProcesses(G4ProcessTable* procTable)
{
  auto proc_vec = procTable-> FindProcesses();
  return make_process_list(proc_vec);
}

// --------------------------------------------------------------------------
py::list f2_FindProcesses(G4ProcessTable* procTable,
		                      const G4ProcessManager* procManager)
{
  auto proc_vec = procTable-> FindProcesses(procManager);
  return make_process_list(proc_vec);
}

// --------------------------------------------------------------------------
py::list f3_FindProcesses(G4ProcessTable* procTable,
                          const G4String& pname)
{
  auto proc_vec = procTable-> FindProcesses(pname);
  return make_process_list(proc_vec);
}

// --------------------------------------------------------------------------
py::list f4_FindProcesses(G4ProcessTable* procTable,
	 	                      G4ProcessType ptype)
{
  auto proc_vec = procTable-> FindProcesses(ptype);
  return make_process_list(proc_vec);
}

// --------------------------------------------------------------------------
py::list GetProcNameList(G4ProcessTable* procTable)
{
  py::list pylist;

  auto pname_list = procTable-> GetNameList();

  auto nproc= pname_list-> size();
  for( int i = 0; i < nproc; i++ ) {
    pylist.append((*pname_list)[i]);
  }

  return pylist;
}

}

// ==========================================================================
void export_G4ProcessTable(py::module& m)
{
  py::class_<G4ProcessTable>(m, "G4ProcessTable")
  // ---
  .def_static("GetProcessTable",  &G4ProcessTable::GetProcessTable,
                                  py::return_value_policy::reference)
  // ---
  .def("Length",      &G4ProcessTable::Length)
  // ---
  .def("FindProcess", py::overload_cast<const G4String&, const G4String&>
                      (&G4ProcessTable::FindProcess, py::const_),
                      py::return_value_policy::reference)
  .def("FindProcess", py::overload_cast<const G4String&,
                                        const G4ParticleDefinition*>
                      (&G4ProcessTable::FindProcess, py::const_),
                      py::return_value_policy::reference)
  .def("FindProcess", py::overload_cast<const G4String&,
                                        const G4ProcessManager*>
                      (&G4ProcessTable::FindProcess, py::const_),
                      py::return_value_policy::reference)
  .def("FindProcess", py::overload_cast<G4ProcessType,
                                        const G4ParticleDefinition*>
                      (&G4ProcessTable::FindProcess, py::const_),
                      py::return_value_policy::reference)
  .def("FindProcess", py::overload_cast<G4int, const G4ParticleDefinition*>
                      (&G4ProcessTable::FindProcess, py::const_),
                      py::return_value_policy::reference)

  .def("FindProcesses",        &::f1_FindProcesses)
  .def("FindProcesses",        &::f2_FindProcesses)
  .def("FindProcesses",        &::f3_FindProcesses)
  .def("FindProcesses",        &::f4_FindProcesses)
  // ---
  .def("SetProcessActivation", py::overload_cast<const G4String&, G4bool>
                               (&G4ProcessTable::SetProcessActivation))
  .def("SetProcessActivation", py::overload_cast<const G4String&,
                                                 const G4String&, G4bool>
                               (&G4ProcessTable::SetProcessActivation))
  .def("SetProcessActivation", py::overload_cast<const G4String&,
                                                 const G4ParticleDefinition*,
                                                 G4bool>
                               (&G4ProcessTable::SetProcessActivation))
  .def("SetProcessActivation", py::overload_cast<const G4String&,
                                                 G4ProcessManager*, G4bool>
                               (&G4ProcessTable::SetProcessActivation))
  .def("SetProcessActivation", py::overload_cast<G4ProcessType, G4bool>
                               (&G4ProcessTable::SetProcessActivation))
  .def("SetProcessActivation", py::overload_cast<G4ProcessType,
                                                 const G4String&, G4bool>
                               (&G4ProcessTable::SetProcessActivation))
  .def("SetProcessActivation", py::overload_cast<G4ProcessType,
                                                 G4ProcessManager*, G4bool>
                               (&G4ProcessTable::SetProcessActivation))
  // ---
  .def("GetNameList",          &::GetProcNameList)
  .def("DumpInfo",             &G4ProcessTable::DumpInfo,
                               py::arg("process"),
                               py::arg("particle") = nullptr)
  .def("SetVerboseLevel",      &G4ProcessTable::SetVerboseLevel)
  .def("GetVerboseLevel",      &G4ProcessTable::GetVerboseLevel)
  ;
}
