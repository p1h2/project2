#include<iostream>
#include"管理系统.h"
using namespace std;
void manager::menu()   //菜单管理
{
	cout << "**************"<<endl;
	cout << "1、打开管理系统" << endl;
	cout << "2、查看以前的演讲记录" << endl;
	cout << "3、清空" << endl;
	cout << "0、退出管理系统" << endl;
}

 
void manager::creatpeople() //选手名字编号
{
	string nameseed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameseed.size(); i++)
	{
		people fk;
		fk.name = "选手";
		fk.name += nameseed[i];
		fk.score= 0;
		this->v1.push_back(i);   //插入选手编号
		this->v3.insert(pair<int,people>(i,fk));
	}
	 
}

void manager::star()   // 选手抽签
{
	cout << "第" << this->number << "次比赛选手开始抽签" << endl;
	cout << "抽签的结果为：" << endl;

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
	star();//抽签
}  

void manager::speech()
{
	 
	vector<int>vs;   //比赛选手容器
	multimap<double, int,greater<double>>v4;  //存放临时数据
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
	cout << "----------第" << this->number << "次比赛开始————————" << endl;
	//选手打分
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
		double count = accumulate(de.begin(), de.end(), 0.0f);//最后一个参数必须要有
		double pingjun = count / (double)de.size();
		this->v3[*it].score = pingjun; //放入平均分
		v4.insert(pair<double, int>(pingjun, *it));//存放每组编号和平均分  会自动排序键值  
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "轮的比赛开始了" << endl;
			for (multimap<double, int, greater<double>>::iterator nb = v4.begin(); nb != v4.end(); nb++)
			{
				cout << "编号为：" << nb->second <<"   " << "姓名为：" << this->v3[nb->second].name << "   " << "分数为" << nb->first << endl;
			}
			cout << endl;
		          //取走前三名
			int i = 0;
			for (multimap<double, int, greater<double>>::iterator nb = v4.begin();i<3&&nb != v4.end(); nb++,i++)//要用&&来限制
			{
				 
				if (this->number == 1)
				{
					v2.push_back((*nb).second);  //把第一组,第二组的前三名放在v2容器中
				 }
				else
				{
					v5.push_back((*nb).second);
				}
			}
			v4.clear();
		}
	}
	cout << "-----------第" << this->number << "次比赛结束"<<endl;
	system("pause");
	cout << endl;
}


void manager::promotion()   //晋级信息打印
{
	cout <<"第"<<this->number <<"次晋级的人有："<< endl;
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
		cout << "编号为" << *nb <<" " << "姓名为" << v3[*nb].name << " " << "分数为" << v3[*nb].score << endl;
	}
}

void manager::victory()
{
	if(this->v5.size())
	{
		cout << "决赛前三名：" << endl;
		for (vector<int>::iterator nb = this->v5.begin(); nb != this->v5.end(); nb++)
		{
			cout << "编号为" << *nb << " " << "姓名为" << v3[*nb].name << " " << "分数为" << v3[*nb].score << endl;
		}
	}
	else
	{
		cout << "没有决赛名单" << endl;
	}
}

void manager::save()
{
	ofstream  Write;
	Write.open("speech.csv", ios::out | ios::app);//用追加方式写
	for (vector<int>::iterator nb = this->v5.begin(); nb != this->v5.end(); nb++)
	{
		Write << "姓名：" << this->v3[*nb].name << ",分数为：" << this->v3[*nb].score << endl;
	}
	Write.close();
	cout << "记录已经保存"<<endl;
} 

void manager::read()
{
	ifstream read; ("speech.csv", ios::in);
	read.open("speech.csv", ios::in);
	if (!read.is_open())
	{
		cout << "文件不存在" << endl;
		read.close();
		return;
	}
	else
	{
		string ph;
		read >> ph;
		if (ph.empty())
		{
			cout << "文件为空";
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
 