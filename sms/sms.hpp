#ifndef __SMS
#define __SMS

#include <iostream>
#include "Message.hpp"

class SMS : public Message
{
    std::string message = "";
    int id;

public:
    SMS(std::string, std::string, std::string);

public:
    std::string getTexte() const;
    std::string afficher() const;
    void setTexte(const std::string);
    int getId() const;
};

#endif