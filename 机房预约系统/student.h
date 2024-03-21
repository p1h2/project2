#pragma once
#include"people.h"
class student:public people
{
public:
	student()
	{

	}
	student(int id, string name, string pwd);  //有参构造：学号、姓名、密码
    virtual  void menu();   //菜单界面
	void applyorder();    //申请预约
	void showorder();     //查看预约
	void showallorder();  //查看所有预约
	void cancleorder();                     //取消预约
};