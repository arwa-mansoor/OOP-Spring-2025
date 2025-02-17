#include <iostream>
using namespace std;

class Book{
	string title;
	float price;
	int *stock = new int;
	
	public:
	Book()
	{
		title = "Unknown";
		price = 0.0;
		*stock = 30;
	}
	
	Book(string name, float cost, int quantity)
	{
		title = name;
		price = cost;
		*stock = quantity;
	}
	
	~Book()
	{
		delete stock;
	}
	
	void updateBook()
	{
		cout << "Enter the new price of the book: ";
		cin >> price;
		cout << "Book price updated successfully" << endl;
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

	void displayBook()
	{
		cout << "Book Details:" << endl;
		cout << "Title: " << title << endl;
		cout << "Price: " << price << endl;
		cout << "Stock: " << *stock << endl;
	}
	
	void applyDiscount(int purchases)
	{
		if(purchases > 5)
		{
			price *= 0.95;
		}
		else if(purchases > 10)
		{
			price *= 0.9;	
		}
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
	cin.ignore();
	getline(cin, bookTitle);
	cout << "Price: ";
	cin >> bookPrice;
	cout << "Stock: ";
	cin >> bookStock;
	cout << endl;
	
	Book book(bookTitle, bookPrice, bookStock);
	
	bool flag = false;
	int option;
	
	while(flag == false)
	{
		cout << "Menu" << endl;
		cout << "1: Update Book" << endl;
		cout << "2: Remove Stock" << endl;
		cout << "3: Add Stock" << endl;
		cout << "4: Check Stock" << endl;
		cout << "5: Display Book Details" << endl;
		cout << "6: Exit" << endl;
		cout << "Enter the option: ";
		cin >> option;
		cout << endl;
		
		switch(option)
		{
			case 1:
				book.updateBook();
				cout << endl;
				break;
				
			case 2:
				book.removeStock();
				cout << endl;
				break;
			
			case 3:
				book.addStock();
				cout << endl;
				break;
			
			case 4:
				book.checkStock();
				cout << endl;
				break;
			
			case 5:
				book.displayBook();
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
