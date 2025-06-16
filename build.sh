mkdir -p build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCODE_COVERAGE=ON -DCMAKE_INSTALL_PREFIX=.. -DBUILD_SHARED_LIBS=ON
make
make install
cd ..
cmake --build build --target doc_doxygen