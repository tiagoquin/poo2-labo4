/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Bank.cpp
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2019

 But         : implémente les méthode de la classe Bank.
 -----------------------------------------------------------------------------------
*/


#include "Bank.h"


std::string Bank::toString() const {
    std::string string;
    string = this->name + " : ";
    for (Person *person : this->persons) {

        string += person->getName() + ' ';
    }
    return string;

}

Bank::Bank(const std::string &name, std::initializer_list<Person *> persons) : AbstractContainer(name) {
    for (Person *person : persons) {
        this->addMember(person);
    }
}

Bank::Bank(const std::string &name) : AbstractContainer(name) {}