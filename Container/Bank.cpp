//
// Created by chadanlo on 2019-05-16.
//

#include "Bank.h"


std::string Bank::toString() const {
    std::string string;
    string = this->name + " : ";
    for (const std::weak_ptr<Person> &person : this->persons) {
        std::shared_ptr<Person> sp = person.lock();
        if (sp)
            string += (*sp).getName() + ' ';
    }
    return string;
}

Bank::Bank(const std::string &name, const std::list<std::shared_ptr<Person>> &persons) : Container(name) {
    for (std::weak_ptr<Person> person : persons) {
        this->addMember(person);
    }
}

Bank::Bank(const std::string &string) : Container(string) {}
