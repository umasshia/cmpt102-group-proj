#ifndef LECTURER_H
#define LECTURER_H

#include <iostream>
#include <string>

using namespace std;

//Used this to handle the two classes using each other.
class Course;

class Lecturer
{
private:
	int id;
	string name;
	int courses_num;
	Course** courses;
	int max_courses;
public:
	//Constructors.
	Lecturer()
	{
		id = 0;
		name = "";
	}
	Lecturer(int i, string n)
	{
		id = i;
		name = n;
		courses_num = 0;
		max_courses = 3;
		courses = new Course* [max_courses];
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
	int getCoursesNum()
	{
		return courses_num;
	}
	int getMaxCourses()
	{
		return max_courses;
	}

	void assign_course(Course*); //Function for adding a course to the array of courses the lecturer is teaching.
	void display_info(); //Function for displaying lecturer info.
	void display_courses_l(); //Added function for displaying just courses of the lecturer.
};

#endif