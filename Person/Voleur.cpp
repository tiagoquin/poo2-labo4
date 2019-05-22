/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Voleur.cpp
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2018

 But         : implemente les fonctions de la class Voleur
 -----------------------------------------------------------------------------------
*/

#include "Voleur.h"


Voleur::Voleur(std::string string) : Person(string, false) {}

std::string Voleur::type_info() {
    return typeid(Voleur).name();
}
