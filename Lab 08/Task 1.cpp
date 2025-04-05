#include <iostream>
using namespace std;

class Humidity;

class Temperature
{
    private:
        float temperature;

    public:
        Temperature(float temperature) : temperature(temperature){}

        float getTemperture()
        {
            return temperature;
        }

        friend float calculculateHeatIndex(Temperature t, Humidity h);
};

class Humidity
{
    private:
        float humidity;
    
    public:
        Humidity(float humidity) : humidity(humidity){}

        float getHumidity()
        {
            return humidity;
        }

        friend float calculculateHeatIndex(Temperature t, Humidity h);

};

float calculculateHeatIndex(Temperature t, Humidity h)
{
    return (-42.379 + 2.04901523 * t.temperature + 10.14333127 * h.humidity - 0.22475541 * t.temperature * h.humidity);
}

int main()
{
    Temperature temperature(25);
    Humidity humidity(55);
    cout << "Temperature: " << temperature.getTemperture() << "°C\n";
    cout << "Humidity: " << humidity.getHumidity() << "%\n";
    cout << "Heat Index: " << calculculateHeatIndex(temperature, humidity) << "°C\n";
    return 0;
}
