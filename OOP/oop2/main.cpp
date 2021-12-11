#include <iostream>
#include "BankService.h"
#include <Windows.h>
using namespace std;


int getCommand();



int main()
{
	BankService bankService;


	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);




	int command = 0;
	while (command != 100)
	{
		command = getCommand();

		switch (command) {
		case 1:
			bankService.Print();
			break;
		case 2: {
			bankService.Add();
			break;
		}
		case 3: {
			bankService.Sort();
			break;
		}
		case 4: {
			string fan;
			cout << "������� �������:";	cin >> fan;
			bankService.Search(fan);
			break;
		}
		case 5: {
			double sum; cout << "������� �����:"; cin >> sum;
			bankService.Filter(sum);
			break;
		}
		case 6: {
			Date date;
			cout << "������� ���� (dd.mm.yyyy):";	cin >> date;
			bankService.Search(date);
			break;
		}
		case 7: {
			Date date;
			cout << "������� ���� (dd.mm.yyyy):";	cin >> date;
			bankService.Filter(date);
			break;
		}
		case 8: {
			Date date; string fan; string name; int account; double sum;
			cout << "������� ��������� ������ (dd.mm.yyyy fan name account sum):";
			cin >> date >> fan >> name >> account >> sum;
			Bank bank(fan, name, account, sum, date);
			cout << "��������� ������:" << bank << endl;

			bankService.EtalonCompare(bank);



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
		<< "1 - ������ ������\n"
		<< "2 - ������� ����� ����\n"
		<< "3 - ���������� �� �������\n"
		<< "4 - ����� �� �������\n"
		<< "5 - ������ �� ����� �� �����\n"
		<< "6 - ����� �� ����\n"
		<< "7 - ������ �� ����\n"
		<< "8 - ��������� ������\n"
		<< "100 - �����\n"
		<< "������� �������:"
		;
	int command;
	cin >> command;
	cout << "\n";
	return command;
}