#pragma once
#define CLASS(keyword, function)                                                        \
    CREATE_CLASS(keyword##Class, MEMBERS_FUNCTIONS(), MEMBERS_VARIABLES(function))      \
    CREATE_MEMBER_FUNCTION(template <typename T> keyword##Class,                        \
                           operator<,                                                   \
                           (T lhs, keyword##Class rhs),                                 \
                           rhs.set(lhs); return rhs;)                                   \

#define MEMBERS_VARIABLES(function)                                                        \
    CREATE_MEMBER_VARIABLE(FunctionInfo<decltype(&function)>::firstArgType, curr{})          \
    CREATE_MEMBER_VARIABLE(decltype(&function), _op0, function)

#define MEMBERS_FUNCTIONS()                                                                                           \
    CREATE_MEMBER_FUNCTION(template <typename T> auto, operator>, (T other) const, return _op0(curr, other);)         \
    CREATE_MEMBER_FUNCTION(template <typename T> void, set, (T value), curr = value;)
