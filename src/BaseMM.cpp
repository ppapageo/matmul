#include "BaseMM.h"

BaseMM::BaseMM(int a_h, int a_w, int b_h, int b_w, float* a, float* b){
	if(a_w!=b_h){
		std::cerr<<"Error, incompatible matrix dimensions\n";
		std::cerr<<"Matrix A has width "<<a_w<<", but Matrix B has height "<<b_h<<"\n";
		exit(1);
	}
	this->a_h = a_h;
	this->a_w = a_w;
	this->b_h = b_h;
	this->b_w = b_w;
	this->a = a;
	this->b = b;
	this->c=populate_zero(this->a_h*this->b_w);
}
BaseMM::~BaseMM(){
	delete[] c;
}
