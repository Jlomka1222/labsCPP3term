#include "functions.cpp"
#include <iostream>
#include "Exp.h"
#include "Exp_vvod.h"
#include "Exp_zero.h"

int main()
{
	system("color 70");
	system("mode 150,35");
	setlocale(LC_ALL, "Rus");
	rewind(stdin);
	int choose;
	Ring <int> a;
	while (true)
	{
			system("cls");
			cout << "Choose function from list\n" <<
				"1.Add element to lincked list\n" <<
				"2.Delete element from lincked list\n" <<
				"3.Print lincked list\n" <<
				"4.Delete all list\n" <<
				"5.Add to start\n" <<
				"6.End of program\n";
			try
			{
				cin.clear();
				cin >> choose;
				if (choose <= 0 || choose > 6) throw Exp_vvod(-3, "error");
			}
			catch (Exp_vvod inErr)
			{
				inErr.Show();
				system("pause");
			}
			
			system("cls");
			switch (choose)
			{
			case(1):
			{
				try
				{
					int k;
					cin.clear();
					cout << "Write data which you want to add into list" << endl;
					cin >> k;
					if (k == 0) throw Exp_zero(0, "error of input zero");
					a.push(k);
					break;
				}
				catch (Exp_zero inErr)
				{
					inErr.Show();
					system("pause");
				}
				break;
			}
			case(2):
			{
				int k;
				cin.clear();
				cout << "Write data which you want to delete in list" << endl;
				cin >> k;
				a.delFromData(k);
				system("pause");
				break;
			}
			case(3):
			{
				cout << "Your list:\n";
				a.loop();
				cout << "Lenght of list:\t" << a.getlength() << endl;
				system("pause");
				break;
			}
			case(4):
			{
				a.clear();
				cout << "Ring was deleted" << endl;
				system("pause");
				break;
			}
			case(5):
			{
				int k;
				cin.clear();
				cout << "Write data which you want to add into start of list" << endl;
				cin >> k;
				a.push_start(k);
				break;
			}
			case(6):
			{
				a.~Ring();
				cout << "The END" << endl;
				exit(1);
			}
			default:
			{
				cout << "Incorrect choose, please try again\n";
				cin.clear();
				system("pause");
				break;
			}
			}
	}
}