#pragma once
#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <regex>

using namespace std;


class Man
{

	string lastName;
	string firstName;

	friend ostream& operator<<(ostream& out, Man& d) {
		out << d.lastName << " " << d.firstName;
		return out;

	}
	friend istream& operator>>(istream& in, Man& d) {
		in >> d.lastName >> d.firstName;
		return in;
	}


public:

	Man(string lastName = "?", string firstName = "?") : firstName(firstName), lastName(lastName) {}
	Man(const Man& other) : firstName(other.firstName), lastName(other.lastName) {}

	bool operator==(const Man& b) {
		return this->firstName == b.firstName && this->lastName == b.lastName;
	};

	string get_firstName() { return firstName; }
	string get_lastName() { return lastName; }

};


class Fio
{

	string firstName;
	string secondName;
	string lastName;

	friend ostream& operator<<(ostream& out, Fio& d) {
		out << d.lastName << " " << d.firstName << " " << d.secondName;
		return out;
	}

	friend istream& operator>>(istream& in, Fio& d) {
		in >> d.lastName >> d.firstName >> d.secondName;
		return in;
	}




public:


	Fio(string lastName = "?", string firstName = "?", string secondName = "?") : firstName(firstName), secondName(secondName), lastName(lastName)
	{
	}

	string get_firstName() { return firstName; }
	string get_secondName() { return secondName; }
	string get_lastName() { return lastName; }

	bool operator==(const Fio& b) {
		return this->firstName == b.firstName && this->lastName == b.lastName && this->secondName == b.secondName;
	};

};



class Common
{

protected:

	static bool checkName(string name) {


		regex expression("^[а-яёА-ЯЁ]+$");
		sregex_token_iterator first(name.begin(), name.end(), expression);
		sregex_token_iterator last;
		return (first != last);
	}

public:


	virtual void Print() {}

	virtual void Write(ofstream& fout) {}

	virtual void Read(ifstream& fin) {}

	virtual string sortingName() { return ""; }

	virtual bool findMe(string lastName, string firstName) { return false; }




};


class Leaner : public Common {

	Man man;


public:
	Leaner(Man man = Man()) : Common(), man(man) {}

	Man get_Man() { return man; }
	void set_Man(Man value) { man = value; }

	virtual void Print() {
		cout << man;
	}

	virtual void Write(ofstream& fout) {
		fout << man << endl;
	}

	virtual void Read(ifstream& fin) {
		fin >> man;
	}

	virtual string sortingName() { return man.get_lastName(); }
	virtual bool findMe(string lastName, string firstName) {
		return man.get_lastName() == lastName && man.get_firstName() == firstName;
	}

};



class Prepod : public Common {

	Fio fio;

public:
	Prepod(Fio fio = Fio()) : Common(), fio(fio) {}

	Fio get_Fio() { return fio; }
	void set_Fio(Fio value) { fio = value; }

	virtual void Print() {
		cout << fio;
	}


	virtual void Write(ofstream& fout) {
		fout << fio << endl;
	}

	virtual void Read(ifstream& fin) {
		fin >> fio;
	}

	virtual string sortingName() { return fio.get_lastName(); }

	virtual bool findMe(string lastName, string firstName) {
		return fio.get_lastName() == lastName && fio.get_firstName() == firstName;
	}


};



class Student : public Leaner {

	string department = "";
	int groupNumber = 0;

	friend istream& operator>>(istream& cin, Student& d) {
		


		cout << "Фамилия Имя через пробел:"; Man man; cin >> man;
		if (!checkName(man.get_lastName()) || !checkName(man.get_firstName())) {
			throw exception("Введены недопустимые символы!");
		}
		d.set_Man(man);

		cout << "Факультет:"; string department; cin >> department;
		if (!checkName(department)) {
			throw exception("Введены недопустимые символы!");
		}
		d.department = department;


		cout << "Номер группы:"; int groupNumber; cin >> groupNumber;
		if (cin.fail()) {
			throw exception("Не корректный ввод");
		}

		d.groupNumber = groupNumber;
		
	}


public:
	Student(Man man = Man(), string department = "-", int groupNumber = 0) : Leaner(man), department(department), groupNumber(groupNumber)
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




enum Cafedra { spintex, bms, pkims };


class Teacher : public Prepod {

