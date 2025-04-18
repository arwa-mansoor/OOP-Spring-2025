#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(string title, string author, string ISBN) : title(title), author(author), ISBN(ISBN) {}

string Book::getTitle() 
{
    return title;
}

string Book::getAuthor() 
{
    return author;
}

string Book::getISBN() 
{
    return ISBN;
}

int Library::bookCount = 0;

void Library::addBook(Book& book) 
{
    if (bookCount >= 100) 
    {
        cout << "Library is full\n";
        return;
    }
    booksArr[bookCount++] = book;
    cout << "Book Added!\n";
}

void Library::removeBook(string isbn) 
{
    for (int i = 0; i < bookCount; i++) 
    {
        if (booksArr[i].getISBN() == isbn) 
        {
            for (int j = i; j < bookCount - 1; j++) 
            {
                booksArr[j] = booksArr[j + 1];
            }
            bookCount--;
            cout << "Book Removed\n";
            return;
        }
    }
    cout << "Book with ISBN: " << isbn << " not found\n";
}

void Library::searchBook(string isbn) 
{
    for (int i = 0; i < bookCount; i++) 
    {
        if (booksArr[i].getISBN() == isbn) 
        {
            cout << "Book found!\n";
            return;
        }
    }
    cout << "Book not found\n";
}
