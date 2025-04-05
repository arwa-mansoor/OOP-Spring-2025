#include <iostream>
using namespace std;
class Teacher;

class Student
{   
    private:
        string studentName;
        float gradesArr[3];

    public:
        Student(string studentName, float grades[]) : studentName(studentName)
        {
            for(int i = 0; i < 3; i++)
            {
                gradesArr[i] = grades[i];
            }
        }
        friend class Teacher;
        friend void calculateAverageGrade(const Student& student);
};

class Teacher
{
    public:
        void displayStudentDetails(const Student& student)
        {
            cout << "Student Details:\n";
            cout << "Name: " << student.studentName << endl;
            cout << "Grades: ";
            for(int i = 0; i < 3; i++)
            {
                cout << student.gradesArr[i] << " | ";
            }
            cout << endl;
        }

        void updateGrade(Student& student, float newGrade, int index)
        {
            if(index > 0 && index <= 3)
            {
                student.gradesArr[index - 1] = newGrade;
            }
            else
            {
                cout << "Invalid Index!\n";
            }
            
        }
};

void calculateAverageGrade(const Student& student)
{
    float sum;
    for(int i = 0; i < 3; i++)
    {
        sum += student.gradesArr[i];
    }
    cout << "Average Grade: " << (sum / 3) << endl;
}

int main()
{
    float grade[3] = {72.5, 88.3, 65.5};
    Student student("Mike", grade);
    Teacher teacher;

    cout << "Before Updating One Grade:\n";
    teacher.displayStudentDetails(student);
    calculateAverageGrade(student);
    cout << endl;

    cout << "After Updating One Grade:\n";
    teacher.updateGrade(student, 91.7, 3);
    teacher.displayStudentDetails(student);
    calculateAverageGrade(student);

    return 0;
}
