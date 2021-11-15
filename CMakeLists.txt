#==============================================================================
#  CMakeLists.txt for buidlig Geant4-Python
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
set(CMAKE_MODULE_PATH
    ${PROJECT_SOURCE_DIR}/cmake/Modules
    ${CMAKE_MODULE_PATH})

# library path (lib or lib64)
if(NOT DEFINED CMAKE_INSTALL_LIBDIR)
  set(_LIBDIR_DEFAULT lib)
  if(CMAKE_SYSTEM_NAME MATCHES "Linux"
     AND NOT EXISTS "/etc/debian_version")
    if("${CMAKE_SIZEOF_VOID_P}" EQUAL "8")
      set(_LIBDIR_DEFAULT lib64)
    endif()
  endif()
  set(CMAKE_INSTALL_LIBDIR ${CMAKE_INSTALL_PREFIX}/${_LIBDIR_DEFAULT})
endif()

# python module install path
set(G4MODULES_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/geant4)

# find packages
find_package(Geant4 REQUIRED)
if(GEANT4_FOUND)
  if(NOT (${GEANT4_VERSION} VERSION_GREATER_EQUAL 11.0.0))
    message(FATAL_ERROR "Geant4 v11.0.0+ is required.")
  endif()
endif()

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
#find_package(pybind11 REQUIRED PATH ${PYBIND11_SEARCH_PATH})
find_package(pybind11 REQUIRED)

# c++17
add_library(global_cflags INTERFACE)
target_compile_features(global_cflags INTERFACE cxx_std_17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)

# compiler flags
set(cxx_flags)

# build options
if(NOT CMAKE_BUILD_TYPE)
  if(DEBUG)
    set(CMAKE_BUILD_TYPE "Debug")
    if(MSVC)
      set(cxx_flags ${cxx_flags} /DDEBUG)
    else()
      set(cxx_flags ${cxx_flags} -DDEBUG)
    endif()
  elseif(OPTIMIZE)
    set(CMAKE_BUILD_TYPE "Release")
  else()
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
  endif()
endif()

add_library(dev_flags INTERFACE)
target_compile_options(dev_flags INTERFACE
  $<$<COMPILE_LANGUAGE:CXX>:${cxx_flags}>)

target_link_libraries(global_cflags INTERFACE
  $<BUILD_INTERFACE:dev_flags>)

# rpath setting
if(UNIX)
  set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
  set(CMAKE_EXE_LINKER_FLAGS -Wl,--disable-new-dtags)
endif()

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
# adding sub directories to the project
add_subdirectory(source)
