#ifndef BASEMM_H
#define BASEMM_H
#include "string_exec.h"
#include "MMUtils.h"
#include <omp.h>
class BaseMM
{
	public:
	int a_h;
	int a_w;
	int b_h;
	int b_w;
	float *a;
	float *b;
	float *c;

	BaseMM(int a_h, int a_w, int b_h, int b_w, float* a, float* b);
	virtual ~BaseMM();
};
#endif
