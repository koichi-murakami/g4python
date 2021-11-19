# - build module

file (GLOB PY_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.py)

foreach (_pyfile ${PY_FILES})
  configure_file (${CMAKE_CURRENT_SOURCE_DIR}/${_pyfile}
                  ${CMAKE_CURRENT_BINARY_DIR}/${_pyfile} COPYONLY)
endforeach()

# install
install (FILES ${PY_FILES} DESTINATION ${G4MODULES_INSTALL_DIR})
