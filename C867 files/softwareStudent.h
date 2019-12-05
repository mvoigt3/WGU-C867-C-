
#pragma once
#include <string>
#include "degree.h"
#include "student.h"
class SoftwareStudent : public Student
{
public:
	SoftwareStudent();
	SoftwareStudent(
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

	~SoftwareStudent();
};