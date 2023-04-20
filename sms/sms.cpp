#include "sms.hpp"


SMS::SMS(std::string exp,std::string des, std::string d): Message(exp, des, d), id{getCle() - 1}{
}

std::string SMS::getTexte() const{
    return message;
}

std::string SMS::afficher() const{
    return getTexte();
}

void SMS::setTexte(const std::string text){
    if(text.length() <= 160){
        message = text;
    }
    else{
        throw std::invalid_argument("Texte trop long pour un sms");
    }
}

int SMS::getId() const{
    return id;
}
