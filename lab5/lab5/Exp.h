#pragma once
#include <string>

using namespace std;

class Exp 
{
protected:
	int code;
	string msg;

public:
	Exp(){}
	Exp(int Code,string message) 
	{
		this->code = code;
		this->msg = msg;
	}
	void Show()
	{
		cout << "unnamed error:"  << code << endl;
	}
	
};