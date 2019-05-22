//
// Created by chadanlo on 2019-05-16.
//

#ifndef POO2_LABO4_BANK_H
#define POO2_LABO4_BANK_H


#include <ostream>
#include "Container.h"

class Bank : public Container {

public:
    Bank(const std::string &string);

    std::string toString() const override;

    Bank(const std::string &name,std::initializer_list<Person*>persons);
};


#endif //POO2_LABO4_BANK_H
