//
// Created by chadanlo on 2019-05-16.
//

#ifndef POO2_LABO4_PERSON_H
#define POO2_LABO4_PERSON_H

#include <ostream>
#include <map>
#include <memory>
#include "string"


class Person {

    std::string name;
    bool drive;

public:
     bool canDrive();

    virtual std::string type_info() = 0;

    explicit Person(const std::string &name);
    explicit Person(const std::string &name, bool drive);


    const std::string &getName() const;

    friend std::ostream &operator<<(std::ostream &os, const Person &person);
};


#endif //POO2_LABO4_PERSON_H
