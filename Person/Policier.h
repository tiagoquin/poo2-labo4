//
// Created by Alexandre Gabrielli on 21.05.2019.
//

#ifndef POO2_LABO4_POLICIER_H
#define POO2_LABO4_POLICIER_H


#include "Person.h"

class Policier : public Person {

    std::string type_info() override;
public:
    explicit Policier(std::string string);
};


#endif //POO2_LABO4_POLICIER_H
