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
				cout << "�������:"; int position; cin >> position;
				commonService.AddStudent(position);
				break;
			}

			case 4: {
				commonService.AddTeacher();
				break;
			}

			case 5: {
				cout << "�������:"; int position; cin >> position;
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
				cout << "�����\n";
				break;
			default:
				cout << "�� �����\n";
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
		<< "1 - ������ ���������\n"
		<< "2 - ������� ������ �������� � ����� ������\n"
		<< "3 - ������� ������ �������� � �������� ������� ������\n"
		<< "4 - ������� ������ ������������� � ����� ������\n"
		<< "5 - ������� ������ ������������� � �������� ������� ������\n"
		<< "6 - ������� ������� �� ������ ������\n"
		<< "7 - ���������� �� ���\n"
		<< "8 - ����� �� ����� � �������\n"
		<< "100 - �����\n"
		<< "������� �������:"
		;
	int command;
	cin >> command;
	cout << "\n";
	return command;
}