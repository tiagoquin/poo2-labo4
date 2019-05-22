/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Voleur.h
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2018

 But         : la class  Voleur represente un policier est hérite de Personne,
 un policier ne peu pas conduire
 -----------------------------------------------------------------------------------
*/

#ifndef POO2_LABO4_VOLEUR_H
#define POO2_LABO4_VOLEUR_H


#include "Person.h"

class Voleur : public Person {
    std::string type_info() override;
public:
    explicit Voleur(std::string string);
};


#endif //POO2_LABO4_VOLEUR_H
