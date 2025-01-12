// Learning C++ 
// Challenge 04_05
// Calculate a GPA, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include "records.h"

int main(){
    float GPA = 0.0f;
    int id;
    
    std::vector<Student> students = {Student(1, "George P. Burdell"),
                                    Student(2, "Nancy Rhodes")};

    std::vector<Course> courses = {Course(1, "Algebra", 5),
                                Course(2, "Physics", 4),
                                Course(3, "English", 3),
                                Course(4, "Economics", 4)};

    std::vector<Grade> grades = {Grade(1, 1, 'B'), Grade(1, 2, 'A'), Grade(1, 3, 'C'),
                                Grade(2, 1, 'A'), Grade(2, 2, 'A'), Grade(2, 4, 'B')};

    std::cout << "Enter a student ID: " << std::flush;
    std::cin >> id;

    // Calculate the GPA for the selected student.
    float totalPoints = 0.0f, totalCredits = 0.0f;

    for (Grade& grd : grades){
        if (grd.get_student_id() == id){
            float points = 0.0f;
            switch (grd.get_grade())
            {
            case 'A':
                points += 4;
                break;
            case 'B':
                points += 3;
                break;
            case 'C':
                points += 2;
                break;
            case 'D':
                points += 1;
                break;
            case 'E':
                points += 0;
                break;            
            default:
                break;
            }

            float credits = 0.0f;
            for (Course& crs : courses){
                if (crs.get_id() == grd.get_course_id())
                    credits = crs.get_credits();
            }

            totalPoints += points * credits;
            totalCredits += credits;
        }
    }

    GPA = totalPoints / totalCredits;

    std::string student_str;
    for (Student& stud : students){
        if (stud.get_id() == id)
            student_str = stud.get_name();
    }

    std::cout << "The GPA for " << student_str << " is " << GPA << std::endl;
    
    std::cout << std::endl << std::endl;
    return (0);
}
