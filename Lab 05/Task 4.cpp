#include <iostream>
using namespace std;

class Battery{
	private:
		int capacity;	
		
	public:
		Battery(int cap) : capacity(cap){}
		
		void display()
		{
			cout << "Battery capacity is " << capacity << " mAh\n";
			cout << endl;
		}			
};

class Smartphone{
	
	private:
		string model;
		Battery battery;
		
	public:
		Smartphone(string mod, int cap) : model(mod), battery(cap){}
	
		void displayDetails()
		{
			cout << "Smartphone Details:\n";
			cout << "Model: " << model << endl;
			battery.display();
		}			
};

int main()
{
	Smartphone p1("Samsung S1", 4500);
	Smartphone p2("Redmi", 3500);
	
	p1.displayDetails();
	p2.displayDetails();
	
	return 0;
	
}
