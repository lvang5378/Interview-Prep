##pointer to classes example
```c++
#include <iostream>
using namespace std;

class Rectangle {
  int width, height;
public:
  Rectangle(int x, int y) : width(x), height(y) {}
  int area(void) { return width * height; }
};


int main() {
  Rectangle obj (3, 4);
  Rectangle * foo, * bar, * baz;
  foo = &obj;
  bar = new Rectangle (5, 6);
  baz = new Rectangle[2] { {2,5}, {3,6} };
  cout << "obj's area: " << obj.area() << '\n';
  cout << "*foo's area: " << foo->area() << '\n';
  cout << "*bar's area: " << bar->area() << '\n';
  cout << "baz[0]'s area:" << baz[0].area() << '\n';
  cout << "baz[1]'s area:" << baz[1].area() << '\n';       
  delete bar;
  delete[] baz;
  return 0;
}	
```


###Expression	can be read as
- *x:	pointed to by x
- &x:	address of x
- x.y:	member y of object x
- x->y:	member y of object pointed to by x
- (*x).y:	member y of object pointed to by x (equivalent to the previous one)
- x[0]:	first object pointed to by x
- x[1]:	second object pointed to by x
- x[n]:	(n+1)th object pointed to by x

---

##Overloading operators: 
###className:className::operator + (const className& param){//main body of operator}
Overloadable operators
```
    +    -    *    /    =    <    >    +=   -=   *=   /=   <<   >>
    <<=  >>=  ==   !=   <=   >=   ++   --   %    &    ^    !    |
    ~    &=   ^=   |=   &&   ||   %=   []   ()   ,    ->*  ->   new 
    delete    new[]     delete[]
```

####Example
```c++
class CVector {
  public:
    int x,y;
    CVector () {};
    CVector (int a,int b) : x(a), y(b) {}
    CVector operator + (const CVector&);
};

CVector CVector::operator+ (const CVector& param) {
  CVector temp;
  temp.x = x + param.x;
  temp.y = y + param.y;
  return temp;
}

CVector operator+ (const CVector& lhs, const CVector& rhs) {  //operator may be overloaded in two forms!!!!
  CVector temp; 
  temp.x = lhs.x + rhs.x;
  temp.y = lhs.y + rhs.y;
  return temp;
}
```
---
##Static members
**A static data member of a class is also known as a "class variable", because there is only one common variable for all the objects of that same class, sharing the same value: i.e., its value is not different from one object of this class to another. （每个declare的class instance, 他们的static data member都是一样的）**

A class can contain static members, either data or functions.

##Const member functions:
The access to its data members from outside the class is **restricted to read-only**, as if all its data members were const for those accessing them from outside the class. Note though, that the constructor is still called and is allowed to initialize and modify these data members:

```c++
  const MyClass foo(10);
  int get()  {return x;}          //不可以！！
  int get() const {return x;}     //才可以
```
```c++
int get() const {return x;}        // const member function
const int& get() {return x;}       // member function returning a const&
const int& get() const {return x;} // const member function returning a const& 
```
```c++
// overloading members on constness
#include <iostream>
using namespace std;

class MyClass {
    int x;
  public:
    MyClass(int val) : x(val) {}
    const int& get() const {return x;}
    int& get() {return x;}
};

int main() {
  MyClass foo (10);
  const MyClass bar (20);
  foo.get() = 15;         // ok: get() returns int&
// bar.get() = 25;        // not valid: get() returns const int&
  cout << foo.get() << '\n';
  cout << bar.get() << '\n';

  return 0;
}
```

##Templates:
Just like we can create function templates, we can also create class templates, allowing classes to have members that use template parameters as types. For example:    
```c++
template <class T>
class mypair {
    T values [2];
  public:
    mypair (T first, T second)
    {
      values[0]=first; values[1]=second;
    }
    T getmax ();

};

mypair<int> myobject (115, 36);

mypair<double> myfloats (3.0, 2.18); 

template <class T> 
T mypair<T>::getmax ()            //NOTICE: the syntax pf the definition of member function getmax !!!
{
  T retval;
  retval = a>b? a : b;
  return retval;
}
```

##template specialization:
It is possible to define a different implementation for a template when a specific type is passed as template argument. This is called a template specialization.
```c++
// class template:
template <class T>
class mycontainer {
    T element;
  public:
    mycontainer (T arg) {element=arg;}
    T increase () {return ++element;}
};

// class template specialization:
template <>
class mycontainer <char> {
    char element;
  public:
    mycontainer (char arg) {element=arg;}
    char uppercase ()
    {
      if ((element>='a')&&(element<='z'))
      element+='A'-'a';
      return element;
    }
};

int main () {
  mycontainer<int> myint (7);
  mycontainer<char> mychar ('j');
  cout << myint.increase() << endl;
  cout << mychar.uppercase() << endl;
  return 0;
}
```
