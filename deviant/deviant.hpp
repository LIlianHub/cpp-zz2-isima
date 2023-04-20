#ifndef __deviant_hpp__
#define __deviant_hpp__

#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
// completer la liste suivant vos besoins

enum class TYPE { PERSONNE, DEVIANT };

// Utiliser une des versions de Cite
// 


/*Individu*/

class Personne;


class Individu{
    int id;
    static int cpt;
    

    public:
        Individu();
        Individu(Personne&);
        virtual ~Individu();
        static int getCompteur();
        virtual void afficher(std::ostream&) const;
        int getId() const;
        friend std::ostream& operator<<(std::ostream&, Individu);
        virtual TYPE getType() const;

};

std::ostream& operator<<(std::ostream&, Individu);

/*Personne*/

class Personne : public Individu{

    std::string nom;
    
    public:
        Personne(std::string = "inconnu");
        ~Personne();
        std::string getNom() const;
        void setNom(std::string);
        void afficher(std::ostream&) const;
        friend std::ostream& operator<<(std::ostream&, Personne);
        TYPE getType() const override;
};

std::ostream& operator<<(std::ostream&, Personne);

/*excepetion*/

class IllegalException : public std::invalid_argument{
    public:
        IllegalException() : std::invalid_argument("illegal exception"){}
};

class Deviant : public Individu{

    std::string obs;

    public:
        Deviant(const Personne&, std::string = "");
        void setObs(std::string);
        std::string getObs() const;
        bool operator<(const Deviant&) const;
        TYPE getType() const override;

};


/* Cite */

class Cite{
    int nb = 0;
    friend class Personne;
    friend class Deviant;
    std::list<Personne*> membres;
    

    public:
        Cite();
        int size() const;
};

extern Cite CITE;
//#define CITE Cite::getCite()

class Covid{
    std::list<Deviant> membres;
    public:
        Covid();
        void push(const Deviant&);
        void pop();
        const Deviant& top() const;
        void affiche(std::ostream&);
};

#endif
