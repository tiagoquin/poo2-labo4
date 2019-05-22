/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Policier.h
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2018

 But         : la class  Policier represente un policier est hérite de Personne,
 un policier peu conduire
 -----------------------------------------------------------------------------------
*/

#ifndef POO2_LABO4_POLICIER_H
#define POO2_LABO4_POLICIER_H


#include "Person.h"

class Policier : public Person {

    std::string type_info() override;
public:
    explicit Policier(std::string string);
};


#endif //POO2_LABO4_POLICIER_H
