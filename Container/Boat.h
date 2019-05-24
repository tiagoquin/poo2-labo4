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
    /**
     * constructeur
     */
    explicit Boat(const std::string &string);

    /**
     * verifie si l'état actuel correspond au régle (vérifie qu'il n'y ai pas plus de
     */
    bool verifie() override;

    /**
     * offre un affichage
     * @return une string correspondant à l'affichage du container
     */
    std::string toString() const override;

    /**
     * verifie si l'une des personnes au moins à le droit de conduire
     */
    bool hasDriver();


};


#endif //POO2_LABO4_BOAT_H
