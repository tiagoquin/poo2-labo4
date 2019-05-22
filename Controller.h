//
// Created by chadanlo on 2019-05-16.
//

#ifndef POO2_LABO4_CONTROLLER_H
#define POO2_LABO4_CONTROLLER_H

#include <list>
#include <memory>

#include <Container/Bank.h>
#include <Container/Boat.h>

#define RIVEDROITE "droite"
#define RIVEGAUCHE "gauche"
#define BOAT "bateau"


class Controller {
    typedef std::pair<std::string, std::shared_ptr<Person>> value_person;

    void showMenu();

    void display();

public:
    Controller();


    void nextTurn();

private:
    int turn;
    Bank *gauche;
    Bank *droite;
    Boat *boat;
    bool booatpositionisleft;
    std::map<std::string,Person*> persons;

    bool embark( const std::string& person);
    bool debark( const std::string& person);
    bool movePeople( const std::string& person, bool debark);
    void reset();

};


#endif //POO2_LABO4_CONTROLLER_H
