#include"����ϵͳ.h"
#include"��Ա����.h"
#include<iostream>
using namespace std;
void manager::menu()
{
	cout << "***********" << endl;
	cout << "0���˳�����"<< endl;
	cout << "1����ʼ����"<< endl;
	cout << "2����ѯ��ǰ�ļ�¼"<< endl;
	cout << "3����ռ�¼"<< endl;
	 
}


void manager::makepeople()
{
	string Name = "ABCDEFGHIJKL";
	int i = 0;
	people fk;
	for (i; i < Name.size(); i++)
	{
		people fk;
		fk.name = "ѡ��";
		fk.name += Name[i];
		fk.score = 0;
		v2.insert(pair<int, people>(i, fk));
		v1.push_back(i);
	}
}


void manager::luck()
{
	cout << "��" << this->number << "�α�����ʼ" << endl;
	cout << "��ǩ���:"<<endl;
	if (this->number == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator nb=v1.begin();nb!=v1.end();nb++)
		{
		   cout << *nb<<" ";
		}
		cout<<endl;
	 }
	else
	{
		random_shuffle(v3.begin(), v3.end());
		for (vector<int>::iterator nb = v3.begin(); nb != v3.end(); nb++)
		{
			cout << *nb << " ";
		}
		cout << endl;
	}
}


void manager::playscore()
{
	vector<int>v111;
	deque<int>v11;
	if (this->number == 1)
	{
		v111 = v1;
	}
	else
	{
		v111 = v3;
	}
	multimap<double, int, people1>v22;
	int number=0;
	for (vector<int>::iterator nb = v111.begin(); nb != v111.end(); nb++)
	{

		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			v11.push_back(score);
		}
		sort(v11.begin(), v11.end(), greater<int>());
		v11.pop_front();
		v11.pop_back();
		double count = accumulate(v11.begin(), v11.end(), 0);
		double pingjun = count / (double)v11.size();
		v2[*nb].score = pingjun;
		v22.insert(pair<double, int>(pingjun, *nb));
		number++;
		if (number%6 == 0)    //��һ��
		{
			cout<< "��" << number/6 << "������ĳɼ�:" << endl;
			for (multimap<double,int,people1>::iterator nb = v22.begin(); nb != v22.end(); nb++)
			{
				cout << "��ţ�" << nb->second << " " << v2[nb->second].name << " " << "����Ϊ��" <<nb->first<< endl;
			}
			int i = 0;
			cout << endl;
			cout << "ǰ������" << endl;
			for (multimap<double, int,people1>::iterator nb = v22.begin(); nb != v22.end() && i != 3; nb++, i++)
			{   //Ҫ�Ƚϴ�С����ôv22����ҲҪ��people 
				if (this->number == 1)
				{
					cout << "��ţ�" << nb->second << " " << v2[nb->second].name << " " << "����Ϊ��" << v2[nb->second].score << endl;
					v3.push_back(nb->second);
				}
				else
				{
					v4.push_back(nb->second);
					cout << "��ţ�" << nb->second << " " << v2[nb->second].name << " " << "����Ϊ��" << v2[nb->second].score << endl;
				}
			}
			v22.clear();
			cout << endl;
		}
	}


}


void manager::write()
{
	ofstream write;
	write.open("speech.text", ios::out | ios::app);
	for (vector<int>::iterator nb = v4.begin(); nb != v4.end(); nb++)
	{
		write << "���Ϊ��" << *nb << " " << v2[*nb].name << " "<<"����Ϊ��" << v2[*nb].score << endl;
	}
	write.close();
	cout << "��¼���" << endl;
	this->v2.clear();
	this->v3.clear();
	this->v4.clear();
	system("pause");
	system("cls");
}


void manager::read()
{
	ifstream read;   //���������
	read.open("speech.text", ios::in);
	if (!read.is_open())  //�򿪷�ʽ
	{
		cout << "���ܴ��ļ�"<<endl;
		read.close();
		system("pause");
		system("cls");
		return ;
	}

	char a;
	read >> a;
	if (read.eof())
	{
		cout << "�ļ�Ϊ��"<<endl;
		read.close();
		system("pause");
		system("cls");
		return;
		 
	}
	else
	{
		string ph;
		read.putback(a);
		int i = 0;
		int count = 1;
		cout << "��1�α�����¼" << endl;
		while (getline(read, ph))
		{
			cout << ph << endl;
			i++;
			if (i == 3)
			{
				cout << endl;
				count++;
				char a;
				read >> a;
				if (!read.eof())
				{
					cout << "��" << count << "�α�����¼" << endl;
					i = 0;
					read.putback(a);
				}
			}
		}
	}
	system("pause");
	system("cls");
}


void manager::clear()
{
	cout << "�Ƿ�ɾ����¼?" << endl;
	cout << "1����    2����" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		ofstream write;   //���������
		write.open("speech.text", ios::trunc);    //ֻ��ͨ���������Ĳ�����ɾ���ļ�
		cout << "��¼�Ѿ�ɾ��" << endl;
	}
	system("pause");
	system("cls");
}


void manager::Exit()
{
	cout << "�Ƿ��˳�����:" << endl;
	cout << "1����  2����" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		exit(0);
	}
	system("cls");
}


void race::startrace(manager &fk)
{
	fk.makepeople();
	fk.luck();
	fk.playscore();
	fk.number = 2;
	fk.luck();
	fk.playscore();
	fk.write();
}


