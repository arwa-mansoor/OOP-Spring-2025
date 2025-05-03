#include <iostream>
#include <exception>
using namespace std;

class StackUnderflowException;
class StackOverflowException;

template <typename T>
class Stack
{
    private:
        const int capacity;
        int topPtr;
        T* arr;

    public:
        Stack(int capacity) : capacity(capacity), topPtr(-1)
        {
            arr = new T[capacity];
        }

        void push(const T& item)
        {
            if(topPtr == capacity - 1)
            {
                throw StackOverflowException();
            }
            arr[++topPtr] = item;
        }

        T pop()
        {
            if (topPtr == -1)
            {
                throw StackUnderflowException();
            }
            return arr[topPtr--];
        }
};

class StackOverflowException : public exception
{
    public:
        const char* what() const noexcept override
        {   
            return "StackOverflowExcpetion - Stack is full!";
        }
};
class StackUnderflowException : public exception
{
    public:
        const char* what() const noexcept override
        {
            return "StackUnderflowException - Stack is empty!";
        }
};

int main()
{
    Stack<string> names(2);
    try
    {
        names.push("Mike");
        names.push("John");
        names.push("Sara");
    }
    catch(const exception& e)
    {
        cerr << e.what() << endl;
    }

    try
    {
        names.pop();
        names.pop();
        names.pop();
    }
    catch(const exception& e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
