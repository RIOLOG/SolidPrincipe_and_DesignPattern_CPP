// Liskov Substitution Principle (LSP) states that objects of a superclass should be replaceable with objects of its subclasses without affecting the correctness of the program.

//Let's consider a scenario where we have a base class Shape and two derived classes Rectangle and Square. Each shape has a method calculateArea() to compute its area. According to LSP, any method that works with Shape should also work with Rectangle and Square without any issues.


#include<iostream>
using namespace std;

//Base/Main Class:
class Shape {
    public:
        virtual double calculateArea() const = 0;
};


//Derived Class: Rectangle
class Rectangle: public Shape {
    protected:
        double width, height;
        
    public:
        Rectangle(double w, double h)
        {
            width = w;
            height = h;
        }
        
        double calculateArea() const override
        {
            return width * height;
        }
};


//Derived Class: Square
class Square: public Shape {
    protected:
        double side;
        
    public:
        Square(double s)
        {
            side = s;
        }
        
        double calculateArea() const override
        {
            return side* side;
        }
};

//Function to print area of the given shape:
void PrintArea(const Shape& shape)
{
    cout<<"Area is: "<<shape.calculateArea()<<endl;
}


int main()
{
    Rectangle rect(3.0, 4.0);
    Square square(5.0);
    
    PrintArea(rect);
    PrintArea(square);
    
    return 0;
}
