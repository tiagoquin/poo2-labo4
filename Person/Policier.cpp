/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Policier.cpp
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2018

 But         : implemente les fonctions de la class Policier
 -----------------------------------------------------------------------------------
*/

#include "Policier.h"



Policier::Policier(std::string string) : Person(string) {}

std::string Policier::type_info() {
    return typeid(Policier).name();
}
