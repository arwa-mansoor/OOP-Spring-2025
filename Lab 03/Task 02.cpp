//24K-0930
#include <iostream>
#include <string>
using namespace std;

class TeaMug{
	
	public:
		string brand;
		string color;
		int capacity;
		int currentFillLevel;
		
	TeaMug()
	{
		brand = "";
		color = "";
		capacity = 0;
		currentFillLevel = 0;
	}
	
	TeaMug(string b, string col, int cap, int fill)
	{
		brand = b;
		color = col;
		capacity = cap;
		currentFillLevel = fill;		
	}
	
	void sipTea(int current_fill_level)
	{
		if(currentFillLevel == 0)
		{
			cout << "Fill the tea first" << endl;
		}
		else if(currentFillLevel < current_fill_level)
		{
			cout << "The mug does not have enough tea" << endl;
		}
		else
		{
		currentFillLevel -= current_fill_level;
			cout << "The fill level is reduced to " << currentFillLevel << " ml" << endl;			
		}		
	}
	
	void refill()
	{
		if(currentFillLevel >= capacity)
		{
			cout << "The mug already has tea" << endl;
		}
		else
		{	
			currentFillLevel = capacity;
			cout << "The mug is refilled to its full capacity of " << capacity << " ml" << endl;
		}
		
	}
	
	void check()
	{
		if(currentFillLevel == 0)
		{
			cout << "The mug is empty" << endl;
		}
		else
		{
			cout << "The mug's current fill level is " << currentFillLevel << " ml" << endl;
		} 
	}
	
};

int main()
{
	cout << "\tTea Mugs" << endl;
	cout << endl;
	
	int count;
	cout << "Enter the total number of mugs: ";
	cin >> count;
	cout << endl;
	
	
	TeaMug teaMugsArr[count];
	int index;
	
	string br, col;
	int cap;
	
	for(int i = 0; i < count; i++)
	{
		cout << "Tea Mug " << i + 1 <<  endl;
		
		cout << "Enter the brand: ";
		cin.ignore();
		getline(cin, br);
		cout << "Enter the color: ";
		getline(cin, col);
		cout << "Enter the capacity(300-600 ml): ";
		cin >> cap;
		teaMugsArr[i] = TeaMug(br, col, cap, 0);
		cout << endl;	
	}
	
	cout << "Choose the the mug(1 to " << count << ") to drink tea in it: ";
	cin >> index;
	cout << endl;	
		
	int option;
	bool flag = false;
	while(flag == false)
	{
		cout << "Menu" << endl;
		cout << "1: Reduce Fill Level" << endl;
		cout << "2: Refill" << endl;
		cout << "3: Check" << endl;
		cout << "4: Change the mug" << endl;
		cout << "5: Exit the system" << endl; 
		cout << "Enter the option: ";
		cin >> option;
		cout << endl;
		
		switch (option)
		{
			case 1:
				int fill;
				cout << "Enter the fill level to reduce: ";
				cin >> fill;
				teaMugsArr[index - 1].sipTea(fill);
				cout << endl;
				break;
			
			case 2:
				teaMugsArr[index - 1].refill();
				cout << endl;
				break;
				
			case 3:
				teaMugsArr[index - 1].check();
				cout << endl;
				break;
				
			case 4:
				cout << "Enter the index of the mug(1 to " << count << "): ";
				cin >> index;
				cout << endl;
				break;
			
			case 5:
				cout << "Exiting..." << endl;
				flag = true;
				break;
			
			default:
				cout << "Invalid option" << endl;
				cout << endl;		
		}
	}
	return 0;
}
