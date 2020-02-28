
#include <vector>
#include <string>
#include <memory>
#include "gtest/gtest.h"
#include "FileReader.hpp"

#define PROVIDED_WORD_SEARCH "./data/ProvidedWordSearch.txt"
#define EMPTY_FILE "./data/EmptyFile.txt"

#define MINIMUM_LINES_TO_READ 2
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
    std::vector<std::string> lines = file_object->readFileLines();

    // Ensure that the number of lines we received is more than 1. Our file format requires that
    // We have a line of words, and a grid. Therefore we need at least 2 lines.
    //
    // In fact, we are guaranteed to need more lines than 2, but further validation will be performed by another
    // object and is outside the scope of this one.
    ASSERT_GT(lines.size(), MINIMUM_LINES_TO_READ);
}

TEST(FileReadingTests, ReadEmptyFileThrowsException)
{
    std::shared_ptr<FileReader> file_object;
    ASSERT_NO_THROW(file_object = std::make_shared<FileReader>(EMPTY_FILE));
    ASSERT_THROW(std::vector<std::string> lines = file_object->readFileLines(), std::runtime_error);

}

TEST(FileReadingTests, ReadFileAtEOFResetsFileCursor)
{
    std::shared_ptr<FileReader> file_object;
    ASSERT_NO_THROW(file_object = std::make_shared<FileReader>(PROVIDED_WORD_SEARCH));
    std::vector<std::string> first_read_lines;
    std::vector<std::string> second_read_lines;

    ASSERT_NO_THROW(first_read_lines = file_object->readFileLines());
    ASSERT_NO_THROW(second_read_lines = file_object->readFileLines());

    ASSERT_EQ(first_read_lines.size(), second_read_lines.size());
}