//
// Created by Alexandre Gabrielli on 21.05.2019.
//

#ifndef POO2_LABO4_VOLEUR_H
#define POO2_LABO4_VOLEUR_H


#include "Person.h"

class Voleur : public Person {
    std::string type_info() override;
public:
    explicit Voleur(std::string string);
};


#endif //POO2_LABO4_VOLEUR_H
