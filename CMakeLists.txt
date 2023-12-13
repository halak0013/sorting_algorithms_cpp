# FILEPATH: /home/bismih/projelerimiz2/yazilim/c-c++/sort_algos/CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

project(sort_algos)

find_package(OpenMP)

# Add all the source files to a variable
set(SOURCES
    src/common.cpp
    src/sort_algos.cpp
    src/mergeSort.cpp
    src/mergeSort3.cpp
    src/quickSort.cpp
    src/heapSort.cpp
    src/main.cpp
)

set(TEST_a
    src/common.cpp
    src/sort_algos.cpp
    src/mergeSort.cpp
    src/mergeSort3.cpp
    src/quickSort.cpp
    src/heapSort.cpp
    src/test.cpp
)

# Add an executable target for the project
add_executable(${PROJECT_NAME} ${SOURCES})
target_sources(${PROJECT_NAME} PRIVATE 
    src/include/sort_algos.hpp 
    #src/include/mergeSort.hpp
)

if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME} PUBLIC OpenMP::OpenMP_CXX)
endif()

add_executable(test_a ${TEST_a})
target_sources(test_a PRIVATE 
    src/include/sort_algos.hpp 
    #src/include/mergeSort.hpp
)

# Set the C++ standard to C++11
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
