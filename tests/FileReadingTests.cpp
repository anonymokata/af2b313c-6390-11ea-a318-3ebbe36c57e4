
#include <vector>
#include <string>
#include <memory>
#include "gtest/gtest.h"
#include "FileReader.hpp"

#define PROVIDED_WORD_SEARCH "./data/ProvidedWordSearch.txt"

TEST(FileReadingTests, FileOpensWithoutException)
{
    std::shared_ptr<FileReader> file_object;
    ASSERT_NO_THROW(file_object = std::make_shared<FileReader>(PROVIDED_WORD_SEARCH));
}

TEST(FileReadingTests, FileFailsToOpenWithException)
{
    std::shared_ptr<FileReader> file_object;
    ASSERT_THROW(file_object = std::make_shared<FileReader>("./this/doesnt/exist.txt"), std::runtime_error);
}

TEST(FileReadingTests, FileFailesToOpenNullptrNameWithException)
{
    std::shared_ptr<FileReader> file_object;
    ASSERT_THROW(file_object = std::make_shared<FileReader>(nullptr), std::exception);
}

TEST(FileReadingTests, FileFailesToOpenEmptyStringWithException)
{
    std::shared_ptr<FileReader> file_object;
    ASSERT_THROW(file_object = std::make_shared<FileReader>(""), std::runtime_error);
}

TEST(FileReadingTests, ReadFileVectorOfLines)
{
    std::shared_ptr<FileReader> file_object;
    ASSERT_NO_THROW(file_object = std::make_shared<FileReader>(PROVIDED_WORD_SEARCH));
    std::vector<std::string> lines = file_object->ReadFileLines();

    // Ensure that the number of lines we received is more than zero.
    ASSERT_NE(lines.size(), 0);
}