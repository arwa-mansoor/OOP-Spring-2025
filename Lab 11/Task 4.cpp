# include <iostream>
# include <exception>
# include <typeinfo>
#include <type_traits>
# include <cmath>


using namespace std;

template<typename N>
class NegativeNumberException: public exception
{
    public:
        N num;

        NegativeNumberException(N num): num(num){}

        const char* what() const noexcept override
        {
            return "NegativeNumberException - Input must be non-negative!";
        }
};

template<typename I>
class InvalidTypeException: public exception
{
    public:
        I str;

        InvalidTypeException(I str): str(str){}

        const char* what() const noexcept override
        {
            return "InvalidTypeExceptionException - Non-numeric data detected!";
        }
};

template<typename T>
void mySqrt(T num)
{
    if constexpr (!is_arithmetic<T>::value) 
    {
        throw InvalidTypeException<T>(num);
    }
    else if (num < 0)
    {
        throw NegativeNumberException<T>(num);
    }
    else
    {
        cout << "Square Root: " << sqrt(num) << endl;
    }
}

int main()
{
    try 
    {
        mySqrt(-10);
    }
    catch(exception &b)
    {
        cout << b.what() << endl;
    }

    try 
    {
        mySqrt("Hello");
    }
    catch(exception &b)
    {
        cout << b.what() << endl;
    }
    
}
