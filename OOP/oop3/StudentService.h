#pragma once
#include <string>
#include <vector>
#include <fstream>

using namespace std;



class Man
{

	string lastName;
	string firstName;

	friend ostream& operator<<(ostream& out, Man& d);
	friend istream& operator>>(istream& in, Man& d);


public:

	Man(string firstName = "-", string lastName="-");
	Man(const Man& other);
	bool operator==(const Man& b);

};





class Student {

	Man man = Man();
	string department = "";
	int groupNumber = 0;

	friend ostream& operator<<(ostream&, Student&);
	friend istream& operator>>(istream&, Student&);

	friend class StudentService;

public:
	Student();
	Student(string, int, Man);
	Student(const Student&other);

	bool operator==(const Student& other);
	bool operator==(const Man& other);

};




class StudentService
{
	vector<Student> students;

public:

	StudentService();
	~StudentService();

	void Print();
	
	void Add();
	void Add(string, int, Man);

	void SortByGroupNumber();
	void SearchByDepartment(string department);


	void EtalonCompare(Student &etalon);


private: 
	bool Read(string FileName);
	void Write(string FileName);
	void LoadTestData();

};

