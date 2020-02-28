//
// Created by jordan on 2/25/20.
//

#include "FileReader.hpp"
#include <fstream>

FileReader::FileReader(const std::string &file_path) : _filePath(file_path)
{
    if (file_path.empty())
    {
        throw std::runtime_error("Error: You must pass a non-empty string representing a valid file path.");
    }

    _inputFileObject = std::ifstream(file_path);

    if (!_inputFileObject.good())
    {
        throw std::runtime_error("Error: Cannot open the file: " + file_path + " requested.");
    }
}

std::vector<std::string> FileReader::readFileLines()
{
    std::vector<std::string> lines;
    std::string current_line;

    // Reset the file cursor to the beginning of the file.
    _inputFileObject.clear();
    _inputFileObject.seekg(0, std::ios::beg);

    if (_inputFileObject.peek() == std::ifstream::traits_type::eof())
    {
        throw std::runtime_error("Error: Could read the file: " + _filePath + " the file is empty.");
    }

    while(std::getline(_inputFileObject, current_line))
    {
        lines.push_back(current_line);
    }

    return lines;
}