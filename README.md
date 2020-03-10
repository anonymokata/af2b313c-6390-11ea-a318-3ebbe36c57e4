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
   - Download is available here:https://ubuntu.com/download/desktop 
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

 