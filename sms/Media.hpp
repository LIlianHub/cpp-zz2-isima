#ifndef MEDIA
#define MEDIA

#include <iostream>

class Media{

    public:
    Media();
    virtual ~Media();
    
    public:
    virtual std::string afficher() const = 0;



};



#endif