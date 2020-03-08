cmake_minimum_required(VERSION 3.0)
project(WordSearchKata)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Werror -Wextra")

configure_file(${PROJECT_SOURCE_DIR}/tests/data/ProvidedWordSearch.txt ${PROJECT_BINARY_DIR}/data/ProvidedWordSearch.txt COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/tests/data/NextGen.txt ${PROJECT_BINARY_DIR}/data/NextGen.txt COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/tests/data/LorumIpsum.txt ${PROJECT_BINARY_DIR}/data/LorumIpsum.txt COPYONLY)

set(SOURCE_FILES
        src/main.cpp
        src/FileReader.cpp
        src/Point.cpp
        src/Direction.cpp
        src/NaiveSolver.cpp
        src/WordSolution.cpp
        src/WordGrid.cpp
        src/WordSearchSolver.cpp src/WordSearchSolver.hpp src/SinglePassSolver.cpp src/SinglePassSolver.hpp)

add_executable(WordSearchKata ${SOURCE_FILES})
