#include "Message.hpp"

Message::Message(std::string exp,std::string des, std::string d) : expediteur{exp}, destinataire{des}, date{d}
{
    clef++;
}

int Message::clef = 0;

int Message::getCle(){
    return clef;
}

Message::~Message(){}