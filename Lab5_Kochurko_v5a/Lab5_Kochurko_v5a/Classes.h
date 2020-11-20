#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Learner {
	friend ostream& operator<< (ostream& out, const Learner& learner);
	friend istream& operator>> (istream& in, const Learner* learner);

protected:
	string name;
	string surname;
	string patronymic;
	char gender;
	int age;
public:
	Learner();
	Learner(string name, string surname, string patronymic, char gender, int age);
	~Learner();
	void show();
	string get();
	string getName();
	string getSurname();
	string getPatronymic();
	int getAge();
	char getGender();
	void set();
	void setName(string name);
	void setName();
	void setSurname(string surname);
	void setSurname();
	void setPatronymic(string patronymic);
	void setPatronymic();
	void setAge(int age);
	void setAge();
	void setGender(char gender);
	void setGender();
};

class Student : public Learner {
	friend std::ostream& operator<< (std::ostream& out, const Student& student);
	friend istream& operator>> (istream& in, const Learner* learner);

private:
	int recordBookNumber;
	int groupNumber;
	int courseNumber;
	char typeOfStuding; // f --- Full-time / e --- extramural
	bool paidOrFree; // true --- free / false --- paid
public:
	Student();
	Student(string _name, string _surname, string _patronymic, char _gender, int _age, int _recordBookNumber, int _groupNumber, int _courseNumber, char _typeOfStuding, bool _paidOrFree);
	~Student();
	void set();
	int getGroupNumber();
	int getCourseNumber();
	char getTypeOfStuding();
	bool getPaidOrFree();
	void setGroupNumber(int number);
	void setCourseNumber(int number);
	void setTypeOfStuding(char type);
	void setPaidOrFree(bool flag);
	void setGroupNumber();
	void setCourseNumber();
	void setTypeOfStuding();
	//void setPaidOrFree();
	void showStudentInfo();
};

class Schoolchild : public Learner {
	friend std::ostream& operator<< (std::ostream& out, const Schoolchild& schoolchild);
	friend istream& operator>> (istream& in, const Schoolchild* schoolchild);

private:
	char classLatter;
	int classNumber;
	char familyType;

public:
	Schoolchild();
	Schoolchild(string _name, string _surname, string _patronymic, char _gender, int _age, char _classLatter, int _classNumber, char _familyType);

	~Schoolchild();
	void set();
	char getclassLatter();
	int getclassNumber();
	char getfamilyType();
	void setclassLatter(char letter);
	void setclassNumber(int number);
	void setfamilyType(char type);
	void setclassLatter();
	void setclassNumber();
	void setfamilyType();
	void showSchoolchildInfo();

};