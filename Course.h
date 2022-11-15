#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include "Lecturer.h"

using namespace std;

//Used this to handle the two classes using each other. 
class Lecturer;
class Student;

class Course
{
private:
	int id;
	string name;
	Lecturer* lecturer_ptr;
	int reg_students_num;
	Student** reg_students;
	int max_cap;
public:
	//Constructors.
	Course()
	{
		id = 0;
		name = "";
		max_cap = 0;
	}
	Course(int i, string n, int m_c)
	{
		id = i;
		name = n;
		max_cap = m_c;
		reg_students_num = 0;
		reg_students = new Student * [m_c];
		lecturer_ptr = nullptr;
	}
	//Accessors.
	string getName()
	{
		return name;
	}
	int getID()
	{
		return id;
	}
	int getRegStudentsNum()
	{
		return reg_students_num;
	}
	int getMaxCap()
	{
		return max_cap;
	}
	Lecturer* getLecturer()
	{
		return lecturer_ptr;
	}

	void assign_lecturer(Lecturer*); //Function for assigning a taken lecturer to the course.
	void Register(Student*); //Function for adding a student to an array of students in the course.
	void display_info(); //Function for displaying course info.
	void display_students_c(); //Added function for displaying only the students in the course.
	bool checkStudent(int); //Added function for checking if a student is already in the course.
	bool checkLecturer(int); //Added function for checking if a lecturer is already teaching the course.
};

#endif
