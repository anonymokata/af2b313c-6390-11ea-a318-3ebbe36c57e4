# Word Search Kata

## Contents
- [Building](#building)
   - [Ubuntu 18.04](#ubuntu-1804)
   - [Other Linux / Darwin](#other-linux--darwin)
- [Running](#running)
   - [Unit Tests](#unit-tests)
   - [Main Application](#main-application)

## Building

This code can be built on any C++14 compliant compiler, and with CMake version >= 3.0. 

**Note**: Any time you see `$>` in an example, this represents a shell prompt. You do not
actually type these characters. You will type everything after it.


### Ubuntu 18.04

**IMPORTANT**: The build path for Ubuntu 18.04 is the most tested and supported path in these 
instructions. Stray away from them only if you must. However, as Olmec said: https://youtu.be/Bx_BlcZsVW0

1. Set up an Ubuntu environment (VM or otherwise).
   - Download is available here: https://ubuntu.com/download/desktop 
1. Run the build_ubuntu.sh script.
   - This script will automatically install any dependencies that Ubuntu is missing.
   - Example:
   
   ```bash
   $> ./build_ubuntu.sh
   ```

**NOTE**: This will require super-user access in order to download the dependencies via apt and 
install them.

### Other Linux / Darwin
Though untested building on other linux versions, as well as Darwin (OS X) can be generally
accomplished through the following steps:

1. Download CMake: https://cmake.org/download/
1. Build and install CMake
   - [This guide](https://cmake.org/install/) may be helpful.
1. Ensure you have downloaded a C++14 compliant C++ compiler:
   
   - GNUC++ version 3.9 or better  
   - Clang version 3.4 or better
   - Basically any modern C++ compiler.  
   - See [This List](https://en.cppreference.com/w/cpp/compiler_support) for more.

With all of those dependencies installed:

```bash
# Assumes that the present working directory is the main WordSearchKata folder
$> mkdir ./bin
$> cmake ..
$> make WordSearchKata run_tests
```

To run the application see [Running](#running)

## <a href="#running"></a>Running
If the directions above have successfully been executed, there are two main binaries that can be 
run.

### Unit Tests
Unit tests are best run by the helper script 
```bash
$> ./run_tests.sh
```

This script will ensure that the scripts are run out of the proper directory, and return you safely to
the directory you started in. This ensures that any external data that it uses, can be easily found.

However, if you decide that running the script isn't for you, you simply have to make sure to navigate
to the directory in which the `run_tests` binary was built, namely:
```bash
./WordSearchKata/bin/tests/run_tests
``` 
Where `WordSearchKata` is the overall project directory. 

### Main Application
The main application is found in `WordSearchKata/bin/WordSearchKata`. It takes just one parameter,
which is the file you wish to ingest. From the binary's directory simply execute the following:

```bash
$> WordSearchKata <file_name>
```
Where `file_name` is the valid path (relative or otherwise) to the word search you want to find solutions 
for.

## Description of Work
The goal of this application was to create an application to solve Word Search Puzzles. The problem
was outlined [here](https://github.com/PillarTechnology/kata-word-search).

To this effort I present two ways to solve the problem. These two ways are encapsulated in the
objects: `NaiveSolver` and `SinglePassSolver`. Though both of these objects are derrived from the
`WordSearchSolver` abstract object, little code is shared, and more of an interfaces is provided.

### NaiveSolver
The Naive solver was intended to be just that -- a solver that looked for each word, in order, 
and looked in every direction at each  point in the grid. This is a very straight forward attempt
at solving the problem, and works well.


### SinglePassSolver
As the name suggests this solver performs only a single pass on the word search grid (i.e. each point
in the grid is looked at only once).

The general idea is that to accomplish this the algorithm looks top to bottom, left to right and looks for each 
word at each point (forward and reverse). If done this way, the algorithm can eliminate just over half
of the directions it has to look to find a word in the word search.

For example, in the NaiveSolver, each cardinal point is checked near the current point (north, 
north east, east, south east, south, south west, west), unless it's unavailable (e.g. out of bounds).

However, due to the SinglePassSolver's algorithm, we only have to check east, south east, south, 
and south west. All other cardinal points would have revealed a solution at some other point we have
previously seen.

This was supposed to be faster, however when running performance tests on the main `solve` function, 
it was revealed that this solution is only just barely faster, if at all. Each solution 
solves the problem in roughly the same amount of time (+- 10 microseconds).

It's possible that I could even improve upon the speed of the Naive solution to improve its performance
to be better than that of the SinglePassSolver. However, the whole point is that it's a Naive solution,
and so I couldn't determine how best to approach that problem, without making it less Naive.

Regardless, both solutions exist in the code base.

## Future Work

Here are a few improvements that I considered implementing but didn't due to it being out of 
scope.

- There are still some performance tuning that could be performed to the SinglePassSolver. In theory
I could remove a lot of the parameter passing between functions. However, it's likely that the compiler
on it's `-O2` or `-O3` setting will keep those values in registers, and the improvements of few `mov`
instructions wouldn't improve much if at all.

- The `FileReader` object could be made to be more generic such that the same interface could
be used to read in data from any valid stream (such as `stdin`). This wasn't accomplished
because the code met the goal of the project, and there was no mention of another input source.
Having said that, in the real world software development requirements can change quickly, and 
writing the generic version may be warranted.

- I'd like to apologize for including all of the gtest and gmock suite into the project. Believe it or not,
this is the way the documentation recommends. I could have also included it as a submodule, but that
was just one more thing to go wrong if a recursive clone on the repo wasn't executed.

- I'm pretty certian that there are awesome tricks that one can use with templating, and meta programming
in the newest versions of C++. However, for this program they didn't appear to be warranted, and in
the few places that they may have been, I felt they lead to solutions that were unreadable and provided
little benefit otherwise.