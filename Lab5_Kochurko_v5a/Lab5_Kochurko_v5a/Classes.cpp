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

void Learner::setName()
{
	cout << "Name: ";
	cin >> this->name;
}

void Learner::setSurname(string surname)
{
	this->surname = surname;
}

void Learner::setSurname()
{
	cout << "Surname: ";
	cin >> this->surname;
}

void Learner::setPatronymic(string patronymic)
{
	this->patronymic = patronymic;
}

void Learner::setPatronymic()
{
	cout << "Patronymic: ";
	cin >> this->patronymic;
}

void Learner::setAge(int age)
{
	this->age = age;
}

void Learner::setAge()
{
	cout << "Age: ";
	cin >> this->age;
}

void Learner::setGender(char gender)
{
	this->gender = gender;
}

void Learner::setGender(char gender)
{
	cout << "Gender: ";
	cin >> this->gender;
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

std::ostream& operator<< (std::ostream& out, const Learner& learner)
{
	out << learner.name << ' ' << learner.surname << ' ' << learner.patronymic
		<< ' ' << learner.gender << ' ' << learner.age << endl;

	return out;
}

istream& operator>> (std::istream& in, Learner* learner)
{
	learner->setName();
	learner->setSurname();
	learner->setPatronymic();
	learner->setGender();
	learner->setAge();
	return in;
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

void Student::setGroupNumber()
{
	cout << "Group Number: ";
	cin >> this->groupNumber;
}

void Student::setCourseNumber(int number)
{
	this->courseNumber = number;
}

void Student::setCourseNumber()
{
	cout << "Course Number: ";
	cin >> this->courseNumber;
}

void Student::setTypeOfStuding(char type)
{
	this->typeOfStuding = type;
}

void Student::setTypeOfStuding()
{
	cout << "Type of Studing: ";
	cin >> this->typeOfStuding;
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

std::ostream& operator<< (std::ostream& out, const Student& student)
{
	out << student.name << ' ' << student.surname << ' ' << student.patronymic << ' ' << student.gender << ' ' << student.age << ' ' << student.recordBookNumber << ' ' << student.groupNumber
		<< ' ' << student.courseNumber << ' ' << student.typeOfStuding << ' ' << student.paidOrFree << endl;

	return out;
}
istream& operator>> (std::istream& in, Student* student)
{
	student->setName();
	student->setSurname();
	student->setPatronymic();
	student->setGender();
	student->setAge();
	student->setCourseNumber();
	student->setGroupNumber();
	student->setTypeOfStuding();

	return in;
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
	this->classLatter = latter;
}

void Schoolchild::setclassLatter()
{
	cout << "Class latter: ";
	cin >> this->classLatter;
}

void Schoolchild::setclassNumber(int number)
{
	this->classNumber = number;
}

void Schoolchild::setclassNumber()
{
	cout << "Class number: ";
	cin >> this->classNumber;
}

void Schoolchild::setfamilyType(char type)
{
	this->familyType = type;
}

void Schoolchild::setfamilyType(char type)
{
	cout << "Family Type: ";
	cin >> this->familyType;
}


void Schoolchild::showSchoolchildInfo()
{
	cout << name << ' ' << surname << ' ' << patronymic << ' ' << gender << ' ' << age << endl
		<< "class: " << classNumber << classLatter << " family type:" << ((familyType) ? "large" : "ordinary") << endl;
}

std::ostream& operator<< (std::ostream& out, const Schoolchild& schoolchild)
{
	out << schoolchild.name << ' ' << schoolchild.surname << ' ' << schoolchild.patronymic << ' ' << schoolchild.gender << ' ' << schoolchild.age << ' ' << schoolchild.classNumber << schoolchild.classLatter
		<< ' ' << schoolchild.familyType << endl;

	return out;
}

istream& operator>> (std::istream& in, Schoolchild* schoolchild)
{
	schoolchild->setName();
	schoolchild->setSurname();
	schoolchild->setPatronymic();
	schoolchild->setGender();
	schoolchild->setAge();
	schoolchild->setclassLatter();
	schoolchild->setclassLatter();
	schoolchild->setfamilyType();

	return in;
}