#ifndef MMUTILS_H
#define MMUTILS_H
#include <stdio.h>
#include <iostream>
#include <cblas.h>
#include <cstdlib>
#include <math.h>
#include <chrono>
float* populate_rand(int size, float high, float low);
float* populate_zero(int size);
#endif
