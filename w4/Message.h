// Name: MIGUEL RONCANCIO
// Seneca Student ID: 151091170
// Seneca email: mroncancio@myseneca.ca
// Date of completion: October 4 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <fstream>
#include <string>

namespace w4{
    class Message
    {
        private:
        std::string m_user, m_reply, m_tweet;   // stores data pertaining to the message
                
        public:
        
        Message(const Message& other);  // copy constructor
        Message(std::ifstream& in, char c); // retrives a record from the in file, parses and stores its components in the Message object. 'c' denotes the delimiter
        bool empty() const; // returns true if the object is in a safe empty state
        void display(std::ostream& os) const; // displays the message objects within the container
        void storeData(char delimiter, std::string& string, std::string& member);   // stores data from temporary string into instance variables
    };
}

#endif // MESSAGE_H
