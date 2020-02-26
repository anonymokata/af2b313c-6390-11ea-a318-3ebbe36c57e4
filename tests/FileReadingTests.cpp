
#include <vector>
#include <string>
#include <memory>
#include "gtest/gtest.h"
#include "FileReader.hpp"

TEST(FileReadingTests, FileOpensWithoutException)
{
    std::shared_ptr<FileReader> f;
    ASSERT_NO_THROW(f = std::make_shared<FileReader>("./data/ProvidedWordSearch.txt"));
}

TEST(FileReadingTests, FileFailsToOpenWithException)
{
    std::shared_ptr<FileReader> file_object;
    ASSERT_THROW(file_object = std::make_shared<FileReader>("./this/doesnt/exist.txt"), std::runtime_error);
}