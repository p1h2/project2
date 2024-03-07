#pragma once
#include<map>
#include<vector>
#include"人员管理.h"
#include<numeric>
#include<algorithm>>
#include<deque>
#include<fstream>
class manager
{
public:
	manager()
	{
       
	}
	void creatpeople();
	void menu();
	void star();
	void sctor();
	void speech();
	void promotion();
	void victory();
	void save();
	void read();
	int number=1;
	vector<int>v1;  //编号
	vector<int>v2;
	map<int, people>v3;
	vector<int>v5;
};