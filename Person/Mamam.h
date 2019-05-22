/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Mamam.h
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2018

 But         : la class  mamam represente une mamam est hérite de famille, les
 mamams peuvent conduire
 -----------------------------------------------------------------------------------
*/
#ifndef POO2_LABO4_MAMAM_H
#define POO2_LABO4_MAMAM_H


#include "Famile.h"

class Mamam : public Famile {

public:
    std::string type_info() override;

    explicit Mamam(std::string string);
};


#endif //POO2_LABO4_MAMAM_H
