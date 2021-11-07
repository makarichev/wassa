#include "BankService.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const string PATH = "data.txt";



BankService::BankService()
{
	if (!Read(PATH)) LoadTestData();
}

BankService::~BankService()
{
	Write(PATH);
}


bool BankService::Read(string fileName)
{
	
	cout << "reading from " << fileName << endl;

	ifstream fin;
	fin.open(fileName);

	if (fin.is_open()) {

		int size; fin >> size;

		for (int i = 0; i < size; i++) {
			Bank bank;
			fin >> bank;
			banks.push_back(bank);
		}

		return true;
	}
	else {
		cout << "error read file " << fileName << endl;
		return false;
	}

	fin.close();

}

void BankService::Write(string FileName)
{
	ofstream fout;
	fout.open(FileName);
	fout << banks.size() << endl;
	for (Bank bank : banks) fout << bank;
	fout.close();
}

void BankService::Print()
{
	for (Bank bank : banks) cout << bank;
}


void BankService::Add()
{
	Date date;  cout << "дата(dd.mm.yyyy):"; cin >> date;
	string fan;  cout << "фамилия:"; cin >> fan;
	string name;  cout << "имя:"; cin >> name;
	int account;  cout << "счёт:"; cin >> account;
	double sum;  cout << "сумма:"; cin >> sum;

	Add(fan, name, account, sum, date);
}

void BankService::Add(string fan, string name, int account, double sum, Date date) {
	banks.push_back(Bank(fan, name, account, sum, date));
}

void BankService::Sort()
{

	vector<Bank> result;
	copy(banks.begin(), banks.end(), back_inserter(result));
	sort(result.begin(), result.end(), [](const Bank& a, const Bank& b) {return a.fan < b.fan; });
	for (Bank bank : result) cout << bank;
}

void BankService::Search(string fan)
{

	vector<Bank> result;
	copy_if(banks.begin(), banks.end(), back_inserter(result), [&](Bank& a) { return a.fan == fan; });

	if (result.size() == 0)
		cout << "Ничего не найдено" << endl;
	else
		for (Bank b : result)  cout << b;
}


void BankService::Search(Date date)
{
	vector<Bank> result;
	copy_if(banks.begin(), banks.end(), back_inserter(result), [&](Bank& a) { return a.date == date; });
	if (result.size() == 0)
		cout << "Ничего не найдено" << endl;
	else
		for (Bank b : result)  cout << b;
}


void BankService::Filter(double sum)
{
	vector<Bank> result;
	copy_if(banks.begin(), banks.end(), back_inserter(result), [&](Bank& a) { return a.sum >= sum; });
	if (result.size() == 0)
		cout << "Ничего не найдено" << endl;
	else
		for (Bank b : result) cout << b;
}


void BankService::Filter(Date date)
{
	vector<Bank> result;
	copy_if(banks.begin(), banks.end(), back_inserter(result), [&](Bank& a) { return a.date >= date; });
	if (result.size() == 0)
		cout << "Ничего не найдено" << endl;
	else
		for (Bank b : result)  cout << b;

}

void BankService::EtalonCompare(Bank &etalon)
{
	vector<Bank> result;
	copy_if(banks.begin(), banks.end(), back_inserter(result), [&](Bank& a) { return a == etalon; });

	if (result.size() == 0) {
		cout << "эталонный объект не найден." << endl;
		banks.push_back(Bank(etalon));
		cout << "эталонный обект добавлен." << endl;

	}
	else {
		cout << "найдено " << result.size() << " эталонных объектов" << endl;
		for (Bank b : result)  cout << b;
	}

}

void BankService::LoadTestData()
{
	Add("Иванов", "Иван", 10000, 999.99, Date(1, 12, 2020));
	Add("Петров", "Пётр", 10001, 1999.99, Date(28, 2, 2021));
	Add("Сидорова", "Ирина", 10002, 2999.99, Date(14, 10, 2021));
}

