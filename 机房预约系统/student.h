#pragma once
#include"people.h"
class student:public people
{
public:
	student()
	{

	}
	student(int id, string name, string pwd);  //�вι��죺ѧ�š�����������
    virtual  void menu();   //�˵�����
	void applyorder();    //����ԤԼ
	void showorder();     //�鿴ԤԼ
	void showallorder();  //�鿴����ԤԼ
	void cancleorder();                     //ȡ��ԤԼ
};