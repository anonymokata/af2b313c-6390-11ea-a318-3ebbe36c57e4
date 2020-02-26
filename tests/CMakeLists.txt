project(tests)

add_subdirectory(lib)
include_directories(${WordSearchKata_SOURCE_DIR} ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

configure_file(${PROJECT_SOURCE_DIR}/data/ProvidedWordSearch.txt ${PROJECT_BINARY_DIR}/data/ProvidedWordSearch.txt COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/data/EmptyFile.txt ${PROJECT_BINARY_DIR}/data/EmptyFile.txt COPYONLY)

add_executable(run_tests ../FileReader.cpp FileReadingTests.cpp)
target_link_libraries(run_tests gtest gtest_main)