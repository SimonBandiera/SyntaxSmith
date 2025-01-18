# SyntaxSmith
SyntaxSmith is a C++ library that allow custom operators and syntax extensions with ease. By automating class generation, function wrapping, and type introspection, it eliminates boilerplate and streamlines operator overloading


SyntaxSmith implifies the definition of two-sided (`lhs operator rhs`) and one-sided (`operator rhs`) operators using some few macros, allowing to write code like this:

```cpp
int main(int ac, char **av) {
    std::cout << "The quintuple of 10 is: " << (quintuple 10) << std::endl;
    std::cout << "10 + 2 is: " << (10 add 2) << std::endl;
    return 0;
}
```
It was originally create to simplify the lexing process of another one of my project, [JS_CMP](https://github.com/JS-CMP), hence the option to create one-sided operator that can seem useless at first.

# How does it work

The macros will create a custom class with the name you gave.<br> 
The operators `<` and `>` are overloaded so that the values on the left and right of your custom operators are recuperated.<br>
Then you can define a macro to wrape the class with the needed operators.

For the normal version:
```cpp
CREATE_OPERATOR(quintuple, yourFunction)
#define quintuple < quintupleClass >
```

For the one-sided version:
```cpp
CREATE_ONE_SIDE_OPERATOR(add, yourFunction)
#define add addClass >
```

# Usage

Simply write the function you want your new operator to call, and use the `CREATE_OPERATOR` or `CREATE_ONE_SIDE_OPERATOR` macro to define the operator. You then can define a macro to wrap the class that will be created with the name you gave with `<` `>`

```cpp
int quintuple(int value) { 
    return value * 5; 
}

int customAdd(int a, int b) { 
    return a + b; 
}

CREATE_ONE_SIDE_OPERATOR(quintuple, quintuple)
#define quintuple quintupleClass()>

CREATE_OPERATOR(add, customAdd)
#define add <addClass()>

int main(int ac, char **av) {
    std::cout << "The quintuple of 10 is: " << (quintuple 10) << std::endl;
    std::cout << "10 + 2 is: " << (10 add 2) << std::endl;
    return 0;
}
```

To see a working example, you can cmake and check the `example` folder.