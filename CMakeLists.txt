#==============================================================================
#  CMakeLists.txt for building Geant4-Python
#
#  ***************************
#  !! DONOT EDIT THIS FILE  !!
#  ***************************
#==============================================================================
cmake_minimum_required(VERSION 3.16...3.21)

#==============================================================================
project(Geaant4-Python CXX)
#==============================================================================
include(config.cmake)

#------------------------------------------------------------------------------
# cmake modules
set(CMAKE_PREFIX_PATH ${PROJECT_SOURCE_DIR}/cmake
   {CMAKE_PREFIX_PATH})

# python module install path
set(G4MODULES_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/site-packages/geant4)

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

# build options
if(NOT CMAKE_BUILD_TYPE)
  if(DEBUG)
    set(CMAKE_BUILD_TYPE "Debug")
  elseif(OPTIMIZE)
    set(CMAKE_BUILD_TYPE "Release")
  else()
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
  endif()
endif()

# rpath
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH FALSE)
set(CMAKE_INSTALL_RPATH "${GEANT4_LIBRARY_DIR}")

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
# install cmake files
file(GLOB CMAKE_FILES ${PROJECT_SOURCE_DIR}/cmake/geant4py*.cmake)
install(FILES ${CMAKE_FILES}
         DESTINATION ${CMAKE_INSTALL_PREFIX}/share/cmake)

#------------------------------------------------------------------------------
# add source
add_subdirectory(source)

# add tests
add_subdirectory(tests/gtest01)
add_subdirectory(tests/gtest02)
add_subdirectory(tests/gtest03)
