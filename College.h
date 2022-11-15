#ifndef COLLEGE_H
#define COLLEGE_H

#include <iostream>
#include <string>
#include "Course.h"
#include "Student.h"
#include "Lecturer.h"

using namespace std;

//Used this to handle the two classes using each other. 
class Student;
class Lecturer;
class Course;

class College
{
private:
	int id;
	string name;
	int students_num;
	Student* students;
	int lecturers_num;
	Lecturer* lecturers;
	int courses_num;
	Course* courses;
	int studentsArrSize;
	int lecturersArrSize;
	int coursesArrSize;
public:
	//Constructors.
	College() 
	{
		id = 0;
		name = "";
	}
	College(int i, string n)
	{
		id = i;
		name = n;
		students_num = 0;
		lecturers_num = 0;
		courses_num = 0;
		//Default array sizes.
		studentsArrSize = 5000;
		lecturersArrSize = 150;
		coursesArrSize = 400;
		students = new Student[studentsArrSize];
		lecturers = new Lecturer[lecturersArrSize];
		courses = new Course[coursesArrSize];
	}
	//Accessors.
	int getStudentsNum()
	{
		return students_num;
	}
	int getLecturersNum()
	{
		return lecturers_num;
	}
	int getCoursesNum()
	{
		return courses_num;
	}

	void add_student(Student); //Function for adding a student to the array of students in the college.
	void add_lecturer(Lecturer); //Function for adding a lecturer to the array of lecturers in the college.
	void add_course(Course); //Function for adding a course to the array of courses in the college.
	void resize(char); //Function for resizing the arrays mentioned above, if the limit is reached.
	void display_info(char); //Function for calling different display_info functions from other classes.
	Student* findStudent(int); //Function for finding a certain student. (Used for, along other things, error handling.)
	Lecturer* findLecturer(int); //Function for finding a certain lecturer. (Used for, along other things, error handling.)
	Course* findCourse(int); //Function for finding a certain course. (Used for, along other things, error handling.)
	//Functions for checking if an ID already exists. (Used for error handling.)
	bool checkStudentID(int); 
	bool checkLecturerID(int);
	bool checkCourseID(int);
};

#endif

