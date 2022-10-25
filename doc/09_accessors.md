# accessors

In practice, all attributes of a class are private. Getters are the interface between the user and private attributes, to be sure that the values are always correct.

`getter`:
- The accessor member function gets the value of a private data member of the class.
- This method is also known as `get` or Getter method.

`setter`:
- The mutator member function sets a new value to the private data member of the class. There are other use cases where we use the mutator method to clean or ensure that the private data variable can only have valid data.
- This method is also known as `set` or Setter method.

```c++
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample
{
public:

	Sample(void);
	~Sample(void);

	int	getFoo(void) const;
	void setFoo(int v);

private:

	int	_foo;
};

#endif
```

```c++
Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;

	this->setFoo(0);
	std::cout << "this->getFoo() = " << this->getFoo() << std::endl;

	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

// grant only read-only access to the attribute
int	Sample::getFoo(void) const
{
	// return a copy of the _foo attribute
	return this->_foo;
}

// this way allows the user to change the _foo attribute
void	Sample::setFoo(int v)
{
	// don't allow _foo to have a negative value
	if (v >= 0)
		this->_foo = v;
	return;
}
```

## [← Back to menu](./Summary.md)
