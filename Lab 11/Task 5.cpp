#include <iostream>
#include <exception>
#include <sstream>
using namespace std;

class InsufficientFundsException : public exception
{
    private:
        float deficit;
        string message;
    public:
        InsufficientFundsException(float deficit) : deficit(deficit)
        {
            message = "InsufficentFundsException - Deficit: PKR " + to_string(deficit);

        }
        const char* what() const noexcept override
        {
            return message.c_str();
        }
};

template <typename T>
class BankAccount
{
    private:
        T balance;

    public:
        BankAccount(T balance) : balance(balance){}

        void withdarw(T amount)
        {
            if(amount > balance)
            {
                throw InsufficientFundsException(amount - balance);
            }
            balance -= amount;
            cout << "Balance: PKR " << balance << endl; 
        }

        void Deposit(T amount)
        {
            cout << "Amount Deposited!" << endl;
            balance += amount;
            cout << "Balance: " << balance << endl;
        }
};


int main()
{
    try 
    {
        BankAccount<float> acc(500.0);
        acc.withdarw(600.0);
    }
    catch(const exception& e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}
