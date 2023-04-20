#ifndef TELEPHONE_HPP
#define TELEPHONE_HPP

#include <iostream>
#include <string>
#include "Mms.hpp"

class Reseau;


class Telephone {
    std::string numero;
    Reseau  * sonReseau = 0;
    int nbMessage = 0;

    public :
        Telephone(std::string = "");
        Telephone(std::string, Reseau*);

    public:
        void setNumero(std::string);
        const std::string getNumero() const;
        void setReseau(Reseau*);
        const Reseau * getReseau() const;
        int getNbMessages() const;
        void textoter(const std::string, const std::string);
        void mmser(const std::string, MMS*);

    
};

#endif