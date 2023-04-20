#ifndef VIDEO
#define VIDEO

#include <iostream>
#include "Media.hpp"

class Video : public Media{
    public:
    Video();

    public:
    std::string afficher() const;
};

#endif