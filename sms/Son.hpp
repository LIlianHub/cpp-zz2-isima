#ifndef SON
#define SON

#include <iostream>
#include "Media.hpp"

class Son : public Media{
    public:
    Son();

    public:
    std::string afficher() const;
};

#endif