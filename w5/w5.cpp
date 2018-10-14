// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {

    std::cout << "Command Line: ";
    for (int i = 0; i < argc; i++)
        std::cout << argv[i] << ' ';
    std::cout << std::endl;

    if (argc == 1) {
        std::cerr << "\n*** Insufficient number of arguments ***\n";
        std::cerr << "Usage: " << argv[0] << " fileName \n";
        return 1;
    }
    else if (argc != 2) {
        std::cerr << "\n*** Too many arguments ***\n";
        std::cerr << "Usage: " << argv[0] << " fileName \n";
        return 2;
    }

    try{
        Grades grades(argv[1]);    
    

    auto letter = [](double g){
        Letter grade;
        if(g >= 90)
            grade = Letter::A_plus;
        else if(g >= 80)
            grade = Letter::A;
        else if(g >= 75)
            grade = Letter::B_plus;
        else if(g >= 70)
            grade = Letter::B;
        else if(g >= 65)
            grade = Letter::C_plus;
        else if(g >= 60)
            grade = Letter::C;
        else if(g >= 55)
            grade = Letter::D_plus;
        else if(g >= 50)
            grade = Letter::D;
        else
            grade = Letter::F;
        
        return grade;
        };
        
        grades.displayGrades(std::cout, letter);
    
    } catch(const char* message){
        std::cout << message << std::endl;
    }

    return 0;
}