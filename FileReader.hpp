//
// Created by jordan on 2/25/20.
//

#ifndef WORDSEARCHKATA_FILEREADER_HPP
#define WORDSEARCHKATA_FILEREADER_HPP

#include <string>
#include <fstream>

class FileReader
{
public:
    FileReader(const std::string &file_path);
private:
    std::string _file_path;
    std::ifstream _input_file_object;

};


#endif //WORDSEARCHKATA_FILEREADER_HPP
