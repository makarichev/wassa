#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;



struct Bank {
	string Fan;
	string Name;
	int Account;
	double Sum;
	
	void Print() { cout << Fan << "\t" << Name << "\t" << Account << "\t" << Sum << "\n"; }
	
	void Write(ofstream &fout) {
		fout << Fan << endl;
		fout << Name << endl;
		fout << Account << endl;
		fout << Sum << endl;
	}

	static Bank Read(ifstream &fin) {
		Bank bank;
		fin >> bank.Fan;
		fin >> bank.Name;
		fin >> bank.Account;
		fin >> bank.Sum;
		return bank;
	}

};



vector<Bank> banks;
const string PATH = "data.txt";


/*прототипы*/
void loadData();
int getCommand();
void ListBanks();
void AddBank();
void loadTestData();
void saveData();
void loadData();
void sortBanks();
void filterBanks();
void filterSum();


int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//setlocale(LC_ALL, "Rus");


	loadData();

	int command = 0;
	while (command != 100)
	{
		command = getCommand();

		switch (command) {
		case 1:
			ListBanks();
			break;
		case 2:
			AddBank();
			break;
		case 3:
			sortBanks();
			break;
		case 4:
			filterBanks();
			break;
		case 5:
			filterSum();
			break;
		case 100:
			cout << "выход\n";
			break;
		default:
			cout << "не понял\n";
			break;
		}


	}

	saveData();


}


int getCommand() {
	cout
		<< "\n"
		<< "1 - список счетов\n"
		<< "2 - добавть новый счёт\n"
		<< "3 - сортировка по фамилии\n"
		<< "4 - поиск по фамилии\n"
		<< "5 - фильтр по сумме\n"
		<< "100 - выход\n"
		<< "введите команду:"
		;
	int command;
	cin >> command;
	cout << "\n";
	return command;
}


void ListBanks() {
	for (Bank bank : banks) bank.Print();
}


void sortBanks() {
	
	vector<Bank> result;
	copy(banks.begin(), banks.end(), back_inserter(result));
	sort(result.begin(), result.end(), [](const Bank& a, const Bank& b) {return a.Fan < b.Fan; });
	for (Bank bank : result) bank.Print();
}


void filterBanks() {

	string searchString;
	cout << "Введите фамилию:";
	cin >> searchString;

	vector<Bank> result;
	copy_if(banks.begin(), banks.end(), back_inserter(result), [&](Bank& a) {
		return a.Fan == searchString;
		});

	if (result.size() == 0)
		cout << "Ничего не найдено" << endl;
	else
		for (Bank b : result) b.Print();
}


void filterSum() {

	double sum;
	cout << "Введите сумму:";
	cin >> sum;

	vector<Bank> result;

	copy_if(banks.begin(), banks.end(), back_inserter(result), [&](Bank& a) {
		return a.Sum >= sum;
		});

	if (result.size() == 0)
		cout << "Ничего не найдено" << endl;
	else
		for (Bank b : result) b.Print();
}


void AddBank() {

	Bank bank;
	cout << "фамилия:"; cin >> bank.Fan;
	cout << "имя:"; cin >> bank.Name;
	cout << "счёт:"; cin >> bank.Account;
	cout << "сумма:"; cin >> bank.Sum;

	banks.push_back(bank);
}


void saveData() {

	ofstream fout;
	fout.open(PATH);
	fout << banks.size() << endl;

	for (Bank bank : banks) bank.Write(fout);

	fout.close();
}

void loadData() {


	cout << "Загрузка данных" << endl;

	ifstream fin;
	fin.open(PATH);

	if (fin.is_open()) {


		int size;
		fin >> size;

		for (int i = 0; i < size; i++) {
			banks.push_back(Bank::Read(fin));
		}

	}
	else {
		cout << "error read file " << PATH << endl;
		cout << "loading test data" << endl;
		loadTestData();
	}

	fin.close();

}


void loadTestData() {

	Bank b2;
	b2.Fan = "Сидорова";
	b2.Name = "Ирина";
	b2.Account = 10002;
	b2.Sum = 2999.99;
	banks.push_back(b2);

	Bank b0;
	b0.Fan = "Иванов";
	b0.Name = "Иван";
	b0.Account = 10000;
	b0.Sum = 999.99;
	banks.push_back(b0);

	Bank b1;
	b1.Fan = "Петров";
	b1.Name = "Пётр";
	b1.Account = 10001;
	b1.Sum = 1999.99;
	banks.push_back(b1);


}


