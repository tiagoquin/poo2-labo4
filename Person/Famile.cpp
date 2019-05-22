//
// Created by Alexandre Gabrielli on 21.05.2019.
//

#include "Famile.h"
#include "Voleur.h"
#include "Policier.h"

Famile::Famile(const std::string &name) : Person(name) {}

Famile::Famile(const std::string &name, bool drive) : Person(name, drive) {}
