cmake_minimum_required(VERSION 3.19)
set(PACKAGE_NAME MatplotlibCPP)
set(${PACKAGE_NAME}_FOUND TRUE)

#Matplotlib
#set(CMAKE_EXE_LINKER_FLAGS "-Xlinker -export-dynamic")
#Paths
if(NOT DEFINED PYTHONHOME)
    set(PYTHONHOME "C:/Program Files/Python39")
endif()

set(${PACKAGE_NAME}_INCLUDE_DIRS 
    ${CMAKE_CURRENT_LIST_DIR}/../../../Extern/Matplotlib
    ${PYTHONHOME}
    ${PYTHONHOME}/include
    ${PYTHONHOME}/Lib/site-packages/numpy/core/include
)
set(${PACKAGE_NAME}_SOURCE_DIR "")
set(${PACKAGE_NAME}_SOURCES "")
set(${PACKAGE_NAME}_LIBS 
    ${PYTHONHOME}/libs/python39.lib
    ${PYTHONHOME}/libs/python3.lib
)

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(${PACKAGE_NAME} REQUIRED_VARS ${PACKAGE_NAME}_FOUND)

