# - build module

file (GLOB PY_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.py)

foreach (_pyfile ${PY_FILES})
  configure_file (${CMAKE_CURRENT_SOURCE_DIR}/${_pyfile}
                  ${CMAKE_CURRENT_BINARY_DIR}/${_pyfile} COPYONLY)
endforeach()

#add_custom_target (geant4 ALL)
#add_custom_command (TARGET geant4
#  COMMAND ${Python3_EXECUTABLE}
#    ARGS -m compileall -f ${CMAKE_CURRENT_BINARY_DIR}
#  COMMAND ${Python3_EXECUTABLE}
#    ARGS -O -m compileall -f ${CMAKE_CURRENT_BINARY_DIR}
#)

# install
install (FILES ${PY_FILES} DESTINATION ${G4MODULES_INSTALL_DIR})
#install (DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/__pycache__
#         DESTINATION ${G4MODULES_INSTALL_DIR})
