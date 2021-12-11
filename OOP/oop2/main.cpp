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
			cout << "¬ведите фамилию:";	cin >> fan;
			bankService.Search(fan);
			break;
		}
		case 5: {
			double sum; cout << "¬ведите сумму:"; cin >> sum;
			bankService.Filter(sum);
			break;
		}
		case 6: {
			Date date;
			cout << "¬ведите дату (dd.mm.yyyy):";	cin >> date;
			bankService.Search(date);
			break;
		}
		case 7: {
			Date date;
			cout << "¬ведите дату (dd.mm.yyyy):";	cin >> date;
			bankService.Filter(date);
			break;
		}
		case 8: {
			Date date; string fan; string name; int account; double sum;
			cout << "¬ведите эталонный объект (dd.mm.yyyy fan name account sum):";
			cin >> date >> fan >> name >> account >> sum;
			Bank bank(fan, name, account, sum, date);
			cout << "эталонный объект:" << bank << endl;

			bankService.EtalonCompare(bank);



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
		<< "1 - список счетов\n"
		<< "2 - добавть новый счЄт\n"
		<< "3 - сортировка по фамилии\n"
		<< "4 - поиск по фамилии\n"
		<< "5 - фильтр по сумме на счете\n"
		<< "6 - поиск по дате\n"
		<< "7 - фильтр по дате\n"
		<< "8 - эталонный объект\n"
		<< "100 - выход\n"
		<< "введите команду:"
		;
	int command;
	cin >> command;
	cout << "\n";
	return command;
}