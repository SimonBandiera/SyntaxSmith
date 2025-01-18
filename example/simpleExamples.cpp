#include "../includes/SyntaxSmith.hpp"
#include <iostream>

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