
#include "Roster.h"
#include <iostream>
#include <string>
using namespace std;



int main() {
    int numStudents = 5;
    
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Devin,Perdue,devinperdue16@gmail.com,23,15,30,25,SOFTWARE"
};
    
    
    cout << "C867 - Scripting & Programming: Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 009925256" << endl;
    cout << "Name : Devin Perdue" << endl << endl;
    
    Roster* classRoster = new Roster(numStudents);
    for (int i = 0; i < 5; i++) {
        (*classRoster).parse(studentData[i]);
    }
  
    cout << "Displaying all students:" << endl;
    (*classRoster).printAll();
    
    (*classRoster).printInvalidEmails();
    
    cout << endl;
    for (int i = 0; i < 5; i++) {
        (*classRoster).printAverageDaysInCourse((*classRoster).getStudent(i)->getStudentID());
    }
    
    cout << endl;
    (*classRoster).printByDegreeProgram(DegreeProgram::SOFTWARE);
    
    cout << endl << "Removing A3:" << endl << endl;
    (*classRoster).remove("A3");
    
    (*classRoster).printAll();
    
    cout << endl << "Removing A3 again:" << endl;
    (*classRoster).remove("A3");
    
   
    
    return 0;
}


