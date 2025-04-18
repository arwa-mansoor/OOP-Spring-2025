#include <iostream>
#include <string>
using namespace std;

class PaymentMedthod
{
    public:
        virtual void processPayment(double amount) = 0;
};

class CreditCard : public PaymentMedthod
{
    private:
        string cardNumber;
    
    public:
        CreditCard(string cardNumber) : cardNumber(cardNumber){}

        void processPayment(double amount)
        {
            string cardNum;
            cout << "Enter your credit card number:";
            cin >> cardNum;
            if(cardNum == cardNumber)
            {
                cout << "Valid! Processing payment...\n";
                return;
            }
            cout << "Invalid Card Number!\n";
        }
};

class DigitalWallet : public PaymentMedthod
{
    private:
        double balance;
    
    public:
        DigitalWallet(double balance) : balance(balance){}

        void processPayment(double amount)
        {
            if(amount > balance)
            {
                cout << "Payment can not be processed due to insuffficient funds!\n";
                return;
            }
            cout << "Payment processed successfully!\n";
            cout << "Current Balance: " <<  balance << endl;
        }
};

int main()
{
    CreditCard creditCard("ABC123");
    DigitalWallet digitalWallet(1500);

    cout << "Credit Card\n";
    creditCard.processPayment(500);
    cout << endl;
    
    cout << "Digital Wallet\n";
    digitalWallet.processPayment(1600);
    cout << endl;
    return 0;
}
