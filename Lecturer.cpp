#include <iostream>
#include <string>
#include "Course.h"
#include "Lecturer.h" 

void Lecturer::assign_course(Course* c) //Adding a course to the array and and adding one to the total number.
{
		courses[courses_num] = c;
		courses_num++;
		cout << "\nLecturer " << name << " has been assigned to the course " << c->getName() << "\n";
}

void Lecturer::display_info() //Displaying info.
{
	cout <<"ID: " << id << endl <<"Name: " << name << endl << "Number of courses taught: " << courses_num << endl;
}

void Lecturer::display_courses_l() //Displaying the names of courses in the array created in the assign_course function.
{
	for (int i = 0; i < courses_num; i++)
	{
		cout << i + 1 << ". " << courses[i]->getName() << endl;
	}
}