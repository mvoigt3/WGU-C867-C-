#include<iostream>
#include<iomanip>
#include "student.h"
using namespace std;

Student::Student() {
	// variables 
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->Age = "";
	this->daysInCourse = new double[daysInCourseArray];
	for (int i = 0; i < daysInCourseArray; i++) this->daysInCourse[i] = 0;
}
Student::Student(string studentID, string firstName, string lastName, string emailAddress, string Age, double daysIncourse[], DegreeType type)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->Age = Age;
	this->daysInCourse = new double[daysInCourseArray];
	for (int i = 0; i < 3; i++) this->daysInCourse[i] = daysInCourse[i];
}
string Student::getStudentID(){
		return studentID;//get student id
}

string Student::getFirstName() {
		return firstName;//get first name
}
string Student::getLastName() {
		return lastName;//get last name
}
string Student::getEmailAddress() {
		return emailAddress;//get email address
}
string Student::getAge() {
		return Age;//get age
}
double * Student::getDaysInCourse() {
		return daysInCourse; //get days left array
}
void Student::setStudentID(string studentID)//set student id
{
		this->studentID = studentID;
}

void Student::setFirstName(string firstName) //set first name
{
		this->firstName = firstName;
}

void Student::setLastName(string lastName) //set last name
{
		this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress)//set email address
{
		this->emailAddress = emailAddress;
}
	void Student::setAge(string Age)//set age
	{
		this->Age = Age;
	}

	//brand new array
	void Student::setDaysInCourse(double daysInCourse[])
	{
		if (this->daysInCourse != nullptr) {
			delete[] this->daysInCourse;
			this->daysInCourse = nullptr;
		}
		this->daysInCourse = new double[daysInCourseArray];
		for (int i = 0; i < 3; i++)
			this->daysInCourse[i] = daysInCourse[i];
	}
	void Student::print() {
		//organization of print layout
		cout << left << setw(10) << studentID << '\t';
		cout << left << setw(30) << firstName << '\t';
		cout << left << setw(20) << lastName << '\t';
		cout << left << setw(45) << emailAddress << '\t';
		cout << left << setw(5) << Age << '\t';
		cout << left << setw(10) << daysInCourse[0] << '\t';
		cout << left << setw(10) << daysInCourse[1] << '\t';
		cout << left << setw(10) << daysInCourse[2] << '\t';
	}

	Student::~Student()
		//destructor for student
	{
		if (daysInCourse != nullptr) {
			delete[]daysInCourse;
			daysInCourse = nullptr;
		}
	}