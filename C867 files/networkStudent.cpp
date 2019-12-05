#include <iostream>
#include "networkStudent.h"
#include "student.h"
using std::cout;

NetworkStudent ::NetworkStudent()
{
	setDegreeType(NETWORK);
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName,string emailAddress, string Age, double * daysInCourse, DegreeType degreeType)
{
	setDegreeType(NETWORK);
}

DegreeType NetworkStudent::getDegreeType()
{
	return NETWORK;
}

void NetworkStudent::setDegreeType(DegreeType c)
{
	this->type = NETWORK;
}

void NetworkStudent::print()
{
	this->Student::print();
	cout << "NETWORK" << "\n";
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();

}
