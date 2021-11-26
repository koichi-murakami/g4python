# - build module
#------------------------------------------------------------------------------
set(MODULE gtest03)
#------------------------------------------------------------------------------

configure_file(read_gdml.py read_gdml.py COPYONLY)
configure_file(ecalgeom.gdml ecalgeom.gdml COPYONLY)

file(GLOB XSD_FILES RELATIVE
    "${CMAKE_SOURCE_DIR}/tests/gtest03" "GDMLSchema/*")

foreach (_xsdfile ${XSD_FILES})
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${_xsdfile}
                "${CMAKE_CURRENT_BINARY_DIR}/${_xsdfile}"
                COPYONLY)
endforeach()
