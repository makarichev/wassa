#include "StudentService.h"
#include <iostream>
using namespace std;



ostream& operator<<(ostream& out, Student& b)
{
	out << b.man << "\t" << b.department << "\t" << b.groupNumber << endl;
	return out;
}

istream& operator>>(istream& in, Student& b)
{
	in >> b.man >> b.department >> b.groupNumber;
	return in;
}


Student::Student()
	: department(""), groupNumber(0), man("", "")
{}

Student::Student(string department, int groupNumber, Man man)
	: department(department), groupNumber(groupNumber), man(man)
{}

Student::Student(const Student& other)
	: department(other.department), groupNumber(other.groupNumber), man(other.man)
{}

bool Student::operator==(const Student& other)
{
	return
		this->department == other.department
		&& this->groupNumber == other.groupNumber
		&& this->man == other.man
		;
}

bool Student::operator==(const Man& other)
{
	return this->man == other;
}

