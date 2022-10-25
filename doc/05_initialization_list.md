# initialization list
Initialization list is used in initializing the data members of a class. The list of members to be initialized is indicated with constructor as a comma-separated list followed by a colon

Before the body of the constructor is run, all of the constructors for its parent class and then for its fields are invoked.
By default, the no-argument constructors are invoked. Initialization lists allow you to choose which constructor is called and what arguments that constructor receives.

If you have a reference or a const field, or if one of the classes used does not have a default constructor, you must use an initialization list.

```c++
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {

public:
	// data
	char a1;
	int a2;
	float a3;

	Sample(char p1, int p2, float p3);
	~Sample(void);
};

#endif
```

```c++
Sample::Sample(char p1, int p2, float p3) : a1(p1), a2(p2), a3(p3) {
	std::cout << "Constructor called" << std::endl;
	std::cout << "this->a1 = " << this->a1 << std::endl;
	std::cout << "this->a2 = " << this->a2 << std::endl;
	std::cout << "this->a3 = " << this->a3 << std::endl;
}

Sample::~Sample(void) {
	std::cout << "Destructor called" << std::endl;
	return;
}
```

```c++
#include <iostream>
#include "Sample.class.hpp"

int	main(void)
{
	Sample	instance('a', 42, 4.2f);

	return (0);
}
```

```text
// Output

Constructor called
this->a1 = a
this->a2 = 42
this->a3 = 4.2
Destructor called
```

## [← Back to menu](./Summary.md)
