# - build module
#------------------------------------------------------------------------------
set(MODULE pyG4run)
#------------------------------------------------------------------------------
pybind11_add_module(${MODULE}
  pyG4Run.cc
  pyG4RunManager.cc
  pyG4UserRunAction.cc
  pyG4VUserActionInitialization.cc
  pyG4VModularPhysicsList.cc
  pyG4VUserDetectorConstruction.cc
  pyG4VUserPhysicsList.cc
  pyG4VUserPrimaryGeneratorAction.cc
  pymodG4run.cc
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
set_target_properties(${MODULE} PROPERTIES OUTPUT_NAME "G4run")
set_target_properties(${MODULE} PROPERTIES SUFFIX ".so")

# install
install(TARGETS ${MODULE} LIBRARY DESTINATION ${G4MODULES_INSTALL_DIR})
