#include "BaseMM.h"
#include "GEMM.h"
#include "CgenMM.h"
#include "VanillaMM.h"
#include "MMUtils.h"
extern "C" void openblas_set_num_threads(int num_threads);
int main( int argc, char** argv )
{
	if (argc<=5){
		std::cout<<"Too few arguments"<<"\n";
		std::cout<<"Usage ./time_mm <a_h> <a_w> <b_h> <b_w> <threads>"<<"\n";
		exit(1);
	}
	int a_h = atoi(argv[1]);
	int a_w = atoi(argv[2]);
	int b_h = atoi(argv[3]);
	int b_w = atoi(argv[4]);
	int t = atoi(argv[5]);
	std::cout<<"threads "<<t<<"\n";
	openblas_set_num_threads(t);
	omp_set_num_threads(t);
	srand (static_cast <unsigned> (time(0)));
	float* a = populate_rand(a_h*a_w,15.42,0.42);
	float* b = populate_rand(b_h*b_w,15.42,0.42);
	VanillaMM v(a_h,a_w,b_h,b_w,a,b);
	auto cr_start = std::chrono::high_resolution_clock::now();
	v.mult();
	auto cr_end = std::chrono::high_resolution_clock::now();
	std::cout<<"Vanilla Time(s):\t"<< std::chrono::duration<double>(cr_end-cr_start).count()<<"\n";
	CgenMM c(a_h,a_w,b_h,b_w,a,b);
	cr_start = std::chrono::high_resolution_clock::now();
	c.mult();
	cr_end = std::chrono::high_resolution_clock::now();
	std::cout<<"Cgen Time(s):\t"<< std::chrono::duration<double>(cr_end-cr_start).count()<<"\n";
	GEMM g(a_h,a_w,b_h,b_w,a,b);
	cr_start = std::chrono::high_resolution_clock::now();
	g.mult();
	cr_end = std::chrono::high_resolution_clock::now();
	std::cout<<"GEMM Time(s):\t"<< std::chrono::duration<double>(cr_end-cr_start).count()<<"\n";
	int size = a_h*b_w;
	if(size>9) size = 9;
	for (int i = 0; i < size; i++){
		std::cout<<v.c[i]<<" : "<<c.c[i]<<" : "<<g.c[i]<<"\n";
	}

	delete[] a;
	delete[] b;
}
