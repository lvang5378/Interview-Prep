http://www.cplusplus.com/doc/tutorial/structures/

A data structure is a group of data elements grouped together under one name. These data elements, known as members, can have different types and different lengths. Data structures can be declared in C++ using the following syntax:


```c++
struct product {
  int weight;
  double price;
} apple, banana;  //apple and banana are optional, 
                  //the optional field object_names can be used to directly declare objects of the structure type
```

##Can also define functions for a struct.
```c++
struct foo {
  int bar;
  foo() : bar(3) {}   //look, a constructor
  int getBar() 
  { 
    return bar; 
  }
};

foo f;
int y = f.getBar(); // y is 3
```

##Difference between struct and class
http://stackoverflow.com/questions/92859/what-are-the-differences-between-struct-and-class-in-c  
If you don't specify `public:` or `private:`, members of a struct are public by default; members of a class are private by default.

