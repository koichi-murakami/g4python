# - build module
#------------------------------------------------------------------------------
set(MODULE pyG4gdml)
#------------------------------------------------------------------------------
pybind11_add_module(${MODULE}
  pyG4GDMLParser.cc
  pymodG4g4gdml.cc
)

if(GEANT4_GDML)
  add_definitions(-DENABLE_GDML)
endif()

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
set_target_properties(${MODULE} PROPERTIES OUTPUT_NAME "G4gdml")
set_target_properties(${MODULE} PROPERTIES SUFFIX ".so")

# install
install(TARGETS ${MODULE} LIBRARY DESTINATION ${G4MODULES_INSTALL_DIR})
