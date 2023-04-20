#ifndef RESEAU
#define RESEAU

#include <string>
#include <iostream>
#include <list>


#include "Telephone.hpp"

class MauvaisNumero : public std::invalid_argument
{
public:
    MauvaisNumero(const std::string &what_arg)
        : std::invalid_argument(what_arg)
    {
    }
    MauvaisNumero()
        : std::invalid_argument("mauvais numero")
    {
    }
};

class Reseau
{
    std::list<Telephone> membres;

public:
    Reseau();
    ~Reseau();

public:
    void ajouter(const std::string);
    const std::string lister() const;
    Telephone& trouveTel(const std::string);
};

#endif