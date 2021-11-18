# - build module
#------------------------------------------------------------------------------
set(MODULE pyG4materials)
#------------------------------------------------------------------------------
pybind11_add_module(${MODULE}
  #pyG4AtomicShells.cc
  #pyG4Element.cc
  #pyG4ElementTable.cc
  #pyG4ElementVector.cc
  #pyG4Isotope.cc
  #pyG4Material.cc
  #pyG4MaterialTable.cc
  #pyG4NistManager.cc
  pymodG4materials.cc
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
set_target_properties(${MODULE} PROPERTIES OUTPUT_NAME "G4materials")
set_target_properties(${MODULE} PROPERTIES SUFFIX ".so")
set_target_properties(${MODULE}
                      PROPERTIES INSTALL_RPATH
                      ${GEANT4_LIBRARY_DIR}
                      BUILD_WITH_INSTALL_RPATH TRUE)

# install
install(TARGETS ${MODULE} LIBRARY DESTINATION ${G4MODULES_INSTALL_DIR})
