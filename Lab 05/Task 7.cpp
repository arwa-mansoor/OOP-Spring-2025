#include <iostream>
using namespace std;

class Product{
	public:
		int id;
		string name;
		float price;
	
		Product(int ID, string n, float cost) : id(ID), name(n), price(cost){}
		
		void displayProductDetails()
		{
			cout << "ID: " << id << endl;
			cout << "Name: " << name << endl;
			cout << "Price: " << price << endl;
			cout << endl;	
		}
	
};

class Inventory{
	Product *products[50];
	int productCount = 0;
	
	public:
		
		void addProduct(int id, string name, float price)
		{
			products[productCount++] = new Product(id, name, price);
		}
		
		void sort()
		{
			for(int i = 0; i < productCount - 1; i++)
			{
				for(int j = i + 1; j < productCount; j++)
				{
					if(products[i]->price > products[j]->price)
					{
						Product *temp = products[i];
						products[i] = products[j];
						products[j] = temp;
					}
				}
			}
		}
		
		void search(string name)
		{
			bool found = false;
			for (int i = 0; i < productCount; i++)
			{
				if(products[i]->name == name)
				{
					cout << "Product Found\n";
					products[i]->displayProductDetails();
					found = true;
					return;
				}
			}
			cout << "Product not found\n";
		}
		
		void displayInventory()
		{
			cout << "Inventory Details\n";
			for (int i = 0; i < productCount; i++)
			{
				products[i]->displayProductDetails();
			}
		}		
};

int main()
{
	Inventory store;
	store.addProduct(123, "Mobile Phone", 50000);
	store.addProduct(156, "Pants", 2000);
	store.addProduct(170, "Sugar", 500);
	store.addProduct(124, "Laptop", 70000);
	
	cout << "Before Sorting\n";
	store.displayInventory();
	
	cout << "After Sorting\n";
	store.sort();
	store.displayInventory();
	
	store.search("Sugar");
	
	store.search("Television");
	
	return 0;
}
