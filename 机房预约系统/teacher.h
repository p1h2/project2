#pragma once
#include"people.h"
class teacher :public people
{
public:
	teacher()
	{

	}
	teacher(int empid, string name, string pwd);
	virtual void menu();
	void showorder();
	void checkorder();
};