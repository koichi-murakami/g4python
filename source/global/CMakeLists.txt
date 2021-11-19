# - build module
#------------------------------------------------------------------------------
set(MODULE pyG4global)
#------------------------------------------------------------------------------
pybind11_add_module(${MODULE}
  G4PyCoutDestination.cc
#  pyG4ApplicationState.cc
  pyG4Exception.cc
  pyG4ExceptionHandler.cc
  pyG4ExceptionSeverity.cc
#  pyG4RandomDirection.cc
#  pyG4RotationMatrix.cc
#  pyG4StateManager.cc
  pyG4String.cc
  pyG4ThreeVector.cc
#  pyG4Timer.cc
#  pyG4Transform3D.cc
  pyG4TwoVector.cc
#  pyG4UnitsTable.cc
#  pyG4UserLimits.cc
  pyG4Version.cc
#  pyRandomEngines.cc
#  pyRandomize.cc
#  pygeomdefs.cc
  pyglobals.cc
  pymodG4global.cc
)

target_include_directories(${MODULE} PRIVATE
  ${GEANT4_INCLUDE_DIR}
  ${Python3_INCLUDE_DIRS}
  ${pybind11_INCLUDE_DIR}
)

target_link_directories(${MODULE} PRIVATE ${GEANT4_LIBRARY_DIR})

target_link_libraries(${MODULE} PRIVATE
  ${GEANT4_LIBRARIES} ${Python3_LIBRARIES}
  global_cflags
)

#------------------------------------------------------------------------------
set_target_properties(${MODULE} PROPERTIES PREFIX "")
set_target_properties(${MODULE} PROPERTIES OUTPUT_NAME "G4global")
set_target_properties(${MODULE} PROPERTIES SUFFIX ".so")

# install
install(TARGETS ${MODULE} LIBRARY DESTINATION ${G4MODULES_INSTALL_DIR})
