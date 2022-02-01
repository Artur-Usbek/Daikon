cmake_minimum_required(VERSION 3.19)
set(PACKAGE_NAME Eigen)
set(${PACKAGE_NAME}_FOUND TRUE)
message(STATUS "Found ${PACKAGE_NAME}!")


if(NOT DEFINED EIGEN_PATH)
    message(FATAL_ERROR ">>> Please define 'EIGEN_PATH' (Path to Eigen directory)!")
endif()

set(${PACKAGE_NAME}_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/../../src/eigen_utils")
set(${PACKAGE_NAME}_INCLUDE_DIRS 
    ${EIGEN_PATH}
    ${${PACKAGE_NAME}_SOURCE_DIR}
)
set(${PACKAGE_NAME}_SOURCES "")
set(${PACKAGE_NAME}_LIBS "")

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(${PACKAGE_NAME} REQUIRED_VARS ${PACKAGE_NAME}_FOUND)
