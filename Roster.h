//
//  Roster.hpp
//  Performance Assessment
//
//  Created by Devin Perdue on 5/13/22.
//

#ifndef Roster_h
#define Roster_h
#include <stdio.h>
#include "Student.h"

class Roster {
public:
    int lastIndex;
    int rosterSize = 5;
    
    //Array of pointers
    Student** classRosterArray;
    
    Roster(int rosterSize);
    
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int numDay1, int numDay2, int numDay3, DegreeProgram degreeProgram);
    Student* getStudent(int index);
    bool remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void parse(string row);
  
    ~Roster();
};








#endif /* Roster_hpp */


