//
// Created by chadanlo on 2019-05-16.
//

#ifndef POO2_LABO4_PERSON_H
#define POO2_LABO4_PERSON_H

#include "string"

class Person {

    std::string name;

public:
    virtual bool canDrive() = 0;
};


#endif //POO2_LABO4_PERSON_H
