#include <iostream>
using namespace std;

class car
{
	public:
	    int* registrationNum;
	    string* model;
	    string *ownerName;
	
	car(int num, string m, string name)
	{
	    registrationNum = new int(num);
	    model = new  string (m);
	    ownerName = new string (name);
	}
	car(const car &c)
	{
	    registrationNum = c.registrationNum;
	    model = c.model;
	    ownerName = c.ownerName;
	}
	
	void display()
	{
	    cout << "Registration Number :" << *registrationNum << endl;
	    cout << "Model Name: " << *model << endl;
	    cout << "Owner Name: " << *ownerName << endl;
	    cout << "-----------------" << endl;
	}
	
	~car(){}
};

int main()
{
    car c1(122,"cb09","Ali");
	c1.display();
    car c2(c1);
    *c2.ownerName = "Maria";
	cout << "Car 1 owner's name changed\n";
	c1.display();
	cout << "Car 2\n";
    c2.display();   
}

