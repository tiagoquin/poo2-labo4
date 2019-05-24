/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Fille.h
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2018

 But         : la class  Fille represente une fille est hérite de famille , toutes
 filles ne peut pas conduire
 -----------------------------------------------------------------------------------
*/

#ifndef POO2_LABO4_FILLE_H
#define POO2_LABO4_FILLE_H


#include "Famile.h"

class Fille : public Famile {


public:
    std::string type_info() override;

    explicit Fille(const std::string &name);
};


#endif //POO2_LABO4_FILLE_H
