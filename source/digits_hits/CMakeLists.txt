# - build module
#------------------------------------------------------------------------------
set(MODULE pyG4digis_hits)
#------------------------------------------------------------------------------
pybind11_add_module(${MODULE}
  pyG4VSensitiveDetector.cc
  pymodG4digits_hits.cc
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
set_target_properties(${MODULE} PROPERTIES OUTPUT_NAME "G4digits_hits")
set_target_properties(${MODULE} PROPERTIES SUFFIX ".so")
set_target_properties(${MODULE}
                      PROPERTIES INSTALL_RPATH
                      ${GEANT4_LIBRARY_DIR}
                      BUILD_WITH_INSTALL_RPATH TRUE)

# install
install(TARGETS ${MODULE} LIBRARY DESTINATION ${G4MODULES_INSTALL_DIR})
