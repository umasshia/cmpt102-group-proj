#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

//Used this to handle the two classes using each other.
class Course;

class Student
{
private:
	int id;
	string name;
	int courses_num;
	int max_courses;
	Course** courses;
public:
	//Constructors.
	Student()
	{
		id = 0;
		name = "";
	}
	Student(int i, string n)
	{
		id = i;
		name = n;
		courses_num = 0;
		max_courses = 6;
		courses = new Course * [max_courses];
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
	int getMaxCourses()
	{
		return max_courses;
	}
	int getCoursesNum()
	{
		return courses_num;
	}

	void Register(Course*); //Function for adding a course to an array of courses the student is taking.
	void display_info(); //Function for displaying the student info.
	void display_courses_s(); //Added function for displaying just the courses the student is taking.
};

#endif