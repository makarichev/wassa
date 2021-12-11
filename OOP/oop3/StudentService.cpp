#include "StudentService.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const string PATH = "data.txt";



StudentService::StudentService()
{
	if (!Read(PATH)) LoadTestData();
}

StudentService::~StudentService()
{
	Write(PATH);
}


bool StudentService::Read(string fileName)
{
	
	cout << "reading from " << fileName << endl;

	ifstream fin;
	fin.open(fileName);

	if (fin.is_open()) {

		int size; fin >> size;

		for (int i = 0; i < size; i++) {
			Student student;
			fin >> student;
			students.push_back(student);
		}

		return true;
	}
	else {
		cout << "error read file " << fileName << endl;
		return false;
	}

	fin.close();

}

void StudentService::Write(string FileName)
{
	ofstream fout;
	fout.open(FileName);
	fout << students.size() << endl;
	for (Student student : students) fout << student;
	fout.close();
}

void StudentService::Print()
{
	for (Student student : students) cout << student;
}


void StudentService::Add()
{
	Man man;  cout << "��� �������:"; cin >> man;
	string department;  cout << "���������:"; cin >> department;
	int groupNumber;  cout << "������:"; cin >> groupNumber;

	Add(department, groupNumber, man);
}

void StudentService::Add(string department, int groupNumber, Man man) {
	students.push_back(Student(department, groupNumber, man));
}

void StudentService::SortByGroupNumber()
{
	vector<Student> result;
	copy(students.begin(), students.end(), back_inserter(result));
	sort(result.begin(), result.end(), [&](const Student& a, const Student& b) {return a.groupNumber < b.groupNumber; });
	for (Student student : result) cout << student;
}

void StudentService::SearchByDepartment(string department)
{

	vector<Student> result;
	copy_if(students.begin(), students.end(), back_inserter(result), [&](Student& a) { return a.department == department; });

	if (result.size() == 0)
		cout << "������ �� �������" << endl;
	else
		for (Student b : result)  cout << b;
}



void StudentService::EtalonCompare(Student&etalon)
{
	vector<Student> result;
	copy_if(students.begin(), students.end(), back_inserter(result), [&](Student& a) { return a == etalon; });

	if (result.size() == 0) {
		cout << "��������� ������ �� ������." << endl;
		students.push_back(Student(etalon));
		cout << "��������� ����� ��������." << endl;

	}
	else {
		cout << "������� " << result.size() << " ��������� ��������" << endl;
		for (Student b : result)  cout << b;
	}

}

void StudentService::LoadTestData()
{
	Add("���������1", 10, Man("����", "������"));
	Add("���������1", 20, Man("����", "������"));
	Add("���������2", 10, Man("������", "�������"));
	Add("���������2", 20, Man("�������", "���������"));
}

