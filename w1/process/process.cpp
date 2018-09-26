// Name: MIGUEL RONCANCIO
// Seneca Student ID: 151091170
// Seneca email: mroncancio@myseneca.ca
// Date of completion: September 12 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include "process.h"

using namespace w1;

void process(const char* string, std::ostream& os){

    w1::CString foo(string);
    // os << foo << std::endl;
    w1::operator<<(os,foo);
    os << std::endl;

}