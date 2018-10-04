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
        void format(); // formats the message stored in __message
        void storeData(char delimiter, std::string& string, std::string& member);   // stores data from temporary string into instance variables
    };
}

#endif // MESSAGE_H
