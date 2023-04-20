#include "Reseau.hpp"

Reseau::Reseau()
{
}

Reseau::~Reseau()
{
}

bool TelephoneCompare(const Telephone a, const Telephone b)
{
    return (a.getNumero() < b.getNumero());
}

void Reseau::ajouter(const std::string num)
{
    Telephone tel(num, this);
    // tel.setReseau(this);
    membres.push_back(tel);
    membres.sort(TelephoneCompare);
}

const std::string Reseau::lister() const
{
    std::string concat = "";
    for (Telephone tel : membres)
    {
        concat += tel.getNumero() + "\n";
    }
    return concat;
}

Telephone& Reseau::trouveTel(const std::string num)
{
    for (Telephone& tel : membres)
    {
        if (tel.getNumero() == num)
        {
            return tel;
        }
    }

    throw MauvaisNumero();
}
