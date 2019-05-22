//
// Created by chadanlo on 2019-05-16.
//

#include "Bank.h"


std::string Bank::toString() const {
    std::string string;
    string = this->name + " : ";
    for (Person *person : this->persons) {

        string += person->getName() + ' ';
    }
        return string;

}

Bank::Bank(const std::string &name, const std::list<Person*> &persons) : Container(name) {
    for (Person* person : persons) {
        this->addMember(person);
    }
}

Bank::Bank(const std::string &string) : Container(string) {}