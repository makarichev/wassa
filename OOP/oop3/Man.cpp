#include "StudentService.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;



Man::Man(string firstName, string lastName) : firstName(firstName), lastName(lastName)
{
}

Man::Man(const Man& other): firstName(other.firstName), lastName(other.lastName)
{
}


bool Man::operator==(const Man& other)
{
	return this->firstName == other.firstName && this->lastName == other.lastName;
}


ostream& operator<<(ostream& out, Man& d)
{
	out << d.firstName << " " << d.lastName;
	return out;
}

istream& operator>>(istream &in, Man&d)
{

	in >> d.firstName >> d.lastName;
	return in;
}


