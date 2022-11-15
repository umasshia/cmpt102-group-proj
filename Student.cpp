#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"

void Student::Register(Course* c) //Adding a course to the array and and adding one to the total number.
{
		courses[courses_num] = c;
		courses_num++;
		cout << "\nStudent " << name << " has been registered on the course " << c->getName()<<"\n";
}

void Student::display_info() //Displaying student info.
{
	cout << "ID: " << id << endl << "Name: " << name << endl << "Number of courses taken: " << courses_num << endl;
}

void Student::display_courses_s() //Displaying the names of courses in the array created in the Register function.
{
	for (int i = 0; i < courses_num; i++)
	{
		cout << i+1 << ". " << courses[i]->getName() << endl;
	}
}

