# exampleB1

## Introducton

This example has the same capability as Geant4 basic example B1.
The geometry is implemented in C++ and exported to a Python module,
which shows how to export your C++ component to Python.

~~~
# cd examples/exampleB1
# ls
geomB1/  CMakeLists.txt  exampleB1.ipynb
# ls geomB1
DetectorConstruction.cc  DetectorConstruction.hh  pygeomB1.cc
~~~

## Simulation setup

* Geometry : examleB1 (C++ implemenation)
* Primary Particle : ParticleGun (Python module)
* Physics List : QBBC (Python module)

## How to Run

Before running the example, you should build the module.
We provide `CMakeLists.txt` for building a user module.
In this cmake file, you have to specify the Geant4Py cmake path
(`geant4py_DIR`) and Geant4 installation path (`GEANT4_INSTALL`).

~~~~
# cat CMakeLists.txt
#==============================================================================
#  CMakeLists.txt for building Geant4Py user modules
#==============================================================================
cmake_minimum_required(VERSION 3.16...3.21)

#==============================================================================
project(geomB1)
#==============================================================================
# Geant4Py cmake path
set(geant4py_DIR $ENV{HOME}/opt/geant4/geant4py-11.0.0/share/cmake)

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
# DONOT Edit the below.
...
~~~~

As usual, make `build` directory and execute `cmake ..` and
`make install`, that creates a Python module (`geomB1`)
in the example directory.

~~~~
# mkdir build
# cd build
# cmake ..
# make install
# cd ..
# ls
build/  geomB1/  CMakeLists.txt  exampleB1.ipynb  geomB1.so
~~~~


Now you are ready to play around on Jupyter.
Launch Jupyter with `jupyter-lab` (`jupyter-notebook`) command,
it automatically connects the session to your browser.
Before launching Jupyter, do not forget to define necessary
environment variables described above.

[Jupyter notebook for exampleB1](https://github.com/koichi-murakami/g4python/blob/main/examples/exampleB1/exampleB1.ipynb)
