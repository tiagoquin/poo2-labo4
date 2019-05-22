//
// Created by Alexandre Gabrielli on 21.05.2019.
//

#ifndef POO2_LABO4_PAPA_H
#define POO2_LABO4_PAPA_H


#include "Famile.h"

class Papa : public Famile {


public:
    std::string type_info() override;

    explicit Papa(std::string string);
};


#endif //POO2_LABO4_PAPA_H
