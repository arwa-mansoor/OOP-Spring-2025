#include <iostream>
#include <fstream>
using namespace std;

class FileHandler
{
    public:
        void write()
        {
            ofstream largeLog("large_log.txt", ios::out);
            if(!largeLog)
            {
                cerr << "File creation failed!\n";
                exit(1);
            }
            largeLog << "This is the first part.\nThis is the second part of the log.\nAnd the third part\n";
            largeLog.close();
        }

        void read()
        {
            ifstream largeLog("large_log.txt", ios::in);
            if(!largeLog)
            {
                cerr << "File failed to open!\n";
                exit(1);
            }
            char buffer[11] = {0};
            
            streampos pos;
            largeLog.read(buffer, 10);
            pos = largeLog.tellg();
            cout << "Get pointer position after 10 characters: " << pos << endl;
            
            largeLog.read(buffer, 10);
            pos = largeLog.tellg();
            cout << "Get pointer position after 10 characters: " << pos << endl;
                
            largeLog.close();
        }
};

int main()
{
    FileHandler large_log;
    large_log.write();
    large_log.read();
    return 0;
}
