#include <iostream>
using namespace std;

class Employee
{
    protected:
    string name;
    float salary;

    public:
    Employee(string name, float salary): name(name), salary(salary){}

    void displayDetails()
    {
        cout << "-----------------------\n";
        cout << "Employee Name: " << name << endl;
        cout << "Employee Salary: " << salary << endl;
    }
};

class Manager : public Employee
{
    protected:
    float bonus;

    public:
    Manager(string name, float salary, float bonus) :
    Employee(name, salary), bonus(bonus){}

    void displayDetails()
    {
        Employee::displayDetails();
        cout << "Manager Bonus: " << bonus << endl;
    }
};

int main()
{
    Manager m1("John", 500.87, 35.7);
    m1.displayDetails();
    return 0;
}
