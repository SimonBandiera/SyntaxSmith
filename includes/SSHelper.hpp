#pragma once
#define CREATE_CLASS(name, publicMembers, privateMembers)   \
    class name {                                            \
    public:                                                 \
        publicMembers                                       \
    private:                                                \
        privateMembers                                      \
    };

#define CREATE_MEMBER_VARIABLE(type, name, ...) \
    type name __VA_OPT__(= __VA_ARGS__);

#define CREATE_MEMBER_FUNCTION(return_type, name, args, body) \
    return_type name args { body }
