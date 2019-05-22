#include <Person/Voleur.h>
#include <Person/Policier.h>
#include <Person/Fille.h>
#include <Person/Fils.h>
#include <Person/Mamam.h>
#include <Person/Papa.h>

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

    return 0;
}