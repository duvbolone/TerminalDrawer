cd build
rm -rf `ls -Ab`
cmake -D CMAKE_CXX_COMPILER=g++ ..
make