//
//  Roster.cpp
//  Performance Assessment
//
//  Created by Devin Perdue on 5/13/22.
//
#include <iostream>
#include <string>
#include "Roster.h"
using namespace std;


Roster::Roster(int rosterSize) {
    this-> rosterSize = rosterSize;
    this-> lastIndex = -1;
    this-> classRosterArray = new Student* [rosterSize];
}

void Roster::parse(string row){
    int parseArray[Student::rosterSize];
    
    
    if(lastIndex < rosterSize){
        lastIndex++;
    }
    this->classRosterArray[lastIndex] = new Student();
    
        size_t rhs = row.find(",");
        (*classRosterArray[lastIndex]).setStudentID (row.substr(0, rhs));
        
        size_t lhs = rhs + 1;
        rhs = row.find(",", lhs);
        (*classRosterArray[lastIndex]).setFirstName(row.substr(lhs, rhs - lhs));
        
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        (*classRosterArray[lastIndex]).setLastName(row.substr(lhs, rhs - lhs));
        
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        (*classRosterArray[lastIndex]).setEmailAddress(row.substr(lhs, rhs - lhs));
        
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        int age = stoi(row.substr(lhs, rhs - lhs));
        (*classRosterArray[lastIndex]).setAge(age);
        
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        parseArray[0]= stoi(row.substr(lhs, rhs - lhs));
        
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        parseArray[1] = stoi(row.substr(lhs, rhs - lhs));
        
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        parseArray[2] = stoi(row.substr(lhs, rhs - lhs));
        
        (*classRosterArray[lastIndex]).setNumDay(parseArray);
    
        lhs = rhs + 1;
        
        if(row[lhs] == 'S') {
        if(row[lhs +1] == 'E') (*classRosterArray[lastIndex]).setDegreeProgram(SECURITY);
        else if (row[lhs + 1] == 'O') (*classRosterArray[lastIndex]).setDegreeProgram(SOFTWARE);
    
        }
    else if(row[lhs] == 'N') (*classRosterArray[lastIndex]).setDegreeProgram(NETWORK);
    else {
        cout << "Invalid Degree Program" << endl;
    }
    }


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int numDay1, int numDay2, int numDay3, DegreeProgram degreeProgram) {
    
    int arrnumDay[Student::rosterSize];
    
    arrnumDay[0] = numDay1;
    arrnumDay[1] = numDay2;
    arrnumDay[2] = numDay3;
    
    classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, arrnumDay, degreeProgram);
}

Student* Roster::getStudent(int index) {
    return classRosterArray[index];
}

void Roster::printAll() {
    for (int i =0; i <= this->lastIndex; i++)
    (*classRosterArray[i]).print();
}

bool Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (this->classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            delete this->classRosterArray[i];
            this->classRosterArray[i] = this->classRosterArray[lastIndex];
            lastIndex--;
        }
    }
    if(!found) {
        cout << endl <<  "The student with the ID: " << studentID << " not found." << endl;
    }
    return found;
}

void Roster::printAverageDaysInCourse(string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        if((*classRosterArray[i]).getStudentID() == studentID) {
            found = true;
            int* numDays = (*classRosterArray[i]).getNumDay();
            cout << "Student ID: " << studentID << ", " << "average days in course is: "<< (numDays[0] + numDays[1] + numDays[2]) / 3 << endl;
        }
    }
    if(!found) cout << "Student not found!\n";
}

void Roster::printInvalidEmails() {
    cout << endl << "Displaying invalid emails:" << endl;
    for (int i = 0; i < 5; i++) {
        string email = (*classRosterArray[i]).getEmailAddress();
        if((email.find("@") == string::npos || email.find(".") == string::npos || (email.find(" ") != string::npos)))
           cout << email << " - is invalid." << endl;
           }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    cout << "Showing students in degree program:  " << courseTypeStrings[degreeProgram] << endl;
    for (int i = 0; i<=lastIndex; i++) {
        if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) (*classRosterArray[i]).print();
    }
}

Roster::~Roster() {
    for (int i = 0; i < 5; i++) {
        delete this->classRosterArray[i];
    }
    //delete this;
}
