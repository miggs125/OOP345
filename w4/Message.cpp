// Name: MIGUEL RONCANCIO
// Seneca Student ID: 151091170
// Seneca email: mroncancio@myseneca.ca
// Date of completion: October 4 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <string>
#include <iomanip>
#include "Message.h"


namespace w4{

    Message::Message(const Message& other){ // copy constructor 
        m_reply = other.m_reply;
        m_tweet = other.m_tweet;
        m_user = other.m_user;
    }
    
    
    void Message::storeData(char delimiter, std::string& string, std::string& member){
        
        while(string.at(0) == ' ' || string.at(0) == '@')   //  remove leading spaces and '@' characters
            string.erase(0,1);

        while(string.at(0) != delimiter){
            member += string[0];    // store data in instance variable
            string.erase(0,1);  //  remove parsed data from temporary string
        }
    }


    Message::Message(std::ifstream& in, char c)// retrives a record from the in file object parses the record and
    {// stores its components in the Message object. 'c' denotes the delimiter    
    std::string tmp; // create temporary string object
        if(in.is_open())   // check if file is open
            std::getline(in, tmp, c); // store message

        if(tmp.find(' ') != -1){ // if a space is found, there is a message

            storeData(' ', tmp, m_user); // store data from tmp into m_user

            int msg_start; // will hold the index where tweet begins
            if(tmp.find('@') != -1)// if '@' is found within the string, there is a reply
                storeData(' ', tmp, m_reply);   // store tweet reply user within instance variable    
            
            storeData('\r', tmp, m_tweet); // store tweet message in instance variable
        }
    }

    bool Message::empty() const // returns whether message is empty or not
    {
        bool isEmpty = true;
        if(!m_tweet.empty())
            isEmpty = false;

        return isEmpty;
    }

    void Message::display(std::ostream& os) const // formats message and inserts into output stream
    { // inserts message to the output stream
        os << "Message" << std::endl << std::setfill(' ') << std::setw(7) << std::left<< " User" << ": " << m_user << std::endl;
        if(!m_reply.empty())
            os << std::setfill(' ') << std::setw(7) << std::left << " Reply" << ": " <<  m_reply << std::endl;
        os << std::setfill(' ') << std::setw(7) << std::left <<" Tweet" << ": " << m_tweet << std::endl;
    }
}