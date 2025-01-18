#ifndef SYNTAX_SMITH_HPP
    #define SYNTAX_SMITH_HPP
    #include "SSBase.hpp"
    #include "SSOneSide.hpp"
    #include "SSHelper.hpp"
    #include <functional>

template <typename T>
struct FunctionInfo;
template <typename R, typename first, typename... Args>
struct FunctionInfo<R(*)(first, Args...)> {
    using type = R;
    using firstArgType = first;
    using args = std::tuple<Args...>;
};

#define CREATE_OPERATOR(keyword, function)              \
    CLASS(keyword, function)                            \

#define CREATE_ONE_SIDE_OPERATOR(keyword, function)     \
    CLASS_ONE_SIDE(keyword, function)                   \


#endif