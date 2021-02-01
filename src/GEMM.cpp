#include "GEMM.h"
void GEMM::mult(){
	float alpha = 1;
	float beta = 0;
	int m = a_h; 
	int k = a_w;
	int n = b_w;
	cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
			m, n, k, alpha, this->a,
			k, this->b, n, beta, this->c, n);
}
