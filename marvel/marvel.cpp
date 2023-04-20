#include "marvel.hpp"

/*Personne*/

Personne::Personne(std::string p, std::string n, Personne::Genre g) : prenom{p}, nom{n}, genre{g} {}

Personne::~Personne() {}

std::string Personne::getPrenom() const
{
    return prenom;
}
std::string Personne::getNom() const
{
    return nom;
}

Personne::Genre Personne::getGenre() const
{
    return genre;
}

std::string toStringGenre(Personne::Genre g)
{
    switch (g)
    {
    case Personne::HOMME:
        return "HOMME";
        break;
    case Personne::FEMME:
        return "FEMME";
        break;
    default:
        return "INDETERMINE";
        break;
    }
}

void Personne::afficher(std::ostream &s) const
{
    s << prenom << " " << nom << " "
      << "[" << toStringGenre(genre) << "]";
}

Personne Personne::INCONNU = Personne{"Inconnu", "Inconnu", Personne::INDETERMINE};

bool Personne::operator==(const Personne &a) const
{
    return getGenre() == a.getGenre() && getPrenom() == a.getPrenom() && getNom() == a.getNom();
}

std::ostream &operator<<(std::ostream &s, Personne &p)
{
    p.afficher(s);
    return s;
}

/* Super*/

Super::Super(std::string sn, Personne p) : superName{sn}, personne{p} {}

Super::~Super()
{
}

std::string Super::getNom() const
{
    return superName;
}

bool Super::estAnonyme() const
{
    return !isReveal;
}

void Super::enregistrer()
{
    isReveal = true;
}

Personne Super::getIdentite() const
{
    if (isReveal)
        return personne;
    throw AnonymeException();
}

void Super::setIdentite(Personne p)
{
    personne.genre = p.getGenre();
    personne.nom = p.getNom();
    personne.prenom = p.getPrenom();
    isReveal = false;
}

void Super::ajouter(Capacite *c)
{
    level += c->getNiveau();
    capa.push_back(c);
}

int Super::getNiveau() const
{
    return level;
}

void Super::setNom(std::string n)
{
    superName = n;
}

/*Capacité*/

Capacite::Capacite(std::string n, int niv) : nom{n}, niveau{niv} {}
Capacite::~Capacite() {}

int Capacite::getNiveau()
{
    return niveau;
}

void Capacite::action(std::ostream &s, std::string ajout)
{
    s << nom << " [" << niveau << "]" << ajout;
}

std::string Capacite::getNom()
{
    return nom;
}

Materiel::Materiel(std::string n, int niv) : Capacite(n, niv) {}

void Materiel::actionner(std::ostream &s)
{
    action(s, " en action");
}

void Materiel::utiliser(std::ostream &s)
{
    actionner(s);
}

Capacite *Materiel::clone()
{
    return new Materiel(getNom(), getNiveau());
}


Physique::Physique(std::string n, int niv) : Capacite(n, niv) {}

void Physique::exercer(std::ostream &s)
{
    action(s, "");
}

void Physique::utiliser(std::ostream &s)
{
    exercer(s);
}

Capacite * Physique::clone()
{
    return new Psychique(getNom(), getNiveau());
}

Psychique::Psychique(std::string n, int niv) : Capacite(n, niv) {}

void Psychique::penser(std::ostream &s)
{
    action(s, "");
}

void Psychique::utiliser(std::ostream &s)
{
    penser(s);
}

Capacite * Psychique::clone()
{
    return new Psychique(getNom(), getNiveau());
}

/* Equipe*/

Equipe::Equipe(std::string n) : nom{n} {}

Equipe::~Equipe(){

}

void Equipe::ajouter(Super *s)
{
    membres.push_back(s);
    niveau += s->getNiveau();
    nombre += 1;
}
int Equipe::getNombre() const
{
    return nombre;
}
int Equipe::getNiveau() const
{
    return niveau;
}