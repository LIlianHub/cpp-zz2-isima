// NOM    : BALLEJOS
// PRENOM : Lilian

#ifndef __gangster_hpp__
#define __gangster_hpp__

#include <iostream>
#include <list>
#include <ostream>

/* Personne*/

class Personne
{
    std::string nom;

public:
    Personne(std::string = "");
    ~Personne();

public:
    void setNom(std::string);
    std::string getNom() const;
    bool equals(const Personne &) const;
};

const Personne INCONNU = Personne("INCONNU");

/*Gangster*/

class Gangster
{
    int id;
    int influence = 1;
    static int cpt;
    Personne personne;
    bool isReveal = false;

public:
    Gangster();
    ~Gangster();

public:
    int getId() const;
    int getInfluence() const;
    void setInfluence(int);
    Personne getPersonne();
    void setPersonne(Personne);
    bool operator<(const Gangster &) const;
    bool getIsReveal();
};

/* CHef */

class Chef : public Gangster
{
    std::list<Gangster *> equipe;

public:
    Chef();
    ~Chef();

public:
    void commande(Gangster *);

private:
    void RecalculeInfluence();
};

/*INconuu exception*/

class InconnuException : public std::invalid_argument
{
public:
    InconnuException() : std::invalid_argument("personnalite inconnue") {}
};

/*Famille*/

class Famille
{
    std::list<Gangster *> membres;

public:
    Famille();
    ~Famille();

public:
    void ajouter(Gangster *);
    void listePersonnes(std::ostream &) const;
    void listeMembres(std::ostream &) const;
    friend std::ostream &operator<<(std::ostream &, const Famille &);
};

/*Foncteur*/

class FoncteurInf
{

public:
    FoncteurInf(){}

    // This operator overloading enables calling
    // operator function () on objects of increment
    bool operator()(Gangster* g1, Gangster* g2) const
    {
        return g1->getInfluence() <= g2->getInfluence();
    }
};

#endif
