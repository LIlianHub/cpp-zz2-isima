#include "gangster.hpp"

/* Personne */

Personne::Personne(std::string n) : nom{n} {}

Personne::~Personne() {}

void Personne::setNom(std::string n)
{
    nom = n;
}

std::string Personne::getNom() const
{
    return nom;
}

bool Personne::equals(const Personne &p) const
{
    return getNom() == p.getNom();
}

/* Gangster */

int Gangster::cpt = 1;

Gangster::Gangster() : id{cpt}
{
    cpt++;
}

Gangster::~Gangster() {}

int Gangster::getId() const
{
    return id;
}

int Gangster::getInfluence() const
{
    return influence;
}

void Gangster::setInfluence(int v)
{
    influence = v;
}

Personne Gangster::getPersonne()
{

    if (!isReveal)
    {
        throw InconnuException();
    }

    return personne;
}

void Gangster::setPersonne(Personne p)
{
    personne = p;
    isReveal = true;
}

bool Gangster::operator<(const Gangster &g) const
{
    bool retour;
    if (g.getInfluence() > getInfluence())
    {
        retour = true;
        // std::cout << "1er";
    }
    else if (g.getInfluence() < getInfluence())
    {
        retour = false;
        // std::cout << "2eme";
    }
    else
    {
        retour = g.getId() < getId();
        // std::cout << "age";
    }

    // std::cout << "retour: " << retour << std::endl;

    return retour;
}

bool Gangster::getIsReveal()
{
    return isReveal;
}

/* Chef */

Chef::Chef() {}

Chef::~Chef() {
    for(Gangster * g : equipe){}
}

void Chef::commande(Gangster *g)
{
    equipe.push_back(g);
    RecalculeInfluence();
}

void Chef::RecalculeInfluence()
{
    int value = 10;
    for (Gangster *g : equipe)
    {
        value += (*g).getInfluence();
    }
    setInfluence(value);
}

/* Famille */

Famille::Famille() {}

Famille::~Famille() {}

bool compareGangsterAlphabetique(Gangster *a, Gangster *b)
{
    return a->getPersonne().getNom() < b->getPersonne().getNom();
}

void Famille::ajouter(Gangster *g)
{
    membres.push_back(g);
}

void Famille::listePersonnes(std::ostream &stream) const
{
    std::list<Gangster *> areReveal;

    for (Gangster *g : membres)
    {
        if (g->getIsReveal())
        {
            areReveal.push_back(g);
        }
    }
    areReveal.sort(compareGangsterAlphabetique);

    bool outil = true;

    for (Gangster *g : areReveal)
    {
        if(outil){
            stream << (*g).getPersonne().getNom();
            outil = false;
        }
        else{
            stream << ", " << (*g).getPersonne().getNom();
        }
        
    }
}

std::ostream &operator<<(std::ostream &out, const Famille &f)
{
    f.listePersonnes(out);
    return out;
}

void Famille::listeMembres(std::ostream &stream) const
{
    std::list<Gangster *> temp = membres;
    std::list<Gangster *> temp2;
    
    
    temp.sort(FoncteurInf());

    for (Gangster *g : temp)
    {
        temp2.push_front(g);
    }

    bool tool = true;

    for (Gangster *g : temp2)
    {
        if(tool){
            stream << (*g).getId();
            tool = false;
        }
        else{
            stream << " " << (*g).getId();
        }
        
    }
}