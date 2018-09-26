/*
Design and code a class template named Pair for managing a key-value pair off template data types A and B.

Your design includes the following member functions:
• Pair() — default constructor adopts a safe empty state
• Pair(const A&, const B&) — overloaded constructor that sets the key-value pair elements of the class
• const A& getKey() const — returns a read-only version of the stored key information
• const B& getValue() const — returns a read-only version of the stored value information*/

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