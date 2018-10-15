#include <iostream> 



enum class Letter // enumeration example
    { A, B, C };

template<typename Z>
const char* convert(const Z &letter){   
    switch(letter){
        case Letter::A:
            return "A";
        case Letter::B:
            return "B";
        case Letter::C:
            return "C";
    }
    return "dummy";
}

template <typename T, int G = 0> // template syntax
class List {
    public:
    T m_array*;
    size_t arr_size;
    T dummy;

    // custom constructor
    List() : arr_size{G}, m_array{nullptr} { }

    //copy constructor
    List& List(const List& other){ *this = other; }

    // move constructor
    List& List(List&& other){ *this = std::move(other); }

    // copy assignment operator
    List& operator=(const List& other){
        
    }


    // move assignment operator 





    // overloaded [] operator
    const T& operator[](size_t index) const {
        if(index >= 0 && index < count)
            return m_array[index];
	    else
	        return dummy;
    };




    // overloaded += operator
    void operator+=(const T& newLetterGrade) // overloaded operator that adds an element to the array if space is available
    {
        
    
    }






};


int main()
{

    return 0;
}