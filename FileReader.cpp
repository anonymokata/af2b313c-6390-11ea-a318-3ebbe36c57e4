//
// Created by jordan on 2/25/20.
//

#include "FileReader.hpp"
#include <fstream>

FileReader::FileReader(const std::string &file_path) : _file_path(file_path)
{
    if (file_path.empty())
    {
        throw std::runtime_error("Error: You must pass a non-empty string representing a valid file path.");
    }

    _input_file_object = std::ifstream(file_path);

    if (!_input_file_object.good())
    {
        throw std::runtime_error("Error: Cannot open the file: " + file_path + " requested.");
    }
}

std::vector<std::string> FileReader::ReadFileLines()
{
    std::vector<std::string>    lines;
    std::string                 current_line;

    while(std::getline(_input_file_object, current_line))
    {
        lines.push_back(current_line);
    }

    return lines;
}