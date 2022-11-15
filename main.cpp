/*
Giorgi Samushia
Minna Ahmed
Cyrus Yochim

Computer Science II Project

Student/Lecturer classes - Minna
College/Course classes - Cyrus
Main function/Helper functions/Error handling/Corrections - Giorgi

We met up every week to work on this project.
While we did write the classes alone, we corrected 
and tweaked everything together, so the program could
be more consistent.
*/

#include <iostream>
#include <string>
#include "College.h"
#include "Course.h"
#include "Lecturer.h"
#include "Student.h"

using namespace std;

//Sample college.
College college(2371, "Manhattan College");

//Additional function prototypes.
void addStudent();
void addLecturer();
void addCourse();
void enrollStudent();
void assignLecturer();
void displayCourseInfo();
void displayCoursesByID(char);
void displayStudentsInCourse();

int main()
{
	int option = 0;
	while (option != 13)
	{
		cout << "College Registration System Main Menu\n";
		cout << "===============================\n";
		cout << "1. Add a student.\n";
		cout << "2. Add a course.\n";
		cout << "3. Add lecturer.\n";
		cout << "4. Register a student for a course.\n";
		cout << "5. Assign a lecturer for a course.\n";
		cout << "6. Display the complete list of students.\n";
		cout << "7. Display the complete list of courses.\n";
		cout << "8. Display the complete list of lecturers.\n";
		cout << "9. Display course information.\n";
		cout << "10. Display the list of courses currently taken by a student (by id).\n";
		cout << "11. Display the list of courses currently taught by a lecturer (by id).\n";
		cout << "12. Display the list of students enrolled in a particular course (by id).\n";
		cout << "13. Quit\n\n";
		cout << "At any point, enter number 0 to return to main menu\n\n"; //See the bottom of the page.
		cout << "Choose an option: ";
		cin >> option;
		switch (option) //Switch for executing certain functions according to the user's choice.
		{
		case 1: { addStudent(); break; }
		case 2: { addCourse(); break; }
		case 3: { addLecturer(); break; }
		case 4: { enrollStudent(); break; }
		case 5: { assignLecturer(); break; }
		case 6: { college.display_info('s'); break; }
		case 7: { college.display_info('c'); break; }
		case 8: { college.display_info('l'); break; }
		case 9: { displayCourseInfo(); break; }
		case 10: { displayCoursesByID('s'); break; }
		case 11: { displayCoursesByID('l'); break; }
		case 12: { displayStudentsInCourse(); break; }
		case 13: return 0;
		default: break;
		}
	}
		
	return 0;
}

void addStudent() //Adding a student.
{
	int id;
	string name;
	cin.ignore(); //Getline didn't work without this, used it throughout the code. (Googled it.)
	cout << "\nName: ";
	getline(cin, name); //Using getline for full names.
	if (name == "0") return; // These types of if statements are explained at the end of this .cpp file.
	cout << "\nID: ";
	cin >> id;
	if (id == 0) return;
	while (!college.checkStudentID(id)) //Checking if the ID exists and if so, asking the user to enter something else.
	{
		cout << "\nThe ID is taken.\nEnter a unique ID: ";
		cin >> id;
		if (id == 0) return;
	} 
	Student s(id, name); //Creating Student object.
	college.add_student(s); //Adding it.
	cout << "\nStudent added.";
	cout << "\n\n";
}

void addLecturer() //Adding a lecturer.
{
	int id;
	string name;
	cin.ignore();
	cout << "\nName: ";
	getline(cin, name);
	if (name == "0") return;
	cout << "\nID: ";
	cin >> id;
	if (id == 0) return;
	while (!college.checkLecturerID(id)) //Checking if ID exists, if so, asking for something else.
	{
		cout << "\nThe ID is taken.\nEnter a unique ID: ";
		cin >> id;
	}
	Lecturer s(id, name); //Creating Lecturer object.
	college.add_lecturer(s); //Adding it.
	cout << "\nLecturer added.";
	cout << "\n\n";
}

void addCourse() //Adding a course.
{
	int id;
	string name;
	int max_cap;
	cin.ignore();
	cout << "\nName: ";
	getline(cin, name);
	if (name == "0") return;
	cout << "\nID: ";
	cin >> id;
	if (id == 0) return;
	while (!college.checkCourseID(id)) //Checking if ID exists, if so, asking for something else.
	{
		cout << "\nThe ID is taken.\nEnter a unique ID: ";
		cin >> id;
		if (id == 0) return;
	}
	cout << "\nMaximum amount of students: ";
	cin >> max_cap;
	Course c(id, name, max_cap); //Creating Course object. (This time with third variable max_cap.)
	college.add_course(c); //Adding it.
	cout << "\nCourse added.";
	cout << "\n\n";
}

void enrollStudent() //Adding a student to a course.
{
	int id;
	int cID;
	string cname;
	cout << "\nEnter the student's ID: ";
	cin >> id;
	if (id == 0) return;
	Student* s = college.findStudent(id);
	while (s == nullptr) //Checking if the ID is existent, if not, asking the user to try again. When a correct ID is found, taking that object.
	{
		cout << "\nStudent does not exist.\nEnter a correct ID: ";
		cin >> id;
		if (id == 0) return;
		s = college.findStudent(id); 
	}
	cout << "\nEnter the course ID: ";
	cin >> cID;
	if (cID == 0) return;
	Course* c = college.findCourse(cID);
	while (c == nullptr) //Checking if the ID is existent, if not, asking the user to try again. When a correct ID is found, taking that object.
	{
		cout << "\nCourse does not exist.\nEnter a correct ID: ";
		cin >> cID;
		if (cID == 0) return;
		c = college.findCourse(cID);
	}
	if (!c->checkStudent(id)) //Checking if the student is already in the course.
	{
		cout << "\nThe sudent is already registered on this course.\n";
	}
	else if (s->getMaxCourses() == s->getCoursesNum()) //Checking if the student can take more courses.
	{
		cout << "\nA student cannot take more than 6 courses.\n";
	}
	else if (c->getMaxCap() == c->getRegStudentsNum()) //Checking if the course has available seats.
	{
		cout << "\nThere are no available seats in this class.\n";
	}
	else //If all the conditions are satisfied, adding the Student object to the array in the Course class, and adding the Course object to the array in the Student class.
	{
		c->Register(s);
		s->Register(c);
	}
	cout << "\n";
}

