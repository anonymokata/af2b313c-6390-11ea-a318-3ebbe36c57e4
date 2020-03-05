/**
 * @file main.cpp
 *
 * This file contains the actual entry point to our main program.
 *
 * This function is stripped of everything except a call to alt_main. The
 * reason behind this is that gtest suite (or the way I'm using it), compiles my source
 * into a binary that contains its own main function. This is fine, but it means that I can't
 * directly test main due to a conflict. That's alright as all the logic is already tested but
 * for completeness I'm adding an alt_main.
 *
 * @author Jordan Sebastian
 */

#include <iostream>
#include "WordGrid.hpp"
#include "NaiveSolver.hpp"
#include "FileReader.hpp"
#include <vector>
#include <string>
#include <memory>

/**
 * This is some macro trickery to switch out the name of 'main' to avoid
 * a name conflict when we compile main.cpp into the gtest suite. If we don't
 * change the name, then there will be a conflict, as gtest has it's own entrypoint
 * called 'main'.
 *
 * When we are compiling the actual application this macro switches back to the normal name.
 */
#ifdef UNIT_TESTS
    #define MAIN ALT_MAIN
#else
    #define MAIN main
#endif

/**
 * Return values for main.
 */
#define SUCCESS 0
#define INVALID_PARAMETERS 1
#define INVALID_DATA 2

/**
 * Main entrypoint for the program.
 *
 * @param argc The number of arguments (program name is always the 1st argument).
 * @param argv The values of the arguments.
 * @returns SUCCESS on success
 * @returns INVALID_PARAMETERS if the provided filename is in any way invalid, or not present.
 * @returns INVALID_DATA if the data in the provided file is invalid.
 */
int MAIN(int argc, char* argv[])
{
    if (argc < 2 )
    {
        std::cout << "Usage: WordSearchKata <word_grid_filename>" << std::endl;
        return INVALID_PARAMETERS;
    }
    std::string filename(argv[1]);
    std::unique_ptr<FileReader> reader = nullptr;

    try
    {
        reader = std::make_unique<FileReader>(filename);
    }
    catch (std::runtime_error& ex)
    {
        std::cout << ex.what() << std::endl;
        return INVALID_PARAMETERS;
    }

    std::vector<std::string> lines = reader->readFileLines();
    std::unique_ptr<WordGrid> grid = nullptr;

    try
    {
        grid = std::make_unique<WordGrid>(lines);
    }
    catch (std::logic_error& ex)
    {
        std::cout << ex.what() << std::endl;
        return INVALID_DATA;
    }

    NaiveSolver solver(*grid);
    std::vector<WordSolution> solutions = solver.solve();

    for (auto solution : solutions)
    {
        std::cout << solution << std::endl;
    }

    return SUCCESS;
}
