- typedef / using
```c++
  using C = char;
```
- union
```c++
  union type_name {
    member_type1 member_name1;
    member_type2 member_name2;
    member_type3 member_name3;
    .
    .
  } object_names;
```
- enumberate
```c++
  enum type_name {
    value1,
    value2,
    value3,
    .
    .
  } object_names;

```
- Enumerated types with enum class
```c++
  enum class Colors {black, blue, green, cyan, red, purple, yellow, white};
  
  Colors mycolor;
   
  mycolor = Colors::blue;
  if (mycolor == Colors::green) mycolor = Colors::red; 
```
