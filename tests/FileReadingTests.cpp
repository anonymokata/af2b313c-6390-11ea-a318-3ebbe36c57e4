
#include <vector>
#include <string>
#include <memory>
#include "gtest/gtest.h"
#include "FileReader.hpp"

TEST(FileReadingTests, FileOpensWithoutException)
{
    std::shared_ptr<FileReader> file_object;
    ASSERT_NO_THROW(file_object = std::make_shared<FileReader>("./data/ProvidedWordSearch.txt"));
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