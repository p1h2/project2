#pragma once
#include<map>
#include<vector>
#include"ÈËÔ±¹ÜÀí.h"
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
	void speech();
	void promotion();
	void victory();
	void save();
	void read();
        void Record();
        void clearcord();
	int number=1;
	vector<int>v1;  //±àºÅ
	vector<int>v2;
	map<int, people>v3;
	vector<int>v5;
        map<int, vector<string>>record;
};
