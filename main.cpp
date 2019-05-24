/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : main.cpp
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2018

 But         : le main initialise les personnes avec lequel l'application devra "jouer"
 elle instancie ensuite le controleur avec cette list et lance le premier tour
 -----------------------------------------------------------------------------------
*/


#include <Person/Voleur.h>
#include <Person/Policier.h>
#include <Person/Fille.h>
#include <Person/Fils.h>
#include <Person/Mamam.h>
#include <Person/Papa.h>
#include <iostream>

#include "Controller.h"

int main() {
    std::initializer_list<Person *> toBank = {
            new Papa("papa"),
            new Mamam("mamam"),
            new Fils("paul"),
            new Fils("pierre"),
            new Fille("julie"),
            new Fille("janne"),
            new Policier("policier"),
            new Voleur("voleur")
    };

    Controller controller(toBank);

    controller.nextTurn();

    std::cout << "l'application va se terminer" << std::endl;
    return 0;
}