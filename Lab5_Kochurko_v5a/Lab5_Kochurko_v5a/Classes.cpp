#include<iostream>
#include <string>
#include "Classes.h"
using namespace std;


/*

	LEARNER

*/
Learner::Learner()
{
	name = "empty";
	surname = "empty";
	patronymic = "empty";
	gender = '-';
}

Learner::Learner(string _name, string _surname, string _patronymic, char _gender, int _age):name(_name), surname(_surname), patronymic(_patronymic), gender(_gender), age(_age)
{
}

Learner::~Learner()
{
}

void Learner::set()
{
	cout << "Enter Name:" << endl;
	cin >> this->name;
	cout << "Enter Surname:" << endl;
	cin >> this->surname;
	cout << "Enter Patronymic:" << endl;
	cin >> this->patronymic;
	cout << "Enter Gender(M if male and F if female):" << endl;
	cin >> this->gender;
	cout << "Enter age" << endl;
	cin >> this->age;
}


void Learner::setName(string name)
{
	this->name = name;
}

void Learner::setSurname(string surname)
{
	this->surname = surname;
}

void Learner::setPatronymic(string patronymic)
{
	this->patronymic = patronymic;
}

void Learner::setAge(int age)
{
	this->age = age;
}

void Learner::setGender(char gender)
{
	this->gender = gender;
}

string Learner::get()
{
	return name + ' ' + surname + ' ' + patronymic + ' ' + gender + ' ' + to_string(age);
}

string Learner::getName()
{
	return name;
}

string Learner::getSurname()
{
	return surname;
}

string Learner::getPatronymic()
{
	return patronymic;
}

char Learner::getGender()
{
	return gender;
}

int Learner::getAge()
{
	return age;
}

void Learner::show()
{
	cout << name << ' ' << surname << ' ' << patronymic << ' ' << gender << ' ' << age << endl;
}


/*

	STUDENT

*/

Student::Student() : Learner()
{
	this->courseNumber = -1;
	this->groupNumber = -1;
	this->paidOrFree = NULL;
	this->recordBookNumber = -1;
	this->typeOfStuding = '-';
}

Student::Student(string _name, string _surname, string _patronymic, char _gender, int _age, int _recordBookNumber, int _groupNumber, int _courseNumber, char _typeOfStuding, bool _paidOrFree) : Learner(_name, _surname, _patronymic, _gender, _age)
{
	this->courseNumber = _courseNumber;
	this->groupNumber = _groupNumber;
	this->paidOrFree = _paidOrFree;
	this->recordBookNumber = _recordBookNumber;
	this->typeOfStuding = _typeOfStuding;
}

Student::~Student()
{
}

void Student::set()
{
	Learner::set();
	cout << "Enter course number" << endl;
	cin >> this->courseNumber;
	cout << "Enter group number" << endl;
	cin >> this->groupNumber;
	cout << "Enter what type of your studing(daytime --- 'd' or evening --- 'e' )" << endl;
	cin >> this->typeOfStuding;
	cout << "Enter what type of your studing(1 --- free / 0 --- paid)" << endl;
	cin >> this->paidOrFree;
	cout << "Enter your id" << endl;
	cin >> this->recordBookNumber;
}


int Student::getGroupNumber() 
{
	return groupNumber;
}

int Student::getCourseNumber()
{
	return courseNumber;
}

char Student::getTypeOfStuding()
{
	return typeOfStuding;
}

bool Student::getPaidOrFree()
{
	return paidOrFree;

}
void Student::setGroupNumber(int number)
{
	this->groupNumber = number;
}

void Student::setCourseNumber(int number)
{
	this->courseNumber = number;
}

void Student::setTypeOfStuding(char type)
{
	this->typeOfStuding = type;
}

void Student::setPaidOrFree(bool flag)
{
	this->paidOrFree = flag;
}

void Student::showStudentInfo()
{
	cout << recordBookNumber << ' ' << name << ' ' << surname << ' ' << patronymic << ' ' << gender << ' ' << age << endl
		<< "course: " << courseNumber << " group: " << groupNumber << ' ' << ((paidOrFree) ? "free" : "paid") << endl;
}
/*

	SCHOOLCHILD

*/


Schoolchild::Schoolchild() : Learner()
{
	this->classLatter = '-';
	this->classNumber = 0;
	this->familyType = '-';
}

Schoolchild::Schoolchild(string _name, string _surname, string _patronymic, char _gender, int _age, char _classLatter, int _classNumber, char _familyType) : Learner(_name, _surname, _patronymic, _gender, _age)
{
	this->classLatter = _classLatter;
	this->classNumber = _classNumber;
	this->familyType = _familyType;
}

Schoolchild::~Schoolchild()
{
}


void Schoolchild::set()
{
	Learner::set();
	cout << "Enter class number" << endl;
	cin >> this->classLatter;
	cout << "Enter class latter" << endl;
	cin >> this->classLatter;
	cout << "Enter what type of your family(large --- true or ordinary --- false )" << endl;
	cin >> this->familyType;
}

char Schoolchild::getclassLatter()
{
	return classLatter;

}
int Schoolchild::getclassNumber()
{
	return classNumber;
}
char Schoolchild::getfamilyType()
{
	return familyType;
}
void Schoolchild::setclassLatter(char latter)
{
	classLatter = latter;
}
void Schoolchild::setclassNumber(int number)
{
	classNumber = number;
}
void Schoolchild::setfamilyType(char type)
{
	familyType = type;
}

void Schoolchild::showSchoolchildInfo()
{
	cout << name << ' ' << surname << ' ' << patronymic << ' ' << gender << ' ' << age << endl
		<< "class: " << classNumber << classLatter << " family type:" << ((familyType) ? "large" : "ordinary") << endl;
}