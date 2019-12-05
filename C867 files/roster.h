#pragma once
#include<string>
#include<iostream>
#include "student.h"
using std::string;
const int enrollledStudents = 5;
string studentData[enrollledStudents] =
{
 "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SOFTWARE",
 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
 "A5,Matthew,Voigt,mvoigt3@wgu.edu,28,20,20,20,SOFTWARE",
};

class Roster {
public:
	int lastIndex, capacity;

	Student**students;
	Roster();
	Roster (int capacity);
	void parseAdd(string datarow);
	void print_All();
	void remove(string studentID);
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmailEntries();
	void printByDegreeType(DegreeType b);
	~Roster();
};