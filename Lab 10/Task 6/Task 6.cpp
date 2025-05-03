#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

class InventoryItem
{
    private:
        int itemID;
        char itemName[20];

    public:
        void inputItem(int id, const char* name)
        {
            itemID = id;
            strcpy(itemName, name);
            itemName[sizeof(itemName)] = '\0';

        }
        void write()
        {
            ofstream inventory("inventory.dat", ios::binary);
            if(!inventory.is_open())
            {
                cerr << "File unable to open\n";
                exit(1);
            }
            inventory.write((char*)this, sizeof(*this));
            inventory.close();
        }

        void read()
        {
            ifstream inventory("inventory.dat", ios::binary);
            if(!inventory.is_open())
            {
                cerr << "File unable to open\n";
                exit(1);
            }
            inventory.read((char*)this, sizeof(*this));
            inventory.close(); 
            cout << "Item ID: " << itemID << " | Item Name: " << itemName << endl;           
        }

};

int main()
{    
    InventoryItem item;  
    item.inputItem(789, "sugar");
    item.write();
    item.read();
    return 0;
}
