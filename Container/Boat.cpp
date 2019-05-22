//
// Created by chadanlo on 2019-05-16.
//

#include <iostream>
#include "Boat.h"

std::ostream &operator<<(std::ostream &os, const Boat &boat) {
    os<< boat.name << " : <";
    for (const std::weak_ptr<Person> &person : boat.persons) {
        std::shared_ptr<Person> sp = person.lock();
        if (sp)
            os << (*sp).getName() << " ";
    }
   os << " >";

    return os;
}

std::string Boat::toString() const {
    std::string string;
    string = this->name + " : <";
    for (const std::weak_ptr<Person> &person : this->persons) {
        std::shared_ptr<Person> sp = person.lock();
        if (sp)
            string += (*sp).getName() + " ";
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
        std::shared_ptr<Person> sp = person.lock();
        if (sp) {
            if (sp->canDrive()) {
                return true;
            }
        }
    }
    std::cout << "personne n'est en messure de conduire" << std::endl;
    return false;
}


