//
//  Student.cpp
//  Performance Assessment
//
//  Created by Devin Perdue on 5/13/22.
#include <iostream>
#include "Student.h"
#include <string>
using namespace std;


Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    this->arrnumDay = new int[rosterSize];
    for (int i = 0; i < rosterSize; i++)this->arrnumDay[i] = 0;
    this->degreeProgram = SOFTWARE; 
};
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int arrnumDay[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->arrnumDay = new int[rosterSize];
    for (int i = 0; i < rosterSize; i++)this->arrnumDay[i] = arrnumDay[i];
    this->degreeProgram = degreeProgram;
};




//Setters Defined
void Student::setStudentID(string s){
    studentID = s;
}
void Student::setFirstName(string f){
    firstName = f;
}
void Student::setLastName(string l){
    lastName = l;
}
void Student::setEmailAddress(string e) {
    emailAddress = e;
}
void Student::setAge(int a){
    age = a;
}
void Student::setNumDay(int arrnumDay[])
{
    for (int i = 0; i < rosterSize; i++) {
      this->arrnumDay[i] = arrnumDay[i];
}
}

void Student::setDegreeProgram(DegreeProgram d){
    degreeProgram = d;
}

//Getters Defined
string Student::getStudentID(){
    return studentID;
}
string Student::getFirstName(){
    return firstName;
}
string Student::getLastName(){
    return lastName;
}
string Student::getEmailAddress(){
    return emailAddress;
}
int Student::getAge(){
    return age;
}
int* Student::getNumDay() {
    return arrnumDay;
}
DegreeProgram Student::getDegreeProgram(){
    return degreeProgram;
}
void Student::print() {
    cout << getStudentID() << '\t' << getFirstName() << '\t' << getLastName() << '\t' << getAge() << '\t';
    int * arrnumDay = getNumDay();
    cout << '\t' << "{" << arrnumDay[0] << "," << arrnumDay[1] << "," << arrnumDay[2] << "}" << '\t';
    cout << courseTypeStrings[getDegreeProgram()] << endl;
}

Student::~Student() {
    if(arrnumDay != nullptr) {
        delete[] arrnumDay;
        arrnumDay = nullptr;
    }
}

