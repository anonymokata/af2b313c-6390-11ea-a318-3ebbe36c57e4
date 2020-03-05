/**
 * @file FileReader.hpp
 *
 * Reads a given file, line by line.
 *
 * This object is simply responsible for opening and ingesting a given file.
 * The FileReader object provides only one interface to get the whole file,
 * as a vector representing each line in the file.
 *
 * @author Jordan Sebastian
 */
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
     * @note The file may be read multiple times. The file cursor is reset after each
     * read.
     *
     * @param[in] file_path The file path to open. Must be a valid file path on the system.
     * @throws runtime_error when file_path is an empty string or the file is not found.
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

    /**
     * Default Destructor.
     */
    ~FileReader() = default;

private:
    std::string _file_path;
    std::ifstream _input_file_stream;

};


#endif //WORDSEARCHKATA_FILEREADER_HPP
