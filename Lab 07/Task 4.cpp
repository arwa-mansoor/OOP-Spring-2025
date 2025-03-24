#include <iostream>
using namespace std;

class Person
{
    public:
        string name;
        int id;
        string address;
        string phoneNumber;
        string email;

        Person(string name, int id, string address, string phoneNumber, string email) : 
        name(name), id(id), address(address), phoneNumber(phoneNumber), email(email){}

        virtual void displayInfo()
        {
            cout << "Details:\n";
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "Address: " << address << endl;
            cout << "Phone Number: " << phoneNumber << endl;
            cout << "Email: " << email << endl; 
        }

        void updateInfo(string address, string phoneNumber, string email)
        {
            this->address = address;
            this->phoneNumber = phoneNumber;
            this->email = email;
            cout << "Details Updated\n";
        }
};

class Student : public Person{
    protected:
        string coursesEnrolled[5];
        float gpa;
        int enrollmentYear;

    public:
        Student(string name, int id, string address, string phoneNumber, string email, string coursesEnrolled[5], float gpa, int enrollmentYear) :
        Person(name, id, address, phoneNumber, email),
        gpa(gpa), enrollmentYear(enrollmentYear)
        {
            for (int i = 0; i < 5; i++)
            {
                this->coursesEnrolled[i] = coursesEnrolled[i];
            }
        }
    
        void displayInfo()
        {
            Person::displayInfo();
            cout << "Courses Enrolled:\n";
            for (int i = 0; i < 5; i++)
            {
                cout << coursesEnrolled[i] << endl;
            }
            cout << "GPA: " << gpa << endl;
            cout << "Enrollment Year: " << enrollmentYear << endl;
        }
};

class Professor : public Person
{
    protected:
        string department;
        string coursesTaught[3];
        float salary;

    public:
        Professor(string name, int id, string address, string phoneNumber, string email, string department, string coursesTaught[3], float salary) :
        Person(name, id, address, phoneNumber, email),
        department(department), salary(salary)
        {
            for (int i = 0; i < 3; i++)
            {
                this->coursesTaught[i] = coursesTaught[i];
            }        
        }

        void displayInfo()
        {
            Person::displayInfo();
            cout << "Department: " << department << endl;
            cout << "Courses Taught:\n";
            for (int i = 0; i < 3; i++)
            {
                cout << coursesTaught[i] << endl;
            }  
            cout << "Salary: " << salary << endl;      
        }
};

class Staff : public Person
{
    protected:
        string department;
        string position;
        float salary;

    public:
        Staff(string name, int id, string address, string phoneNumber, string email, string department, string position, float salary) :
        Person(name, id, address, phoneNumber, email),
        department(department), position(position), salary(salary){} 

        void displayInfo()
        {
            Person::displayInfo();
            cout << "Department: " << department << endl;
            cout << "Position: " << position << endl;
            cout << "Salary: " << salary << endl;
        }
};

class Course
{
    protected:
        int courseID;
        string courseName;
        int credits;
        string instructor;
        string schedule;
        

    public:
        Course(int courseID, string courseName, int credits, string instructor, string schedule) :
        courseID(courseID), courseName(courseName), credits(credits), instructor(instructor), schedule(schedule){}

        void registerStudent(Student &student)
        {
            cout << student.name << " registered for " << courseName << endl;
        }

        void calculateGrades()
        {
            cout << "Calculating grades " <<" in " << courseName << endl;
        }

};

int main()
{
    string studentCourses[5] = {"MVC", "DLD", "OOP", "EW", "IRS"};
    string professorCourses[3] = {"DLD", "OOP", "MVC"};

    Person* p1 = new Student("Sara", 240987, "123 street", "+921234567890" , "sara@gmail.com", studentCourses, 3.6, 2024);
    p1->displayInfo();
    delete p1;
    cout << endl;

    Person* p2 = new Professor("William", 145, "456 street", "+920987654321", "william@gmail.com", "CS", professorCourses, 75000);
    p2->displayInfo();
    delete p2;
    cout << endl;

    Person* p3 = new Staff("Jane", 32567, "789 street", "+921357924680", "jane@gmail.com", "AI", "Instructor", 85000);
    p3->displayInfo();
    delete p3;
    cout << endl;

    Course course(786, "OOP", 3, "John", "Mon, Thurs, Fri 11:00 AM - 12:30 PM");
    Student student("Sara", 240987, "123 street", "+921234567890" , "sara@gmail.com", studentCourses, 3.6, 2024);
    course.registerStudent(student);
    course.calculateGrades();

    return 0;
}
