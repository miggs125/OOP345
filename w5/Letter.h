#ifndef LETTER_H
#define LETTER_H

#include <cstring>

namespace sict {

    enum class Letter // enumeration constants that define the letter
    {                   // values for the grades in a course 
        A_plus,
        A,
        B_plus,
        B,
        C_plus,
        C,
        D_plus,
        D,
        F
    };

    template<typename T>
    const char* convert(const T &letter) // converts enumeration constant into C-string
    {                                       // returns address of string that represents enumeraiton constant
        char* grade[3];

        switch(letter){
            case Letter::A_plus:
                return "A+";
            case Letter::A:
                return "A";
            case Letter::B_plus:
                return "B+";
            case Letter::B:
                return "B";
            case Letter::C_plus:
                return "C+";
            case Letter::C:
                return "C";
            case Letter::D_plus:
                return "D+";
            case Letter::D:
                return "D";
            case Letter::F:
                return "F";
        }
    }
}   // sict 
#endif