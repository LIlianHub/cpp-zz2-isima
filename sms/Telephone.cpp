#include "Telephone.hpp"
#include "Reseau.hpp"

Telephone::Telephone(std::string num) : numero{num} {}
Telephone::Telephone(std::string num, Reseau *r) : numero{num}, sonReseau{r} {}

const std::string Telephone::getNumero() const
{
    return numero;
}

void Telephone::setNumero(std::string num)
{
    numero = num;
}

void Telephone::setReseau(Reseau *r)
{
    sonReseau = r;
}

const Reseau *Telephone::getReseau() const
{
    return sonReseau;
}

int Telephone::getNbMessages() const
{
    return nbMessage;
}

void Telephone::textoter(const std::string dest, const std::string mess)
{
    nbMessage++;
    try
    {
        Telephone &cible = (*sonReseau).trouveTel(dest);
        cible.nbMessage++;
    }
    catch (const MauvaisNumero &)
    {
    }
}

void Telephone::mmser(const std::string dest, MMS *mms)
{
    nbMessage++;
    mms->setDe(this);
    try
    {
        Telephone &cible = (*sonReseau).trouveTel(dest);
        mms->setA(&cible);
        cible.nbMessage++;
    }
    catch (const MauvaisNumero &)
    {
    }
}