/**
 * @file FileReader.cpp
 *
 * Implementation of the logic of the FileReader object.
 *
 * @author Jordan Sebastian
 */

#include "FileReader.hpp"
#include <fstream>

FileReader::FileReader(const std::string &file_path) : _file_path(file_path)
{
    if (file_path.empty())
    {
        throw std::runtime_error("Error: You must pass a non-empty string representing a valid file path.");
    }

    _input_file_stream = std::ifstream(file_path);

    if (!_input_file_stream.good())
    {
        throw std::runtime_error("Error: Cannot open the file: " + file_path + " requested.");
    }
}

std::vector<std::string> FileReader::readFileLines()
{
    std::vector<std::string> lines;
    std::string current_line;

    // Reset the file cursor to the beginning of the file.
    _input_file_stream.clear();
    _input_file_stream.seekg(0, std::ios::beg);

    if (_input_file_stream.peek() == std::ifstream::traits_type::eof())
    {
        throw std::runtime_error("Error: Could read the file: " + _file_path + " the file is empty.");
    }

    while(std::getline(_input_file_stream, current_line))
    {
        lines.push_back(current_line);
    }

    return lines;
}