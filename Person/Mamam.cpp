//
// Created by Alexandre Gabrielli on 21.05.2019.
//

#include "Mamam.h"


Mamam::Mamam(std::string string): Famile(string) {

}

std::string Mamam::type_info() {
    return typeid(Mamam).name();
}

