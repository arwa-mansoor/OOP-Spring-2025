#include <iostream>
using namespace std;

class Book{
	string *title;
	float *price;
	int *stock = new int;
	
	public:

	Book(string name, float cost, int quantity)
	{
		title = new string(name);
		price = new float (cost);
		stock = new int (quantity);
	}
	Book(Book &obj)
	{
		title = new string(*obj.title);
		price = new float(*obj.price);
		stock = new int(*obj.stock);
	}
	~Book()
	{
		delete title;
		delete price;
		delete stock;
		cout << endl;
		cout << "Object destroyed" << endl;
		
	}
	
	void updateBook()
	{
		
		cout << "Enter the book details to update:" << endl;
		cin.ignore();
		cout << "Enter the name of the book: ";
		getline(cin, *title);
		cout << "Enter the price of the book: ";
		cin >> *price;
		cout << "Enter the stock: ";
		cin >> *stock;
		cout << "Book updated successfully" << endl;
		cout << endl;
	}
	
	void removeStock()
	{
		int count;
		cout << "Enter the number of books bought: ";
		cin >> count;
		
		if (*stock < count)
		{
			cout << "Not enough books in the stock" << endl;
			cout << "The maximum books available is " << *stock << endl;
		}
		else
		{
			*stock -= count;
			cout << count << " books removed from the stock" << endl;	
			if (*stock == 0)
			{
				cout << "The book stock is 0" << endl;
			}		
		}
	}
	void addStock()
	{
		int count;
		cout << "Enter the number of books to add to stock: ";
		cin >> count;
		*stock += count;
		cout << count << " books added successfully to the stock" << endl;
	}
	
	void checkStock()
	{	
		cout << "The current stock is " << *stock << endl;
		
	}
	
	void applyDiscount(int purchases)
	{
		if(purchases > 5)
		{
			*price *= 0.95;
		}
		else if(purchases > 10)
		{
			*price *= 0.9;	
		}
	}
	
	void displayBook()
	{
		cout << "Book Details:" << endl;
		cout << "Title: " << *title << endl;
		cout << "Price: " << *price << endl;
		cout << "Stock: " << *stock << endl;
	}	
};

int main()
{	
	string bookTitle;
	float bookPrice;
	int bookStock;
	
	cout << "\t Bookstore Management System" << endl;
	cout << endl;
	
	cout << "Enter the book details:" << endl;
	cout << "Title: ";
	getline(cin, bookTitle);
	cout << "Price: ";
	cin >> bookPrice;
	cout << "Stock: ";
	cin >> bookStock;
	cout << endl;
	
	Book book1(bookTitle, bookPrice, bookStock);
	Book book2(book1);
	book1.updateBook();
	cout << "Book 1:" << endl;
	book1.displayBook();
	cout << endl;
	cout << "Book 2:" << endl;
	book2.displayBook();
		
	return 0;
}
