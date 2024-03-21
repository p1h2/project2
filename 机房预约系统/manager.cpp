#include"manager.h"
manager::manager(string name,string secret)
{
	this->name = name;
	this->secret = secret;  //初始化管理员信息
}

void manager::menu()
{
	cout << "欢迎管理员：" << this->name << "登录！" << endl;
	cout << "1、添加账号"<<endl;
	cout << "2、查看账号" <<endl;
	cout << "3、查看机房" <<endl;
	cout << "4、清空预约" <<endl;
}

void manager::addperson()
{

}

void manager::showperson()
{

}

void manager::showcomputer()
{

}

void manager::canclerecord()
{

}