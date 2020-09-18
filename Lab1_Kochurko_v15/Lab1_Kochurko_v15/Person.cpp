#include "Person.h"
#include <string>
#include <iostream>

using namespace std;

Person::Person()
{
	name = "empty";
	surname = "empty";
	patronymic = "empty";
	gender = '-';
	education = '-';
	yearOfBirth = -1;
}

Person::Person(string _name, string _surname, string _patronymic, char _gender, char _education, int _yearOfBirth) : name(_name), surname(_surname), patronymic(_patronymic), gender(_gender), education(_education), yearOfBirth(_yearOfBirth)
{
}

Person::~Person()
{
}

void Person::set()
{	
	cout << "Enter Name:" << endl;
	cin >> this->name;
	cout << "Enter Surname:" << endl;
	cin >> this->surname;
	cout << "Enter Patronymic:" << endl;
	cin >> this->patronymic;
	cout << "Enter Gender(M if male and F if female):" << endl;
	cin >> this->gender;
	cout << "Enter Education(H if higer, S if secondary, P if primary):" << endl;
	cin >> this->education;
	cout << "Enter year of birth" << endl;
	cin >> this->yearOfBirth;
}

void Person::setName(string _name)
{
	this->name = _name;
}

void Person::setSurname(string _surname)
{
	this->surname = _surname;
}

void Person::setPatronymic(string _patronymic)
{
	this->patronymic = _patronymic;
}

void Person::setGender(char _gender)
{
	this->gender = _gender;
}

void Person::setEducation(char _education)
{
	this->education = _education;
}

void Person::setYear(int _yearOfBirth)
{
	this->yearOfBirth = _yearOfBirth;
}

string Person::get()
{
	return name + ' ' + surname + ' ' + patronymic + ' ' + gender + ' ' + education + ' ' + to_string(yearOfBirth);
}

string Person::getName()
{
	return name;
}

string Person::getSurname()
{
	return surname;
}

string Person::getPatronymic()
{
	return patronymic;
}

char Person::getGender()
{
	return gender;
}

char Person::getEducation()
{
	return education;
}

int Person::getYear()
{
	return yearOfBirth;
}

void Person::show()
{
	cout << name << ' ' << surname << ' ' << patronymic << ' ' << gender << ' ' << education << ' ' << yearOfBirth << endl;
}


void Person::showAgeMoreThan(int year = 18)
{
	if (/*1970 + ltm->tm_year*/ 2020 - this->getYear() > year)
	{
		this->show();
	}
}
void Person::showEducationIs(char edu = 'H')
{
	if (this->getEducation() == edu)
	{
		this->show();
	}
}
void Person::showGenderIs(char gen = 'M')
{
	if (this->getGender() == 'M')
	{
		this->show();
	}
}

ostream& operator<<(ostream& os, Person& b) {
	os << b.name << ' ' << b.surname << ' ' << b.patronymic << ' ' << b.gender << ' ' << b.education << ' ' << b.yearOfBirth << endl;
	return os;
};