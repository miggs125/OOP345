// Name: MIGUEL RONCANCIO
// Seneca Student ID: 151091170
// Seneca email: mroncancio@myseneca.ca
// Date of completion: September 12 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <cstring>
#include <iostream>
#include "CString.h"

//internal linkage, global variables
int STORED = 3; //specifies the number of characters stored by the object
namespace w1{

    CString::CString() : MAX(0){ // default constructor sets object to safe empty state
        m_string[0] = '\0';
    }


    CString::CString(const char* string) : MAX(STORED) { // constructor
        
        if(string != nullptr){ // check for null address of string
            strncpy(m_string, string, MAX); // copy string into m_string if not null
            m_string[MAX] = '\0';
        } else {
            m_string[0] = '\0';  // store empty m_string in case string is null  
        }
    }

    void CString::display(std::ostream& os) const{
        os << m_string; // insert object string into ostream
    }

    std::ostream& operator<<(std::ostream& os, const CString& current){
        static int insertion = 0; // specifies the number of inset
        os << insertion++ << ": ";
        current.display(os);
        return os;
    }
}
        