void assignLecturer()
{
	int id;
	int cID;
	string cname;
	cout << "\nEnter the lecturer's ID: ";
	cin >> id;
	if (id == 0) return;
	Lecturer* l = college.findLecturer(id); 
	while (l == nullptr) //Checking if the ID is existent, if not, asking the user to try again. When a correct ID is found, taking that object.
	{
		cout << "\nLecturer does not exist.\nEnter a correct ID: ";
		cin >> id;
		if (id == 0) return;
		l = college.findLecturer(id);
	}
	cout << "\nEnter the course ID: ";
	cin >> cID;
	if (cID == 0) return;
	Course* c = college.findCourse(cID);
	while (c == nullptr) //Checking if the ID is existent, if not, asking the user to try again. When a correct ID is found, taking that object.
	{
		cout << "\nCourse does not exist.\nEnter a correct ID: ";
		cin >> cID;
		if (cID == 0) return;
		c = college.findCourse(cID);
	}
	if (!c->checkLecturer(id)) //Checking if the lecturer is already assigned to the course.
	{
		cout << "\nThe lecturer is already teaching this course.\n";
	}
	else if (l->getMaxCourses() == l->getCoursesNum()) //Checking if the lecturer is teaching 3 courses.
	{
		cout << "\nA lecturer cannot teach more than 3 courses.\n";
	}
	else if (c->getLecturer() != nullptr) //Checking if the course is being taught by someone else.
	{
		cout << "\nThis class is already being taught by someone else.\n";
	}
	else //If all the conditions are satisfied, adding the Course object to the array in the Lecturer class, and adding the Lecturer object to the Course class.
	{
		l->assign_course(c);
		c->assign_lecturer(l);
	}
	cout << "\n";
}

void displayCourseInfo()
{
	int id;
	string name;
	cout << "\nEnter the course ID: ";
	cin >> id;
	if (id == 0) return;
	Course* c = college.findCourse(id);
	while (c == nullptr) //Checking if the ID is existent, if not, asking the user to try again. When a correct ID is found, taking that object.
	{
		cout << "\nCourse does not exist.\nEnter a correct ID: ";
		cin >> id;
		if (id == 0) return;
		c = college.findCourse(id);
	}
	cout << "\nHere's the course information: " << endl;
	c->display_info(); //Calling the display_info function from the Course class.
	cout << "\n\n";
}

void displayCoursesByID(char ch)
{
	if (ch == 's')
	{
		int id;
		cout << "Enter the student's ID: ";
		cin >> id;
		if (id == 0) return;
		Student* s = college.findStudent(id);
		while (s == nullptr) //Checking if the ID is existent, if not, asking the user to try again. When a correct ID is found, taking that object.
		{
			cout << "\nStudent does not exist.\nEnter a correct ID: ";
			cin >> id;
			if (id == 0) return;
			s = college.findStudent(id);
		}
		cout << "Here are the courses the student is taking: " << "\n\n";
		s->display_courses_s(); //Calling the display_info function from the Student class.
		cout << "\n";
	}
	else
	{
		int lID;
		cout << "Enter the lecturer's ID: ";
		cin >> lID;
		if (lID == 0) return;
		Lecturer* l = college.findLecturer(lID);
		while (l == nullptr) //Checking if the ID is existent, if not, asking the user to try again.When a correct ID is found, taking that object.
		{
			cout << "\nLecturer does not exist.\nEnter a correct ID: ";
			cin >> lID;
			if (lID == 0) return;
			l = college.findLecturer(lID);
		}
		cout << "Here are the courses the lecturer is teaching: " << "\n\n";
		l->display_courses_l(); //Calling the display_info function from the Lecturer class.
		cout << "\n";
	}
}

void displayStudentsInCourse()
{
	int id;
	cout << "Enter the course ID: ";
	cin >> id;
	if (id == 0) return;
	Course* c = college.findCourse(id);
	while (c == nullptr) //Checking if the ID is existent, if not, asking the user to try again.When a correct ID is found, taking that object.
	{
		cout << "\nCourse does not exist.\nEnter a correct ID: ";
		cin >> id;
		if (id == 0) return;
		c = college.findCourse(id);
	}
	cout << "\nHere are the students taking this course: " << "\n\n";
	c->display_students_c(); //Calling the added display_students_c function from the Course class.
	cout << "\n";
}

/*
Some Notes:

1. Any function that looks like "findStudent()" or "findX()" is an added function used for locating objects by their ids.  
   It's either used for assigning certain objects to one another or handling errors.
2. Any if statement that looks like "if(x==0) return;" is an addition for a simple reason. It's used to take the user back to the menu,
   if something happens to go wrong. (Like making a wrong choice.) There are a lot of while statements and after every "cin>>x" we have this 
   if statement, so the user can backtrack.
*/