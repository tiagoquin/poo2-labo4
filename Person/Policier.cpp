//
// Created by Alexandre Gabrielli on 21.05.2019.
//

#include "Policier.h"



Policier::Policier(std::string string) : Person(string) {}

std::string Policier::type_info() {
    return typeid(Policier).name();
}
