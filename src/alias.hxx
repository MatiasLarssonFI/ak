#ifndef ALIAS_HXX
#define ALIAS_HXX

#include <memory>
#include <iostream>


template<class T>
using uptr = std::unique_ptr<T>;

template<class T>
using sptr = std::shared_ptr<T>;

static auto& errstream = std::cerr;


#endif // ALIAS_HXX
