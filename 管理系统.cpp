#include<iostream>
#include"����ϵͳ.h"
using namespace std;
void manager::menu()   //�˵�����
{
	cout << "**************"<<endl;
	cout << "1���򿪹���ϵͳ" << endl;
	cout << "2���鿴��ǰ���ݽ���¼" << endl;
	cout << "3�����" << endl;
	cout << "0���˳�����ϵͳ" << endl;
}

 
void manager::creatpeople() //ѡ�����ֱ��
{
	string nameseed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameseed.size(); i++)
	{
		people fk;
		fk.name = "ѡ��";
		fk.name += nameseed[i];
		fk.score= 0;
		this->v1.push_back(i);   //����ѡ�ֱ��
		this->v3.insert(pair<int,people>(i,fk));
	}
	 
}

void manager::star()   // ѡ�ֳ�ǩ
{
	cout << "��" << this->number << "�α���ѡ�ֿ�ʼ��ǩ" << endl;
	cout << "��ǩ�Ľ��Ϊ��" << endl;

	if (this->number == 1)
	{
		random_shuffle(this->v1.begin(), this->v1.end());
		for (vector<int>::iterator nb = this->v1.begin(); nb != this->v1.end(); nb++)
		{
			cout << *nb << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(this->v2.begin(), this->v2.end());
		for (vector<int>::iterator nb = this->v2.begin(); nb != this->v2.end(); nb++)
		{
			cout << *nb << " ";
		}
		cout << endl;
	}
	cout << endl;
	system("pause");
}


void manager::sctor()
{
	creatpeople();
	star();//��ǩ
}  

void manager::speech()
{
	 
	vector<int>vs;   //����ѡ������
	multimap<double, int,greater<double>>v4;  //�����ʱ����
	int num = 0;
	if (this->number == 1)
	{
		vs = v1;
	}
	else
	{
	
		vs = v2;
		cout << endl;
	}
	cout << "----------��" << this->number << "�α�����ʼ����������������" << endl;
	//ѡ�ִ��
	for (vector<int>::iterator it = vs.begin(); it != vs.end(); it++)
	{
		num++;
		deque<int>de;
		for (int i = 0; i < 10; i++)
		{
			double  score = (rand() % 401 + 600) / 10.f;
			de.push_back(score);
		}
		sort(de.begin(), de.end(), greater<double>());
		de.pop_front();
		de.pop_back();
		double count = accumulate(de.begin(), de.end(), 0.0f);//���һ����������Ҫ��
		double pingjun = count / (double)de.size();
		this->v3[*it].score = pingjun; //����ƽ����
		v4.insert(pair<double, int>(pingjun, *it));//���ÿ���ź�ƽ����  ���Զ������ֵ  
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "�ֵı�����ʼ��" << endl;
			for (multimap<double, int, greater<double>>::iterator nb = v4.begin(); nb != v4.end(); nb++)
			{
				cout << "���Ϊ��" << nb->second <<"   " << "����Ϊ��" << this->v3[nb->second].name << "   " << "����Ϊ" << nb->first << endl;
			}
			cout << endl;
		          //ȡ��ǰ����
			int i = 0;
			for (multimap<double, int, greater<double>>::iterator nb = v4.begin();i<3&&nb != v4.end(); nb++,i++)//Ҫ��&&������
			{
				 
				if (this->number == 1)
				{
					v2.push_back((*nb).second);  //�ѵ�һ��,�ڶ����ǰ��������v2������
				 }
				else
				{
					v5.push_back((*nb).second);
				}
			}
			v4.clear();
		}
	}
	cout << "-----------��" << this->number << "�α�������"<<endl;
	system("pause");
	cout << endl;
}


void manager::promotion()   //������Ϣ��ӡ
{
	cout <<"��"<<this->number <<"�ν��������У�"<< endl;
	vector<int>v;
	if (this->number == 1)
	{
		v = v2;
	}
	else
	{
		v = v5;
	}
	for (vector<int>::iterator nb =v.begin(); nb != v.end(); nb++)
	{
		cout << "���Ϊ" << *nb <<" " << "����Ϊ" << v3[*nb].name << " " << "����Ϊ" << v3[*nb].score << endl;
	}
}

void manager::victory()
{
	if(this->v5.size())
	{
		cout << "����ǰ������" << endl;
		for (vector<int>::iterator nb = this->v5.begin(); nb != this->v5.end(); nb++)
		{
			cout << "���Ϊ" << *nb << " " << "����Ϊ" << v3[*nb].name << " " << "����Ϊ" << v3[*nb].score << endl;
		}
	}
	else
	{
		cout << "û�о�������" << endl;
	}
}

void manager::save()
{
	ofstream  Write;
	Write.open("speech.csv", ios::out | ios::app);//��׷�ӷ�ʽд
	for (vector<int>::iterator nb = this->v5.begin(); nb != this->v5.end(); nb++)
	{
		Write << "������" << this->v3[*nb].name << ",����Ϊ��" << this->v3[*nb].score << endl;
	}
	Write.close();
	cout << "��¼�Ѿ�����"<<endl;
} 

void manager::read()
{
	ifstream read; ("speech.csv", ios::in);
	read.open("speech.csv", ios::in);
	if (!read.is_open())
	{
		cout << "�ļ�������" << endl;
		read.close();
		return;
	}
	else
	{
		string ph;
		read >> ph;
		if (ph.empty())
		{
			cout << "�ļ�Ϊ��";
			return;
		}
		cout << ph<<endl;
		while(read>>ph)
		{ 
			cout << ph<<endl;
		}

		read.close();
	}
}
 