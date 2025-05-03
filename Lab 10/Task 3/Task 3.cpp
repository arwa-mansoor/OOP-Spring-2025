#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class FileHandler
{
    private: 
        ifstream file;
        string fileName;
        string type, ID, name, year, extraData, certification;
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
            
            while(getline(file, line))
            {
                if(line[0] == '#' || line.length() == 0)
                {
                    continue;
                }
                
                istringstream info(line);
                getline(info, type, ',');
                getline(info, ID, ',');
                getline(info, name, ',');
                getline(info, year, ',');
                getline(info, extraData, ',');
                getline(info, certification, ',');
            }
        }
        
        void convertYearToInteger()
        {
            read();
            int result = stoi(year);
            cout << "Year in Integer: " << result << endl;
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
        vehicles.convertYearToInteger();
    }
    else
    {
        cout << "File unable to open\n";
    }
    return 0;
}
