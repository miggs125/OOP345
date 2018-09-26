// Name: MIGUEL RONCANCIO
// Seneca Student ID: 151091170
// Seneca email: mroncancio@myseneca.ca
// Date of completion: September 18 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
#include <fstream>
#include "Text.h"

//*******CONSTRUCTORS***************
namespace w2{

    // no-one argument constructor, receives reference to file path 
    Text::Text(const char* str) : m_size(0)
    {
        if(str != nullptr && str[0] != '\0'){ //check if filename was passed, str set to nullptr as default  
            std::ifstream file(str);    //create ifstream object and open with string passed
            
            if(file.is_open()){           // check is file is open
                std::string temp;       // create temporary string object
                
                while(getline(file, temp)) //loop goes through file line by line and increases counter when it encounters a new line
                    ++m_size;   // line counter

                m_stringArray = new std::string[m_size];    // allocate memory for string array of size m_size

                for(size_t i = 0; i < m_size; i++)
                    getline(file, m_stringArray[i]);    //store line in array at index i

                file.close(); 
            }
        } else
            m_stringArray = nullptr;  
    }
    

    Text::Text(const Text& other) // copy constructor
    {
        m_stringArray = nullptr;
        *this = other; // calls assignment operator 
    }     
   
    //move constructor
    Text::Text(Text&& other){

        //copy class data members and pointer from source 'other' 
        m_size = other.m_size;
        m_stringArray = other.m_stringArray;
        
        // release 'other' pointer from source object so that
        // destructor does not free memory more than once
        other.m_size = 0;
        other.m_stringArray = nullptr;
    }     
    
    
    Text::~Text() //destructor
    {
        delete [] m_stringArray;
        m_stringArray = nullptr;
    }
    
    //************MEMBER FUNCTIONS*************
    
    size_t Text::size() const { return m_size; } // returns number of records of text data
    
    
    //**********OVERLOADED MEMBER OPERATORS***************
    
    Text& Text::operator=(const Text& other) // copy assignment operator
    {
        m_size = other.m_size; // shallow copy size of array
    
        if(this != &other){ // check for self assignment
            
            // allocate memory
            delete [] m_stringArray;
            m_stringArray = new std::string[m_size];
            
            // deep copy array
            for(size_t i = 0; i< m_size; i++)
                m_stringArray[i] = other.m_stringArray[i];
        }
        return *this;
    }


    Text& Text::operator=(Text&& other) //move assignment operator
    {
        // check for self assignment
        if(this != &other){

            //free existing resource
            delete [] m_stringArray;
            
            //copy pointer and length from other
            m_size = other.m_size;
            m_stringArray = other.m_stringArray;

            //release data pointer from 'other' so that destructor does not
            // free memory multiple times
            other.m_stringArray = nullptr;
            other.m_size = 0;
        }
        return *this;
    }

}
