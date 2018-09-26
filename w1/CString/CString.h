// Name: MIGUEL RONCANCIO
// Seneca Student ID: 151091170
// Seneca email: mroncancio@myseneca.ca
// Date of completion: September 12 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W1_CSTRING_H
#define W1_CSTRING_H

#include <cstring>
#include <iostream>

namespace w1 {
    
    class CString {
        
        char m_string[4];
        const int MAX; // defines the number of characters to be stored inside the object

        public:
        CString();// default constructor
        CString(const char* string); //single argument constructor 
        void display(std::ostream& os) const; // query displays the string as stored in the object

    };
    // helper function. insters the stored string into the ostream
    // preaface the string with the number of the insertion and increments that number
    std::ostream& operator<<(std::ostream& os,const CString& current); 
}

#endif