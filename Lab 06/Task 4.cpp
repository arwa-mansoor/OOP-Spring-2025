#include <iostream>
using namespace std;

class Account
{
    protected:
    int accountNumber;
    float balance;

    public:
    Account(int accountNumber, float balance) : 
    accountNumber(accountNumber), balance(balance){}

    void displayDetails()
    {
        cout << "-------------------------\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account
{
    protected:
    float interestRate;

    public:
    SavingsAccount(int accountNumber, float balance, float interestRate):
    Account(accountNumber, balance), interestRate(interestRate){}

    void displayDetails()
    {
        Account::displayDetails();
        cout << "Interest Rate: " << interestRate << endl;
    }
};

class CheckingAccount : public Account
{
    protected:
    float overdraftLimit;

    public:
    CheckingAccount(int accountNumber, float balance, float overdraftLimit):
    Account(accountNumber, balance), overdraftLimit(overdraftLimit){}

    void displayDetails()
    {
        Account::displayDetails();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main()
{
    SavingsAccount acc1(1234, 500.65, 12.3);
    CheckingAccount acc2(5678, 650.89, 1000.00);
    acc1.displayDetails();
    acc2.displayDetails();
    return 0;
}
