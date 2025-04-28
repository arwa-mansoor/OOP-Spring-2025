#include <iostream>
#include <exception>
using namespace std;

class InvalidValueException : public exception
{
    public:
        const char* what() const noexcept override
        {
            return "Age cannot be negative or exceed 120\n";
        }
};

void validateAge(int age)
{
    try
    {
        if(age < 0 || age > 120) throw InvalidValueException();
        cout << "Age is Valid!\n"; 
    }
    catch (const InvalidValueException &e)
    {
        cout << e.what() << endl;
    }
}

int main()
{
    int age;
    cout << "Enter age: ";
    cin >> age;
    validateAge(age);
    return 0;
}
