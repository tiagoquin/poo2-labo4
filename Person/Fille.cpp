/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Fille.cpp
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2018

 But         : implemente les fonctions de la class Fille
 -----------------------------------------------------------------------------------
*/

#include "Fille.h"
#include "Papa.h"
#include "Mamam.h"

Fille::Fille(const std::string &name) : Famile(name,false) {
}


std::string Fille::type_info() {
    return typeid(Fille).name();
}
