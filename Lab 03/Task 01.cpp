//24K-0930
#include <iostream>
#include <string>
using namespace std;

class MarkerPen{
	
	public:
	string brand;
	string color;
	int inkLevel;
	bool refillability;
	
	MarkerPen()
	{
		brand = "";
		color = "";
		inkLevel = 0;
		refillability = false;
	}
    MarkerPen(string b, string col, int ink, bool refillable) 
	{
        brand = b;
        color = col;
        inkLevel = ink;
        refillability = refillable;
    }
	
	void write(int ink)
	{
		if (ink >= inkLevel)
		{
			cout << "You cannot write due to insufficient amount of ink in the marker pen" << endl;
		}
		else
		{
			inkLevel -= ink;
			cout << "Ink Level: " << inkLevel << endl;
			cout << "You can write" << endl;
		}
	}
	
	void refill()
	{
		if(refillability == true)
		{
			inkLevel = 10;
			cout << "Marker pen is refilled" << endl;
		}
		else
		{
			cout << "Marker pen is not refillable" << endl;
		}
	}
	
	void status()
	{
		cout << "Brand: " << brand << endl;
		cout << "Color: " << color << endl;
		cout << "Ink Level: " << inkLevel << endl;
		cout << "Refillability: ";
		if(refillability == true)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}	
};

int main()
{
	cout << "\tMarker Pens" << endl;
	cout << endl;
	
	int count;
	cout << "Enter the total number of marker pens: ";
	cin >> count;
	cout << endl;
	
	MarkerPen markerPenArr[count];
	string br, col;
	int inkL;
	char refillable;
	
	for (int i = 0; i < count; i++)
	{
		cout << "Marker Pen " << i + 1 << endl;		
		cout << "Enter the brand: ";
		cin.ignore();
		getline(cin, br);
		cout << "Enter the color: ";
		getline(cin, col);
		cout << "Enter the ink level(1-10): ";
		cin >> inkL;
		cout << "Is it refillable?(Y/N): ";
		cin >> refillable;
		if(refillable == 'Y' || refillable == 'y')
		{
			markerPenArr[i] = MarkerPen(br, col, inkL, true);	
		}
		else
		{
			markerPenArr[i] = MarkerPen(br, col, inkL, false);
		}
		cout << endl;
		
	}	
	int option;
	bool flag = false;	
	while (flag == false)
	{	
		cout << "Menu" << endl;
		cout << "1: Write" << endl;
		cout << "2: Refill" << endl;
		cout << "3: Status" << endl;
		cout << "4: Exit" << endl;
		cout << "Enter the option: ";
		cin >> option;
		cout << endl;
		
		int index;
		switch(option)
		{
			case 1: 
				cout << "Enter the marker pen index(1 to " << count << "): ";
				cin >> index;
				int usedInk;
				cout << "Enter the ink amount to use(1-10): ";
				cin >> usedInk;
				cout << endl;
				markerPenArr[index - 1].write(usedInk);
				cout << endl;
				break;

			case 2: 
				cout << "Enter the marker pen index(1 to " << count << "): ";
				cin >> index;
				markerPenArr[index - 1].refill();
				cout << endl;			
				break;

			case 3: 
				cout << "Enter the marker pen index(1 to " << count << "): ";
				cin >> index;
				markerPenArr[index - 1].status();
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
}
