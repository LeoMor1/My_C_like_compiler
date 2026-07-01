cd build
cmake --build .
ctest
make coverage
brave "${PWD}/coverage/index.html"
