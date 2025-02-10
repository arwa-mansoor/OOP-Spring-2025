//24K-0930
#include <iostream>
#include <string>
using namespace std;

class Laptop{

	string brand;
	string model;
	string processor;
	int RAM;
	int storage;
	bool turnOn;
	
	public:
		Laptop()
		{
			brand = "";
			model = "";
			processor = "";
			RAM = 0;
			storage = 0;
						
		}
		Laptop(string b, string m, string p, int ram, int s)
		{			
			brand = b;
			model = m;
			processor = p;
			RAM = ram;
			storage = s;
			turnOn = false;		
		}
		
		string getBrand()
		{
			return brand;
		}
		
		string getModel()
		{
			return model;
		}
		
		string getProcessor()
		{
			return processor;
		}
		
		int getRAM()
		{
			return RAM;
		}
		
		int getStorage()
		{
			return storage;
		}
		
		void turnOnLaptop()
		{
			if (turnOn == false)
			{
				cout << brand << " " << model << " is turned on" << endl;
				turnOn = true;
			}
			else
			{
				cout << brand << " " << model << " is already on" << endl;
			}
		}
		
		void turnOffLaptop()
		{
			if (turnOn == true)
			{
				cout << brand << " " << model << " is turned off" << endl;
				turnOn = false;
			}
			else
			{
				cout << brand << " " << model << " is already off" << endl;
			}
		}
		
		void runProgram(string program)
		{
			if(turnOn == true)
			{
				cout << program << " is running on " << brand << " " << model << endl;
			}
			else			
			{
				cout << "Turn on the " << brand << " " << model << " first" << endl;
			}
		}
		
		void checkSpecifications()
		{
			cout << "Brand: " << brand << endl;
			cout << "Model: " << model << endl;
			cout << "Processor: " << processor << endl;
			cout << "RAM: " << RAM << " GB" <<  endl;
			cout << "Storage: " << storage << " GB" << endl;
		}				
};

int main()
{
	cout << "\t Laptop Comparisons" << endl;
	cout << endl;
	
	Laptop ayeshaLaptop, bilalLaptop;
	
	string laptopBrand, laptopModel, laptopProcessor;
	int  laptopRam, laptopStorage;
	
	for(int i = 0; i < 2; i++)
	{
		if(i == 0) 
		{
			cout << "Enter Ayesha's Laptop details:" << endl;
		}
		else
		{
			cout << "Enter Bilal's Laptop details:" << endl;
		}
				
		cout << "Enter the brand: ";
		getline(cin, laptopBrand);
		cout << "Enter the model: ";
		getline(cin, laptopModel);
		cout << "Enter the processor: ";
		getline(cin, laptopProcessor);
		cout << "Enter the RAM (in GB): ";
		cin >> laptopRam;
		cout << "Enter the storage (in GB): ";
		cin >> laptopStorage;
		cin.ignore();
		
		if(i == 0)
		{
			ayeshaLaptop = Laptop(laptopBrand, laptopModel, laptopProcessor, laptopRam, laptopStorage);
		}
		else
		{
			bilalLaptop = Laptop(laptopBrand, laptopModel, laptopProcessor, laptopRam, laptopStorage);
		}
		cout << endl;
	}	
	
	int option, aORb;
	bool flag = false;
	string programName;
	while(flag == false)
	{
		cout << "Menu" << endl;
		cout << "1: Turn on laptop" << endl;
		cout << "2: Turn off laptop" << endl;
		cout << "3: Run a program" << endl;
		cout << "4: Check Specifications" << endl;
		cout << "5: Compare Laptops" << endl;
		cout << "6: Exit" << endl;
		cout << "Enter the option: ";
		cin >> option;
		cout << endl;
		
		switch (option)
		{
			case 1:
				cout << "Enter 1 for Bilal's laptop or 2 for Ayesha's laptop: ";
				cin >> aORb;
				cout << endl;
				if(aORb == 1)
				{
					bilalLaptop.turnOnLaptop();
				}
				else
				{
					ayeshaLaptop.turnOnLaptop();
				}
				cout << endl;
				break;
			case 2:
				cout << "Enter 1 for Bilal's laptop or 2 for Ayesha's laptop: ";
				cin >> aORb;
				cout << endl;
				if(aORb == 1)
				{
					bilalLaptop.turnOffLaptop();
				}
				else
				{
					ayeshaLaptop.turnOffLaptop();
				}
				cout << endl;				
				break;
			case 3:
				cout << "Enter 1 for Bilal's laptop or 2 for Ayesha's laptop: ";
				cin >> aORb;
				cout << endl;
				cin.ignore();
				cout << "Enter the program name to run: ";
				getline(cin, programName);
				if(aORb == 1)
				{
					bilalLaptop.runProgram(programName);
				}
				else
				{
					ayeshaLaptop.runProgram(programName);
				}
				cout << endl;				
				break;
			case 4:
				cout << "Enter 1 for Bilal's laptop or 2 for Ayesha's laptop: ";
				cin >> aORb;
				cout << endl;
				if(aORb == 1)
				{
					bilalLaptop.checkSpecifications();
				}
				else
				{
					ayeshaLaptop.checkSpecifications();
				}
				cout << endl;				
				break;
				
			case 5:

				if(ayeshaLaptop.getRAM() == bilalLaptop.getRAM())
				{
					cout << "Both " << ayeshaLaptop.getBrand() << " " << ayeshaLaptop.getModel() << " and " << bilalLaptop.getBrand() << " " << bilalLaptop.getProcessor() << " have same RAM" << endl;
				}
				else if(ayeshaLaptop.getRAM() > bilalLaptop.getRAM())
				{
					cout << ayeshaLaptop.getBrand() << " " << ayeshaLaptop.getModel() << " has better RAM than " << bilalLaptop.getBrand() << " " << bilalLaptop.getProcessor() << endl;
				}
				else
				{
					cout << bilalLaptop.getBrand() << " " << bilalLaptop.getProcessor() << " has better RAM than " << ayeshaLaptop.getBrand() << " " << ayeshaLaptop.getModel() << endl;
				}

				if(ayeshaLaptop.getStorage() == bilalLaptop.getStorage())
				{
					cout << "Both " << ayeshaLaptop.getBrand() << " " << ayeshaLaptop.getModel() << " and " << bilalLaptop.getBrand() << " " << bilalLaptop.getProcessor() << " have same storage" << endl;
				}
				else if (ayeshaLaptop.getStorage() > bilalLaptop.getStorage())
				{
					cout << ayeshaLaptop.getBrand() << " " << ayeshaLaptop.getModel() << " has better storage than " << bilalLaptop.getBrand() << " " << bilalLaptop.getProcessor() << endl;
				}
				else
				{
					cout << bilalLaptop.getBrand() << " " << bilalLaptop.getProcessor() << " has better storage than " << ayeshaLaptop.getBrand() << " " << ayeshaLaptop.getModel() << endl;
				}
				cout << endl;
				break;
				
			case 6:
				cout << "Exiting..." << endl;
				flag = true;
				break;
				
			default:
				cout << "Invalid option" << endl;
				
		}
	}
	return 0;
}
