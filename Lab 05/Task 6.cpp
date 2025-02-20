#include <iostream>
using namespace std;

class Movie{
	string title;
	string director;
	int duration;
	
	public:
		Movie(string t, string dir, int dur) : title(t), director(dir), duration(dur){}

		void displayMovieDetails()
		{
			cout << "Title: " << title << endl;
			cout << "Director: " << director << endl;
			cout << "Duration: " << duration << " mins\n";
			cout << endl;			
		}
};

class CinemaHall{
	string name;
	string type;
	Movie *movies[10];
	int movieCount;
	
	public:
		CinemaHall(string n, string t) : name(n), type(t), movieCount(0){}
		
		void addMovie(string title, string director, int duration)
		{
			movies[movieCount++] = new Movie(title, director, duration);
		}
		
		void displayCinemaHallDetails()
		{
			cout << "Cinema Name: " << name << endl;
			cout << "Hall Type: " << type << endl;
			cout << endl;
			cout << "Movies Screening\n";
			for(int i = 0; i < movieCount; i++)
			{
				movies[i]->displayMovieDetails();
			}
			
		}			
};

int main()
{
	CinemaHall cinema("Nuplex", "Platinum");
	
	cinema.addMovie("Kung Fu Panda 2", "Leslee Feldman", 92);
	cinema.addMovie("Mufasa", "Barry Jenkins", 120);
	cinema.addMovie("Inception", "Christopher Nolan", 148);
	
	cinema.displayCinemaHallDetails();
	
	return 0;
}
