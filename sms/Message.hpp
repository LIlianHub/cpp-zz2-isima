#ifndef MESSAGE
#define MESSAGE

#include <iostream>

class Message{
    std::string expediteur;
    std::string destinataire;
    std::string date;
    static int clef; 

    public:
    Message(std::string = "",std::string = "", std::string ="");
    virtual ~Message();
    
    public:
    virtual std::string afficher() const = 0;
    static int getCle();
    virtual int getId() const = 0;


};



#endif