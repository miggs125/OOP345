// Name: MIGUEL RONCANCIO
// Seneca Student ID: 151091170
// Seneca email: mroncancio@myseneca.ca
// Date of completion: September 12 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W2_TEXT_H
#define W2_TEXT_H

#include <iostream>
#include <string>
#include <fstream>

namespace w2 {

    class Text {
        
        std::string* m_stringArray;
        size_t m_size;
        public:

        //CONSTRUCTORS

        Text(const char* str = nullptr); //default, one argument constructor
        Text(const Text& other); // copy constructor
        Text(Text&& other); //move constructor
        ~Text(); //destructor

        // MEMBER FUNCTIONS

        size_t size() const; //returns number of records of text data

        //OVERLOADED MEMBER OPERATORS
        Text& operator=(const Text& other); // copy assignment operator
        Text& operator=(Text&& other); //move assignment operator

    };


}


#endif