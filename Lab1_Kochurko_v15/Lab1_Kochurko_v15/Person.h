#pragma once
#include <string>
using namespace std;

class Person
{
private:
	string name;
	string surname;
	string patronymic;
	char gender;
	char education;
	int yearOfBirth;

public: 
	Person();
	Person(string _name, string _surname, string _patronymic, char _gender, char _education, int _yearOfBirth);
	~Person();
	void set();
	void setName(string);
	void setSurname(string);
	void setPatronymic(string);
	void setGender(char);
	void setEducation(char);
	void setYear(int);
	string get();
	string getName();
	string getSurname();
	string getPatronymic();
	char getGender();
	char getEducation();
	int getYear();
	void show();
};
