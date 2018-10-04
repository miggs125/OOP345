// Name: MIGUEL RONCANCIO
// Seneca Student ID: 151091170
// Seneca email: mroncancio@myseneca.ca
// Date of completion: October 4 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H
#include <string>
#include "Message.h"
namespace w4{


    class Notifications
    {
        private:

        Message *msg_P[10];  // array of pointers to Message objects
        size_t m_size;

        public:

        //************** CONSTRUCTORS / DESTRUCTORS ***********************
        Notifications(); // constructor
        ~Notifications();   // destructor
        Notifications(const Notifications& other); // copy constructor
        Notifications(Notifications&& other); // move constructor


        //************** OVERLOADED OPERATORS ****************************
        Notifications& operator=(const Notifications& other); // copy assignment operator
        Notifications& operator=(Notifications&& other); // move assignment operator
        void operator+=(const Message& msg);  // adds msg to the set of messages *messages



        //************** MEMBER FUNCTIONS ********************************
        void display(std::ostream& os) const; // inserts message objects to the os output stream
    };
}
#endif // NOTIFICATIONS_H
