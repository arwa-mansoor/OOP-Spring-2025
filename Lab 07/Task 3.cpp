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
    Dollar dollar(100);
    dollar.displayCurrency();
    dollar.convertToBase();
    dollar.convertTo("EUR");
    dollar.convertTo("PKR");
    cout << endl;

    Euro euro(100);
    euro.displayCurrency();
    euro.convertToBase();
    euro.convertTo("PKR");
    cout << endl;

    Rupee rupee(100);
    rupee.displayCurrency();
    rupee.convertToBase();
    rupee.convertTo("EUR");
    cout << endl;

    return 0;
}
