#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"
#include "Lecturer.h"

using namespace std;

void Course::assign_lecturer(Lecturer* l) //Assigning the taken lecturer to the course.
{
	lecturer_ptr = l;
}

void Course::Register(Student* s) //Adding a student to the array of students taking the course and adding one to the total number.
{
		reg_students[reg_students_num] = s;
		reg_students_num++;
}

void Course::display_info() //Displaying the course information.
{
	cout << "ID: " << id << endl << "Name: " << name << endl << "Lecturer: ";
	if (lecturer_ptr != nullptr) cout << lecturer_ptr->getName();
	cout<< "\nNumber of registered students: " << reg_students_num << endl << "Number of available seats: " << max_cap - reg_students_num << endl;
}

void Course::display_students_c() //Displaying just the names of students taking the course.
{
	for (int i = 0; i < reg_students_num; i++)
	{
		cout << i + 1 << ". " << reg_students[i]->getName() << endl;
	}
}

bool Course::checkStudent(int id) //Taking the id of the student and checking if the student is already in the course. (Used for error handling.)
{
	for (int i = 0; i < reg_students_num; i++)
	{
		if (id == reg_students[i]->getID())
		{
			return false;
		}
		return true;
	}
}

bool Course::checkLecturer(int id) //Taking the id of the lecturer and checking if the lecturer is already teaching the course. (Used for error handling.)
{
	if (id == lecturer_ptr->getID())
	{
		return false;
	}
	return true;
}
