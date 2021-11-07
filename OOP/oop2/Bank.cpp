#include "BankService.h"
#include <iostream>
using namespace std;



ostream& operator<<(ostream& out, Bank& b)
{
	out << b.date << "\t" << b.fan << "\t" << b.name << "\t" << b.account << "\t" << b.sum << endl;
	return out;
}

istream& operator>>(istream& in, Bank& b)
{
	in >> b.date >> b.fan >> b.name >> b.account >> b.sum;
	return in;
}


Bank::Bank() 
	: fan(""), name(""), account(0), sum(0), date(Date(1,1,1900))
{}

Bank::Bank(string fan, string name, int account, double sum, Date date)
	: fan(fan), name(name), account(account), sum(sum), date(date)
{}

Bank::Bank(const Bank& other)
	: fan(other.fan), name(other.name), account(other.account), sum(other.sum), date(other.date)
{}

bool Bank::operator==(const Bank& other)
{
	return
		this->fan == other.fan
		&& this->fan == other.fan
		&& this->name == other.name
		&& this->account == other.account
		&& this->sum == other.sum
		&& this->date == other.date
		;
}

