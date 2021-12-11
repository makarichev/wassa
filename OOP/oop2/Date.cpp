#include "BankService.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;



Date::Date(int day, int month, int year) : day(day), month(month), year(year)
{
}

Date::Date(const Date& other): day(other.day), month(other.month), year(other.year)
{
}

bool Date::operator>=(const Date& other)
{

	if (this->year < other.year) return false;
	if (this->year > other.year) return true;
	if (this->month < other.month) return false;
	if (this->month > other.month) return true;
	if (this->day < other.day) return false;
	if (this->day >= other.day) return true;

}

bool Date::operator==(const Date& other)
{
	return this->day == other.day && this->month == other.month && this->year == other.year;
}


ostream& operator<<(ostream& out, Date& d)
{
	d.day < 10? out << "0" << d.day : out << d.day;
	out << '.';
	d.month < 10? out << "0" << d.month: out << d.month;
	out << '.' << d.year;
	return out;
}

istream& operator>>(istream &in, Date &d)
{
	char s;
	in >> d.day >> s >> d.month >> s >> d.year;
	return in;
}


