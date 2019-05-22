/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Fils.h
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2018

 But         : la class  Fils represente un fils est hérite de famille ,tous
 fils ne peux pas conduire
 -----------------------------------------------------------------------------------
*/

#ifndef POO2_LABO4_FILS_H
#define POO2_LABO4_FILS_H


#include "Famile.h"

class Fils : public Famile {

    std::string type_info() override;
public:
    explicit Fils(const std::string& name);
};


#endif //POO2_LABO4_FILS_H
