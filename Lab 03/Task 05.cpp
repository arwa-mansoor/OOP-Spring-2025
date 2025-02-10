//24K-0930
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int maxItems = 100;

struct GroceryItem{
	string item;
	float price;
};

struct PurchasedItem{
	string item;
	float price;
	int quantity;
};

class GroceryStore{
	
	GroceryItem inventory[maxItems];
	int count;
	
	public:
	GroceryStore()
	{
		for(int i = 0; i < maxItems; i++)
		{
			inventory[i].item = "";
			inventory[i].price = 0.0;
		}
		count = 0;
	}
	
		void addItem(string name, float cost)
		{
			if(count < maxItems)
			{
				inventory[count].item = name;
				inventory[count].price = cost;
				count++;
				cout << "Item added successfully" << endl;
			}
			else
			{
				cout << "Item cannot be added because inventory is full" << endl;
			}
			
		}
		
		void updatePrice(string name, float cost)
		{
			for(int i = 0; i < count; i++)
			{
				if(inventory[i].item == name)
				{
					inventory[i].price = cost;
					cout << "Price of " << name << " updated successfully" << endl;
					return;
				}
			}
			cout << name << " not found in the inventory" << endl;
		}
		
		void viewInventory()
		{
			if (count == 0)
			{
				cout << "Inventory is empty" << endl;
			}
			else
			{
				cout << left << setw(25) << "Item Name" << right << setw(10) << "Price (Rs)" << endl;
				for(int i = 0; i < count; i++)
				{
					cout << left << setw(25) << inventory[i].item << right << setw(10) << fixed << setprecision(2) << inventory[i].price << endl;
				}
			}
		}
		
		void generateReceipt(PurchasedItem purchases[], int totalItems)
		{
			for(int i = 0; i < totalItems; i++)
			{
				for(int j = 0; j < count; j++)
				{
					if(purchases[i].item == inventory[j].item)
					{
						purchases[i].price = inventory[j].price;
						break;
					}
				}
			}
			
			cout << "\t\t\tReceipt" << endl;
			cout << endl;
			cout << left << setw(25) << "Item Name" << right << setw(10) << "Quantity" << right << setw(15) << "Price(Rs)" << right<< setw(15) << "Total(Rs)" << endl;
			float total = 0.0;
			for(int i = 0; i < totalItems; i++)
			{
				total += (purchases[i].price * purchases[i].quantity);
				cout << left << setw(25) << purchases[i].item << right << setw(10) << purchases[i].quantity << right << setw(15) << fixed << setprecision(2) << purchases[i].price << right<< setw(15) << fixed << setprecision(2) << purchases[i].price * purchases[i].quantity << endl;
			}
			cout << endl;
			cout << "Grand Total(Rs): " << fixed << setprecision(2) << total << endl;
		}	
};

int main()
{
	GroceryStore zainabInventory;
	cout << "\tZainab's Grocery Store" << endl;
	cout << endl;
	
	bool flag = false;
	int option;
	while (flag == false)
	{
		cout << "Menu" << endl;
		cout << "1: Add items" << endl;
		cout << "2: Update price" << endl;
		cout << "3: View Inventory" << endl;
		cout << "4: Generate Receipt" << endl;
		cout << "5: Exit" << endl;
		cout << "Enter the option: ";
		cin >> option;
		cout << endl;
		
		int itemCount;
		string itemName;
		float itemPrice;
		
		switch (option)
		{
			case 1:
				cout << "Enter the count of items: ";
				cin >> itemCount;
				cin.ignore();
				cout << endl;
				
				for(int i = 0; i < itemCount; i++)
				{
					cout << "Enter the item name: ";
					getline(cin, itemName);
					cout << "Enter the price: ";
					cin >> itemPrice;
					cin.ignore();
					zainabInventory.addItem(itemName, itemPrice);
					cout << endl;
				}
				break;
				
			case 2:
				
				cin.ignore();
				cout << "Enter the name of the item to update price: ";
				getline(cin, itemName);
				cout << "Enter the new price for this item: ";
				cin >> itemPrice;
				zainabInventory.updatePrice(itemName, itemPrice);
				cout << endl;
				break;
			
			case 3:
				zainabInventory.viewInventory();
				cout << endl; 
				break;
			
			case 4:
			{
				cout << "The list of available items and their prices" << endl;
				cout << endl;
				zainabInventory.viewInventory();
				cout << endl;
				cout << "Enter the number of items to purchase: ";
				cin >> itemCount;
				cin.ignore();
				cout << endl;
				PurchasedItem purchaseArr[itemCount];
				for(int i = 0; i < itemCount; i++)
				{

					cout << "Enter the name of the item: ";
					getline(cin, purchaseArr[i].item);
					cout << "Enter the quantity of this item: ";
					cin >> purchaseArr[i].quantity;
					cin.ignore();
					cout << endl;
				}
				cout << endl;
				zainabInventory.generateReceipt(purchaseArr, itemCount);
				cout << endl;
				break;
				}
			
			case 5:
				flag = true;
				cout << "Exiting..." << endl;
				break;
				
			default:
				cout << "Invalid option" << endl;		
		}
		
	}
	return 0;
}
