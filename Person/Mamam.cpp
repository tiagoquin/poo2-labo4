/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Mamam.cpp
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2018

 But         : implemente les fonctions de la class Mamam
 -----------------------------------------------------------------------------------
*/

#include "Mamam.h"


Mamam::Mamam(std::string string): Famile(string) {

}

std::string Mamam::type_info() {
    return typeid(Mamam).name();
}

