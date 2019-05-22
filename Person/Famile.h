//
// Created by Alexandre Gabrielli on 21.05.2019.
//

#ifndef POO2_LABO4_FAMILE_H
#define POO2_LABO4_FAMILE_H

#include "Person.h"


class Famile : public Person {

    virtual std::string type_info() =0;

protected:
    explicit Famile(const std::string& name);
    explicit Famile(const std::string& name, bool drive);

private:



};


#endif //POO2_LABO4_FAMILE_H
