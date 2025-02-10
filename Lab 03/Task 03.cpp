//24K-0930
#include <iostream>
#include <string>
using namespace std;

class Planner
{
	string jan[31];
	string feb[28];
	string mar[31];
	string apr[30];
	string may[31];
	string jun[30];
	string jul[31];
	string aug[31];
	string sep[30];
	string oct[31];
	string nov[30];
	string dec[31];
	
	public:
	Planner()
	{
		initializeTasks(jan, 31);
		initializeTasks(feb, 28);
		initializeTasks(mar, 31);
		initializeTasks(apr, 30);
		initializeTasks(may, 31);
		initializeTasks(jun, 30);
		initializeTasks(jul, 31);
		initializeTasks(aug, 31);
		initializeTasks(sep, 30);
		initializeTasks(oct, 31);
		initializeTasks(nov, 30);
		initializeTasks(dec, 31);
	}
	void initializeTasks(string month[], int days)
	{
		for(int i = 0; i < days; i++)
		{
			month[i] = "";
		}
	}
	
	void addTask(string month[], int day)
	{
		cin.ignore();
		cout << "Enter the task to add: ";
		getline(cin, month[day - 1]);
		cout << "Task added successfully" << endl;
	}
	
	void removeTask(string month[], int day)
	{
		month[day - 1] = "";
		cout << "Task removed successfully" << endl;
	}
	
	void displayTasks(string month[], int days)
	{
		bool noTasks = true;
		for(int i = 0; i < days; i++)
		{
			if(month[i] != "")
			{
				cout << "Day " << i + 1 << ": " << month[i] << endl;
				noTasks = false;
			}
		}
		if(noTasks == true)
		{
			cout << "No tasks scheduled for this month" << endl;
		}
	}
	
	string *getMonthArr(int month, int &days)
	{
		switch(month)
		{
			case 1:
				days = 31;
				return jan;
			
			case 2:
				days = 28;
				return feb;
			
			case 3:
				days = 31;
				return mar;
			
			case 4:
				days = 30;
				return apr;
			
			case 5:
				days = 31;
				return may;
			
			case 6:
				days = 30;
				return jun;
			
			case 7:
				days = 31;
				return jul;
			
			case 8:
				days = 31;
				return aug;
			
			case 9:
				days = 30;
				return sep;
			
			case 10:
				days = 31;
				return oct;
			
			case 11:
				days = 30;
				return nov;
			
			case 12:
				days = 31;
				return dec;
		}
	}
};


void displayMenu()
{
	cout << " 1: January(31 days)" << endl;
	cout << " 2: February(28 days)" << endl;
	cout << " 3: March(31 days)" << endl;
	cout << " 4: April(30 days)" << endl;	
	cout << " 5: May(31 days)" << endl;	
	cout << " 6: June(30 days)" << endl;
	cout << " 7: July(31 days)" << endl;
	cout << " 8: August(31 days)" << endl;
	cout << " 9: September(30 days)" << endl;
	cout << "10: October(31 days)" << endl;
	cout << "11: November(30 days)" << endl;
	cout << "12: December(31 days)" << endl;
	cout << endl;
}

int optionMonth()
{
	int month;
	cout << "Enter the month: ";
	cin >> month;
	return month;
}

int optionDay()
{
	int day;
	cout << "Enter the day: ";
	cin >> day;
	cout << endl;
	return day;
}

int main()
{
	Planner hassanPlanner;
	
	cout << "\tHassan's Planner" << endl;
	cout << endl;
	
	bool flag = false;
	int option, month, day, days;
	string *monthsArr;	
	
	while(flag == false)
	{
		cout << "Menu" << endl;
		cout << "1: Add Task" << endl;
		cout << "2: Remove Task" << endl;
		cout << "3: Display Tasks" << endl;
		cout << "4: Exit" << endl;
		cout << "Enter the option: ";
		cin >> option;
		cout << endl;
		
		switch(option)
		{
			case 1:
				displayMenu();
				month = optionMonth();
				day = optionDay();
				
				monthsArr = hassanPlanner.getMonthArr(month, days);

				if(day < 1 || day > days)
				{
					cout << "Invalid day" << endl;
				}
				else if(monthsArr[day - 1] != "")
				{
					cout << "A task is already stored on this day" << endl;
				}
				else
				{
					hassanPlanner.addTask(monthsArr, day);
				}
				cout << endl;
				break;
			
			case 2:
				displayMenu();
				month = optionMonth();
				day = optionDay();
				monthsArr = hassanPlanner.getMonthArr(month, days);
				if(day < 1 || day > days)
				{
				}
				else if(monthsArr[day - 1] == "")
				{
					cout << "No task stored on this day" << endl;
				}
				else
				{
					hassanPlanner.removeTask(monthsArr, day);
				}				
				cout << endl;
				break;
				
			case 3:
				displayMenu();
				month = optionMonth();
				monthsArr = hassanPlanner.getMonthArr(month, days);
				hassanPlanner.displayTasks(monthsArr, days);
				cout << endl;
				break;
			
			case 4:
				cout << "Exiting..." << endl;
				flag = true;
				break;	
			
			default:
				cout << "Invalid option" << endl;
		}
			
	}
	return 0;
}
