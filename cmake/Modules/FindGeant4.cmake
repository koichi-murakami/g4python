# - Find Geant4 library
# This module sets up Geant4 information
# It defines:
# GEANT4_FOUND               If the Geant4 is found
# GEANT4_INCLUDE_DIR         PATH to the include directory
# GEANT4_LIBRARY_DIR         PATH to the library directory
# GEANT4_LIBRARIES           Most common libraries
# GEANT4_LIBRARIES_WITH_VIS  Most common libraries with visualization
# GEANT4_VIS                 Availabiliy of Vis package (bool)

find_program(GEANT4_CONFIG NAMES geant4-config
             PATHS ${GEANT4_INSTALL}/bin
                   /usr/local/bin /opt/local/bin)

if(GEANT4_CONFIG)
  set(GEANT4_FOUND TRUE)

  execute_process(COMMAND ${GEANT4_CONFIG} --prefix
                  OUTPUT_VARIABLE GEANT4_PREFIX
                  OUTPUT_STRIP_TRAILING_WHITESPACE)
  execute_process(COMMAND ${GEANT4_CONFIG} --version
                  OUTPUT_VARIABLE GEANT4_VERSION
                  OUTPUT_STRIP_TRAILING_WHITESPACE)
  execute_process(COMMAND ${GEANT4_CONFIG} --has-feature opengl-x11
                  OUTPUT_VARIABLE _GEANT4_VIS_YES_OR_NO
                  OUTPUT_STRIP_TRAILING_WHITESPACE)

  if ( ${_GEANT4_VIS_YES_OR_NO} MATCHES "yes" )
    set(GEANT4_VIS true)
  else()
    set(GEANT4_VIS false)
  endif()

  message(STATUS "Found Geant4: ${GEANT4_PREFIX} (${GEANT4_VERSION})")
  message(STATUS "Geant4 Visualization: ${GEANT4_VIS}")

else()
  set(GEANT4_FOUND FALSE)
  if (Geant4_FIND_REQUIRED)
    message(FATAL_ERROR "NOT Found Geant4: set GEANT4_INSTALL.")
  else()
    #message(WARNING "NOT Found Geant4: set GEANT4_INSTALL.")
  endif()

endif()

set(GEANT4_INCLUDE_DIR ${GEANT4_PREFIX}/include/Geant4)
set(GEANT4_LIBRARY_DIR ${GEANT4_PREFIX}/${_LIBDIR_DEFAULT})
set(GEANT4_LIBRARIES  G4interfaces G4persistency G4analysis
                      G4error_propagation G4readout G4physicslists
                      G4tasking G4run G4event G4tracking G4parmodels
                      G4processes G4digits_hits G4track G4particles
                      G4geometry G4materials G4graphics_reps G4intercoms
                      G4global G4ptl G4clhep G4zlib)

set(GEANT4_LIBRARIES_WITH_VIS
                      G4OpenGL G4gl2ps G4Tree G4FR G4GMocren G4visHepRep
                      G4RayTracer G4VRML G4vis_management G4modeling
                      G4interfaces G4persistency G4analysis
                      G4error_propagation G4readout G4physicslists
                      G4tasking G4run G4event G4tracking G4parmodels
                      G4processes G4digits_hits G4track G4particles
                      G4geometry G4materials G4graphics_reps G4intercoms
                      G4global G4ptl G4clhep G4zlib)
