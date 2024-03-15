#pragma once
#include"人员管理.h"
#include<vector>
#include<map>
#include<stdlib.h>
#include<algorithm>
#include<deque>
#include<numeric>
#include<fstream>
#include<string>
class manager
{
    friend class race;
    public:
    void menu();
    void  makepeople();
    void luck();
    void playscore();
    void write();
    void read();
    void clear();
    void Exit();
    int number = 1;
    vector<int>v1;
    map<int,people>v2;  //存放人员姓名编号信息
    vector<int>v3;   //存放第二次比赛选手的编号
    vector<int> v4;  //存放最终比赛结果
 };
class people1
{
public:
    bool operator()( double a,  double b) const 
    {
        return a > b; 
    }
    
};


class race
{
public:
    void startrace(manager &fk);
};