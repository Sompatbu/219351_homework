cmake_minimum_required(VERSION 3.3)
project(web_application_dev)

find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++11")

set(SOURCE_FILES main.cpp BubbleSort.cpp BubbleSort.h)
add_executable(web_application_dev ${SOURCE_FILES})
target_link_libraries(web_application_dev ${MPI_LIBRARIES})

if(MPI_COMPILE_FLAGS)
    set_target_properties(web_application_dev PROPERTIES
            COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
    set_target_properties(web_application_dev PROPERTIES
            LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()
