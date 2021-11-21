# - build module
#------------------------------------------------------------------------------
set(MODULE pyG4particles)
#------------------------------------------------------------------------------
add_library(${MODULE} SHARED)

target_sources(${MODULE} PRIVATE
  pyG4DynamicParticle.cc
  pyG4ParticleDefinition.cc
  pyG4IonTable.cc
  pyG4ParticleTable.cc
  pyG4PrimaryParticle.cc
  pyG4PrimaryVertex.cc
  pymodG4particles.cc
)

target_include_directories(${MODULE} PRIVATE
  ${GEANT4_INCLUDE_DIR}
  ${Python3_INCLUDE_DIRS}
  ${pybind11_INCLUDE_DIR}
)

target_link_directories(${MODULE} PRIVATE ${GEANT4_LIBRARY_DIR})

target_link_libraries(${MODULE} PRIVATE
  ${GEANT4_LIBRARIES} ${Python3_LIBRARIES}
  global_cflags
)

#------------------------------------------------------------------------------
set_target_properties(${MODULE} PROPERTIES PREFIX "")
set_target_properties(${MODULE} PROPERTIES OUTPUT_NAME "G4particles")
set_target_properties(${MODULE} PROPERTIES SUFFIX ".so")

# install
install(TARGETS ${MODULE} LIBRARY DESTINATION ${G4MODULES_INSTALL_DIR})
