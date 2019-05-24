/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Controller.cpp
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2018

 But         : définition de nos fonctions
 -----------------------------------------------------------------------------------
*/

#include <Person/Papa.h>
#include <iostream>
#include <iomanip>
#include "Controller.h"

#define AFFICHERTOUCH 'p'
#define EMBARQUERTOUCH 'e'
#define DEBARQUERTOUCH 'd'
#define REINISIALISETOUCH 'r'
#define QUITTOUCH 'q'
#define MENUTOUCH 'h'
#define MOUVETOUCH 'm'

#define TUTOP "p : afficher\n"
#define TUTOE "e <nom>: embarquer <nom>\n"
#define TUTOD "d <nom>: debarquer <nom>\n"
#define TUTOM "m : deplacer bateau\n"
#define TUTOR "r : reinitialiser\n"
#define TUTOQ "q : quitter\n"
#define TUTOH "h : menu\n"
#define INPUTERROR "je n'est pas compris ce que vous voulez faire, appuyer sur h afficher l'aide"
#define NONAMEFOUND "ce nom ne semble pas correct"
#define NOPERSONINSID "la personne n'est pas dans "


#define LIGNESEPARATOR '-'
#define CENTERSEPARATOR '='
#define LIGNESIZE 60


Controller::Controller(std::initializer_list<Person *> persons) : turn(0), booatpositionisleft(true) {

    for (Person *person : persons) {
        this->persons.insert(name_person(person->getName(), person));
    }
    gauche = new Bank(RIVEGAUCHE, persons);
    droite = new Bank(RIVEDROITE);
    boat = new Boat(BOAT);

    showMenu();
    display();


}


void Controller::nextTurn() {
    bool again = false;
    turn++;
    std::cout << turn;
    /*pas de vérification de saisie utilisateur => pas de bufferOverflow*/
    std::string choice;
    std::getline(std::cin, choice);
    std::cin.clear();
    std::fflush(stdin);

    switch (choice[0]) {
        case AFFICHERTOUCH:
            showMenu();
            break;
        case EMBARQUERTOUCH:
            embark(choice.substr(2));
            break;
        case DEBARQUERTOUCH:
            debark(choice.substr(2));
            break;
        case MOUVETOUCH:
            if (boat->hasDriver())
                booatpositionisleft = !booatpositionisleft;
            break;
        case REINISIALISETOUCH:
            reset();
            break;
        case QUITTOUCH:
            again = true;
        case MENUTOUCH:
            showMenu();
            break;
        default:
            std::cout << INPUTERROR;
            break;

    }
    display();
    //ne quitte pas t'en qu'on a pas appuyer sur q
    if (!again)
        nextTurn();
}

void separatorLine(char separator) {
    for (size_t i = 0; i < LIGNESIZE; i++) {
        std::cout << separator;
    }
    std::cout << std::endl;
}

void Controller::showMenu() {
    std::cout << TUTOP << TUTOE << TUTOD << TUTOM << TUTOR << TUTOQ << TUTOH << std::endl;
}

void Controller::display() {
    separatorLine(LIGNESEPARATOR);
    std::cout << *gauche << std::endl;
    separatorLine(LIGNESEPARATOR);
    booatpositionisleft ? std::cout << *boat << std::endl : std::cout << std::endl;
    separatorLine(CENTERSEPARATOR);
    !booatpositionisleft ? std::cout << *boat << std::endl : std::cout << std::endl;
    separatorLine(LIGNESEPARATOR);
    std::cout << *droite << std::endl;
    separatorLine(LIGNESEPARATOR);
}


bool Controller::movePeople(const std::string &person, bool debark) {
    AbstractContainer *containers[2];
    auto it = persons.find(person);
    if (it != persons.end()) {

        Person *p = it->second;

        containers[debark ? 1 : 0] = booatpositionisleft ? gauche : droite;

        containers[debark ? 0 : 1] = boat;
        if (containers[0]->removeMember(p)) {
            containers[1]->addMember(p);
        } else {
            std::cout << NOPERSONINSID << containers[0]->getName() << std::endl;
            return false;
        }

        if (!(containers[0]->verifie() && containers[1]->verifie())) {
            containers[1]->removeMember(p);
            containers[0]->addMember(p);
        }
    } else {
        std::cout << NONAMEFOUND << std::endl;
    }
}


bool Controller::debark(const std::string &person) {
    return movePeople(person, true);
}

bool Controller::embark(const std::string &person) {
    return movePeople(person, false);
}

void Controller::reset() {
    turn = 0;

    for (auto p : droite->getPersons()) {
        gauche->addMember(p);
        droite->removeMember(p);
    }
    for (auto p : boat->getPersons()) {
        gauche->addMember(p);
        boat->removeMember(p);
    }

    booatpositionisleft = true;
}

Controller::~Controller() {
    delete boat;
    delete gauche;
    delete droite;
}

