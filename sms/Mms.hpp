#ifndef MMSGUARD
#define MMSGUARD

#include "sms.hpp"
#include "Media.hpp"
#include <iostream>
#include <list>

class Telephone;

class MMS : public SMS
{
    std::list<Media *> joint;
    Telephone *env = nullptr;
    Telephone *dest = nullptr;

public:
    MMS(std::string, std::string, std::string);
    ~MMS();

public:
    void joindre(Media *);
    std::string afficher() const override;
    std::string getDe() const;
    std::string getA() const;
    void setA(Telephone *);
    void setDe(Telephone *);
};

#endif