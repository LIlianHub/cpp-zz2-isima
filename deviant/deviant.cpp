#include <algorithm>

#include "deviant.hpp"

Cite CITE;

/*Inddividu*/

Individu::Individu() : id{getCompteur() + 1}
{
    cpt++;
}

Individu::Individu(Personne &p)
{
    id = p.getId();
}

Individu::~Individu() {}

int Individu::cpt = 0;

int Individu::getCompteur()
{
    return cpt;
}

void Individu::afficher(std::ostream &s) const
{
    s << id;
}

int Individu::getId() const
{
    return id;
}

std::ostream &operator<<(std::ostream &s, Individu i)
{
    i.afficher(s);
    return s;
}

TYPE Individu::getType() const
{
    throw IllegalException();
}

/*Personne*/

Personne::Personne(std::string n) : nom{n}
{
    CITE.nb++;
    CITE.membres.push_back(this);
}

Personne::~Personne()
{
    CITE.nb--;
}

std::string Personne::getNom() const
{
    return nom;
}
void Personne::setNom(std::string n)
{
    nom = n;
}

void Personne::afficher(std::ostream &s) const
{
    s << nom << " ";
    Individu::afficher(s);
}

std::ostream &operator<<(std::ostream &s, Personne p)
{
    p.afficher(s);
    return s;
}

TYPE Personne::getType() const
{
    return TYPE::PERSONNE;
}

/*Deviant*/

Deviant::Deviant(const Personne &p, std::string o) : Individu{p}, obs{o} {
    CITE.nb --;
}


void Deviant::setObs(std::string s)
{
    obs = s;
}

std::string Deviant::getObs() const
{
    return obs;
}

bool Deviant::operator<(const Deviant& d) const{
    return obs < d.getObs();
}


TYPE Deviant::getType() const
{
    return TYPE::DEVIANT;
}

/* Cite */

Cite::Cite() {}

int Cite::size() const
{
    return nb;
}

/*Covid*/

Covid::Covid(){}

bool forTrieList(const Deviant& a, const Deviant& b){
    return !(a < b);
}

void Covid::push(const Deviant& d){
    membres.push_back(d);
    membres.sort(forTrieList);
    
}

void Covid::pop(){
    membres.pop_front();
}

const Deviant& Covid::top() const{
    return membres.front();
}

void Covid::affiche(std::ostream& s){
    for(Deviant d : membres){
        //s << d.getObs() << std::endl;
        s << &d << " " << d.getObs() << std::endl;
    }
}