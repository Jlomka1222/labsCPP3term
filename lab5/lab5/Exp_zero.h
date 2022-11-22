#pragma once
#include "Exp.h"

class Exp_zero: public Exp
{
public:
	Exp_zero() {};
	Exp_zero(int Code, string message) {
		code = Code;
		msg = message;
	}
	void Show()
	{
		cout << "U can't input zero,error code:" << code << ", " << msg << endl;
	}
}; 
