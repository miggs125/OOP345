// Name: MIGUEL RONCANCIO
// Seneca Student ID: 151091170
// Seneca email: mroncancio@myseneca.ca
// Date of completion: September 26 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef PAIR_H
#define PAIR_H

#include <iostream>

template <typename A = char*, typename B = int>
class Pair {
    A m_key;
    B m_value;

    public:
    
    Pair() // default constructor, adopts safe empty state
    {

    };


    Pair(const A& key, const B& value) // overloaded constructor, sets key-value pair elements of the class 
    {
        m_key = key;
        m_value = value;
    };
     
    const A& getKey() const { return m_key; }
    const B& getValue() const { return m_value; }
};

#endif