//
// Created by Alexandre Gabrielli on 21.05.2019.
//

#ifndef POO2_LABO4_FILS_H
#define POO2_LABO4_FILS_H


#include "Famile.h"

class Fils : public Famile {

    std::string type_info() override;
public:
    explicit Fils(const std::string& name);
};


#endif //POO2_LABO4_FILS_H
