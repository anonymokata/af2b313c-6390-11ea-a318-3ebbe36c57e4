project(tests)

add_subdirectory(lib)
include_directories(${WordSearchKata_SOURCE_DIR} ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

configure_file(${PROJECT_SOURCE_DIR}/data/ProvidedWordSearch.txt ${PROJECT_BINARY_DIR}/data/ProvidedWordSearch.txt COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/data/EmptyFile.txt ${PROJECT_BINARY_DIR}/data/EmptyFile.txt COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/data/WordSearchWrongNumberOfRows.txt ${PROJECT_BINARY_DIR}/data/WordSearchWrongNumberOfRows.txt  COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/data/WordSearchWrongNumberOfColumns.txt ${PROJECT_BINARY_DIR}/data/WordSearchWrongNumberOfColumns.txt  COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/data/WordSearchWrongCharacters.txt ${PROJECT_BINARY_DIR}/data/WordSearchWrongCharacters.txt  COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/data/WordSearchMultipleCharactersBetweenDelimiters.txt ${PROJECT_BINARY_DIR}/data/WordSearchMultipleCharactersBetweenDelimiters.txt  COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/data/WordSearchMultipleDelimitersBetweenCharacters.txt ${PROJECT_BINARY_DIR}/data/WordSearchMultipleDelimitersBetweenCharacters.txt  COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/data/WordSearchInvalidSearchWordsDosCommas.txt ${PROJECT_BINARY_DIR}/data/WordSearchInvalidSearchWordsDosCommas.txt  COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/data/WordSearchInvalidSearchWordsLength.txt ${PROJECT_BINARY_DIR}/data/WordSearchInvalidSearchWordsLength.txt  COPYONLY)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SOURCE_FILES
        ../FileReader.cpp
        ../WordGrid.cpp
        ../Point.cpp
        ../Direction.cpp
        ../WordSearchSolver.cpp)

set(TEST_FILES TestWordGrid.cpp TestPoint.cpp TestDirections.cpp TestWordSearchSolver.cpp FileReadingTests.cpp TestConstants.hpp)

add_executable(run_tests ${SOURCE_FILES} ${TEST_FILES})
target_link_libraries(run_tests gtest gtest_main)