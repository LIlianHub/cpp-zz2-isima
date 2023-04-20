#include "Mms.hpp"
#include "Telephone.hpp"

MMS::MMS(std::string exp, std::string des, std::string d) : SMS(exp, des, d)
{
}

void MMS::joindre(Media *m)
{
    joint.push_back(m);
}

std::string MMS::afficher() const
{
    std::string retour = getTexte();
    for (Media *m : joint)
    {
        retour += (*m).afficher();
    }
    return retour;
}

std::string MMS::getDe() const
{
    return (*env).getNumero();
}

std::string MMS::getA() const
{
    return (*dest).getNumero();
}

void MMS::setDe(Telephone * tel)
{
    env = tel;
}

void MMS::setA(Telephone * tel)
{
    dest = tel;
}
MMS::~MMS(){
    for (Media *m : joint)
    {
        delete m;
    }
}