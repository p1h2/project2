#pragma once
#include"��Ա����.h"
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
    map<int,people>v2;  //�����Ա���������Ϣ
    vector<int>v3;   //��ŵڶ��α���ѡ�ֵı��
    vector<int> v4;  //������ձ������
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