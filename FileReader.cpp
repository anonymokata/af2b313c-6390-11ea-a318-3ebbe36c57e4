//
// Created by jordan on 2/25/20.
//

#include "FileReader.hpp"
#include <fstream>
#include <exception>
FileReader::FileReader(const std::string &file_path)
{
    if (file_path.empty())
    {
        throw std::runtime_error("Error: You must pass a non-empty string representing a valid file path.");
    }
    _file_path = file_path;
    _input_file_object = std::ifstream(file_path);

    if (!_input_file_object.good())
    {
        throw std::runtime_error("Cannot open the file: " + file_path + " requested.");
    }
}