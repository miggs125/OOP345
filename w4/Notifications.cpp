// Name: MIGUEL RONCANCIO
// Seneca Student ID: 151091170
// Seneca email: mroncancio@myseneca.ca
// Date of completion: October 4 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Notifications.h"
#include "Message.h"

namespace w4 {
    //************** CONSTRUCTORS / DESTRUCTORS ***********************
    Notifications::Notifications(): msg_P{nullptr}, m_size{0} {} // default constructor sets instance in an empty state

    Notifications::~Notifications() // destructor
    {
        for(int i = 0; i < 10; i++){
            if(msg_P[i] != nullptr){
                delete msg_P[i];
                msg_P[i] = nullptr;
            }  
        }
    }

    // copy constructor
    Notifications::Notifications(const Notifications& other){ *this = other; }

    Notifications::Notifications(Notifications&& other) { *this = std::move(other); }

    //************** OVERLOADED OPERATORS ****************************

    Notifications& Notifications::operator=(const Notifications& other) // copy assignment operator
    {
        //check for self assignment
        if(this != &other){
            

            for(int i = 0; i < m_size; ++i){
                if(msg_P[i] != nullptr)
                    delete msg_P[i]; // free memory
            }
            m_size = 0; // shallow copy of data members
            for(int i = 0; i < other.m_size; i++){
                *this += *other.msg_P[i];   // copy data
            }
        }
        return *this;
    }

    Notifications& Notifications::operator=(Notifications&& other)// move assignment operator
    {
        // check for self assignment
        if(this != &other){
            for(int i = 0; i < 10; i++) //move resources and member variables
                *this+= *other.msg_P[i]; 
        }
        return *this;
    }

    void Notifications::operator+=(const Message& msg) // adds msg to the set of messages *messages
    {
        if(m_size < 10)
            msg_P[m_size++] = new Message(msg);
    }

    //************** MEMBER FUNCTIONS ********************************
    void Notifications::display(std::ostream& os) const // inserts message objects to the os output stream
    {
        for(size_t i = 0; i < m_size; ++i){
            msg_P[i]->display(os);      // arrow operator used because msg_P[i] is a pointer. need to dereference.
            os << std::endl;
        }
    }
}
