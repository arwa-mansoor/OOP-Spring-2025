#include <iostream>
using namespace std;

class TourGuide
{
	string name;
	int yearsOfExperience;
	string specialization;
	
	public:
		TourGuide(string n, int years, string speci) : name(n), yearsOfExperience(years), specialization(speci){}

		void display()
		{
			cout << "Name: " << name << endl;
			cout << "Years of Experience: " << yearsOfExperience << endl;
			cout << "Specialization: " << specialization << endl;
			cout << endl;
		}
};

class TravelAgency
{
	string agencyName;
	TourGuide *tourGuide[25];
	int tourGuideCount = 0;
	
	public:
		TravelAgency(string name) : agencyName(name){}
		
		void addTourGuide(string name, int yearsOfExperience, string specialization)
		{
			tourGuide[tourGuideCount++] = new TourGuide(name, yearsOfExperience, specialization);	
		}
		
		void displayAgencyDetails()
		{
			cout << "Travel Agency Details:\n";
			cout << "Travel Agency Name: " << agencyName << endl;
			cout << endl;
			cout << "Tour Guides Details:\n";
			for(int i = 0; i < tourGuideCount; i++)
			{
				tourGuide[i]->display();
			}
		}	
};

int main()
{
	TravelAgency agency("Paragon");
	
	agency.addTourGuide("John", 5, "Adventure");
	agency.addTourGuide("Michael", 7, "Historical");
	agency.addTourGuide("William", 8, "Cultural");
	
	agency.displayAgencyDetails();
	return 0;
}
