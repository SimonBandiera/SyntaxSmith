#include "../includes/SyntaxSmith.hpp"
#include <iostream>

int quintuple(int value) {
    return value * 5;
}

int customAdd(int a, int b) {
    return a + b;
}

int ex() {
    exit(0);
}

CREATE_ONE_SIDE_OPERATOR(quintuple, quintuple)
#define quintuple quintupleClass()>

CREATE_OPERATOR(add, customAdd)
#define add <addClass()>

CREATE_NO_ARGS_OPERATOR(ex, ex)
#define ex exClass()

int main(int ac, char **av) {
    std::cout << "The quintuple of 10 is: " << (quintuple 10) << std::endl;
    std::cout << "10 + 2 is: " << (10 add 2) << std::endl;
    ex;
    std::cout << "will not print" << std::endl;
    return 0;
}