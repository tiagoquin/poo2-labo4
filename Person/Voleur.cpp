//
// Created by Alexandre Gabrielli on 21.05.2019.
//

#include "Voleur.h"


Voleur::Voleur(std::string string) : Person(string, false) {}

std::string Voleur::type_info() {
    return typeid(Voleur).name();
}
