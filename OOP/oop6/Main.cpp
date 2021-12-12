#include <iostream>
#include "CommonService.h"
#include <Windows.h>
using namespace std;


int getCommand();



int main()
{
	CommonService commonService;


	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);




	int command = 0;
	while (command != 100)
	{

		try
		{



			command = getCommand();

			switch (command) {
			case 1:
				commonService.Print();
				break;
			case 2: {
				commonService.AddStudent();
				break;
			}
			case 3: {
				commonService.AddTeacher();
				break;
			}
			case 4: {
				commonService.Sort();
				break;
			}

			case 5: {
				commonService.Find();
				break;
			}

			case 100:
				cout << "выход\n";
				break;
			default:
				cout << "не понял\n";
				break;
			}

		}
		catch (...)
		{
			cout << "ERROR!";
		}

	}



}



int getCommand() {
	cout
		<< "\n"
		<< "1 - список студентов\n"
		<< "2 - добавть нового студента\n"
		<< "3 - добавть нового преподавателя\n"
		<< "4 - сортировка по ФИО\n"
		<< "5 - поиск по имени и фамилии\n"
		<< "100 - выход\n"
		<< "введите команду:"
		;
	int command;
	cin >> command;
	cout << "\n";
	return command;
}