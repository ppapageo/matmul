#ifndef VANILLAMM_H
#define VANILLAMM_H
#include "BaseMM.h"
#include "string_exec.h"
class VanillaMM: public BaseMM
{
	public:
		using BaseMM::BaseMM;
		//VanillaMM(a_h,a_w,b_h,b_w);
		//~VanillaMM();
		void mult();
};
#endif
