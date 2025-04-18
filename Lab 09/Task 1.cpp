#include <iostream>
using namespace std;

class Vehicle
{
    protected:
        string model;
        double rate;

    public:
        Vehicle(string model, double rate) : model(model), rate(rate){}
        virtual double getDailyRate() = 0;
        virtual void displayDetails() = 0;
};

class Car : public Vehicle
{
    public:
        Car(string model, double rate) : Vehicle(model, rate){}

        double getDailyRate() override 
        {
            return rate;
        }

        void displayDetails() override 
        {
            cout << "Car Details:\n";
            cout << "Model: " << model << endl;
            cout << "Daily Rate: " << rate << endl;
        }
};


class Bike : public Vehicle
{
    public:
        Bike(string model, double rate) : Vehicle(model, rate){}

        double getDailyRate() override 
        {
            return rate;
        }

        void displayDetails() override 
        {
            cout << "Bike Details:\n";
            cout << "Model: " << model << endl;
            cout << "Daily Rate: " << rate << endl;
        }    
};

int main()
{
    Vehicle* vehicle[2];

    Car car("Civic", 1700);
    Bike bike("Honda", 800);

    vehicle[0] = &car;
    vehicle[1] = &bike;

    for(int i = 0; i < 2; i++)
    {
        vehicle[i]->displayDetails();
        cout << "Rate: " << vehicle[i]->getDailyRate() << endl;
        cout << endl;
    }
    
    return 0;
}
