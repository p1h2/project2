#include"manager.h"
manager::manager(string name,string secret)
{
	this->name = name;
	this->secret = secret;  //��ʼ������Ա��Ϣ
}

void manager::menu()
{
	cout << "��ӭ����Ա��" << this->name << "��¼��" << endl;
	cout << "1������˺�"<<endl;
	cout << "2���鿴�˺�" <<endl;
	cout << "3���鿴����" <<endl;
	cout << "4�����ԤԼ" <<endl;
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