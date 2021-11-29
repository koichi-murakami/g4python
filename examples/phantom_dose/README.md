# phantom_dose

## Introductuon

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


## Simulation setup

* Geometry : WaterPhantom (Python module)
* Primary Particle : MedicalBeam (Python module)
* Physics List : FTFP_BERT (Python module)
* EvenAction : EventCounter (Python module)

A water phantom is located in the center of the world volume.
The phantom size can be changed.

The medical beam is a point source beam of electron/gamma/proton.
There are some beam properties of SSD (source surface distance) and
field size at the phantom surface.

The event counter is a utility event action. It shows event counter
information at every check point.

These modules can be loaded as extra `utils` module components.

~~~
from geant4 import *
from geant4.utils import WaterPhantom
from geant4.utils import MedicalBeam
from geant4.utils import EventCounter
~~~

These modules are provided as utility modules that should be loaded on demand.
* WaterPhantom: Water phantom geometry
* MedicalBeam: Primary generator with medical beam profile (SSD/beam shaping)
* EventCount: Event counter in event action

## Scoring
In the example, we calculate dose distributions in a water phantom
for electron and proton beams.
Voxel doses are scored with Geant4 command-line scoring capability
and stored into CSV files.
The UI-commands for scoring are defined in `scoring.mac` geant4 macro file.


## Analysis
We analyze this CSV output with Pandas and Matplotlib Python tools.
Finally, we can obtain dose maps and depth dose curves.

[Jupyter notebook for phantom_dose](https://github.com/koichi-murakami/g4python/blob/main/examples/phantom_dose/phantomdose.ipynb)
