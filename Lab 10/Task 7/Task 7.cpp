#include <iostream>
#include <fstream>
using namespace std;

class FileHandler
{
    private:
        ofstream sensorLog;

    public:
        FileHandler()
        {
            sensorLog.open("sensor_log.txt", ios::out | ios::app);
            if(!sensorLog.is_open())
            {
                cerr << "File creation failed!\n";
                exit(1);
            }
        }
        void write(string data)
        {
            sensorLog << data;
            streampos pos = sensorLog.tellp();
            cout << "Current Postion of the put pointer: " << pos << endl;
        }

        ~FileHandler()
        {
            sensorLog.close();
        }
};

int main()
{
    FileHandler sensor_log;
    sensor_log.write("Sensor 1: 25,5 C\n");
    sensor_log.write("Sensor 2: 98.1 %RH\n");
    return 0;
}
