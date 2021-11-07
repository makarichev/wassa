#pragma once
#include <string>
#include <vector>
#include <fstream>

using namespace std;


class Date
{


	int day;
	int month;
	int year;


	friend ostream& operator<<(ostream& out, Date& d);
	friend istream& operator>>(istream& in, Date& d);
	
	

public:

	Date(int day = 1, int month = 1, int year = 1900);
	Date(const Date &other);

	bool operator>=(const Date& b);
	bool operator==(const Date& b);

};



class Bank {

	string fan = "";
	string name = "";
	int account = 0;
	double sum = 0;
	Date date = Date(1, 1, 1900);

	friend ostream& operator<<(ostream&, Bank&);
	friend istream& operator>>(istream&, Bank&);

	friend class BankService;

public:
	Bank();
	Bank(string, string, int, double, Date);
	Bank(const Bank &other);

	bool operator==(const Bank& other);
};




class BankService
{
	vector<Bank> banks;

public:

	BankService();
	~BankService();

	void Print();
	
	void Add();
	void Add(string, string, int, double, Date);

	void Sort();
	void Search(string fan);
	void Search(Date date);
	void Filter(double sum);
	void Filter(Date date);

	void EtalonCompare(Bank &etalon);


private: 
	bool Read(string FileName);
	void Write(string FileName);
	void LoadTestData();

};

