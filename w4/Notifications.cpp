#include "Notifications.h"
#include "Message.h"

namespace w4 {
    //************** CONSTRUCTORS / DESTRUCTORS ***********************
    Notifications::Notifications(): msg_P{nullptr}, m_size{0} {} // default constructor sets instance in an empty state

    Notifications::~Notifications() // destructor
    {
        for(int i = 0; i < 10; i++){
            if(msg_P[i] != nullptr){
                delete [] msg_P[i];
                msg_P[i] = nullptr;
            } 
        }
    }


    Notifications::Notifications(const Notifications& other) // copy constructor  TODO: UPDATE TO HANDLE ARRAY OF POINTERS
    {
        *this = other; // calls copy assignment operator
    }


    Notifications::Notifications(Notifications&& other) // move constructor
    {
        //move resources and member variables
        for(int i = 0; i < 10; i++){
            msg_P[i] = other.msg_P[i];
            delete [] other.msg_P[i];
            other.msg_P[i] = nullptr;
        }
    }

    //************** OVERLOADED OPERATORS ****************************

    Notifications& Notifications::operator=(const Notifications& other) // copy assignment operator
    {
        //check for self assignment
        if(this != &other){
            m_size = other.m_size; // shallow copy of data members

            for(int i = 0; i < 10; i++){
                if(msg_P[i] != nullptr)
                    delete [] msg_P[i]; // free memory
                msg_P[i] = other.msg_P[i];  // copy over data 
            }
        }
        return *this;
    }

    Notifications& Notifications::operator=(Notifications&& other)// move assignment operator
    {
        // check for self assignment
        if(this != &other){
            
            m_size = other.m_size;
            // free exisiting resource
            for(int i = 0; i < 10; i++){
                if(msg_P[i] != nullptr)
                    delete [] msg_P[i]; // free current memory
                msg_P[i] = other.msg_P[i];  // transfer resources from other
                other.msg_P[i] = nullptr;   // release memory 
            }
        }
        return *this;
    }

    void Notifications::operator+=(const Message& msg) // adds msg to the set of messages *messages
    {

        if(m_size < 10){
            msg_P[m_size++] = new Message(msg); 
           // msg_P[m_size++] = const_cast<Message*>(&msg);
        }
    }

    //************** MEMBER FUNCTIONS ********************************
    void Notifications::display(std::ostream& os) const // inserts message objects to the os output stream
    {
        /*for(size_t i = 0; i < m_numMessages; ++i)
            messages[i].display(os);*/
    }
}
