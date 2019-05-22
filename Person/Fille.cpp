//
// Created by Alexandre Gabrielli on 21.05.2019.
//

#include "Fille.h"
#include "Papa.h"
#include "Mamam.h"

Fille::Fille(const std::string &name) : Famile(name,false) {
}


std::string Fille::type_info() {
    return typeid(Fille).name();
}
