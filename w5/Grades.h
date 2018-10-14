#ifndef GRADES_H
#define GRADES_H

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Letter.h"

class Grades {
    
    private: 

    int* studentNumber; // array that stores the student id's in the class
    double* studentGrade; // array that stores the grades of the students in the class
    size_t arrSize; // size of the arrays and therefore the number of students in the class

    public:

    Grades(const char* file); // constructor
    ~Grades(); // destructor
    Grades(const Grades&) = delete; // prohibit copy constructor
    Grades(Grades&&) = delete;  // prohibit move constructor
    Grades& operator=(Grades&&) = delete;    // prohibit move assignment
    Grades& operator=(const Grades&) = delete; // prohibit copy assignment
    void parseData(char delimiter, std::string& string, std::string& member);

    template<typename F>
    void displayGrades(std::ostream& os, F func) const{
        for(size_t i = 0; i < arrSize; ++i)
            std::cout << std::setprecision(2) << std::fixed << studentNumber[i] << " " << studentGrade[i] 
            << " " << sict::convert(func(studentGrade[i])) << std::endl;      
    }

}; 


#endif