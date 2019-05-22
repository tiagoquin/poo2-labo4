//
// Created by chadanlo on 2019-05-16.
//
#include <utility>
#include <cstring>
#include <iostream>
#include <Person/Voleur.h>
#include <Person/Policier.h>
#include <Person/Mamam.h>
#include <Person/Fille.h>
#include "Container.h"

bool Container::addMember(Person *person) {
    this->persons.push_back(person);
}


Container::Container(const std::string &name) : name(name) {}

std::ostream &operator<<(std::ostream &os, const Container &container) {
    return os << container.toString();
}


bool Container::removeMember(const Person *person) {
    for (auto it = persons.begin(); it != persons.end(); ++it) {
        if (((Person *) *it)->getName() == person->getName()) {
            persons.erase(it);
            return true;
        }
    }
    return false;
}

bool Container::verifie() {
    bool isBoyPresent = false;
    bool isGirlPresent = false;
    bool isFatherPresent = false;
    bool isMotherPresent = false;
    bool isThiefPresent = false;
    bool isCopPresent = false;

    for (const auto &person : persons) {
        if (person->type_info() == typeid(Voleur).name()) {
            isThiefPresent = true;
        } else if (person->type_info() == typeid(Policier).name()) {
            isCopPresent = true;
        } else {
            if (person->canDrive()) {

                if (person->type_info() == typeid(Mamam).name()) {
                    isMotherPresent = true;
                } else {
                    isFatherPresent = true;
                }
            } else {
                if (person->type_info() == typeid(Fille).name()) {
                    isGirlPresent = true;
                } else {
                    isBoyPresent = true;
                }
            }

        }
    }

// vérification des contraintes
// policier - voleur
    if (isThiefPresent && !isCopPresent && (isFatherPresent || isMotherPresent || isBoyPresent || isGirlPresent)) {
        std::cout <<
                  "# Le voleur ne peut rester en contact avec un membre de la famille si le policier n'est pas present !"
                  << std::endl;
        return false;
    }
// mère - fils
    if (isMotherPresent && isBoyPresent && !isFatherPresent) {
        std::cout << "# Les fils ne peuvent rester seuls avec leur mere si le pere n'est pas present !"
                  << std::endl;
        return false;

    }

// père - fille
    if (isFatherPresent && isGirlPresent && !isMotherPresent) {
        std::cout << "# Les filles ne peuvent rester seules avec leur pere si la mere n'est pa presente !"
                  << std::endl;
        return false;
    }
    return true;
}

const std::list<Person *> &Container::getPersons() const {
    return persons;
}

const std::string &Container::getName() const {
    return name;
}
