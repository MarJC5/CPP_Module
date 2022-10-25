# class & instance

A class in C++ is the building block that leads to Object-Oriented programming. It is a user-defined data type, which holds its own data members and member functions, which can be accessed and used by creating an instance of that class. A C++ class is like a blueprint for an object.

For Example: Consider the Class of Cars. There may be many cars with different names and brand but all of them will share some common properties like all of them will have 4 wheels, Speed Limit, Mileage range etc. So here, Car is the class and wheels, speed limits, mileage are their properties.

``ClassName.hpp``

```h
#ifndef CLASS_NAME_H
# define CLASS_NAME_H

class Sample {

    // Access specifier
    public: // can be private, public or protected

    // Data members
    string str;

    //Default Constructor
    Sample(void); // Methods to access data members
    ~Sample(void);
};

#endif
```

A **constructor** is a special type of member function of a class which initializes objects of a class. In C++, Constructor is automatically called when object(instance of class) is created. It is special member function of the __class because it does not have any return type__.

**Destructor** is an instance member function which is invoked automatically whenever an object is going to be destroyed. Meaning, a destructor is the last function that is going to be called before an object is destroyed.

The thing is to be noted here, if the object is created by using new or the constructor uses new to allocate memory which resides in the heap memory or the free store, the destructor should use delete to free the memory.

``ClassName.cpp``

```cpp
#include <iostream>
#include "ClassName.hpp"

Sample::Sample(void) {
    std::cout << "Constructor called" << std::endl;
    return;
}

Sample::~Sample(void) {
    std::cout << "Destructor called" << std::endl;
    return;
}
```

``main.cpp``

```cpp
#include "ClassName.hpp"

int main(void)
{
    Sample instance;

    return(0);
}
```

## [← Back to menu](./Summary.md)
