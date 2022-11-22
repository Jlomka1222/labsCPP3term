#pragma once
#include "Exp.h"

using namespace std;

class Exp_vvod : public Exp
{
public:
	Exp_vvod() {}
	Exp_vvod(int Code, string message)
	{
		code = Code;
		msg = message;
	}
	void Show()
	{
		cout << "Error in input, error code:" << code << ", " << msg << endl;
	}
};