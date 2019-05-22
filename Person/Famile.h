/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Famile.h
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2018

 But         : la class abstaite fammille represente uen fammile, toute class héritante
 appartienne à la fammile.
 -----------------------------------------------------------------------------------
*/
#ifndef POO2_LABO4_FAMILE_H
#define POO2_LABO4_FAMILE_H

#include "Person.h"


class Famile : public Person {

    virtual std::string type_info() =0;

protected:
    explicit Famile(const std::string& name);
    explicit Famile(const std::string& name, bool drive);

private:



};


#endif //POO2_LABO4_FAMILE_H
