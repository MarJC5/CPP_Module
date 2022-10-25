# visibility

`Public`: 
- All the class members declared under public will be available to everyone. The data members and member functions declared public can be accessed by other classes too. The public members of a class can be accessed from anywhere in the program using the direct member access operator (.) with the object of that class.

`Private`:
- The class members declared as private can be accessed only by the functions inside the class. They are not allowed to be accessed directly by any object or function outside the class. Only the member functions or the friend functions are allowed to access the private data members of a class.

`Keep in mind`: for attributes or functions that have nothing to do with the user, keep them private in the class. When designing the class, always think about what to keep internally or expose to the outside

```c++
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample
{
public:

	int publicFoo;
	
	Sample(void);
	~Sample(void);

	void publicBar(void) const;

private:

	// use _ prefix for all private identifier
	int _privateFoo;

	void _privateBar(void) const;
};

#endif
```

```c++
Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;

	this->publicFoo = 0;
	std::cout << "this->publicFoo = " << this->publicFoo <<std::endl;
	this->_privateFoo = 0;
	std::cout << "this->_privateFoo = " << this->_privateFoo <<std::endl;

	this->publicBar();
	this->_privateBar();

	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void	Sample::publicBar(void) const
{
	std::cout << "Member function publicBar called" << std::endl;
	return;
}

void	Sample::_privateBar(void) const
{
	std::cout << "Member function _privateBar called" << std::endl;
	return;
}
```

## [← Back to menu](./Summary.md)
