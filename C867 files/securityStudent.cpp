#include <iostream>
#include "securityStudent.h"
using std::cout;

SecurityStudent::SecurityStudent()
{
	setDegreeType(SECURITY);
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, string Age, double * daysInCourse, DegreeType degreeType)
{
	setDegreeType(SECURITY);
}

DegreeType SecurityStudent::getDegreeType()
{
	return SECURITY;
}

void SecurityStudent::setDegreeType(DegreeType b)
{
	this->type = SECURITY;
}

void SecurityStudent::print()
{
	this->Student::print();
	cout << "SECURITY" << "\n";
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();

}
