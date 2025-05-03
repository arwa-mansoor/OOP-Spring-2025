#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class FileHandler
{
    private: 
        ifstream file;
        string fileName;

    public:
        FileHandler(string fileName) : fileName(fileName)
        {
            file.open(fileName);
        }

        bool isOpen() const
        {
            return file.is_open();
        }

        void read()
        {
            string line;
            while(getline(file, line));
        }

        ~FileHandler()
        {
            if(file.is_open())
            {
                file.close();
            }
        }
};

int main()
{
    FileHandler vehicles("vehicles.txt");
    if(vehicles.isOpen())
    {
        cout << "File opened successfully\n";
        vehicles.read();
    }
    else
    {
        cout << "File unable to open\n";
    }
    return 0;
}
