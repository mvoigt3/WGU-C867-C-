#pragma once
#include <string>
#include "degree.h"
#include "student.h"
class SecurityStudent : public Student
{
public:
	SecurityStudent();
	SecurityStudent(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		string Age,
		double* daysInCourse,
		DegreeType degreeType
	);
	DegreeType getDegreeType();
	void setDegreeType(DegreeType b);
	void print();

	~SecurityStudent();
};