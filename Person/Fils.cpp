//
// Created by Alexandre Gabrielli on 21.05.2019.
//

#include "Fils.h"

Fils::Fils(const std::string &name) : Famile(name, false) {
}

std::string Fils::type_info() {
    return typeid(Fils).name();
}

