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
			cout << "������� ���������:";	cin >> department;
			studentService.SearchByDepartment(department);
			break;
		}

		case 100:
			cout << "�����\n";
			break;
		default:
			cout << "�� �����\n";
			break;
		}
	}

	

}



int getCommand() {
	cout
		<< "\n"
		<< "1 - ������ ���������\n"
		<< "2 - ������� ������ ��������\n"
		<< "3 - ���������� �� ����������� ������ ������\n"
		<< "4 - ����� �� ����������\n"
		<< "100 - �����\n"
		<< "������� �������:"
		;
	int command;
	cin >> command;
	cout << "\n";
	return command;
}