/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Famile.cpp
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2018

 But         : implemente les fonctions de la class Famile
 -----------------------------------------------------------------------------------
*/
#include "Famile.h"
#include "Voleur.h"
#include "Policier.h"

Famile::Famile(const std::string &name) : Person(name) {}

Famile::Famile(const std::string &name, bool drive) : Person(name, drive) {}
