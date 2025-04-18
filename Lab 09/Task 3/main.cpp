#include "Book.h"
#include <iostream>
using namespace std;


int main()
{
    Book book("Harry Potter", "JK Rowling", "92AD06LP86Q");
    cout << "Book Details:\n";
    cout << "Title: " << book.getTitle() << endl;
    cout << "Author: " << book.getAuthor() << endl;
    cout << "ISBN: " << book.getISBN() << endl;

    return 0;
}
