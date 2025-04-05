#include <iostream>
using namespace std;

class Fraction
{
    private:
        int numerator;
        int denominator;

    public:
        Fraction(int numerator = 0, int denominator = 0) : numerator(numerator), denominator(denominator){}

        Fraction operator+(const Fraction& fraction)
        {
            Fraction temp;
            if(denominator != fraction.denominator)
            {
                temp.denominator = denominator * fraction.denominator;
                temp.numerator = (numerator * fraction.denominator) + (fraction.numerator * denominator);
            }
            else
            {
                temp.denominator = denominator;
                temp.numerator = numerator + fraction.numerator;
            }
            return temp;
        }

        Fraction operator-(const Fraction& fraction)
        {
            Fraction temp;
            if(denominator != fraction.denominator)
            {
                temp.denominator = denominator * fraction.denominator;
                temp.numerator = (numerator * fraction.denominator) - (fraction.numerator * denominator);
            }
            else
            {
                temp.denominator = denominator;
                temp.numerator = numerator - fraction.numerator;
            }
            return temp;
        }

        Fraction operator*(const Fraction& fraction)
        {
            return Fraction(numerator * fraction.numerator, denominator * fraction.denominator);
        }

        Fraction operator/(const Fraction& fraction)
        {
            return Fraction(numerator * fraction.denominator, denominator * fraction.numerator);
        }

        friend ostream& operator<<(ostream& os, const Fraction& fraction);
};

ostream& operator<<(ostream& os, const Fraction& fraction)
{
    os << fraction.numerator << "/" << fraction.denominator;
    return os;
}

int main()
{
    Fraction fraction1(3, 4), fraction2(1,2);
    cout << "Addition\n";
    cout << "3/4 + 1/2 = " << fraction1 + fraction2 << endl;
    cout << "Subtraction:\n";
    cout << "3/4 - 1/2 = " << fraction1 - fraction2 << endl;
    cout << "Multiplication:\n";
    cout << "3/4 * 1/2 = " << fraction1 * fraction2 << endl;
    cout << "Division:\n";
    cout << "3/4 ÷ 1/2 = " << fraction1 / fraction2 << endl;
    return 0;
}
