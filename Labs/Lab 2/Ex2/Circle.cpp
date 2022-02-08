/*
* Circle.cpp
*
* Description: This class models a Circle ...
*
* Author: Jet Simon
* Creation date: 1/18/2022
*/

#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>	// As we need to print data
#include "Circle.h"	// The header file for the class - we need this!

using namespace std;	

// Default constructor
// Note: This part of the constructor's header " : width(1), height(1)"
// is called the "initialiation list". 
// Check what our textbooks and online resources have to say about it!
Circle::Circle() : x(0), y(0), radius(10) {

}//Circle()

// Parameterized constructor
// Description: Create a new Circle with the given values.
Circle::Circle(int _x, int _y, double _radius)
{
   x = _x;
   y = _y;
   setRadius(_radius);
}//Circle(int, int, double)

// Getters return information about the Circle. 
// Note the const at the end of the method.
// This guarantees that the method cannot alter the member variables.
int Circle::getX() const
{
   return x;
   
}//getWidth

int Circle::getY() const
{
   return y;
   
}//getHeight

double Circle::getRadius() const
{
    return radius;
}

// Setters change the values of the class' data members.
void Circle::setX(int _x)
{
    x = _x;
}//setX

void Circle::setY(int _y)
{
    y =_y;
	  
}//setY

void Circle::setRadius(double _radius)
{
    radius = _radius;
    if(radius < 0) radius = 0;
}//setRadius

void Circle::move(int h, int v)
{
    y += v;
    x += h;
}//move
   
// Description: Compute and return the area of "this" Circle.
double Circle::computeArea() const   
{
   return M_PI * radius * radius;
   
}//computeArea

// Description: Prints the Circle's height and width.
void Circle::displayCircle() const
{
   cout << "radius " << radius << " at point x = " << x << ", y = " << y << endl;
   
}//displayCircle

bool Circle::intersect(Circle c)
{
    double distance = sqrt( pow(x - c.getX(), 2) + pow(y - c.getY(), 2) );
    return distance < radius;
}

// End of the implementation file