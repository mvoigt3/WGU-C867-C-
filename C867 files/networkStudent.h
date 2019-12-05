#pragma once
#include <string>
#include "degree.h"
#include "student.h"
class NetworkStudent  : public Student
{
public:
	NetworkStudent();
	NetworkStudent(
		string studentID,string firstName,string lastName,
		string emailAddress,
		string Age,
		double* daysInCourse,
		DegreeType degreeType
	);
	DegreeType getDegreeType();
	void setDegreeType(DegreeType b);
	void print();

	~NetworkStudent();
};