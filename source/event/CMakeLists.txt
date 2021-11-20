# - build module
#------------------------------------------------------------------------------
set(MODULE pyG4event)
#------------------------------------------------------------------------------
pybind11_add_module(${MODULE}
  #pyG4ClassificationOfNewTrack.cc
  pyG4Event.cc
  pyG4EventManager.cc
  pyG4ParticleGun.cc
  #pyG4StackManager.cc
  pyG4UserEventAction.cc
  #pyG4UserStackingAction.cc
  pyParticleGunGenerator.cc
  pymodG4event.cc
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
set_target_properties(${MODULE} PROPERTIES OUTPUT_NAME "G4event")
set_target_properties(${MODULE} PROPERTIES SUFFIX ".so")

# install
install(TARGETS ${MODULE} LIBRARY DESTINATION ${G4MODULES_INSTALL_DIR})
