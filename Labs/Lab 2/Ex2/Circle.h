/*
* Circle.h
*
* Description: This class models a rectangle ...
*
* Author: Jet Simon
* Creation date: 1/18/2022
*/

class Circle {

private: 

   // Everything that follows is private and cannot be "seen" and 
   // directly accessed from outside the class.
   // To access these private data members, client code needs to use the getters and setters.
  
   int x;
   int y;
   double radius;
   
   // Some classes have private methods like our Temperature class. This one doesn't!

public: 

   // Everything that follows is public and can be "seen" and directly accessed 
   // from outside the class (from client code).
   
   // Default constructor
   // Note that the default constructor has no parameters.
   Circle(); 
   
   // Parameterized constructor
   // Description: Create a new circle with the given values.
   Circle(int _x, int _y, double _radius);
      
   // Getters return information about the circle. 
   // Note the const at the end of the method.
   // This guarantees that the method cannot alter the member variables.
   int getX() const;
   int getY() const;
   double getRadius() const;


   // Setters change the values of the class' data members.
   void setX(int _x);
   void setY(int _y);
   void setRadius(double _radius);
   void move(int h, int v);
   
   // Description: Compute and return the area of "this" circle.
   double computeArea() const;   
   
   // Description: Prints the circle's height and width.
   void displayCircle() const;

   bool intersect(Circle c);

}; // Note the ";" - don't forget it!
// End of Circle.h
