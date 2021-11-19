# - build module
#------------------------------------------------------------------------------
set(MODULE pyG4visualization)
#------------------------------------------------------------------------------
pybind11_add_module(${MODULE}
  pyG4VisDrivers.cc
  pyG4OpenGLX.cc
  pyG4VisManager.cc
  pymodG4visualization.cc
)

if(GEANT4_VIS)
  add_definitions(-DG4VIS_USE_OPENGLX)
endif()

target_include_directories(${MODULE} PRIVATE
  ${GEANT4_INCLUDE_DIR}
  ${Python3_INCLUDE_DIRS}
  ${pybind11_INCLUDE_DIR}
)

target_link_directories(${MODULE} PRIVATE ${GEANT4_LIBRARY_DIR})

target_link_libraries(${MODULE} PRIVATE
  ${GEANT4_LIBRARIES_WITH_VIS} ${Python3_LIBRARIES}
  global_cflags
)

#------------------------------------------------------------------------------
set_target_properties(${MODULE} PROPERTIES PREFIX "")
set_target_properties(${MODULE} PROPERTIES OUTPUT_NAME "G4visualization")
set_target_properties(${MODULE} PROPERTIES SUFFIX ".so")
set_target_properties(${MODULE}
                      PROPERTIES INSTALL_RPATH
                      ${GEANT4_LIBRARY_DIR}
                      BUILD_WITH_INSTALL_RPATH TRUE)

# install
install(TARGETS ${MODULE} LIBRARY DESTINATION ${G4MODULES_INSTALL_DIR})
