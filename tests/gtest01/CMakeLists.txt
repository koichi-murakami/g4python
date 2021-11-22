# - build module
#------------------------------------------------------------------------------
set(MODULE gtest01)
#------------------------------------------------------------------------------
pybind11_add_module(${MODULE}
  ecalgeom/ecalgeom.cc
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
set_target_properties(${MODULE} PROPERTIES OUTPUT_NAME "gtest01")
set_target_properties(${MODULE} PROPERTIES SUFFIX ".so")

#------------------------------------------------------------------------------
configure_file(tests.py tests.py COPYONLY)
configure_file(vis.mac vis.mac COPYONLY)
