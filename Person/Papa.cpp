//
// Created by Alexandre Gabrielli on 21.05.2019.
//

#include "Papa.h"


Papa::Papa(std::string string) :Famile(string){

}

std::string Papa::type_info() {
    return typeid(Papa).name();
}
