#include "CgenMM.h"
CgenMM::CgenMM(int a_h, int a_w, int b_h,int b_w,float* a,float* b): BaseMM(a_h,a_w,b_h,b_w,a,b){
	se.append_file("../templates/mm.txt");
	se.replace("$a_h",std::to_string(a_h));
	se.replace("$b_w",std::to_string(b_w));
	se.replace("$a_w",std::to_string(a_w));
	se.save();
	se.compile();

	se.openlib("/tmp/cpp-codegen/libtmpmm.so");
	se.loadlib("func");
}
CgenMM::~CgenMM(){
	se.closelib();
}
void CgenMM::mult(){
	se.func(a,b,&c);
}
