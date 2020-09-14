//Разработать классы для описанных ниже объектов.Включить в
//класс методы set(…), get(…), show(…).Определить другие методы.
//Вариант 15
//Person: Фамилия, Имя, Отчество, Адрес, Пол, Образование,
//Год рождения.Создать массив объектов.Вывести :
//	а) список граждан, возраст которых превышает заданный;
//	б) список граждан с высшим образованием;
//	в) список граждан мужского пола.
#include <iostream>
#include "Person.h"
#include <string>
//#include <ctime>
//#include <time.h>

using namespace std;

void showListAge(Person** persons, const int N,int year)
{
	/*time_t now = time(0);
	tm* ltm = localtime_s(&now);*/
	for (int i = 0; i < N; i++)
	{
		if (/*1970 + ltm->tm_year*/ 2020 - persons[i]->getYear() > year) 
		{
			persons[i]->show();
		}
	}
}

void showListEducation(Person** persons, const int N)
{
	for (int i = 0; i < N; i++)
	{
		if (persons[i]->getEducation() == 'H')
		{
			persons[i]->show();
		}
	}
}


void showListMale(Person** persons, const int N)
{
	for (int i = 0; i < N; i++)
	{
		if (persons[i]->getGender() == 'M')
		{
			persons[i]->show();
		}
	}
}


int main()
{
	Person** pointer;
	pointer = new Person * [5];
	pointer[0] = new Person("Vladisalv", "Kochurko", "Alexandrovich", 'M', 'H', 2002);
	pointer[1] = new Person("Sergey", "Harlanov", "Alexandrovich", 'M', 'H', 2001);
	pointer[2] = new Person("Anastasia", "Malevich", "Evgenevna", 'F', 'H', 2000);
	pointer[3] = new Person("Egor", "Saleychuk", "Alexandrovich", 'M', 'S', 1980);
	pointer[4] = new Person("Yarik", "Kamornik", "Sergeevich", 'M', 'P', 2005);

	showListAge(pointer, 5, 18);
	cout << endl << endl;
	showListEducation(pointer, 5);
	cout << endl << endl;
	showListMale(pointer, 5);

	
	system("pause");
	return 0;
}