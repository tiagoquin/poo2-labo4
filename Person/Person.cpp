//
// Created by chadanlo on 2019-05-16.
//

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









