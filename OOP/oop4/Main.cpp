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
		command = getCommand();

		switch (command) {
		case 1:
			commonService.Print();
			break;
		case 2: {
			cout << "������� ��� ����� ������:"; Man man; cin >> man;
			cout << "���������:"; string department; cin >> department;
			cout << "����� ������:"; int groupNumber; cin >> groupNumber;
			commonService.Add(new Student(man, department, groupNumber));
			break;
		}
		case 3: {
			cout << "��� ����� ������:"; Fio fio; cin >> fio;
			cout << "������� (0 - spintex, 1 - bms, 2 - pkims):"; int cafedraNumber; cin >> cafedraNumber;
			cout << "������� ����:"; string course; cin >> course;
			commonService.Add(new Teacher(fio, static_cast<Cafedra>(cafedraNumber), course));
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
		<< "3 - ������� ������ �������������\n"
		<< "4 - ���������� �� ���\n"
		<< "5 - ����� �� ����� � �������\n"
		<< "100 - �����\n"
		<< "������� �������:"
		;
	int command;
	cin >> command;
	cout << "\n";
	return command;
}