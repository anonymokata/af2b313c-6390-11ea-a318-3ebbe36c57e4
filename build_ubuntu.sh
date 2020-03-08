#!/usr/bin/env bash

sudo apt-get -y update
sudo apt-get -y install build-essential cmake

current_dir=`pwd`

# Set up a build directory
mkdir -p ./bin
cd ./bin

# Configure make files
cmake ../

# Build tests and the main program.
make run_tests
make WordSearchKata

# Execute our unit tests.
cd ./tests
./run_tests

# Ensure that the unit tests ran correctly.
exit_status=$?
if [ $exit_status -ne 0 ]; then
	echo "[-] Error: Unit tests may have failed. Check previous errors."
	echo "[-] You can still attempt to run ./bin/WordSearchKata, if you'd like"
	cd $current_dir
	exit 1
fi

echo ""
echo "[+] Build and tests successfully completed."
echo "[+] To run unit tests manually execute from the main project directory:"
echo "[+] $> cd ./bin/tests; ./run_tests"
echo "[+] OR"
echo "[+] ./run_tests.sh"
echo "[+]"
echo "[+] To execute the main application use: "
echo "[+] ./bin/WordSearchKata <input_file>"
echo "[+]"
echo "[+] Note: There are several example word searches to try in ./bin/data"
echo "Thank you for your time."
cd $current_dir
