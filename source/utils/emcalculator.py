"""
# ==================================================================
#  [emcalculator] submodule
# ==================================================================
"""
from .. import *

# ==================================================================
# public symbols
# ==================================================================
__all__ = [ 'CalculatePhotonCrossSection', 'CalculateDEDX' ]

# ==================================================================
# Photon Cross Section
# ==================================================================
def CalculatePhotonCrossSection(material_name=None, Elist=None, verbose=0):
    """
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
  value = xsec_list[energy_index]["compt"]"""

    if material_name == None:
        raise RuntimeError("!!! material name is not specified.")

    if Elist == None :
        elist = []

    if verbose > 0 :
        print("-------------------------------------------------------------------")
        print("                  Photon Cross Section (", material_name, ")")
        print("Energy      Compton     Raleigh     Photo-      Pair        Total")
        print("            Scattering  Scattering  electric    Creation")
        print("(MeV)       (cm2/g)     (cm2/g)     (cm2/g)     (cm2/g)     (cm2/g)")
        print("-------------------------------------------------------------------")

    xsection_list = []

    for ekin in Elist:
        xsec = {}
        xsec["compt"] = gEmCalculator.ComputeCrossSectionPerVolume(
                        ekin, "gamma", "compt", material_name) * cm2/g

        xsec["rayleigh"] = gEmCalculator.ComputeCrossSectionPerVolume(
                           ekin, "gamma", "rayleigh", material_name) * cm2/g

        xsec["phot"] = gEmCalculator.ComputeCrossSectionPerVolume(
                       ekin, "gamma", "phot", material_name) * cm2/g

        xsec["conv"] = gEmCalculator.ComputeCrossSectionPerVolume(
                       ekin, "gamma", "conv", material_name) * cm2/g

        xsec["tot"] = xsec["compt"] + xsec["rayleigh"] + xsec["phot"] + xsec["conv"]

        xsection_list.append((ekin, xsec))

        if verbose > 0 :
            print(" %8.3e   %8.3e   %8.3e   %8.3e   %8.3e   %8.3e" \
               % (ekin/MeV, xsec["compt"]/(cm2/g), xsec["rayleigh"]/(cm2/g),
                  xsec["phot"]/(cm2/g), xsec["conv"]/(cm2/g), xsec["tot"]/(cm2/g)))

    return xsection_list


# ==================================================================
# Stopping Power
# ==================================================================
def CalculateDEDX(particle_name=None, material_name=None,
                  Elist=None, verbose=0):
    """
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
  value = dedx_list[energy_index]["ioni"]"""

    if particle_name == None :
        raise RuntimeError("!!! partice neme is not specifed.")

    if material_name == None :
        raise RuntimeError("!!! material neme is not specifed.")

    if Elist == None :
        Elist = []

    if verbose > 0 :
        print("------------------------------------------------------")
        print("       Stopping Power (", particle_name, ",", material_name, ")")
        print("  Energy       Ionization    Radiation     Total")
        print("  (MeV)        (MeVcm2/g)    (MeVcm2/g)    (MeVcm2/g)")
        print("------------------------------------------------------")

    procname_brems = ""
    procname_ioni = ""

    if particle_name == "e+" or particle_name == "e-" :
        procname_ioni = "eIoni"
        procname_brems = "eBrem"

    elif particle_name == "mu+" or particle_name == "mu-" :
        procname_ioni = "muIoni"
        procname_brems = "muBrems"

    elif particle_name == "proton" or particle_name == "deutron" or \
         particle_name == "triton" :
        procname_ioni = "hIoni"
        procname_brems = ""

    elif particle_name == "alpha" or particle_name == "He3" or \
         particle_name == "GenericIon" :
        procname_ioni = "ionIoni"
        procname_brems = ""
    else :
        raise RuntimeError("!!! particle name is not supported.")

    dedx_list = []

    for ekin in Elist:
        dedx = {}
        dedx["ioni"] = gEmCalculator.ComputeDEDX(
                       ekin, particle_name, procname_ioni, material_name) * MeV*cm2/g

        dedx["brems"] = gEmCalculator.ComputeDEDX(
                        ekin, particle_name, procname_brems, material_name) * MeV*cm2/g

        dedx["tot"] = dedx["ioni"] + dedx["brems"]

        if verbose > 0 :
            print(" %8.3e     %8.3e     %8.3e     %8.3e" \
               % (ekin/MeV, dedx["ioni"]/(MeV*cm2/g),
                  dedx["brems"]/(MeV*cm2/g), dedx["tot"]/(MeV*cm2/g) ))

        dedx_list.append((ekin, dedx))

    return dedx_list
