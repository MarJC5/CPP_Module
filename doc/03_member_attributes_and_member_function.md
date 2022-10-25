# member attributes & member function

Member functions can be defined within the class definition or separately using scope resolution operator, : −. Defining a member function within the class definition declares the function inline, even if you do not use the inline specifier. So either you can define Volume() function as below:

```c++
#ifndef CLASS_NAME_H
# define CLASS_NAME_H

class Sample {

    public:
        std::string str;
        
        void getStr(std::string str)
        {
            std::cout << str << std::endl;
        }

    Sample(void);
    ~Sample(void);
};

#endif
```

## [← Back to menu](./Summary.md)
