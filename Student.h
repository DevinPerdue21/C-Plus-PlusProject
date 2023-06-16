//
//  Student.hpp
//  Performance Assessment
//
//  Created by Devin Perdue on 5/13/22.
#include "Degree.h"
#include <iostream>
#ifndef Student_h
#define Student_h
#include <string>
using namespace std;

#include <stdio.h>
class Student {
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int * arrnumDay;
    DegreeProgram degreeProgram;
public:
    const static int rosterSize = 3;
    //Constructor
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int arrnumDay[], DegreeProgram degreeProgram);
    
    
        
    //Setters
    void setStudentID(string);
    void setFirstName(string);
    void setLastName(string);
    void setEmailAddress(string);
    void setAge(int);
    void setNumDay(int arrnumDay[]);
    void setDegreeProgram(DegreeProgram degreeProgram);
    void print();
    //Getters
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getNumDay();
    DegreeProgram getDegreeProgram();

    //Destructor
    ~Student();
};


    



#endif /* Student_hpp */
