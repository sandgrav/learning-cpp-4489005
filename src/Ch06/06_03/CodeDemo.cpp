// Learning C++ 
// Challenge 06_03
// Upgrade to work with files, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include <fstream>
#include "records.h"

void initialize(StudentRecords&);

int main(){
    int id;
    StudentRecords SR;
    
    initialize(SR);

    SR.report_card("reports.txt");
    
    std::cout << "Finished reportcards!" << std::endl << std::endl;
    return (0);
}

void initialize(StudentRecords& srec){
    std::ifstream instream;
    std::string str;
    int sid, cid, credits;
    std::string course_name;
    char grade;

    instream.open("students.txt");
    if(instream.fail()){
        std::cout << "File students.txt not found!" << std::endl;
    }
    else{
        while(!instream.eof()){
            getline(instream, str);
            sid = stoi(str);
            getline(instream, str);
            srec.add_student(sid, str);
        }
        instream.close();
    }

    instream.open("courses.txt");
    if(instream.fail()){
        std::cout << "File courses.txt not found!" << std::endl;
    }
    else{
        while(!instream.eof()){
            getline(instream, str);
            cid = stoi(str);
            getline(instream, str);
            course_name = str;
            getline(instream, str);
            credits = stoi(str);
            srec.add_course(cid, course_name, credits);
        }
        instream.close();
    }

    instream.open("grades.txt");
    if(instream.fail()){
        std::cout << "File grades.txt not found!" << std::endl;
    }
    else{
        while(!instream.eof()){
            getline(instream, str);
            sid = stoi(str);
            getline(instream, str);
            cid = stoi(str);
            getline(instream, str);
            grade = str[0];
            srec.add_grade(sid, cid, grade);
        }
        instream.close();
    }
}
