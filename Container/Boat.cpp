//
// Created by chadanlo on 2019-05-16.
//

#include <iostream>
#include "Boat.h"

std::ostream &operator<<(std::ostream &os, const Boat &boat) {
    os << boat.name << " : <";
    for (const auto &person : boat.persons) {
        os << person->getName() << " ";
    }
    os << " >";

    return os;
}

std::string Boat::toString() const {
    std::string string;
    string = this->name + " : <";
    for (const auto &person : this->persons) {
        string += person->getName() + " ";
    }
    string += " >";

    return string;
}

Boat::Boat(const std::string &string) : Container(string) {}

bool Boat::verifie() {
    if (persons.size() > MAXBOATCAPACITY) {
        std::cout << "capacity max du bateau " << MAXBOATCAPACITY << std::endl;
        return false;
    }
    return Container::verifie();

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


