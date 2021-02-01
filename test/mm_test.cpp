#include <gtest/gtest.h>
#include "BaseMM.h"
#include "GEMM.h"
#include "CgenMM.h"
#include "VanillaMM.h"
#include "MMUtils.h"
#define THRESHOLD 5e-4
int perc_diff(float a, float b){
	return 100*(a-b)/a;
}
//In 2 equal sized matrices, checks if all float elements
//differ only up to a tolerance level
bool matr_all_equal(float* a, float* b, int size){
	for(int i =0; i<size; i++){
		if(perc_diff(a[i],b[i])>THRESHOLD)
			return false;
	}
	return true;
}
TEST(Matmul, VanillaMMDims){
	int a_h = 10;
	int a_w = 6;
	int b_h = 3;
	int b_w = 9;
	srand (static_cast <unsigned> (time(0)));
	float* a = populate_rand(a_h*a_w,15.42,0.42);
	float* b = populate_rand(b_h*b_w,15.42,0.42);
	std::stringstream errmsg;

	errmsg<<"Error, incompatible matrix dimensions\n";
	errmsg<<"Matrix A has width "<<a_w<<", but Matrix B has height "<<b_h<<"\n";
	EXPECT_EXIT({
			VanillaMM v(a_h,a_w,b_h,b_w,a,b);
			},::testing::ExitedWithCode(1),errmsg.str());

	delete[] a;
	delete[] b;
}
TEST(Matmul, CgenMM) {
	int a_h = 100;
	int a_w = 50;
	int b_h = 50;
	int b_w = 90;
	srand (static_cast <unsigned> (time(0)));
	float* a = populate_rand(a_h*a_w,15.42,0.42);
	float* b = populate_rand(b_h*b_w,15.42,0.42);
	VanillaMM v(a_h,a_w,b_h,b_w,a,b);
	v.mult();
	CgenMM c(a_h,a_w,b_h,b_w,a,b);
	c.mult();
	EXPECT_EQ(true,matr_all_equal(v.c,c.c,a_h*b_w));
	delete[] a;
	delete[] b;
}
TEST(Matmul, GEMM) {
	int a_h = 100;
	int a_w = 50;
	int b_h = 50;
	int b_w = 90;
	srand (static_cast <unsigned> (time(0)));
	float* a = populate_rand(a_h*a_w,15.42,0.42);
	float* b = populate_rand(b_h*b_w,15.42,0.42);
	VanillaMM v(a_h,a_w,b_h,b_w,a,b);
	v.mult();
	GEMM g(a_h,a_w,b_h,b_w,a,b);
	g.mult();
	EXPECT_EQ(true,matr_all_equal(v.c,g.c,a_h*b_w));
	delete[] a;
	delete[] b;
}
