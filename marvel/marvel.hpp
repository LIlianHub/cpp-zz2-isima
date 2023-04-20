#ifndef marvel__hpp
#define marvel__hpp

#include <iostream>
#include <list>

/*Personne*/

class Personne{

    friend class Super;

    public:
        enum Genre{
            HOMME,
            FEMME,
            INDETERMINE
        };
    
    public:
        Personne(std::string, std::string, Personne::Genre = Personne::HOMME);
        ~Personne();
    
    public:
    std::string getPrenom() const;
    Personne::Genre getGenre() const;
    std::string getNom() const;
    void afficher(std::ostream &) const;
    bool operator==(const Personne&) const;

    public:
    static Personne INCONNU;
    

    private:
    std::string prenom;
    std::string nom;
    Genre genre;
    
};

std::ostream& operator<<(std::ostream&, Personne&);

/*Capacité*/

class Capacite{
    std::string nom;
    int niveau;

    public:
        virtual ~Capacite();
        Capacite(std::string, int = 0);
        
    
    public :
        void action(std::ostream&, std::string);
        virtual void utiliser(std::ostream&) = 0;
        int getNiveau();
        virtual Capacite * clone() = 0;
        std::string getNom();
};


class Materiel : public Capacite{
    public:
        Materiel(std::string, int = 0);
        void actionner(std::ostream&);
        void utiliser(std::ostream&);
        Capacite * clone();

};

class Physique : public Capacite{
    public:
        Physique(std::string, int = 0);
        void exercer(std::ostream&);
        void utiliser(std::ostream&);
        Capacite * clone();
    
};

class Psychique : public Capacite{
    public:
        Psychique(std::string, int = 0);
        void penser(std::ostream&);
        void utiliser(std::ostream&);
        Capacite * clone();
    
};


/* super*/

class Super{
    std::string superName;
    Personne personne;
    bool isReveal = false;
    int level = 0;
    std::list<Capacite*> capa;
    
    public:
        Super(std::string, Personne);
        ~Super();
        std::string getNom() const;
        bool estAnonyme() const;
        void enregistrer();
        Personne getIdentite() const;
        void setIdentite(Personne);
        void ajouter(Capacite *);
        int getNiveau() const;
        void setNom(std::string);

};

/*exception*/

class AnonymeException : public std::invalid_argument{
    public:
        AnonymeException() : std::invalid_argument("identite anonyme"){}
};

/*Equipe*/

class Equipe{
    int niveau = 0;
    int nombre = 0;
    std::string nom;
    std::list<Super*> membres;

    public:
        Equipe(std::string);
        ~Equipe();
        void ajouter(Super*);
        int getNombre() const;
        int getNiveau() const;
};


#endif
