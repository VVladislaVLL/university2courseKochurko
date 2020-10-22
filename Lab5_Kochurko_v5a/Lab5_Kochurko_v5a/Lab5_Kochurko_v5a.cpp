#include <iostream>
#include <string>
#include "Classes.h"

using namespace std;

void main()
{
	Student student;
	
	/*student.set();
	student.show();*/
	Learner learner("vlad", "kochurko", "alexandrovich", 'm', 18);
	Learner* learners = new Learner[6];
	learners[0] = Student("Vladislav", "Kochurko", "Alexandrovich", 'm', 18, 123123, 2, 2, 'd', 1);
	learners[1] = Student("Student", "Student", "Student", 'm', 18, 123123, 2, 2, 'd', 1);
	learners[2] = Schoolchild("Schoolchild", "Schoolchild", "Schoolchild", 'm', 16, 'A', 11, false);
	learners[3] = Schoolchild("Schoolchild", "Schoolchild", "Schoolchild", 'm', 16, 'A', 11, false);
	learners[4] = Schoolchild("Schoolchild", "Schoolchild", "Schoolchild", 'm', 16, 'A', 11, false);
	learners[5] = Student("Student", "Student", "Student", 'm', 18, 123123, 2, 2, 'd', 1);

	for (int i = 0; i < 6; i++)
	{
		learners[i].show();
	}
}