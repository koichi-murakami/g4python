#==============================================================================
# CMake configuration for Geant4-Python
#
# NOTE:
# CACHE variables can be changed in CMake CLI with -D option.
#==============================================================================
# Installation prefixes
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX $ENV{HOME}/opt/geant4/pymodules CACHE
      PATH "Install prefix" FORCE)
endif()

# Geant4 installation path
set(GEANT4_INSTALL $ENV{HOME}/opt/geant4/11.0
    CACHE STRING "Geant4 installation path")

# Python header file location
set(PYTHON_INCLUDE_DIR /usr/include/python3.8
    CACHE STRING "Python include path")

# Pybind11 header files location (pybind11)
set(PYBIND11_INCLUDE_DIR /usr/include
    CACHE STRING "Pybind11 include path")

#set(PYBIND11_INCLUDE_DIR /opt
#    CACHE STRING "Pybind11 include path")
