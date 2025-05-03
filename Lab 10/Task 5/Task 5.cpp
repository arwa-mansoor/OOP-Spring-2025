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
                convertExtraDataToInteger();
            }
        }

        void convertExtraDataToInteger()
        {
            size_t startPos;
            string num;
            if(type == "AutonomousCar")
            {
                
                startPos = extraData.find(':');
                if(startPos == string::npos)
                {
                    cerr << "Colon not found!\n";
                    exit(1);
                }
                num = extraData.substr(startPos + 1, extraData.length() - 1);
                float softwareVersion = stof(num);
                cout << "Vehicle ID: " << ID << " | Softaware Version in float: " << softwareVersion << endl;
            }
            else if(type == "ElectricVehicle")
            {
                
                startPos = extraData.find(':');
                if(startPos == string::npos)
                {
                    cerr << "Colon not found!\n";
                    exit(1);
                }
                num = extraData.substr(startPos + 1, extraData.length());
                int batterCapacity = stoi(num);
                cout << "Vehicle ID: " << ID << " | Battery Capacity in Integer: " << batterCapacity << endl;
            }

            else if(type == "HybridTruck")
            {
                size_t colon = extraData.find(':');
                if(colon == string::npos)
                {
                    cerr << "Colon not found!\n";
                    exit(1);
                }
                size_t pipe = extraData.find('|');
                if(pipe == string::npos)
                {
                    cerr << "Pipe not found!\n";
                    exit(1);
                }
                string num1 = extraData.substr(colon + 1, pipe - 1);
                int cargo = stoi(num1);
                string num2 = extraData.substr(pipe + 1, extraData.length());
                int battery = stoi(num2);
                cout << "Vehicle ID: " << ID << " | Battery Capacity in Integer: " << battery << " | Cargo in Integer: " << cargo << endl;
            }

            else
            {
                cout << "Unknown Vehicle Type!\n";
            }


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
        vehicles.read();
    }
    else
    {
        cout << "File unable to open\n";
    }
    return 0;
}
