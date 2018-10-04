#include <string>
#include <regex>
#include "Message.h"


namespace w4{

    Message::Message(){}
    Message::Message(const Message& other){
        m_reply = other.m_reply;
        m_tweet = other.m_tweet;
        m_user = other.m_user;
    }
    
    
    void Message::storeData(char delimiter, std::string& string, std::string& member){
        if(string.at(0) == ' ' || string.at(0) == '@' )
            string.erase(0,1);

        while(string.at(0) != delimiter){
                member += string[0];
                string.erase(0,1);
            }
    }


    Message::Message(std::ifstream& in, char c)
    {// retrives a record from the in file object parses the record and stores its components in the Message object
    // 'c' denotes the delimiter
    
    std::string tmp;
        if(in.is_open()){   // check if file is open
            std::getline(in, tmp, c); // store message
        }

        if(tmp.find(' ') != -1){ // if a space is found, there is a message

            storeData(' ', tmp, m_user); // store data from tmp into m_user

            int msg_start; // will hold the index where tweet begins
            if(tmp.find('@') != -1)// if '@' is found within the string, there is a reply
                storeData(' ', tmp, m_reply);    
            
            storeData('\r', tmp, m_tweet);
        }
        std::cout << m_user << ' ' << m_reply << ' ' << m_tweet << std::endl;
    }

    bool Message::empty() const
    {
        bool isEmpty = true;
        if(!m_tweet.empty())
            isEmpty = false;

        return isEmpty;

    }

    void Message::display(std::ostream& os) const
    { // inserts message to the output stream
        std::cout << "Message" << std::endl;
        os << __message;
    }
}
