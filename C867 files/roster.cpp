#include "roster.h"
#include "student.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include <vector>
#include <sstream>
#include <cstddef>
using std::cout;
using std::cerr;
using namespace std;
Roster::Roster() {
	this->capacity = 0;
	this->lastIndex = -1;
	this->students= nullptr;
}
Roster::Roster(int capacity) {
	this->capacity = capacity;
	this->lastIndex = -1;
	this->students = new Student*[capacity];
}

void Roster::parseAdd(string row)
{
	if (lastIndex < capacity) {
		lastIndex++;

		double parray[Student::daysInCourseArray];

	
		if (row.back()== 'Y')
		{
			this->students[lastIndex] = new SecurityStudent ();
			students[lastIndex]->setDegreeType(SECURITY);
		}
		else if (row.back() == 'K') {
			this->students[lastIndex] = new NetworkStudent ();
			students[lastIndex]->setDegreeType(NETWORK);
		}
		else if (row.back() == 'E') {
			this->students[lastIndex] = new SoftwareStudent();
				students[lastIndex]->setDegreeType(SOFTWARE);
		}

		else
		{
			cerr << "INVALID DEGREE TYPE!  EXITING NOW!\n";
			exit(-1);
		}

		
		int x = studentData[lastIndex].find(",");

		students[lastIndex]->setStudentID(studentData[lastIndex].substr(0, x));


		int y = x + 1;
		x = studentData[lastIndex].find(",", y);
	
		students[lastIndex]->setFirstName(studentData[lastIndex].substr(y, x - y));
		
		y = x + 1;
		x = studentData[lastIndex].find(",", y);
		
		students[lastIndex]->setLastName(studentData[lastIndex].substr(y, x - y));
		y = x + 1;
		x = studentData[lastIndex].find(",", y);
		
		students[lastIndex]->setEmailAddress(studentData[lastIndex].substr(y, x - y));
		y = x + 1;
		x = studentData[lastIndex].find(",", y);

		students[lastIndex]->setAge(studentData[lastIndex].substr(y, x - y));

	
	
		y = x + 1;
		x = studentData[lastIndex].find(",", y);
		
		parray[0] = stod(studentData[lastIndex].substr(y, x - y));

		y = x + 1;
		x = studentData[lastIndex].find(",", y);
	
		parray[1] = stod(studentData[lastIndex].substr(y, x - y));

		y = x + 1;
		x = studentData[lastIndex].find(",", y);
	
		parray[2] = stod(studentData[lastIndex].substr(y, x - y));

	
		students[lastIndex]->setDaysInCourse(parray);
	}
	else
	{
		cerr << "ERROR! LIST HAS EXCEEDED MAXIMUM CAPACITY!\n EXITING NOW!";
		exit(-1);
	}
}

void Roster::print_All(){
	for (int i = 0; i <= this->lastIndex; i++) (this->students)[i]->print();
}

void Roster::remove(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->students[i]->getStudentID() == studentID) 
		{
			found = true;

			delete this->students[i];
			
			this->students[i] = this->students[lastIndex];
			lastIndex--;
		}
		
	}
	if (!found) cout << "Student ID " <<studentID <<" not found";
	else cout << studentID << " was removed"<<"\n";
}

void Roster::printAverageDaysInCourse(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->students[i]->getStudentID() == studentID) 
		{
			found = true;
			double* p = students[i]->getDaysInCourse();
			cout << " " <<  (p[0] + p[1] + p[2]) / 3 << "\n";
		}
	}
	if (!found) cout << "Student not found!\n";
}

void Roster::printInvalidEmailEntries()
{// handler for invalid email entries 
	int i = 0;
	cout << "Displaying invalid E-mail entries:\n";
	while (i < 5) {
		Student* student = students[i];
		string email = student->getEmailAddress();
		bool foundError = false;

		if (email.find('@') == string::npos) {
			foundError = true;
		}

		if (email.find('.') == string::npos) {
			foundError = true;
		}

		if (email.find(' ') != string::npos) {
			foundError = true;
		}

		if (foundError == true) {
			cout << email << "\n";
		}

		i++;
	}
}



void Roster::printByDegreeType(DegreeType a)
{//by assigining the the degreetypStrings to a 0 index(software) we can just print that specific degree type 
	cout << "Printing Students of type " << degreeTypeStrings[0] << "\n";
	for (int i = 0; i <= lastIndex; i++) {
		if (this->students[i]->getDegreeType() == a) this->students[i]->print();
	}
}

Roster::~Roster()
{
	for (int i = 0; i < enrollledStudents; i++)
	{
		delete this->students[i];
	}
	delete this;
}

int main()// main method 
{
	cout << "Course: C867, Programming Language: C++, Student I.D: #000954943, Name: Matthew Voigt" << "\n";//title
	cout << "\n";
	Roster * classRoster = new Roster(enrollledStudents);//declare new classRoster instance
	cout << "Loading data and adding students:\t";
	for (int i = 0; i < enrollledStudents; i++)
	{
		classRoster->parseAdd(studentData[i]);//funciton for displaying all of header data from student data
	}
	cout << "DONE.\n";
	cout << "Displaying all Students:\n";
	cout << "\n";
	classRoster->print_All(); //prints the parsed data rows
	cout << "\n";
	classRoster->printInvalidEmailEntries(); //calls the print invalid email entries and displays them 
	cout << "\n";
	cout << "Average Days left in Course"<<"\n";

	cout << "Student ID:" << " A1 "  ;// here I wanted each students average day to completion to be directly associated to their ID.
	//otherwise its just hard to figure out if the averages are working correctly 
	classRoster->printAverageDaysInCourse("A1");
	cout << "Student ID:" << " A2 " ;
	classRoster->printAverageDaysInCourse("A2");
	cout << "Student ID:" << " A3 ";
	classRoster->printAverageDaysInCourse("A3");
	cout << "Student ID:" << " A4 ";
	classRoster->printAverageDaysInCourse("A4");
	cout << "Student ID:" << " A5 ";
	classRoster->printAverageDaysInCourse("A5");
	cout << "\n";
	cout << "Removing A3:\n";
	classRoster->remove("A3");//void funciton for removal of specified students
	cout << "Removing A3:\n";
	classRoster->remove("A3");// classRoster->print_All();
	//else cout << "Student not found!\n";

	//cout << "Removing A3:\n";
	//if (classRoster->remove("A3")) classRoster->print_All();
	//else cout << "Student not found!\n";
	/////////this was a previous funciton I wrote that relayed on a bool instead of a void function




	cout << "\n";
	classRoster->printByDegreeType(SOFTWARE);//print just for software types 

	system("pause");
	return 0;
}
