#include <iostream>
using namespace std;

class Currency
{
    protected:
        float amount;
        string currencyCode;
        string currencySymbol;
        float exchangeRate;

    public:
        Currency(float amount, string currencyCode, string currencySymbol, float exchangeRate) :
        amount(amount), currencyCode(currencyCode), currencySymbol(currencySymbol), exchangeRate(exchangeRate){}
        
        virtual void convertToBase()
        {
            cout << "Converted to base: " << amount * exchangeRate << endl;
        }

        virtual void convertTo(string targetCurrency)
        {
            if(targetCurrency == "USD")
            {
                cout << "Converted to USD: " << (amount * exchangeRate) / 1 << endl;
            }
            else if(targetCurrency == "EUR")
            {
                cout << "Converted to EUR: " << amount * exchangeRate / 1.09 << endl;
            }
            else if(targetCurrency == "PKR")
            {
                cout << "Converted to PKR: " << (amount * exchangeRate) /0.0036 << endl;
            }
            else
            {
                cout << "Exchange rate not found!\n";
            }

        }

        void displayCurrency()
        {
            cout << "Currency Details:\n";
            cout << "Amount: " << amount << endl;
            cout << "Code: " << currencyCode << endl;
            cout << "Symbol: " << currencySymbol << endl;
            cout << "Exchange Rate: " << exchangeRate << endl;
        }
};

class Dollar : public Currency
{
    public:
        Dollar(float amount) : Currency(amount, "USD", "$", 1.0){}

        void convertToBase()
        {
            Currency::convertToBase();
        }

        void displayCurrency()
        {
            Currency::displayCurrency();
        }
};

class Euro : public Currency
{
    public:
        Euro(float amount) : Currency(amount, "EUR", "€", 1.09){}
        
        void convertToBase()
        {
            Currency::convertToBase();
        }

        void displayCurrency()
        {
            Currency::displayCurrency();
        }


};

class Rupee : public Currency
{
    public:
        Rupee(float amount) : Currency(amount, "PKR", "Rs" , 0.0036){}

        void convertToBase()
        {
            Currency::convertToBase();
        }

        void displayCurrency()
        {
            Currency::displayCurrency();
        }
 
};

int main()
{
    Currency* c1 = new Dollar(100);
    c1->displayCurrency();
    c1->convertToBase();
    c1->convertTo("EUR");
    c1->convertTo("PKR");
    delete c1;
    cout << endl;

    Currency* c2 = new Euro(100);
    c2->displayCurrency();
    c2->convertToBase();
    c2->convertTo("PKR");
    delete c2;
    cout << endl;

    Currency* c3 = new Rupee(100);
    c3->displayCurrency();
    c3->convertToBase();
    c3->convertTo("EUR");
    delete c3;
    cout << endl;

    return 0;
}
