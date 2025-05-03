#include <iostream>
#include <fstream>
using namespace std;

class FileHandler
{
    public:
        void write()
        {
            ofstream record("data_records.txt", ios::out);
            if(!record)
            {
                cerr << "File creation failed\n";
                exit(1);
            }
            record << "Record 1\n";
            record << "Record 2\n";
            record << "Record 3\n";
            record << "Record 4\n";
            record.close();
        }

        void read()
        {
            ifstream record;
            record.open("data_records.txt", ios::in);
            if(!record.is_open())
            {
                cerr << "File unable to open!\n";
                exit(1);
            }
            
            string line;
            for(int i = 0; i < 2; i++)
            {
                getline(record, line);
            }
            
            streampos pos = record.tellg();
            record.seekg(pos);
            getline(record, line);
            cout << line << endl;

        }
};

int main()
{
    FileHandler record;
    record.write();
    record.read();
    return 0;
}


