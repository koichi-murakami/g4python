"""
# ==================================================================
#  [visualization control panel] module package
# ==================================================================
"""
from .G4intercoms import *

# ------------------------------------------------------------------
# Scene
# ------------------------------------------------------------------
class G4Scene :
    def __init__(self, name, vol="world", copyno=0,
                 event_mode=0, run_mode=1):
        self.name =    name
        self.volume =  vol
        self.copyno =  copyno
        self.mode_eventaction = event_mode  # 0: accumulate / 1: refresh
        self.mode_runaction =   run_mode
        self._mode = ("accumulate", "refresh")

    def create_scene(self):
        ApplyUICommand("/vis/scene/create " + self.name)
        ApplyUICommand("/vis/scene/add/volume %s %d" %
                       (self.volume, self.copyno))
        ApplyUICommand("/vis/scene/add/trajectories")
        self.update_scene()

    def update_scene(self):
        ApplyUICommand("/vis/scene/select " + self.name)
        ApplyUICommand("/vis/sceneHandler/attach")
        ApplyUICommand("/vis/scene/endOfEventAction %s" %
                       (self._mode[self.mode_eventaction]) )
        ApplyUICommand("/vis/scene/endOfRunAction %s" %
                       (self._mode[self.mode_runaction]) )

# ------------------------------------------------------------------
# Visualization Control Panel
# ------------------------------------------------------------------
class VisControlPanel :
    def __init__(self, gsys="OGL"):
        self.gsystem =    gsys
        self.scenelist =  [G4Scene("default")]
        self.viewpoint =  [270., 90.]
        self.selected = 0

        rc = ApplyUICommand("/vis/open " + gsys)
        if rc != 0:
            print("Canot open visualization.")
            return

        self.scenelist[0].create_scene()

        ApplyUICommand("/vis/viewer/set/viewpointThetaPhi %f %f" %
                       (self.viewpoint[0], self.viewpoint[1]) )
        ApplyUICommand("/tracking/storeTrajectory 1")

    def add_scene(self, ascene):
        if type(ascene) is not G4Scene :
            print("!!! scene should be G4Scene.")
            return
        self.scenelist.append(ascene)
        self.selected = len(self.scenelist) - 1

    def add_scene_with_name(self, name):
        if type(name) is not str :
            print("!!! name should be str.")
            return
        new_scene = G4Scene(name)
        self.scenelist.append(new_scene)
        self.selected = len(self.scenelist) - 1
        self.select_scene(self.selected)

    def list_scene(self):
        idx = 0
        for s in self.scenelist :
            flag = '  '
            if idx == self.selected :
                flag = '* '
            print(flag, idx, ':', s.name)
            idx = idx+1

    def select_scene(self, iscene):
        if iscene < 0 or iscene >= len(self.scenelist):
            print("!!! scene out of range.")
            return

        self.selected = iscene
        self.scenelist[iscene].update_scene()

        ApplyUICommand("/vis/viewer/set/viewpointThetaPhi %f %f" %
                       (self.viewpoint[0], self.viewpoint[1]) )
