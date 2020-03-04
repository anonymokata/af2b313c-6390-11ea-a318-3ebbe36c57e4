cmake_minimum_required(VERSION 3.15)
project(WordSearchKata)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")

configure_file(${PROJECT_SOURCE_DIR}/tests/data/ProvidedWordSearch.txt ${PROJECT_BINARY_DIR}/data/ProvidedWordSearch.txt COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/tests/data/NextGen.txt ${PROJECT_BINARY_DIR}/data/NextGen.txt COPYONLY)

set(SOURCE_FILES
        main.cpp
        FileReader.cpp
        Point.cpp
        Direction.cpp
        NaiveWordSearchSolver.cpp
        WordSolution.cpp
        WordGrid.cpp
        WordSearchSolver.cpp WordSearchSolver.hpp SinglePassSolver.cpp SinglePassSolver.hpp)

add_executable(WordSearchKata ${SOURCE_FILES})