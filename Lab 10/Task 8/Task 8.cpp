#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileHandler
{
    public:

        void write(string data)
        {  
            ofstream config("config.txt", ios::out);
            if(!config.is_open())
            {
                cerr << "File creation failed!\n";
                exit(1);
            } 
            config << data;
            config.close();

        }

        void readWrite(string data)
        {
            ofstream config("config.txt", ios::in | ios::out);
            if(!config.is_open())
            {
                cerr << "File creation failed!\n";
                exit(1);
            }
            config.seekp(5);
            config << data;
            config.close();
        }

        void read()
        {
            string line;
            ifstream config("config.txt", ios::in);
            if(!config.is_open())
            {
                cerr << "File creation failed!\n";
                exit(1);
            }
            while(getline(config, line))
            {
                cout << line << endl;
            }
            config.close();
        }

};

int main()
{
    FileHandler config;

    config.write("AAAAABBBBBCCCCC");
    cout << "File content before Updating:\n";
    config.read();
    cout << endl;

    config.readWrite("XXXXX");
    cout << "File content after Updating:\n";
    config.read();

    return 0;
}
