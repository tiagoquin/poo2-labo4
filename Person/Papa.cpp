/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Papa.cpp
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2018

 But         : implemente les fonctions de la class Papa
 -----------------------------------------------------------------------------------
*/

#include "Papa.h"


Papa::Papa(std::string string) :Famile(string){

}

std::string Papa::type_info() {
    return typeid(Papa).name();
}
