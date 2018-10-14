#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <stdio.h>
#include "Grades.h"

Grades::Grades(const char* file) : arrSize{0}, 
studentNumber{nullptr}, studentGrade{nullptr} {
    std::fstream m_file;
    std::string tmp; // temporary string for line count
    
    m_file.open(file);

    if(!m_file.is_open())
        throw "There was an error in opening the file";    
    else{

    }
    while(getline(m_file, tmp)){    // count the number of lines, therefore array size
        arrSize++;
    }
    m_file.clear();
    m_file.seekg(0, std::ios::beg);
    // allocation of memory for grades arrays
    studentNumber = new int[arrSize];
    studentGrade = new double[arrSize];

    for(size_t i = 0; i < arrSize; ++i){
        m_file >> studentNumber[i];
        m_file.ignore();
        m_file >> studentGrade[i];
    }
}

Grades::~Grades(){
    delete [] studentNumber;
    delete [] studentGrade;
    studentGrade = nullptr;
    studentNumber = nullptr;

}
