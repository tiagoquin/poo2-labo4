//
// Created by Alexandre Gabrielli on 21.05.2019.
//

#ifndef POO2_LABO4_FILLE_H
#define POO2_LABO4_FILLE_H


#include "Famile.h"

class Fille : public Famile {


public:
    std::string type_info() override;
    explicit Fille(const std::string& name);
};


#endif //POO2_LABO4_FILLE_H
