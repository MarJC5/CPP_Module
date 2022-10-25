# non member attributes & non member functions

A (non-static) member function has an implicit this argument, a non-member doesn't.

`Member` attributes / functions are present inside of a class. It means that the class needs to be instantiated, in order to use this attribute / function. Each attribute will be different in each instance

`Non member` variables and functions exist at the class level, and not at the instance level.

```c++
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {

public:

	Sample(void);
	~Sample(void);

	// non member function
	// when the function does not have anything to do with the other class
	// functions, but you want it to be part of the class
	static int getNbInst(void);

private:

	// non member attribute
	// number of instances: this information only makes sense at the class level
	static int _nbInst;

};

#endif
```

```c++
Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;
	Sample::_nbInst += 1;

	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	Sample::_nbInst -= 1;
	return;
}

// With member function, CPP will pass as a parameter, an instance of your class
// so this-> can be used

// this pointer is not passed for a non member function, so you can't
// use this-> here
int	Sample::getNbInst(void)
{
	return Sample::_nbInst;
}

// this is the only way to initialise a non member attribute (static attribute)
// this is initialised without an instance being created
int	Sample::_nbInst = 0;
```

An algorithm created by Scott Meyers [(source link)](https://www.drdobbs.com/cpp/how-non-member-functions-improve-encapsu/184401197)
```c++
if (f needs to be virtual)
    make f a member function of C;
else if (f is operator>> or operator<<)
{
    make f a non-member function;
    if (f needs access to non-public members of C)
        make f a friend of C;
}
else if (f needs type conversions on its left-most argument)
{
    make f a non-member function;
    if (f needs access to non-public members of C)
        make f a friend of C;
}
else if (f can be implemented via C public interface)
    make f a non-member function;
else
    make f a member function of C;
```

## [← Back to menu](./Summary.md)
