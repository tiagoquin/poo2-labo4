/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Fils.cpp
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2018

 But         : implemente les fonctions de la class Fils
 -----------------------------------------------------------------------------------
*/
#include "Fils.h"

Fils::Fils(const std::string &name) : Famile(name, false) {
}

std::string Fils::type_info() {
    return typeid(Fils).name();
}

