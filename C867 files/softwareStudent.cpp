#include <iostream>
#include "softwareStudent.h"
using std::cout;

SoftwareStudent::SoftwareStudent()
{
	setDegreeType(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, string Age, double * daysInCourse, DegreeType degreeType)
{
	setDegreeType(SOFTWARE);
}

DegreeType SoftwareStudent::getDegreeType()
{
	return SOFTWARE;
}

void SoftwareStudent::setDegreeType(DegreeType a)
{
	this->type = SOFTWARE;
}

void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE" << "\n";
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();

}
