/*
Quiz 3 Assignment 
Student: Ryan Arif
Class: 2022FL COSC-1437-58001
Professor: Dr Tyson McMillan
Date: 11/16/2022
*/
#include <iostream>
#include "Input_Validation_Extended.h"
using namespace std;

class Triangle{
    private:
        double base;
        double height;
    public:
        //Default Constructor
        Triangle()
        {
            base = 0.0;
            height = 0.0;
        }
        //Other Constructor
        Triangle (double x, double y)
        {
            base = x;
            height = y;
        }
        void setBase(double d){ base = d; }
        void setHeight(double d){ height = d; }
        double getBase(){ return base; }
        double getHeight(){ return height; }
        double getArea() { return (0.5*base*height); } //A = 1/2 * bh
};

int main()
{
    Triangle t1, t2, t3; //declare 3 triangles and set them up with the default constructor
    double userVal = 0.0; //variable to store the value from the user
    double totalArea = 0.0; //total area of the 3 triangles
    cout << "Please enter the base value for Triangle 1: ";
    userVal = validateDouble(userVal); //validate the double 
    t1.setBase(userVal);
    cout << "Please enter the height value for Triangle 1";
    userVal = validateDouble(userVal);
    t1.setHeight(userVal);
    cout << "The total area of the first triangle is: ";
    totalArea += t1.getArea();
    cout << "Area of the first Triangle is: " << t1.getArea() << endl;

    cout << "Pleaes enter the base value for Triangle 2: ";
    userVal = validateDouble(userVal);
    t2.setBase(userVal);
    cout << "Please enter the height value for Triangle 2: ";
    userVal = validateDouble(userVal);
    t2.setHeight(userVal);
    cout << "Area of the second triangle is: " << t2.getArea() << endl;

    totalArea = t2.getArea();

    cout << "Pleaes enter the height value for Triangle 3: ";
    userVal = validateDouble(userVal);
    t3.setHeight(userVal);

    cout << "Pleaes enter the base value for Triangle 3: ";
    userVal = validateDouble(userVal);
    t3.setBase(userVal);
    totalArea += t3.getArea();
    cout << "Area of the third triangle is: " << t3.getArea() << endl;

    cout << "Total Area is: " << totalArea;
    
    return 0;
}
