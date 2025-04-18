#include <iostream>
using namespace std;

class Activity
{
    public:
        virtual void calculateCaloriesBurned(double weight) = 0;
};

class Running : public Activity
{
    private:
        double distance;
        double time;

    public:
        Running(double distance, double time) : distance(distance), time(time){}

        void calculateCaloriesBurned(double weight)
        {
            cout << 0.9 * weight * distance << " calories burned during running\n";
        }
};

class Cycling : public Activity
{
    private:
        double speed;
        double time;

    public:
        Cycling(double speed, double time) : speed(speed), time(time){}
        
        void calculateCaloriesBurned(double weight)
        {
            cout << 0.28 * weight * speed * time << " calories burned during cycling\n";
        }
};

int main()
{
    Running running(5, 30);
    running.calculateCaloriesBurned(70);

    Cycling cycling(20, 0.2);
    cycling.calculateCaloriesBurned(55);
    return 0;
}
