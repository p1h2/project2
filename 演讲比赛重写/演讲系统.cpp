#include"����ϵͳ.h"
int main()
{  
  //��ϰgetline()

	srand(time(NULL));
	manager fk;
	race FK;
	while (true)
	{
		fk.menu();
		cout << "��ѡ��" << endl;
		int select;
		cin >> select;
		switch (select)
		{
		case 0:
			fk.Exit();
			break;
		case 1:
			FK.startrace(fk);
			break;
		case 2:
			fk.read();
			break;

		case 3:
			fk.clear();
			break;

		}
	}
}






























	 
