#include <iostream>
using namespace std;

class Book
{
    private:
        string title;
        float price;

    public:
        Book(string title, float price) : title(title), price(price){}

        friend class Librarian;


        void update(string t, float p)
        {
            title = t;
            price = p;
            cout << "Book Details updated\n";
        }
};

class Librarian
{
    public:
        void displayDetails(const Book& book)
        {
            cout << "Book Details:\n";
            cout << "Title: " << book.title << endl;
            cout << "Original Price: " << book.price << endl;
        }

        float applyDiscount(Book& book, float discount)
        {
            book.price -= discount;
            return book.price;
        }
};

int main()
{
    Book book("Harry Potter", 650.0);
    Librarian librarian;
    librarian.displayDetails(book);
    cout << "Price after Discount: " << librarian.applyDiscount(book, 100) << endl;

    return 0;
}
