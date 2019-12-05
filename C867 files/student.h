#pragma once
#include <string>
#include "degree.h"
using std::string;
class Student 
{
protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	string Age;
	double* daysInCourse;
	DegreeType type;

public:
	const static int daysInCourseArray = 3;
	Student();
	Student(string studentID, string firstName,string lastName, string emailAddress, string Age, double daysIncourse[], DegreeType type);

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	string getAge();
	double *getDaysInCourse();
	virtual DegreeType getDegreeType() = 0;

	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(string Age);
	void setDaysInCourse(double daysInCourse[]);
	virtual void setDegreeType(DegreeType x) = 0;
	virtual void print() = 0;

	~Student();

	
};