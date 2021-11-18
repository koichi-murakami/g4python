#==============================================================================
#  CMakeLists.txt for buidlig Python module
#==============================================================================
cmake_minimum_required(VERSION 3.16...3.21)

# Installation prefixes
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX $ENV{HOME}/opt/geant4/pymodules CACHE
      PATH "Install prefix" FORCE)
endif()

#==============================================================================
project(pymodule CXX)
#==============================================================================
set(MODULE ecalgeom)

# Geant4 installation path
set(GEANT4_INSTALL $ENV{HOME}/opt/geant4/11.0
    CACHE STRING "Geant4 installation path")

# python module install path
set(G4MODULES_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/${MODULE})

#------------------------------------------------------------------------------
# cmake modules
set(CMAKE_MODULE_PATH
    ${PROJECT_SOURCE_DIR}/../../cmake/Modules
    ${CMAKE_MODULE_PATH})

# find packages
find_package(Geant4 REQUIRED)
if(GEANT4_FOUND)
  if(NOT (${GEANT4_VERSION} VERSION_GREATER_EQUAL 11.0.0))
    message(FATAL_ERROR "Geant4 v11.0.0+ is required.")
  endif()
endif()

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 REQUIRED)

# c++17
add_library(global_cflags INTERFACE)
target_compile_features(global_cflags INTERFACE cxx_std_17)
set(CMAKE_CXX_EXTENSIONS OFF)

#------------------------------------------------------------------------------
# parameters for building
message(STATUS "--------------------------------------------------------")
message(STATUS "Parameters for building")
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message(STATUS "CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "GEANT4_VERSION: ${GEANT4_VERSION}")
message(STATUS "GEANT4_LIBRARY_DIR: ${GEANT4_LIBRARY_DIR}")
message(STATUS "Python3_EXECUTABLE: ${Python3_EXECUTABLE}")
message(STATUS "PYTHON3_INCLUDE_DIRS: ${Python3_INCLUDE_DIRS}")
message(STATUS "pybind11_VERSION: ${pybind11_VERSION}")
message(STATUS "pybind11_INCLUDE_DIR: ${pybind11_INCLUDE_DIR}")
message(STATUS "--------------------------------------------------------")

#------------------------------------------------------------------------------
pybind11_add_module(${MODULE} ecalgeom/ecalgeom.cc)
set_target_properties(${MODULE} PROPERTIES SUFFIX ".so")

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
# install
install(TARGETS ${MODULE} LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX})
