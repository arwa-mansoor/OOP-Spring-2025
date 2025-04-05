#include <iostream>
using namespace std;

class Currency
{
    private:
        float value;

    public:
        Currency(float value = 0) : value(value){}

        Currency operator-() const
        {
            return Currency(-value);
        }

        Currency operator+(const Currency& other)
        {
            return Currency(value + other.value);
        }

        Currency operator-(const Currency& other)
        {
            return Currency(value - other.value);
        }

        Currency& operator+=(const Currency& other)
        {
            value += other.value;
            return *this;
        }

        Currency& operator-=(const Currency& other)
        {
            value -= other.value;
            return *this;
        }
        
        friend ostream& operator<<(ostream& os, const Currency& other);
};  

ostream& operator<<(ostream& os, const Currency& other)
{
    os << other.value;
    return os;
}

int main()
{
    Currency currency1(450.0), currency2(100.0);
    cout << "Currency Value 1: 450\n";
    cout << "Currency Value 2: 100\n";
    cout << endl;
    cout << "Negated Value: " << -currency1 << endl;
    cout << "Value after Addition: " << currency1 + currency2 << endl;
    cout << "Value after Subtraction: " << currency1 - currency2 << endl;
    currency1 += currency2;
    cout << "Value with Profit: " << currency1 << endl;
    currency1 -= currency2;
    cout << "Value after Loss: " << currency1 << endl;

    return 0;
}
