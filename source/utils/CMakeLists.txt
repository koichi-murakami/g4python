# - build module
#------------------------------------------------------------------------------
set(MODULE pyUtils)
#------------------------------------------------------------------------------
pybind11_add_module(${MODULE}
  eventcounter.cc
  medicalbeam.cc
  particlegun.cc
  gps.cc
  water_phantom.cc
  simplebox.cc
  pymod_utils.cc
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
set_target_properties(${MODULE} PROPERTIES OUTPUT_NAME "G4utils")
set_target_properties(${MODULE} PROPERTIES SUFFIX ".so")

#------------------------------------------------------------------------------
file (GLOB PY_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.py)

# install
install(TARGETS ${MODULE} LIBRARY DESTINATION ${G4MODULES_INSTALL_DIR}/utils)
install(FILES ${PY_FILES} DESTINATION ${G4MODULES_INSTALL_DIR}/utils)
