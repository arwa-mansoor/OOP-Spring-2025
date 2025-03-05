#include <iostream>
using namespace std;

class Device
{
    protected:
    int deviceID;
    bool status;

    public:
    Device(int deviceID, bool status) : deviceID(deviceID), status(status){}

    void displayDetails()
    {
        cout << "---------------------\n";
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl; 
    }
};

class SmartPhone : virtual public Device
{
    protected:
    float screenSize;

    public:
    SmartPhone(int deviceID, bool status, float screenSize) : 
    Device(deviceID, status),
    screenSize(screenSize){}

    void displayDetails()
    {
        //Device::displayDetails();
        cout << "Screen Size: " << screenSize << endl;
    }
}; 

class SmartWatch : virtual public Device
{
    protected:
    bool heartRateMonitor;

    public:
    SmartWatch(int deviceID, bool status, bool hearRateMonitor):
    Device(deviceID, status),
    heartRateMonitor(heartRateMonitor){}

    void displayDetails()
    {
        //Device::displayDetails();
        cout << "Heart Rate: " << (heartRateMonitor ? "Healthy" : "Unhealthy") << endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch
{
    protected:
    int stepCounter;

    public:
    SmartWearable(int deviceID, bool status, float screenSize, bool hearRateMonitor, int stepCounter) :
    Device(deviceID, status),
    SmartPhone(deviceID, status, screenSize),
    SmartWatch(deviceID, status, heartRateMonitor),
    stepCounter(stepCounter){}

    void displayDetails()
    {
        Device::displayDetails();
        SmartPhone::displayDetails();
        SmartWatch::displayDetails();
        cout << "Steps Count: " << stepCounter << endl;
    }
};

int main()
{
    SmartWearable w1(123, true, 5.5, true, 298);
    w1.displayDetails();
    return 0;
}

