# this

Every object in C++ has access to its own address through an important pointer called this pointer. The this pointer is an implicit parameter to all member functions.
Therefore, inside a member function, this may be used to refer to the invoking object.

```c++
#ifndef CLASS_NAME_H
# define CLASS_NAME_H

class Sample {

    public:
       int  foo;
	   
	   Sample(void);
	   ~Sample(void);
	   
	   void bar(void);
};

#endif
```

```c++
Sample::Sample(void) {
	
	std::cout << "Constructor called" << std::endl;
	
	this->foo = 42;
	std::cout << "this->foo: " << this->foo << std::endl;
	
	this->bar();
	
	return;
};

Sample::~Sample(void) {
	
	std::cout << "Destructor called" << std::endl;
	return;
};

void    Sample::bar(void) {
	std::cout << "Member function bar called" << std::endl;
	return;
};
```

```text
// Output

Constructor called
this->foo: 42
Member function bar called
Destructor called
```

## [← Back to menu](./Summary.md)