	Cafedra cafedra;
	string course;
	string cafedraNames[3]{ "spintex","bms","pkims" };


	friend istream& operator>>(istream& cin, Teacher& d) {
		cout << "ФИО через пробел:"; Fio fio; cin >> fio;
		if (!checkName(fio.get_lastName()) || !checkName(fio.get_firstName()) || !checkName(fio.get_secondName())) {
			throw exception("Введены недопустимые символы!");
		}
		d.set_Fio(fio);

		cout << "Кафедра (0 - spintex, 1 - bms, 2 - pkims):"; int cafedraNumber; cin >> cafedraNumber;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			throw exception("Не корректный ввод");
		}
		if (cafedraNumber != 0 && cafedraNumber != 1 && cafedraNumber != 2) {
			throw exception("Не корректно указана кафедра");
		}

		d.cafedra = static_cast<Cafedra>(cafedraNumber);


		cout << "Учкбный курс:"; string course; cin >> course;
		if (!checkName(course)) {
			throw exception("Введены недопустимые символы!");
		}

		d.course = course;
		

	}

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
	list<Common*> records;
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



	void Add(Common* item) {
		records.push_back(item);
	}

	void Add(Common* item, int position) {
		auto it = records.begin();
		advance(it, position);
		records.insert(it, item);
	}



	bool checkName(string name) {

		//regex expression("\\b[a-zA-Z]");
		regex expression("^[а-яёА-ЯЁ]+$");
		sregex_token_iterator first(name.begin(), name.end(), expression);
		sregex_token_iterator last;
		return (first != last);
	}


	void AddStudent() {
		try
		{
			Student* s = new Student;
			cin >> *s;
			Add(s);

		}
		catch (const std::exception& ex)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "ERROR:" << ex.what() << endl;
		}
	}

	void AddStudent(int position) {
		try
		{
			Student* s = new Student;
			cin >> *s;
			Add(s, position);

		}
		catch (const std::exception& ex)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "ERROR:" << ex.what() << endl;
		}
	}

	void AddTeacher() {
		try
		{

			Teacher* s = new Teacher;
			cin >> *s;
			Add(s);


		}
		catch (const exception& ex)
		{
			cout << "ERROR:" << ex.what() << endl;
		}
	}


	void AddTeacher(int position) {
		try
		{

			Teacher* s = new Teacher;
			cin >> *s;
			Add(s, position);


		}
		catch (const exception& ex)
		{
			cout << "ERROR:" << ex.what() << endl;
		}
	}


	void RemoveFirst() {
		records.pop_front();
	}


	void Sort()
	{


			vector<Common*> result;
			copy(records.begin(), records.end(), back_inserter(result));
			sort(result.begin(), result.end(), [](Common* a, Common* b) {
				return a->sortingName() < b->sortingName();
				});
			for (Common* student : result) {
				student->Print();
				cout << endl;
			}

	}


	void Find()
	{

		try
		{
			cout << "Фамилия:"; string lastName; cin >> lastName;
			if (!checkName(lastName)) 
				throw exception("Введены недопустимые символы!");
			

			cout << "Имя:"; string firstName; cin >> firstName;
			if (!checkName(firstName))
				throw exception("Введены недопустимые символы!");

			vector<Common*> result;
			copy_if(records.begin(), records.end(), back_inserter(result), [&](Common* a) {
				return a->findMe(lastName, firstName);
				});

			if (result.size() == 0)
				cout << "Ничего не найдено" << endl;
			else
				for (Common* record : result) {
					record->Print();
					cout << endl;
				}


		}
		catch (const std::exception& ex)
		{
			cout << "ERROR:" << ex.what() << endl;
		}


	}


	void LoadTestData() {

		Add(new Student(Man("Николаев", "Николай"), "факультет1", 115));
		Add(new Student(Man("Сидоров", "Сидор"), "факультет1", 116));
		Add(new Teacher(Fio("Петров", "Пётр", "Петрович"), Cafedra::bms, "Математика"));
		Add(new Student(Man("Степвнов", "Степан"), "факультет1", 115));
		Add(new Teacher(Fio("Макарычев", "Василий", "Дмитриевич"), Cafedra::pkims, "Физика"));
		Add(new Student(Man("Ольгина", "Ольга"), "факультет2", 116));
		Add(new Student(Man("Макарычев", "Василий"), "факультет2", 116));
	}

};

