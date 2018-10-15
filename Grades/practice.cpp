#include <iostream> 



enum class Letter // enumeration example
    { A, B, C };

template<typename Z> // template syntax
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
};

class List {
    public:
    
    double *m_array;
    size_t arr_size;

    // custom constructor
    List() : arr_size{0} , m_array{nullptr} {};

    //copy constructor
    List(const List& other){ *this = other; };

    // move constructor
    List(List&& other){ *this = std::move(other); };

    // copy assignment operator
    List& operator=(const List& other){
        
    };


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