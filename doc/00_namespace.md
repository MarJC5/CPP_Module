## namespace

Namespaces provide a method for preventing name conflicts in large projects.

In each scope, a name can only represent one entity. So, there cannot be two variables with the same name in the same scope. Using namespaces, we can create two variables or member functions having the same name.

A namespace definition begins with the keyword namespace followed by the namespace name.

```c++
#include <iostream>

using namespace std;
  
// Variable created inside namespace
namespace first
{
    int val = 500;
}
  
// Global variable
int val = 100;
  
int main(void)
{
    // Local variable
    int val = 200;
  
    // These variables can be accessed from
    // outside the namespace using the scope
    // operator ::
    cout << first::val << '\n'; 
  
    return 0;
}

// Result => 500
```

## [← Back to menu](./Summary.md)
