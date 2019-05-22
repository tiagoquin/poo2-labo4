/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Boat.h
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2019

 But         : Déclaration des méthode de la classe Boat. La class Boat hérite de
 AbstractContainer
 -----------------------------------------------------------------------------------
*/

#ifndef POO2_LABO4_BOAT_H
#define POO2_LABO4_BOAT_H


#include <ostream>
#include "AbstractContainer.h"

#define MAXBOATCAPACITY 2
class Boat : public AbstractContainer {


public:

    bool verifie() override;

    explicit Boat(const std::string& string);

    std::string toString() const override;

    bool hasDriver();


};


#endif //POO2_LABO4_BOAT_H
