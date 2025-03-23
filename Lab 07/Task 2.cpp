#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
    protected:
        string position;
        string color;
        float borderThickness;

    public:
        Shape(string position, string color, float borderThickness) : 
        position(position), color(color), borderThickness(borderThickness){}
        virtual void draw()
        {
            cout << "Drawing a shape at " << position << " with color " << color << " and border thickness " << borderThickness << "mm\n";
        }
        virtual void calculateArea() = 0;

        virtual void calculatePerimeter() = 0;
};

class Circle : public Shape
{
    protected:
        float radius;
        string centerPosition;

    public:
        Circle(string position, string color, float borderThickness, float radius, string centerPosition):
        Shape(position, color, borderThickness),
        radius(radius), centerPosition(centerPosition){}

        void draw()
        {
            cout << "Drawing a circle at " << position << " with radius " << radius << endl;
        }

        void calculateArea()
        {
            cout << "Area of Circle: " << M_PI * pow(radius, 2) << endl;
        }

        void calculatePerimeter()
        {
            cout << "Perimeter of Circle: " << 2 * M_PI * radius << endl;
        }  
};

class Rectangle : public Shape
{
    protected:
        float width;
        float height;
        string topLeftCornerPosition;

    public:
        Rectangle(string position, string color, float borderThickness, float width, float height, string topLeftCornerPosition):
        Shape(position, color, borderThickness),
        width(width), height(height), topLeftCornerPosition(topLeftCornerPosition){}

        void draw()
        {
            cout << "Drawing a rectangle at " << position << " with width " << width << " and height " << height << endl;
        }  
        
        void calculateArea()
        {
            cout << "Area of Rectangle: " << width * height << endl;
        }

        void calculatePerimeter()
        {
            cout << "Perimeter of Rectangle: " << 2 * (width + height) << endl;
        }
};

class Triangle : public Shape
{
    protected:
        float height;
        float base;
        float sideA;
        float sideB;
    
    public:
        Triangle(string position, string color, float borderThickness, float height, float base, float sideA, float sideB):
        Shape(position, color, borderThickness),
        height(height), base(base), sideA(sideA), sideB(sideB){}

        void draw()
        {
            cout << "Drawing a triangle at " << position << " with height " << height << " and base " << base << endl;
        }

        void calculateArea()
        {
            cout << "Area of Triangle: " << 0.5 * base * height << endl;
        }

        void calculatePerimeter()
        {
            cout << "Perimeter of Triangle: " << base + sideA + sideB << endl;
        }

};

class Polygon : public Shape
{
    protected:
       int numberOfSides;
       float length; 

    public:
        Polygon(string position, string color, float borderThickness, int numberOfSides, float length):
        Shape(position, color, borderThickness),
        numberOfSides(numberOfSides), length(length){}

        void draw()
        {
            cout << "Drawing a polygon at " << position << " with " << numberOfSides << " sides, each of " << length << endl;
        }

        void calculateArea()
        {
            cout << "Area of polygon: " << (numberOfSides * pow(length,2)) / (4 * tan(M_PI / numberOfSides)) << endl;
        }

        void calculatePerimeter()
        {
            cout << "Perimeter of Polygon: " << numberOfSides * length << endl;
        }
};

int main()
{
    Circle circle("center", "yellow", 2, 6, "[0,0]");
    circle.draw();
    circle.calculateArea();
    circle.calculatePerimeter();
    cout << endl;

    Rectangle rectangle("top-right", "red", 4.3, 7, 10, "[5,5]");
    rectangle.draw();
    rectangle.calculateArea();
    rectangle.calculatePerimeter();
    cout << endl;

    Triangle triangle("bottom-left", "blue", 2.1, 5.5, 7.5, 6.5, 8);
    triangle.draw();
    triangle.calculateArea();
    triangle.calculatePerimeter();
    cout << endl;

    Polygon polygon("center", "green", 1.5, 5, 6.4);
    polygon.draw();
    polygon.calculateArea();
    polygon.calculatePerimeter();
    cout << endl;

    return 0;
}
