# - build module
#------------------------------------------------------------------------------
set(MODULE pyG4run)
#------------------------------------------------------------------------------
add_library(${MODULE} SHARED)

target_sources(${MODULE} PRIVATE
  #pyG4Run.cc
  pyG4RunManager.cc
  #pyG4RunManagerKernel.cc
  #pyG4UserRunAction.cc
  #pyG4VModularPhysicsList.cc
  #pyG4VPhysicsConstructor.cc
  #pyG4VUserDetectorConstruction.cc
  #pyG4VUserPhysicsList.cc
  #pyG4VUserPrimaryGeneratorAction.cc
  pymodG4run.cc
)

target_include_directories(${MODULE} PRIVATE
  ${GEANT4_INCLUDE_DIR}
  ${PYTHON_INCLUDE_DIR}
  ${PYBIND11_INCLUDE_DIR}
)

target_link_directories(${MODULE} PRIVATE ${GEANT4_LIBRARY_DIR})

target_link_libraries(${MODULE} PRIVATE
  ${GEANT4_LIBRARIES} global_cflags
)

set_target_properties(${MODULE} PROPERTIES PREFIX "")
set_target_properties(${MODULE} PROPERTIES OUTPUT_NAME "G4run")
set_target_properties(${MODULE} PROPERTIES SUFFIX ".so")
set_target_properties(${MODULE} PROPERTIES INSTALL_RPATH
                      ${GEANT4_LIBRARY_DIR}
                      BUILD_WITH_INSTALL_RPATH TRUE)

# install
install(TARGETS ${MODULE} LIBRARY DESTINATION ${G4MODULES_INSTALL_DIR})
