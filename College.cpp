#include <iostream>
#include <string>
#include "College.h"
#include "Student.h"
#include "Lecturer.h"
#include "Course.h"

using namespace std;

void College::resize(char ch) //Creating a bigger array, and copying all the objects of the old one in it. Deleting the old one after the fact.
	{
		if (ch == 's')
		{
			Student* temp;
			temp = new Student[2 * studentsArrSize];
			for (int i = 0; i < students_num; i++)
				temp[i] = students[i];
			delete[] students;
			students = temp;
		}
		else if (ch == 'c')
		{
			Course* temp;
			temp = new Course[2 * coursesArrSize];
			for (int i = 0; i < courses_num; i++)
				temp[i] = courses[i];
			delete[] courses;
			courses = temp;
		}
		else 
		{
			Lecturer* temp;
			temp = new Lecturer[2 * lecturersArrSize];
			for (int i = 0; i < lecturers_num; i++)
				temp[i] = lecturers[i];
			delete[] lecturers;
			lecturers = temp;
		}
	}

	void College::add_student(Student newStudent) //Adding a new student to the array of students in the college. Resizing if needed.
	{
		if (students_num == 5000) resize('s');
		students[students_num] = newStudent;
		students_num++;
	}

	void College::add_course(Course newCourse) //Adding a new course to the array of courses in the college. Resizing if needed.
	{
		if (courses_num == 400) resize('c');
		courses[courses_num] = newCourse;
		courses_num++;
	}

	void College::add_lecturer(Lecturer newLecturer) //Adding a new lecturer to the array of lecturers in the college. Resizing if needed.
	{
		if (lecturers_num == 150) resize('l');
		lecturers[lecturers_num] = newLecturer;
		lecturers_num++;
	}

	void College::display_info(char ch) //Calling functions from different classes to display information.
	{
		if (ch == 's')
		{
			for (int i = 0; i < students_num; i++)
			{
				cout << i + 1 << "." << endl;
				students[i].display_info();
				cout << endl;
			}
		}
		else if (ch == 'l')
		{
			for (int i = 0; i < lecturers_num; i++)
			{
				cout << i + 1 << "." << endl;
				lecturers[i].display_info();
				cout << endl;
			}
		}
		else
		{
			for (int i = 0; i < courses_num; i++)
			{
				cout << i + 1 << "."<<endl;
				courses[i].display_info();
				cout << endl;
			}
		}
	}

	Student* College::findStudent(int id) //Finding a student by ID and returning the object's address. If not, returning a null pointer.
	{
		for (int i = 0; i < students_num; i++)
		{
			if (id == students[i].getID())
				return &students[i];
		}
		return nullptr;
	}

	Lecturer* College::findLecturer(int id) //Finding a lecturer by ID and returning the object's address. If not, returning a null pointer.
	{
		for (int i = 0; i < lecturers_num; i++)
		{
			if (id == lecturers[i].getID())
				return &lecturers[i];
		}
		return nullptr;
	}

	Course* College::findCourse(int cID) //Finding a course by ID and returning the object's address. If not, returning a null pointer.
	{
		for (int i = 0; i < courses_num; i++)
		{
			if (cID == courses[i].getID())
			{
				return &courses[i];
			}
		}
		return nullptr;
	}

	bool College::checkStudentID(int id) //Checking if a student ID already exists.
	{
		for (int i = 0; i < students_num; i++)
		{
			if (id == students[i].getID())
				return false;
		}
		return true;
	}

	bool College::checkLecturerID(int id) //Checking if a lecturer ID already exists.
	{
		for (int i = 0; i < lecturers_num; i++)
		{
			if (id == lecturers[i].getID())
				return false;
		}
		return true;
	}

	bool College::checkCourseID(int id) //Checking if a course ID already exists.
	{
		for (int i = 0; i < courses_num; i++)
		{
			if (id == courses[i].getID())
				return false;
		}
		return true;
	}

