#ifndef CGENMM_H
#define CGENMM_H
#include "BaseMM.h"
#include "string_exec.h"
class CgenMM: public BaseMM
{
	public:
	StringExec se={"../cmpflags.txt","/tmp/cpp-codegen","tmpmm"};
	CgenMM(int a_h, int a_w, int b_h,int b_w,float* a,float* b);
	~CgenMM();
	void mult();
};
#endif
