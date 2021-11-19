# - build module
#------------------------------------------------------------------------------
set(MODULE pyG4intercoms)
#------------------------------------------------------------------------------
pybind11_add_module(${MODULE}
#pyG4UIcommand.cc
  pyG4UIcommandTree.cc
  pyG4UImanager.cc
  #pyG4UIparameter.cc
  pymodG4intercoms.cc
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
set_target_properties(${MODULE} PROPERTIES OUTPUT_NAME "G4intercoms")
set_target_properties(${MODULE} PROPERTIES SUFFIX ".so")

# install
install(TARGETS ${MODULE} LIBRARY DESTINATION ${G4MODULES_INSTALL_DIR})
