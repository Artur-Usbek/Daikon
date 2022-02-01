cmake_minimum_required(VERSION 3.19)

project(Daikon)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_LIST_DIR}/cmake/modules)

find_package(Daikon REQUIRED)
find_package(Eigen REQUIRED)
find_package(MatplotlibCPP REQUIRED)
find_package(Utils REQUIRED)


add_executable(${PROJECT_NAME} main.cpp)

target_sources(${PROJECT_NAME} PUBLIC
                ${Daikon_SOURCES}
                ${Eigen_SOURCES}
                ${MatplotlibCPP_SOURCES}
                ${Utils_SOURCES}
)

target_include_directories(${PROJECT_NAME} PUBLIC 
                            ${Daikon_INCLUDE_DIRS}
                            ${Eigen_INCLUDE_DIRS}
                            ${MatplotlibCPP_INCLUDE_DIRS}
                            ${Utils_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
                    ${Daikon_LIBS}
                    ${Eigen_LIBS}
                    ${MatplotlibCPP_LIBS}
                    ${Utils_LIBS}
                    )

