#pragma once
#define CLASS_ONE_SIDE(keyword, function)                                                        \
    CREATE_CLASS(keyword##Class, MEMBERS_FUNCTIONS_ONE_SIDE(), MEMBERS_VARIABLES_ONE_SIDE(function))      \

#define MEMBERS_VARIABLES_ONE_SIDE(function)                                                        \
    CREATE_MEMBER_VARIABLE(decltype(&function), _op0, function)

#define MEMBERS_FUNCTIONS_ONE_SIDE()                                                                                  \
    CREATE_MEMBER_FUNCTION(template <typename T> auto, operator>, (T other) const, return _op0(other);)               \
