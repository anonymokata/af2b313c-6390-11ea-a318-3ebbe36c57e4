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

std::vector<std::string> FileReader::readFileLines()
{
    std::vector<std::string> lines;
    std::string current_line;

    // Reset the file cursor to the beginning of the file.
    _input_file_object.clear();
    _input_file_object.seekg(0, std::ios::beg);

    if (_input_file_object.peek() == std::ifstream::traits_type::eof())
    {
        throw std::runtime_error("Error: Could read the file: " + _file_path + " the file is empty.");
    }

    while(std::getline(_input_file_object, current_line))
    {
        lines.push_back(current_line);
    }

    return lines;
}