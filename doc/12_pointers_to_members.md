# pointers to members

In C++ , function pointers when dealing with member functions of classes or structs, it is invoked using an object pointer or a this call. We can only call members of that class (or derivatives) using a pointer of that type as they are type safe.

```c++
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample
{
public:

	int foo;

	Sample(void);
	~Sample(void);

	void bar(void) const;

};

#endif
```

```c++
Sample::Sample(void) : foo(0)
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void Sample::bar(void) const
{
	std::cout << "Member function bar called" << std::endl;
	return;
}
```

```c++
int main(void)
{
	// allocated on the stack
	Sample instance;
	// declared a pointer to the address of instance, \
	// which is stored in a variable (instancep)
	Sample * instancep = &instance;

	// declaring a pointer on an interger attribute of a Sample class
	int Sample::*p = NULL;
	// declaring a pointer on a const member function of a Sample class
	void (Sample::*f)(void) const;

	p = &Sample::foo; // this is not specific about which instance that p refers to

	std::cout << "Value of member foo = " << instance.foo << std::endl;
	// .* operator to specify the instance that p refers to
	instance.*p = 21; // directly using the instance
	std::cout << "Value of member foo = " << instance.foo << std::endl;
	instancep->*p = 42; // pointer to an instance
	std::cout << "Value of member foo = " << instance.foo << std::endl;

	f = &Sample::bar; // can't tell which instance that it's refering to

	(instance.*f)(); // use .* operator to specify the specify
	(instancep->*f)(); // or use ->* a pointer to refer to the instance

	return 0;
}
```

## [← Back to menu](./Summary.md)
