"""
# ==================================================================
#  [geant4] module package
# ==================================================================
"""
# ------------------------------------------------------------------
# check Qt5 shared library (for Anaconda Python)
# ------------------------------------------------------------------
import os
import ctypes
from ctypes.util import find_library

_qt5_prefix_ubuntu = "/lib/x86_64-linux-gnu/"
_qt5_prefix_rh = "/usr/lib64/"

_qt5_prefix = ""
if os.path.exists(_qt5_prefix_ubuntu+"libQt5Core.so"):
    _qt5_prefix = _qt5_prefix_ubuntu
elif os.path.exists(_qt5_prefix_rh+"libQt5Core.so"):
    _qt5_prefix = _qt5_prefix_rh

_qt5core_lib = find_library("Qt5Core")

if _qt5core_lib != None and not _qt5core_lib.startswith("libQt5Core.so"):
    print("""
#####################################################################
!!! Warning !!!
A non-system python (e.g. Anaconda version of Python) is detected.
If you have a problem with Qt5 library version,
set the environment variables, "G4PY_QT5_PRELOAD = 1"
to preload the system Qt5 library as a temporal solution.
Please consider to install Geant4 library without the Qt feature.
#####################################################################
""")
    if ( os.getenv('G4PY_QT5_PRELOAD') != None ):
      ctypes.cdll.LoadLibrary(_qt5_prefix + "libQt5Core.so")
      ctypes.cdll.LoadLibrary(_qt5_prefix + "libQt5Gui.so")
      ctypes.cdll.LoadLibrary(_qt5_prefix + "libQt5Widgets.so")
      ctypes.cdll.LoadLibrary(_qt5_prefix + "libQt5OpenGL.so")

# ==========================================================================
# force sequential mode
os.environ['G4FORCE_RUN_MANAGER_TYPE'] = 'Serial'

# import submodules
from .G4global import *
from .G4interface import *
from .G4intercoms import *
from .G4run import *
from .G4event import *
from .G4tracking import *
from .G4track import *
from .G4geometry import *
from .G4materials import *
from .G4digits_hits import *
from .G4particles import *
from .G4processes import *
from .G4physicslists import *
from .G4visualization import *
from .G4gdml import *
from .G4graphics_reps import *
from .hepunit import *

def print_version():
    print("""=============================================================
  _____              __  ____ ___
 / ___/__ ___ ____  / /_/ / // _ \__ __  Geant4-Python Interface
/ (_ / -_) _ `/ _ \/ __/_  _/ ___/ // /  Version: %s
\___/\__/\_,_/_//_/\__/ /_//_/   \_, /   Date: %s
                                /___/
=============================================================
""" % ( G4VERSION_NUMBER, G4Date) )

# ==================================================================
# initialize module
# ==================================================================
print_version()

# set G4cout/G4cerr to Python stdout
SetG4PyCoutDestination()

# ==================================================================
# globals, which start with "g"
# ==================================================================
# gUImanager
gUImanager = G4UImanager.GetUIpointer()

# create RunManager
CreateRunManager()

# gRunManager
gRunManager = G4RunManager.GetRunManager()

# gEventManager
gEventManager = G4EventManager.GetEventManager()

# gStackManager
gStackManager = gEventManager.GetStackManager()

# gTrackingManager
gTrackingManager = gEventManager.GetTrackingManager()

# gStateManager
gStateManager = G4StateManager.GetStateManager()
gExceptionHandler = G4ExceptionHandler() # automatically registered

# gGeometryManager
gGeometryManager = G4GeometryManager.GetInstance()

# gTransportationManager
gTransportationManager = G4TransportationManager.GetTransportationManager()

# gParticleTable
gParticleTable = G4ParticleTable.GetParticleTable()
gIonTable = gParticleTable.GetIonTable()

# gProcessTable
gProcessTable = G4ProcessTable.GetProcessTable()

# gProductionCutsTable
gProductionCutsTable = G4ProductionCutsTable.GetProductionCutsTable()

# gEmCalculator
gEmCalculator = G4EmCalculator()

# gMaterial/ElementTable
gMaterialTable = G4Material.GetMaterialTable()
gElementTable = G4Element.GetElementTable()
gIsotopeTable = G4Isotope.GetIsotopeTable()

