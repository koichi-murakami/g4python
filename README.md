# Geant4Py

[![geant4](https://img.shields.io/badge/geant4-11.0-blue.svg)](http://www.geant4.org/)

Geant4-Python interface.

Formerly c++-python bridge was realized with Boost-Python.
From Geant4 version 11, we migrate to use `pybind11` as a Python binding tool,
and completely revise the toolset.


## System Requirements

### Tested Platforms

* Ubuntu 20.04 LTS
* AlmaLinux 8 (RH8 clones)
* macOS (Monterey) + Homebrew

### CMake
CMake(3.16+) is used for building the tool.

### Python3

* Python 3.6+
* Anaconda Python3 (2021.05)

### pybind11

`pybind11` is a binding tool between C++ and Python.

https://github.com/pybind/pybind11

You can install `pybind11` with system packaging tools
(e.g. apt, dnf, Homebrew).

Ubuntu (apt)
~~~~
# sudo apt install pybind11-dev
~~~~

AlmaLinux 8 / RH8 (dnf)
~~~~
# sudo dnf install pybind11-dev
~~~~

macOS
~~~~
# brew install pybind11
~~~~

### Geant4
Install Geant4 library in a normal way. Here assume the following installation
directory.

~~~~
# cd $HOME/opt/geant4/11.0
# ls
bin/  include/  lib/  share/
~~~~

> !!! Warning !!!
>
> We recommend building the Geant4 library without the Qt feature,
> because the Qt5 system library conflicts with the Anaconda version of Qt5.
> See below for the mitigation of the library conflict.

----
## How to Install

There is a CMake configuration file (`config.cmake`)
for setting user environment.
You should set proper settings here.

~~~~
# cat config.cmake
#==============================================================================
# CMake configuration for Geant4-Python
#
# NOTE:
# CACHE variables can be changed in CMake CLI with -D option.
#==============================================================================
# Installation prefixes
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX $ENV{HOME}/opt/geant4/geant4py-11.0.0
  CACHE PATH "Install prefix" FORCE)
endif()

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
~~~~

Here you can set
* Geant4Py installation directory [$HOME/opt/geant4/geant4py-11.0.0]
* Geant4 installation path [$HOME/opt/geant4/11.0]
* Pybind11 cmake config path [/opt/homebrew/share/cmake/pybind11]

> In the config file, we set the pybind11 path to the default
> installation path of Homebrew in macOS.
> We assume `pybind11` is installed in the system directory
> for Linux systems. So it works both on Linux and macOS.
> If you use your own installed pybind11, set the installation path here.

> !!! Warning !!!
>
> Basically, you don't need to modify `CMakeLists.txt`.
> System configurations are described inside the file. Do not edit it.

As a normal CMake building process, build `Geant4Py`
in a temporal working directory (`build`).

~~~~
# mkdir build
# cd build
# cmake ..
# make
# make install
~~~~

> !!! Notes !!!
>
> CMake automatically detect `GDML` and `OpenGL` features
> that the using Geant4 library has or not.


`Geant4Py` is installed in `$HOME/opt/geant4/geant4py-11.0.0`.
In this case,`$HOME/opt/geant4/geant4py-11.0.0/site-packages`
is needed for `PYTHONPATH` environment variable as Python module import path.

~~~~
# tree geant4py-11.0.0
geant4py-11.0.0
├── share
│   └── cmake
│       ├── Geant4Config.cmake
│       └── geant4pyCommon.cmake
└── site-packages
    └── geant4
        ├── G4digits_hits.so
        ├── G4event.so
        ├── G4gdml.so
        ├── G4geometry.so
        ├── G4global.so
        ├── G4graphics_reps.so
        ├── G4intercoms.so
        ├── G4interface.so
        ├── G4materials.so
        ├── G4particles.so
        ├── G4physicslists.so
        ├── G4processes.so
        ├── G4run.so
        ├── G4tracking.so
        ├── G4track.so
        ├── G4visualization.so
        ├── hepunit.py
        ├── __init__.py
        ├── __pycache__
        │   ├── hepunit.cpython-38.pyc
        │   └── __init__.cpython-38.pyc
        └── utils
            ├── colortable.py
            ├── emcalculator.py
            ├── G4utils.so
            ├── g4viscp.py
            ├── __init__.py
            └── __pycache__
                ├── colortable.cpython-38.pyc
                ├── emcalculator.cpython-38.pyc
                ├── g4viscp.cpython-38.pyc
                └── __init__.cpython-38.pyc
~~~~

## How to Use:

There are two types of tests and examples in the software.

There are testing codes in the `tests` directory that are build
with cmake installation build.

~~~~
# ls tests
gtest01/  gtest02/  gtest03/
~~~~

You can play with them in the build directory.
~~~~
# cd build/tests/gtest01
# ls
__pycache__/  cmake_install.cmake  Makefile   vis.mac
CMakeFiles/   gtest01.so*          tests.py*  write_gdml.py*
~~~~

Here, Python testing scripts are copied from the original and
a user module (`gtest01.so`) is built in the same directory.

Each test demonstrates:

**gtest01**
* How to export c++ code fragments to Python
* How to use Geant4Py in Python
  * use Geant4 objects
  * define user classes (geometry/physics list/user actions)
  * set up Geant4 application
  * define magnetic field in Python
  * export geometry to a GDML file
