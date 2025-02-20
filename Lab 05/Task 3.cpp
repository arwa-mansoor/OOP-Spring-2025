#include <iostream>
using namespace std;

class Professor{
	public:
		string name;
		string department;
		
		Professor(string profName, string deptName) : name(profName), department(deptName){}
		
		void display()
		{
			cout << "Professor Name: " << name << endl;
			cout << "Department Name: " << department << endl;
			cout << endl; 
		}
};

class University{
		private:
			Professor *professor[50];
			int professorCount = 0;
			
		public:
			void addProfessor(Professor *prof)
			{
				professor[professorCount++] = prof;
			}
			
			void displayUniversityDetails()
			{
				cout << "Professor Details:\n";
				for(int i = 0; i < professorCount; i++)
				{
					professor[i]->display();
				}
			}
};

int main()
{
	Professor p1("Michael", "CS");
	Professor p2("Sara", "AI");
	Professor p3("John", "DS");
	Professor p4("William", "SE");

	University uni;
	uni.addProfessor(&p1);
	uni.addProfessor(&p2);
	uni.addProfessor(&p3);
	
	uni.displayUniversityDetails();
	
	cout << "Independent Professor:\n";
	p4.display();
	
	return 0;	
}

