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
				cout << "позиция:"; int position; cin >> position;
				commonService.AddStudent(position);
				break;
			}

			case 4: {
				commonService.AddTeacher();
				break;
			}

			case 5: {
				cout << "позиция:"; int position; cin >> position;
				commonService.AddTeacher(position);
				break;
			}

			case 6: {
				commonService.RemoveFirst();
				break;
			}

			case 7: {
				commonService.Sort();
				break;
			}

			case 8: {
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
		<< "2 - добавть нового студента в конец списка\n"
		<< "3 - добавть нового студента в заданную позицию списка\n"
		<< "4 - добавть нового преподавателя в конец списка\n"
		<< "5 - добавть нового преподавателя в заданную позицию списка\n"
		<< "6 - удалить элемент из начала списка\n"
		<< "7 - сортировка по ФИО\n"
		<< "8 - поиск по имени и фамилии\n"
		<< "100 - выход\n"
		<< "введите команду:"
		;
	int command;
	cin >> command;
	cout << "\n";
	return command;
}