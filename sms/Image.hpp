#ifndef IMAGE
#define IMAGE

#include <iostream>
#include "Media.hpp"

class Image : public Media{
    public:
    Image();

    public:
    std::string afficher() const;
};

#endif