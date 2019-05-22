/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Boat.cpp
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2019

 But         : implémente les méthode de la classe Boat.
 -----------------------------------------------------------------------------------
*/

#include <iostream>
#include "Boat.h"


std::string Boat::toString() const {
    std::string string;
    string = this->name + " : <";
    for (const auto &person : this->persons) {
        string += person->getName() + " ";
    }
    string += " >";

    return string;
}

Boat::Boat(const std::string &string) : AbstractContainer(string) {}

bool Boat::verifie() {
    if (persons.size() > MAXBOATCAPACITY) {
        std::cout << "capacity max du bateau " << MAXBOATCAPACITY << std::endl;
        return false;
    }
    return AbstractContainer::verifie();

}

bool Boat::hasDriver() {

    for (const auto &person : persons) {
        if (person->canDrive()) {
            return true;
        }
    }
    std::cout << "personne n'est en messure de conduire" << std::endl;
    return false;
}


