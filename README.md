matmul [![CI](https://github.com/ppgpn/matmul/workflows/CI/badge.svg)](https://github.com/ppgpn/matmul/actions)
=======

Matrix multiplication example for testing the use of [cpp-codegen](https://github.com/ppgpn/cpp-codegen) library as a cmake module.

Matrix multiplication code generated with boundary loop substitution is compared against naive and gemm based matrix multiplications.

Requirements
-----------
gtest, cmake, libopenblas-dev

Build cpp-codegen
-----------
```bash
git clone https://github.com/ppgpn/cpp-codegen.git
cd cpp-codegen
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX=<cpp-codegen/install/location>/installed ..
make -j $(nproc)
make install
```

Build
-----------
```bash
cd <project/dir>
mkdir build && cd build
cmake -DBUILD_TEST=1 -DCppCodegen_DIR=<cpp-codegen/install/location>/installed/cmake .. 
cmake .. 
make
```
Run
-------
```bash
export CXX=g++ //or your favorite C++ compiler
cd <project/dir>/build
./src/time_mm <a_h> <a_w> <b_h> <b_w> <threads>
```
