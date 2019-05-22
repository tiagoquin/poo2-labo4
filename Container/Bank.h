/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Bank.h
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2019

 But         : Déclaration des méthode de la classe Bank. La class Bank hérite de 
 AbstractContainer et peu en plus être construit depuis une initializer_list de personne
 -----------------------------------------------------------------------------------
*/

#ifndef POO2_LABO4_BANK_H
#define POO2_LABO4_BANK_H


#include <ostream>
#include "AbstractContainer.h"

class Bank : public AbstractContainer {

public:
    Bank(const std::string &string);

    std::string toString() const override;

    Bank(const std::string &name,std::initializer_list<Person*>persons);
};


#endif //POO2_LABO4_BANK_H
