#define CLASS_NOARGS(keyword, function)                                                                             \
    CREATE_CLASS(keyword##Class, MEMBERS_FUNCTIONS_NOARGS(keyword##Class), MEMBERS_VARIABLES_NOARGS(function))      \

#define MEMBERS_VARIABLES_NOARGS(function)                          \
    CREATE_MEMBER_VARIABLE(decltype(&function), _op0, function)

#define MEMBERS_FUNCTIONS_NOARGS(className)                         \
    CREATE_MEMBER_FUNCTION( , className, (), _op0();)               \

