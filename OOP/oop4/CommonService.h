#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

class Fio
{

	string firstName;
	string secondName;
	string lastName;

	friend ostream& operator<<(ostream& out, Fio& d) {
		out << d.firstName << " " << d.secondName << " " << d.lastName;
		return out;
	}

	friend istream& operator>>(istream& in, Fio& d) {
		in >> d.firstName >> d.secondName >> d.lastName;
		return in;
	}

	


public:


	Fio(string firstName = "?", string secondName = "?", string lastName = "?") : firstName(firstName), secondName(secondName), lastName(lastName)
	{
	}

	bool operator<(const Fio& other)
	{
		if (this->lastName < other.lastName) return true;
		if (this->lastName > other.lastName) return false;

		if (this->firstName < other.firstName) return true;
		if (this->firstName > other.firstName) return false;

		if (this->secondName < other.secondName) return true;
		if (this->secondName > other.secondName) return false;
	}
};



class Common
{

public:

	Fio fio;

	Common(Fio fio = Fio())
	{
		this->fio = fio;
	}

	virtual void Print() {
		cout << fio;
	}

	virtual void Write(ofstream& fout) {
		fout << fio << endl;
	}

	virtual void Read(ifstream& fin) {
		fin >> fio;
	}


};


class Leaner : public Common {
public:
	Leaner(Fio fio = Fio()) : Common(fio) {}
};



class Prepod : public Common {
public:
	Prepod(Fio fio = Fio()) : Common(fio) {}
};



class Student : public Leaner {

	string department = "";
	int groupNumber = 0;


public:
	Student(Fio fio = Fio(), string department = "-", int groupNumber = 0) : Leaner(fio), department(department), groupNumber(groupNumber)
	{
	}

	void Print() {
		cout << "студент:";
		Leaner::Print();
		cout << " Факультет:" << department;
		cout << " Номер группы:" << groupNumber;
	}

	void Write(ofstream& fout) {
		fout << "student" << endl;
		Leaner::Write(fout);
		fout << department << endl;
		fout << groupNumber << endl;
		
	}

	void Read(ifstream& fin) {
		Leaner::Read(fin);
		fin >> department;
		fin >> groupNumber;
	}

	
};




enum Cafedra {spintex,bms,pkims};


class Teacher : public Prepod {
	
	Cafedra cafedra;
	string course;
	string cafedraNames[3] {"spintex","bms","pkims"};

public:


	Teacher(Fio fio = Fio(), Cafedra cafedra = Cafedra::bms, string course = "-") : Prepod(fio), cafedra(cafedra), course(course) {}


	void Print() {
		cout << "преподователь: ";
		Prepod::Print();
		cout << " Кафедра:" << cafedraNames[cafedra] << " курс:" << course;
		{

		};
	}

	void Write(ofstream& fout) {
		fout << "teacher" << endl;
		Prepod::Write(fout);
		fout << cafedra << endl;
		fout << course << endl;

	}
	void Read(ifstream& fin) {
		Prepod::Read(fin);
		int temp;
		fin >> temp;
		cafedra = static_cast<Cafedra>(temp);
		fin >> course;
	}

};



class CommonService {
	vector<Common*> records;
	const string PATH = "data.txt";

public:

	CommonService() {
		if (!Read(PATH)) 
			LoadTestData();
	}

	~CommonService() {
		Write(PATH);
	}


	void Print() {
		for (Common* record : records) {
			record->Print();
			cout << endl;

		}
	}
	
	void Write(string FileName) {
		ofstream fout;
		fout.open(FileName);
		fout << records.size() << endl;
		for (Common* record : records) {
			record->Write(fout);
		}
		fout.close();

	}


	bool Read(string fileName) {
		cout << "reading from " << fileName << endl;

		ifstream fin;
		fin.open(fileName);

		bool result;

		if (fin.is_open()) {

			int size; fin >> size;

			for (int i = 0; i < size; i++) {

				string className;
				fin >> className;

				if (className == "student") {

					Student* record = new Student();
					record->Read(fin);
					Add(record);
				
				}
				else if (className == "teacher") {
					Teacher* record = new Teacher();
					record->Read(fin);
					Add(record);
				}



			}

			result = true;
		}
		else {
			cout << "error read file " << fileName << endl;
			result = false;
		}

		fin.close();
		return result;
	}



	void Add(Common* student) {
		records.push_back(student);
	}
	


	void Sort()
	{
		vector<Common*> result;
		copy(records.begin(), records.end(), back_inserter(result));
		sort(result.begin(), result.end(), [](Common* a, Common* b) {return a->fio < b->fio; });
		for (Common* student : result) {
			student->Print();
			cout << endl;
		}
	}
	

	void LoadTestData() {

		Add(new Student(Fio("Николай", "Николаевич", "Николаев"), "факультет1", 115));
		Add(new Teacher(Fio("Пётр", "Петрович", "Петров"), Cafedra::bms, "Математика"));
		Add(new Student(Fio("Сидор", "Сидорович", "Сидоров"), "факультет1", 116));
		Add(new Student(Fio("Степвнов", "Стеиан", "Степанович"), "факультет1", 115));
		Add(new Teacher(Fio("Макарычев", "Василий", "Дмитриевич"), Cafedra::pkims, "Физика"));
		Add(new Student(Fio("Ольгина", "Ольга", "Олеговна"), "факультет1", 116));
	}

};

