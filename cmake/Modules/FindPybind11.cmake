# - Find Pybind11
#  PYBIND11_FOUND        - system has pybind11
#  PYBIND11_INCLUDE_DIRS  - the pybind11 include directory

find_path(PYBIND11_INCLUDE_DIR
        NAMES pybind11/pybind11.h
        DOC "The directory where pybind11 includes reside"
)

set(PYBIND11_INCLUDE_DIRS ${PYBIND11_INCLUDE_DIR})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Pybind11
        FOUND_VAR PYBIND11_FOUND
        REQUIRED_VARS PYBIND11_INCLUDE_DIRS
)

mark_as_advanced(PYBIND11_FOUND)
