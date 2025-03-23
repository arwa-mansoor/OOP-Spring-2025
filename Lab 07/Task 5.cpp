#include <iostream>
using namespace std;

class Media
{
    protected:
        string title;
        string publicationDate;
        int uniqueID;
        string publisher;

    public:
        Media(string title, string publicationDate, int uniqueID, string publisher) : 
        title(title), publicationDate(publicationDate), uniqueID(uniqueID), publisher(publisher) {}

        void displayInfo()
        {
            cout << "Details:\n";
            cout << "Title: " << title << endl;
            cout << "Publication Date: " << publicationDate << endl;
            cout << "Unique ID: " << uniqueID << endl;
            cout << "Publisher: " << publisher << endl;
        }

        void checkOut()
        {
            cout << title << " checked out\n"; 
        }

        void returnItem()
        {   
            cout << title << " returned\n";
        }
};

class Book : public Media
{
    protected:
        string author;
        string ISBN;
        int numberOfPages;

    public:
        Book(string title, string publicationDate, int uniqueID, string publisher, string author, string ISBN, int numberOfPages) : 
        Media(title, publicationDate, uniqueID, publisher),
        author(author), ISBN(ISBN), numberOfPages(numberOfPages){}

        void displayInfo()
        {
            Media::displayInfo();
            cout << "Author: " << author << endl;
            cout << "ISBN: " << ISBN << endl;
            cout << "Number of Pages: " << numberOfPages << endl;
        }

};

class DVD : public Media
{
    protected:
        string director;
        int duration;
        float rating;

    public:
        DVD(string title, string publicationDate, int uniqueID, string publisher, string director, int duration, float rating) :
        Media(title, publicationDate, uniqueID, publisher),
        director(director), duration(duration), rating(rating){}

        void displayInfo()
        {
            Media::displayInfo();
            cout << "Director: " << director << endl;
            cout << "Duration: " << duration << "mins\n";
            cout << "Rating: " << rating << endl;
        }    

};

class CD : public Media
{
    protected:
        string artist;
        int numberOfTracks;
        string genre;

    public:
        CD(string title, string publicationDate, int uniqueID, string publisher, string artist, int numberOfTracks, string genre):
        Media(title, publicationDate, uniqueID, publisher),
        artist(artist), numberOfTracks(numberOfTracks), genre(genre){}

        void displayInfo()
        {
            Media::displayInfo();
            cout << "Artist: " << artist << endl;
            cout << "Number Of Tracks: " << numberOfTracks << endl;
            cout << "Genre: " << genre << endl;
        }
};

class Magazine : public Media
{
    protected:
        string genre;
        string editor;
        int numberOfPages;


    public:
        Magazine(string title, string publicationDate, int uniqueID, string publisher, string genre, string editor, int numberOfPages):
        Media(title, publicationDate, uniqueID, publisher),
        genre(genre), editor(editor), numberOfPages(numberOfPages) {}

        void displayInfo()
        {
            Media::displayInfo();
            cout << "Genre: " << genre << endl;
            cout << "Editor: " << editor << endl;
            cout << "Number Of Pages: " << numberOfPages << endl;
        }
};

int main()
{
    Book book("Harry Potter", "3/20/1997", 123, "DEF", "HIJ", "BA145", 340);
    book.displayInfo();
    book.checkOut();
    book.returnItem();
    cout << endl;

    DVD dvd("Inception", "7/16/2010", 456, "KLM", "NOP", 150, 8.9);
    dvd.displayInfo();
    dvd.checkOut();
    dvd.returnItem();
    cout << endl;

    CD cd("Cabin Fever", "4/27/2000", 789, "QRS", "TUV", 5, "thriller");
    cd.displayInfo();
    cd.checkOut();
    cd.returnItem();
    cout << endl;

    Magazine magazine("Times", "5/14/2004", 021, "WXY", "news", "ARW", 25);
    magazine.displayInfo();
    magazine.checkOut();
    magazine.returnItem();
    cout << endl;

    return 0;
}
