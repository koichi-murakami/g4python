#==============================================================================
#  CMakeLists.txt for buidlig Geant4Py user modules
#==============================================================================
cmake_minimum_required(VERSION 3.16...3.21)

#==============================================================================
project(geomB1)
#==============================================================================
# Geant4Py cmake path
set(Geant4_DIR $ENV{HOME}/opt/geant4/geant4py-11.0.0/share/cmake)

# Geant4 installation path
set(GEANT4_INSTALL $ENV{HOME}/opt/geant4/11.0
    CACHE STRING "Geant4 installation path")

# Pybind11 cmake files location
# Mac Homebrew
set(pybind11_DIR /opt/homebrew/share/cmake/pybind11
    CACHE STRING "Pybind11 search path")

# alternaive pybind11 path
#set(pybind11_DIR /opt/pybind11/share/cmake/pybind11
#    CACHE STRING "Pybind11 search path")

#------------------------------------------------------------------------------
# python module install path
set(MODULE ${CMAKE_PROJECT_NAME})
set(G4MODULES_INSTALL_DIR ${CMAKE_INSTALL_PREFIX})

include(${Geant4_DIR}/geant4pyCommon.cmake)
#------------------------------------------------------------------------------
# add source
file(GLOB sources ${PROJECT_SOURCE_DIR}/${MODULE}/*.cc)

pybind11_add_module(${MODULE} ${sources})

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

set_target_properties(${MODULE} PROPERTIES PREFIX "")
set_target_properties(${MODULE} PROPERTIES OUTPUT_NAME ${MODULE})
set_target_properties(${MODULE} PROPERTIES SUFFIX ".so")

# install
install(TARGETS ${MODULE} LIBRARY DESTINATION ${PROJECT_SOURCE_DIR})
