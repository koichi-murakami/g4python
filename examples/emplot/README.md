# emplot

## Introductuon

This example shows how to retrieve the photon cross-sections and stopping
powers of charged particles. It prepares a simple Geant4 mockup,
then changes the target materials. The EM calculator can calculate
a cross-section for each process and stopping powers. For stopping power,
the ionization and bremsstrahlung components can be calculated for electrons.
The example includes plots by Matplotlib.


## Simulation setup

The simulation setup is the so-called "Mock-up", a kind of dummy setup.
To activae Geant4 physics, we need to set up Geant4 mandates.
Geometry should contain material for the target for the calculation.
We can change the material for the simple box.


* Geometry : SimpleBox (Python module)
* Primary Particle : ParticleGun (Python module)
* Physics List : FTFP_BERT (Python module)

Used modules:
* geant4.utils.SimpleBox
* geant4.utils.ParticleGun
* geant4.utils.emcalculator

## EM calculator
After initializing Geant4, we can use the EM calculator.
The wrapper of the original `G4EmCalculator` is used in the example.

There are two functions defined in the module.

* CalculatePhotonCrossSection : Calculate phton cross secions
* CalculateDEDX : Calculate stopping powers for changed particles

~~~~
>>> help(emcalculator.CalculatePhotonCrossSection)
Help on function CalculatePhotonCrossSection in module geant4.utils.emcalculator:

CalculatePhotonCrossSection(material_name=None, Elist=None, verbose=0)
    Calculate photon cross section for a given material and
    a list of energy, returing a list of cross sections for
    the components of "Copmton scattering", "rayleigh scattering",
    "photoelectric effect", "pair creation" and total one.

    Arguments:
      material_name:  material name (String)
      Elist:          energy list [None]
      verbose:        verbose level [0]

    Keys of index:
      "compt":     Compton Scattering
      "rayleigh":  Rayleigh Scattering
      "phot" :     photoelectric effect
      "conv" :     pair Creation
      "tot"  :     total

    Example:
      xsec_list = CalculatePhotonCrossSection(...)
      value = xsec_list[energy_index]["compt"]
~~~~

~~~~
>>> help(emcalculator.CalculateDEDX)
Help on function CalculateDEDX in module geant4.utils.emcalculator:

CalculateDEDX(particle_name=None, material_name=None, Elist=None, verbose=0)
    Calculate stopping powers for a give particle, material and
    a list of energy, returing stopping power for the components of
    "Ionization", "Radiation" and total one.

    Arguments:
      particle_name:   particle name
      materia_name:    material name
      Elist:           list of energy
      verbose:         verbose level [0]

    Keys of index:
      "ioni":   ionization
      "brems":  Bremsstrahlung
      "tot":    total

    Example:
      dedx_list = CalculateDEDX(...)
      value = dedx_list[energy_index]["ioni"]
~~~~


> You can use the methods defined in `G4EmCalculator` directly.


## Analysis
We obtain the plots for these data using Matplotlib.
This example shows photon cross-sections of gold and stopping powers of
electron and proton for water target.

[Jupyter notebook for emplot](https://github.com/koichi-murakami/g4python/blob/main/examples/emplot/emplot.ipynb)
