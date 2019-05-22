/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Papa.h
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2018

 But         : la class papa represente un père est hérite de famille, les
 pères peuvent conduire
 -----------------------------------------------------------------------------------
*/
#ifndef POO2_LABO4_PAPA_H
#define POO2_LABO4_PAPA_H


#include "Famile.h"

class Papa : public Famile {


public:
    std::string type_info() override;

    explicit Papa(std::string string);
};


#endif //POO2_LABO4_PAPA_H
