// Name: MIGUEL RONCANCIO
// Seneca Student ID: 151091170
// Seneca email: mroncancio@myseneca.ca
// Date of completion: September 26 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.



#ifndef LIST_H
#define LIST_H

#include <iostream>

template <typename T, int N = 1> // default int type for parameter T
class List {
    
    T m_array[N]; // array of type T, size N
    size_t count;
    T dummy;

    public:

    List() // default constructor adopts a safe empty state
    {
        count = 0; // set count to 0
    };      
    
    size_t size () const { return count; } // returns the number of entries in the array  


    const T& operator[](size_t index) const // overloaded operator that returns the element at the requested index from array
    {
        if(index >= 0 && index < count)
            return m_array[index];
	    else
	        return dummy;
    };
    
     
    void operator+=(const T& newItem) // overloaded operator that adds an element to the array if space is available
    {
        if(count < N){
            m_array[count] = newItem;
            count++;
        }
            
        else 
        std::cout << "Error: Array is full" << std::endl; 
    };  
};


#endif

