/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Person.cpp
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2018

 But         : implemente les méthodes de Person. On peut récupérer leur nom, et
 savoir si ils peuvent conduire le bateau
 -----------------------------------------------------------------------------------
*/

#include "Person.h"


std::ostream &operator<<(std::ostream &os, const Person &person) {
    os << person.name;
    return os;
}

Person::Person(const std::string &name) : name(name), drive(true) {}

Person::Person(const std::string &name, bool drive) : name(name), drive(drive) {}

const std::string &Person::getName() const {
    return name;
}

bool Person::canDrive() {
    return drive;
}









