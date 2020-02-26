//
// Created by jordan on 2/25/20.
//

#ifndef WORDSEARCHKATA_FILEREADER_HPP
#define WORDSEARCHKATA_FILEREADER_HPP

#include <string>
#include <fstream>
#include <vector>

class FileReader
{
public:
    /**
     * Constructor of a file reader object.
     *
     * @note After construction, the file is open assuming no
     * exception was thrown.
     *
     * @param file_path The file path to open. Must be a valid file path on the system.
     * @throws runtime_exception when file_path is an empty string or the file is not found.
     * @throws exception When file_path is a nullptr/NULL.
     */
    explicit FileReader(const std::string &file_path);

    /**
     * Reads all the lines from a file.
     *
     * @throws runtime_error if the file being read is an empty file.
     * @return A vector containing strings representing each line of the file.
     */
    std::vector<std::string> readFileLines();
private:
    std::string _file_path;
    std::ifstream _input_file_object;

};


#endif //WORDSEARCHKATA_FILEREADER_HPP
