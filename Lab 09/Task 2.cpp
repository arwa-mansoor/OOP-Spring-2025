#include <iostream>
using namespace std;

class SmartDevice
{
    public:
        virtual void turnOn() = 0;
        virtual void turnOff() = 0;
        virtual bool getStatus() = 0;
};

class LightBulb : public SmartDevice
{
    protected:
        bool isOn;
        int brightness;

    public:
        LightBulb(bool isOn, int brightness) : isOn(isOn), brightness(brightness){}
        void turnOn()
        {
        	if(isOn)
        	{
        		cout << "The Light Bulb is already ON\n";
        		return;
			}
            isOn = true;
            cout << "The Light Bulb is turned ON\n";        	
        }

        void turnOff()
        {
        	if(isOn)
        	{
        		isOn = false;
        		cout << "The Light Bulb is turned OFF\n";
        		return;
			}
            cout << "The Light Bulb is already OFF\n";			
        }

        bool getStatus()
        {
            return isOn;
        }
};

class Thermostat : public SmartDevice
{
    protected:
        bool isOn;
        double temperature;

    public:
        Thermostat(bool isOn, double temperature) : isOn(isOn), temperature(temperature){}
        void turnOn()
        {
        	if(isOn)
        	{
        		cout << "The Thermostat is already ON\n";
        		return;
			}
            isOn = true;
            cout << "The Thermostat is turned ON\n";
        }

        void turnOff()
        {
        	if(isOn)
        	{
        		isOn = false;
        		cout << "The Thermostat is turned OFF\n";
        		return;
			}
            cout << "The Thermostat is already OFF\n";
        }

        bool getStatus()
        {
            return isOn;
        }
};


int main()
{
    LightBulb lightbulb(false, 0);
    Thermostat thermostat(false, 25.6);

    cout << "Turning ON Light bulb\n";
    lightbulb.turnOn();
    cout << "Light Bulb Current Status: " << lightbulb.getStatus() << endl;
    cout << "Turning OFF Light bulb\n";
    lightbulb.turnOff();
    cout << "Light Bulb Current Status: " << lightbulb.getStatus() << endl;
    cout << endl;

    cout << "Turning ON Thermostat\n";
    thermostat.turnOn();
    cout << "Thermostat Current Status: " << thermostat.getStatus() << endl;
    cout << "Turning OFF Thermostat\n";
    thermostat.turnOff();
    cout << "Thermostat Current Status: " << thermostat.getStatus() << endl;

    return 0;
}
