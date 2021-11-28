# Geant4Py

[![geant4](https://img.shields.io/badge/geant4-11.0-blue.svg)](http://www.geant4.org/)

Geant4-Python interface.

Formerly c++-python bridge was realized with Boost-Python.
In Geant4 version 11, we migrate to `pybind11` as a Python binding tool
and revise the toolset using pybind11.

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

[pybind11](https://github.com/pybind/pybind11)
is a binding tool between C++ and Python.


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
> We recommend building the Geant4 library without the Qt feature for
> the python binding purpose because the Qt5 system library conflicts with
> the Anaconda version of Qt5.
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
* pybind11 cmake config path [/opt/homebrew/share/cmake/pybind11]

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
│       ├── geant4pyConfig.cmake
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

----
## Tests and Examples

There are two types of user codes in the software.

### Tests
Testing codes are located in the `tests` directory that is built
with cmake build.

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
a user module (`gtest01.so`) is built and installed in the directory.

Each test demonstrates:

**gtest01**
* How to export c++ code fragments to Python
  * `ecalgeom` is described in C++ and exposed to a Python module
* How to use Geant4Py in Python
  * use Geant4 objects
  * define user classes (geometry/physics list/user actions)
  * set up Geant4 application
  * define a magnetic field in Python
  * export geometry to a GDML file

**gtest02**
* tests for creating basic solids
* generate a VRML file for each solid
* You can see VRML files with `veiw3dscene`

**gtest03**
* test for reading GDML file as geometry

### Examples
On the other hand, we provide examples demonstrating
how to create users' modules and run GeantPy in the Jupyter
environment. There are complete examples that are self-documented
and run in Jupyter notebooks.

In the `examples` directory, there are three examples.
~~~~
ls examples
emplot/  exampleB1/  phantom_dose/
~~~~

In each example, there is a Jupyter notebook (`.ipynb`) file.
You can open and run the notebook with Jupyter (lab/notebook).

------
## What You should know before

There are some tips for running Geant4 with Python.

Like C++ Geant4 applications, you need to define some environment variables.

At first, source the geant4 setup file.

~~~~
# source [Geant4 install path]/bin/geant4.sh (bash)
# source [Geant4 install path]/bin/geant4.csh (csh/tcsh)

For zsh, once change directory, then source the file
# cd [Geant4 install path]/bin
# source geant4.sh (zsh)
~~~~


**Geant4 Data**


The environment variables for the Geant4 data locations are defined.

~~~~
# env | grep G4
G4NEUTRONHPDATA=/home/kmura/opt/geant4/data/11.0/G4NDL4.6
G4LEDATA=/home/kmura/opt/geant4/data/11.0/G4EMLOW8.0
G4LEVELGAMMADATA=/home/kmura/opt/geant4/data/11.0/PhotonEvaporation5.7
G4RADIOACTIVEDATA=/home/kmura/opt/geant4/data/11.0/RadioactiveDecay5.6
G4PARTICLEXSDATA=/home/kmura/opt/geant4/data/11.0/G4PARTICLEXS4.0
G4PIIDATA=/home/kmura/opt/geant4/data/11.0/G4PII1.3
G4REALSURFACEDATA=/home/kmura/opt/geant4/data/11.0/RealSurface2.2
G4SAIDXSDATA=/home/kmura/opt/geant4/data/11.0/G4SAIDDATA2.0
G4ABLADATA=/home/kmura/opt/geant4/data/11.0/G4ABLA3.1
G4INCLDATA=/home/kmura/opt/geant4/data/11.0/G4INCL1.0
G4ENSDFSTATEDATA=/home/kmura/opt/geant4/data/11.0/G4ENSDFSTATE2.3
~~~~

**LD_LIBRARY_PATH**

Also, the library location (`LD_LIBRARY_PATH`) is defined.

~~~
# echo $LD_LIBRARY_PATH
/home/kmura/opt/geant4/11.0/lib:/usr/lib/x86_64-linux-gnu
~~~

> In macOS, this environment is not necessary.


**PYTHON_PATH**

Python needs to know where the Geant4Py module is installed.
The location can be specified with `PYTHON_PATH`.

~~~
# export PYTHONPATH=~/opt/geant4/geant4py-11.0.0/site-packages (bash/zsh)
# setenv PYTHONPATH ~/opt/geant4/geant4py-11.0.0/site-packages (csh/tcsh)
~~~

There are some additional settings for a specific environment.

**LD_PRELOAD** (Linux)

For TLS memory allocation, currently, we have to preload a Geant4 library
in the Linux environment.
~~~
# export LD_PRELOAD=libG4run.so (bash/zsh)
# setenv LD_PRELOAD libG4run.so (csh/tcsh)
~~~

> In macOS, this is not necessary.


**G4PY_QT5_PRELOAD** (Anaconda, Qt5)

If you use the Anaconda version of Ptyhon3, there might be a conflict
between the Qt5 libraries. When Geant4Py detects the conflict,
it shows the following warning message.

~~~~
#####################################################################
!!! Warning !!!
A non-system python (e.g., Anaconda version of Python) is detected.
If you have a problem with Qt5 library version,
set the environment variables, "G4PY_QT5_PRELOAD = 1"
to preload the system Qt5 library as a temporal solution.
Please consider installing a Geant4 library for Geant4Py
without the Qt feature.
#####################################################################
~~~~

To avoid the conflict, Geant4Py will preload the system Qt5
when this environment variable is set.
~~~
# export G4PY_QT5_PRELOAD=1 (bash/zsh)
# setenv G4PY_QT5_PRELOAD 1 (csh/tcsh)
~~~

> This is a temporal solution. We recommend building Geant4 without
> the Qt5 feature to avoid conflict.


### Multi-threading feature
In the current version of Geant4Py, we limit Geant4 in sequential mode
forcibly by setting `G4FORCE_RUN_MANAGER_TYPE` inside `__init__.py`
script. In the future release, we can lift this limit hopefully.

----
## How to run Geant4 on Python

You have several ways of running Python. If you install Anaconda,
you can run several variants of Python instances.
We recommend an Anaconda version of Python3/Ipython3/Jupyter.

* System Python3
* Anaconda Python3 and virtual env versions
* Ipython frontend
* Jupyter (Jupyter-notebook / Jupyter-lab)

### Importing geant4

`Geant4Py` is loaded with importing the *`geant4`* module. You can see
what is defined in the module with `help` command.

~~~
# python3
Python 3.8.8 (default, Apr 13 2021, 19:58:26)
[GCC 7.3.0] :: Anaconda, Inc. on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> import geant4
=============================================================
  _____              __  ____ ___
 / ___/__ ___ ____  / /_/ / // _ \__ __  Geant4-Python Interface
/ (_ / -_) _ `/ _ \/ __/_  _/ ___/ // /  Version: 1100
\___/\__/\_,_/_//_/\__/ /_//_/   \_, /   Date: (31-October-2021)
                                /___/
=============================================================

Environment variable "G4FORCE_RUN_MANAGER_TYPE" enabled with value == Serial. Forcing G4RunManager type...


          ################################
          !!! G4Backtrace is activated !!!
          ################################


**************************************************************
 Geant4 version Name: geant4-10-07-ref-09 [MT]   (31-October-2021)
                       Copyright : Geant4 Collaboration
                      References : NIM A 506 (2003), 250-303
                                 : IEEE-TNS 53 (2006), 270-278
                                 : NIM A 835 (2016), 186-225
                             WWW : http://geant4.org/
**************************************************************

Visualization Manager instantiating with verbosity "warnings (3)"...
>>> help(geant4)
Help on package geant4:

NAME
    geant4

DESCRIPTION
    # ==================================================================
    #  [geant4] module package
    # ==================================================================

PACKAGE CONTENTS
    G4digits_hits
    G4event
    G4gdml
    G4geometry
    G4global
    G4graphics_reps
    G4intercoms
    G4interface
    G4materials
    G4particles
    G4physicslists
    G4processes
    G4run
    G4track
    G4tracking
    G4visualization
    hepunit
    utils (package)

FUNCTIONS
    ApplyUICommand(...) method of builtins.PyCapsule instance
        ApplyUICommand(arg0: geant4.G4global.G4String) -> G4UIcommandStatus
...
~~~

### gtest01

Change the working directory to the build location after
build and install Geant4Py.

~~~
# cd build
# make install

.... (build and install Geant4Py)

# cd build/tests/gtest01
# ls
__pycache__/  cmake_install.cmake  Makefile   vis.mac
CMakeFiles/   gtest01.so*          tests.py*  write_gdml.py*
~~~

`gtest01.so` is a user module that includes user geometry definition
described in C++.

You can run the python script directly. The Geant4 application
is set up and run the simulation. If visualization is activated,
you can see the event display in an OpenGL window.
~~~
# ./tests.py

=============================================================
  _____              __  ____ ___
 / ___/__ ___ ____  / /_/ / // _ \__ __  Geant4-Python Interface
/ (_ / -_) _ `/ _ \/ __/_  _/ ___/ // /  Version: 1100
\___/\__/\_,_/_//_/\__/ /_//_/   \_, /   Date: (31-October-2021)
                                /___/
=============================================================

Environment variable "G4FORCE_RUN_MANAGER_TYPE" enabled with value == Serial. Forcing G4RunManager type...

...

*** (BRA) #event to be processed =  100
*** (EEA) events processed = 0
*** (ERA) run ID =  0
~~~~

Alternatively, you can run the script in Python frontends.
~~~
# python3
Python 3.8.8 (default, Apr 13 2021, 19:58:26)
[GCC 7.3.0] :: Anaconda, Inc. on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> import tests

=============================================================
  _____              __  ____ ___
 / ___/__ ___ ____  / /_/ / // _ \__ __  Geant4-Python Interface
/ (_ / -_) _ `/ _ \/ __/_  _/ ___/ // /  Version: 1100
\___/\__/\_,_/_//_/\__/ /_//_/   \_, /   Date: (31-October-2021)
                                /___/
=============================================================

Environment variable "G4FORCE_RUN_MANAGER_TYPE" enabled with value == Serial. Forcing G4RunManager type...


          ################################
          !!! G4Backtrace is activated !!!
          ################################


**************************************************************
 Geant4 version Name: geant4-10-07-ref-09 [MT]   (31-October-2021)
                       Copyright : Geant4 Collaboration
                      References : NIM A 506 (2003), 250-303
                                 : IEEE-TNS 53 (2006), 270-278
                                 : NIM A 835 (2016), 186-225
                             WWW : http://geant4.org/
**************************************************************

Visualization Manager instantiating with verbosity "warnings (3)"...

>>> tests.main()

...  (run the simulation)

*** (BRA) #event to be processed =  100
*** (EEA) events processed = 0
*** (ERA) run ID =  0
~~~

Also, you can run with Ipython that has rich features.

~~~~
# ipython3
Python 3.8.8 (default, Apr 13 2021, 19:58:26)
Type 'copyright', 'credits' or 'license' for more information
IPython 7.22.0 -- An enhanced Interactive Python. Type '?' for help.

In [1]: %run tets.py

...  (run the simulation)

*** (BRA) #event to be processed =  100
*** (EEA) events processed = 0
*** (ERA) run ID =  0
~~~~

> !!! Tips !!!
>
> You can use the Geant4 UI terminal with `StartUIsession()` function
> from the Python frontend. You can isssue Geant4 UI comands
> in the UI terminal. After exiting the terminal session, you return
> to the Python. Note that this terminal is NOT available in
> Jupyter.

~~~~
In [3]: StartUISession()
geant4(Idle)[/]:ls
Command directory path : /
 Sub-directories :
   /control/   UI control commands.
   /units/   Available units.
   /profiler/   Profiler controls.
   /particle/   Particle control commands.
   /tracking/   TrackingManager and SteppingManager control commands.
   /geometry/   Geometry control commands.
   /process/   Process Table control commands.
   /event/   EventManager control commands.
   /cuts/   Commands for G4VUserPhysicsList.
   /run/   Run control commands.
   /random/   Random number status control commands.
   /material/   Commands for materials
   /score/   Interactive scoring commands.
   /vis/   Visualization commands.
   /physics_lists/   commands related to the physics simulation engine.
   /gun/   Particle Gun control commands.
   /physics_engine/   ...Title not available...
 Commands :
geant4(Idle)[/]:
~~~~

-----
## Examples/exampleB1
This example has the same capability as Geant4 basic example B1.
The geometry is implemented in C++ and exported to a Python module.

~~~
# cd examples/exampleB1
# ls
geomB1/  CMakeLists.txt  exampleB1.ipynb
# ls geomB1
DetectorConstruction.cc  DetectorConstruction.hh  pygeomB1.cc
~~~

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
it automatically connects the session on your browser.

[Jupyter notebook for exampleB1](https://github.com/koichi-murakami/g4python/blob/79522962dd772c93778d46668c7b532d3d8bfc21/examples/exampleB1/exampleB1.ipynb)


## Examples/phantom_dose
This example shows a more practical application.
It contains a complete chain of simulation and analysis processes.
In the example, we calculate dose distributions in a water phantom
for electron and proton beams.
Voxel doses are scored with Geant4 command-line scoring capability
and stored into CSV files. Then, this data is analyzed with Pandas
and Matplotlib Python tools.
Finally, dose maps and depth dose curves are obtained.

> In this example, there are no user modules. We use only installed
> modules.

[Jupyter notebook for phantom_dose](https://github.com/koichi-murakami/g4python/blob/a41b5a86644aac08dd92c0f689bfd277a0ae6105/examples/phantom_dose/phantomdose.ipynb)

You can see that we use some extra `utils` module components.

~~~
from geant4 import *
from geant4.utils import WaterPhantom
from geant4.utils import MedicalBeam
from geant4.utils import EventCounter
~~~

These modules are provided as utility modules that should be loaded on demand.
* WaterPhantom: Water phantom geometry
* MedicalBeam: Primary generator with medical beam profile (SSD/beam shaping)
* EventCount: Event content event action

----
## Tips

### Global variables and functions

In Geant4Py, we instantiate Geant4 singleton manager objects
(e.g., `G4RunManager`) at the timing of module loading.
These instances are assigned to global variables inside Python,
that starts with *g* character.

For example,
* RunManger : `gRunManager`
* EventManager : `gEventManager`
* NistManager : `gNistManager`
* ScoringManager : `gScoringManager`

Also, some useful methods are defined as global functions.

* `gStartUISession`, `StartUISession` : Start UI terminal
* `gControlExecute`, `ControlExecute` : Execute a macro file
* `gApplyUICommand`, `ApplyUICommand` : Execute UI command
* `gGetCurrentValue`, `GetCurrentValue` : Get current value of UI command

### Python objects
Python variables are automatically managed, which means
a local variable is automatically deleted on the Python side.
This mechanism is different from objects allocated in C++.
Some classes are taken care as `nodeleted` objects in Geant4Py,
but still not perfect. If there is a weird behavior (seg. fault),
set the Python variable as `global`.

> !!! Note !!!
>
>  An object of user inherited class in Python should be set as global.
