#include <iostream>
#include "StudentService.h"
#include <Windows.h>
using namespace std;


int getCommand();



int main()
{
	StudentService studentService;
	

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	

	

	int command = 0;
	while (command != 100)
	{
		command = getCommand();

		switch (command) {
		case 1:
			studentService.Print();
			break;
		case 2: {
			studentService.Add();
			break;
		}
		case 3: {
			studentService.SortByGroupNumber();
			break;
		}
		case 4: {
			string department;
			cout << "¬ведите факультет:";	cin >> department;
			studentService.SearchByDepartment(department);
			break;
		}

		case 100:
			cout << "выход\n";
			break;
		default:
			cout << "не пон€л\n";
			break;
		}
	}

	

}



int getCommand() {
	cout
		<< "\n"
		<< "1 - список студентов\n"
		<< "2 - добавть нового студента\n"
		<< "3 - сортировка по возрастанию номера группы\n"
		<< "4 - поиск по факультету\n"
		<< "100 - выход\n"
		<< "введите команду:"
		;
	int command;
	cin >> command;
	cout << "\n";
	return command;
}