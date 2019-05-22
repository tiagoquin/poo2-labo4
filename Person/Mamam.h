//
// Created by Alexandre Gabrielli on 21.05.2019.
//

#ifndef POO2_LABO4_MAMAM_H
#define POO2_LABO4_MAMAM_H


#include "Famile.h"

class Mamam : public Famile {

public:
    std::string type_info() override;

    explicit Mamam(std::string string);
};


#endif //POO2_LABO4_MAMAM_H