# gNistManager
gNistManager = G4NistManager.Instance()

# gScoringManager
gScoringManager = G4ScoringManager.GetScoringManager()

# gVisManager
_visdriver_list = dir(G4visualization)
_q_opengl_ix = "G4OpenGLImmediateX" in _visdriver_list
_q_opengl_sx = "G4OpenGLStoredX" in _visdriver_list

if G4VisManager.GetConcreteInstance() == None:
    gVisManager = G4VisManager()

    if _q_opengl_ix:
        _opengl_ix = G4OpenGLImmediateX()
    if _q_opengl_sx:
        _opengl_sx = G4OpenGLStoredX()
        _opengl_sx.AddNickname("OGL")

_vrml2     = G4VRML2File()
_dawn      = G4DAWNFILE()
_atree     = G4ASCIITree()
_raytracer = G4RayTracer()
_gmocren   = G4GMocrenFile()

if _q_opengl_ix:
    gVisManager.RegisterGraphicsSystem(_opengl_ix)
if _q_opengl_sx:
    gVisManager.RegisterGraphicsSystem(_opengl_sx)

gVisManager.RegisterGraphicsSystem(_vrml2)
gVisManager.RegisterGraphicsSystem(_dawn)
gVisManager.RegisterGraphicsSystem(_atree)
gVisManager.RegisterGraphicsSystem(_raytracer)
gVisManager.RegisterGraphicsSystem(_gmocren)

gVisManager.Initialize()

# set random engine to MTwister
rnd_engine_mt = MTwistEngine()
HepRandom.setTheEngine(rnd_engine_mt)

# ------------------------------------------------------------------
# functions
# ------------------------------------------------------------------
gStartUISession = G4interface.StartUISession
StartUISession = gStartUISession

gControlExecute = gUImanager.ExecuteMacroFile
ControlExecute = gControlExecute

gApplyUICommand = G4intercoms.ApplyUICommand
ApplyUICommand = gApplyUICommand

gGetCurrentValues = gUImanager.GetCurrentValues
GetCurrentValues = gGetCurrentValues

# ==================================================================
# extentions
# ==================================================================
# ------------------------------------------------------------------
# reset cout destination when exit
# ------------------------------------------------------------------
import atexit

def ResetCoutDestination():
    gGeometryManager.OpenGeometry()
    ResetG4PyCoutDestination()

atexit.register(ResetCoutDestination)

# ------------------------------------------------------------------
# generate one event
# ------------------------------------------------------------------
def _one_event(self):
    self.BeamOn(1)

G4RunManager.OneEvent = _one_event

# ------------------------------------------------------------------
# list material information
# ------------------------------------------------------------------
def _list_material(self):
    n_materials = len(gMaterialTable)
    print("Table of G4Material-s (%d materails defined)" % (n_materials))
    for i in range(0, n_materials) :
        material = gMaterialTable[i]
        print("* %s: %s" % (material.GetName(),
        G4BestUnit(material.GetDensity(),"Volumic Mass")))

    elementVec   = material.GetElementVector()
    fractionVec  = material.GetFractionVector()
    abundanceVec = material.GetVecNbOfAtomsPerVolume()
    totNAtoms    = material.GetTotNbOfAtomsPerVolume()

    n_elements = len(elementVec)
    for j in range(0, n_elements):
        print(" + (%1d) %s(%s): A=%4.1f, N=%5.1f, " \
              "Frac.=(%4.1f%%m,%4.1f%%a)" % \
              (j+1, elementVec[j].GetName(), elementVec[j].GetSymbol(),
             elementVec[j].GetZ(),
             elementVec[j].GetN(),
             fractionVec[j]/hepunit.perCent,
             abundanceVec[j]/totNAtoms/hepunit.perCent))

G4MaterialTable.ListMaterial = _list_material

# ------------------------------------------------------------------
# signal handler
# ------------------------------------------------------------------
import signal

def _run_abort(signum, frame):
    state = gStateManager.GetCurrentState()

    if( state == G4ApplicationState.G4State_GeomClosed or
        state == G4ApplicationState.G4State_EventProc ):
       print("aborting Run ...")
       gRunManager.AbortRun(True)
    else:
      raise KeyboardInterrupt

signal.signal(signal.SIGINT, _run_abort)
