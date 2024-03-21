#pragma once
#include"people.h"
class manager :public people
{
public:
	manager()
	{

	}
	manager(string name,string secret);
	virtual void menu();
	void addperson();
	void showperson();
	void showcomputer();
	void canclerecord();
};