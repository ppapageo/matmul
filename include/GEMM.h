#ifndef GEMM_H
#define GEMM_H
#include <cblas.h>
#include "BaseMM.h"
#include "string_exec.h"
class GEMM: public BaseMM
{
	public:
		using BaseMM::BaseMM;
		//GEMM(int a_h, int a_w, int b_h, int b_w, float* a, float* b);
		//~GEMM();
		void mult();
};
#endif
