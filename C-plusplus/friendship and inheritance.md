http://www.cplusplus.com/doc/tutorial/inheritance/

##Friend functions
In principle, private and protected members of a class cannot be accessed from outside the same class in which they are declared. However, this rule does not apply to "friends".

```c++
class Rectangle {
    int width, height;
  public:
    Rectangle() {}
    Rectangle (int x, int y) : width(x), height(y) {}
    int area() {return width * height;}
    friend Rectangle duplicate (const Rectangle&);    //The duplicate function is a friend of class Rectangle.
};                                                    //NOTICE function!!!, not class !!!

Rectangle duplicate (const Rectangle& param)  
{
  Rectangle res;
  res.width = param.width*2;
  res.height = param.height*2;
  return res;
}

int main () {
  Rectangle foo;
  Rectangle bar (2,3);
  foo = duplicate (bar);
  cout << foo.area() << '\n';
  return 0;
}
```

##Friend Class:
Similar to friend functions, a friend class is a class whose members have access to the private or protected members of another class:

```c++
// friend class
#include <iostream>
using namespace std;

class Square;

class Rectangle {
    int width, height;
  public:
    int area ()
      {return (width * height);}
    void convert (Square a);
};

class Square {
  friend class Rectangle;
  private:
    int side;
  public:
    Square (int a) : side(a) {}
};

void Rectangle::convert (Square a) {
  width = a.side;
  height = a.side;
}
  
int main () {
  Rectangle rect;
  Square sqr (4);
  rect.convert(sqr);
  cout << rect.area();
  return 0;
}
```

---

##Inheritance between classes:
####Classes in C++ can be extended, creating new classes which retain characteristics of the base class. 
This process, known as inheritance, involves a base class and a derived class: The derived class inherits the members of the base class, on top of which it can add its own members.    
![alt text](http://www.cplusplus.com/doc/tutorial/inheritance/inheritance.png)

The Polygon class would contain members that are common for both types of polygon. In our case: width and height. And Rectangle and Triangle would be its derived classes, with specific features that are different from one type of polygon to the other.
####class derivedClass: public baseClass{//main part};    
####class derivedClass: protected baseClass{//main part};    //most accessible level the members inherited from the class is protected  That is, all members that were public in baseClass would become protected in derivedClass. 

```c++
// derived classes
#include <iostream>
using namespace std;

class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b;}
 };

class Rectangle: public Polygon {
  public:
    int area ()
      { return width * height; }
 };

class Triangle: public Polygon {
  public:
    int area ()
      { return width * height / 2; }
  };
  
int main () {
  Rectangle rect;
  Triangle trgl;
  rect.set_values (4,5);
  trgl.set_values (4,5);
  cout << rect.area() << '\n';
  cout << trgl.area() << '\n';
  return 0;
}
```

###What is inherited from the base class:
In principle, a publicly derived class inherits access to every member of a base class **except**:

        its constructors and its destructor
        its assignment operator members (operator=)
        its friends
        its private members
Even though access to the constructors and destructor of the base class is not inherited as such, they are automatically called by the constructors and destructor of the derived class.

```c++
Daughter (int a)          // nothing specified: call default constructor
Son (int a) : Mother (a)  // constructor specified: call this specific constructor 
```

##Multiple inheritance
```c++
class Rectangle: public Polygon, public Output;
class Triangle: public Polygon, public Output; 
```


