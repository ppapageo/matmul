#include "MMUtils.h"
float* populate_zero(int size){
	float* arr = new float[size]();
	return arr;
}

float* populate_rand(int size, float high, float low){
	float* arr = new float[size];
	for (int i=0; i < size; i ++){
		arr[i]= low + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(high-low)));
	}
	return arr;
}
