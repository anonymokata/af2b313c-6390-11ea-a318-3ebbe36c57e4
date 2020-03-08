#!/usr/bin/env bash

current_dir=`pwd`
TEST_EXEC=./bin/tests/run_tests


if [ ! -f "$TEST_EXEC" ]; then
	echo "[-] Tests have not yet been built. Please run ./build_ubuntu.sh first."
	exit 1
fi


cd ./bin/tests
./run_tests

cd $current_dir
