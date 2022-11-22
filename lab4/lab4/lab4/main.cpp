#include "functions.cpp"
#include <iostream>


	
int main()
{
	system("color 70");
	system("mode 150,35");
	setlocale(LC_ALL, "Rus");
	cin.clear();
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
			"0.End of program\n";
		int choose;
		choose = a.GetInt();
		system("cls");
		switch (choose)
		{
		case(1):
		{
			int k;
			cin.clear();
			cout << "Write data which you want to add into list" << endl;
			cin >> k;
			a.push(k);
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
			cout<<"Lenght of list:\t" << a.getlength() << endl;
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
		case(0):
		{
			a.~Ring();
			cout << "The END" << endl;
			exit(1);
		}
		default:
		{
			cout << "Incorrect choose, please try again\n";
			system("pause");
		}
		}
	}
}