# stdio streams

Generally, when we write a program in Linux operating system for G++ compiler, it needs “std” namespace in the program. We use it by writing using namespace std; then we can access any of the objects like cout, cin.

## std::cout

The cout is a predefined object of ostream class using the extraction operator (``<<``), and it is used to print the data on the standard output device.

```c++
#include <iostream>

using namespace std;

int main(void)
{
    std::cout << "42 Lausanne";
    return(0);
}

// Result => 42 Lausanne
```

## std::cin

The cin is a source of characters determined by the environment using the extraction operator (``>>``). It is generally assumed to be input from an external source, such as the keyboard or a file.

```c++
#include <iostream>

using namespace std;

int main(void)
{
    char    buff[512];

    std::cin >> buff;
    std::cout << "Hello " << buff << std::endl;
    return(0);
}

// Result => Hello <buff_value_from_user_input>
```

## [← Back to menu](./Summary.md)
