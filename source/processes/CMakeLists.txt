# - build module
#------------------------------------------------------------------------------
set(MODULE pyG4processes)
#------------------------------------------------------------------------------
add_library(${MODULE} SHARED)

target_sources(${MODULE} PRIVATE
  #pyG4CrossSectionHandler.cc
  pyG4EmCalculator.cc
  pyG4ProcessManager.cc
  pyG4ProcessTable.cc
  pyG4ProcessType.cc
  pyG4ProductionCuts.cc
  pyG4ProductionCutsTable.cc
  #pyG4VCrossSectionHandler.cc
  pyG4VProcess.cc
  pymodG4processes.cc
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
set_target_properties(${MODULE} PROPERTIES OUTPUT_NAME "G4processes")
set_target_properties(${MODULE} PROPERTIES SUFFIX ".so")

# install
install(TARGETS ${MODULE} LIBRARY DESTINATION ${G4MODULES_INSTALL_DIR})
