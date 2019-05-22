//
// Created by chadanlo on 2019-05-16.
//
#include <Person/Papa.h>
#include <Person/Mamam.h>
#include <Person/Fils.h>
#include <Person/Fille.h>
#include <Person/Policier.h>
#include <Person/Voleur.h>
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

#define LIGNESEPARATOR '-'
#define CENTERSEPARATOR '='
#define LIGNESIZE 60


Controller::Controller() : turn(0), booatpositionisleft(true) {
    std::list<std::shared_ptr<Person>> toBank;

    std::shared_ptr<Person> sp_papa(new Papa("papa"));
    persons.insert(value_person(sp_papa->getName(), sp_papa));
    toBank.push_back(sp_papa);

    std::shared_ptr<Person> sp_mamam(new Mamam("mamam"));
    persons.insert(value_person(sp_mamam->getName(), sp_mamam));
    toBank.push_back(sp_mamam);

    std::shared_ptr<Person> sp_paul(new Fils("paul"));
    persons.insert(value_person(sp_paul->getName(), sp_paul));
    toBank.push_back(sp_paul);


    std::shared_ptr<Person> sp_pierre(new Fils("pierre"));
    persons.insert(value_person(sp_pierre->getName(), sp_pierre));
    toBank.push_back(sp_pierre);


    std::shared_ptr<Person> sp_julie(new Fille("julie"));
    persons.insert(value_person(sp_julie->getName(), sp_julie));
    toBank.push_back(sp_julie);


    std::shared_ptr<Person> sp_janne(new Fille("janne"));
    persons.insert(value_person(sp_janne->getName(), sp_janne));
    toBank.push_back(sp_janne);


    std::shared_ptr<Person> sp_policier(new Policier("policier"));
    persons.insert(value_person(sp_policier->getName(), sp_policier));
    toBank.push_back(sp_policier);


    std::shared_ptr<Person> sp_voleur(new Voleur("Voleur"));
    persons.insert(value_person(sp_voleur->getName(), sp_voleur));
    toBank.push_back(sp_voleur);


    gauche = new Bank(RIVEGAUCHE, toBank);
    droite = new Bank(RIVEDROITE);
    boat = new Boat(BOAT);

    showMenu();
    display();


}


void Controller::nextTurn() {
    turn++;
    std::cout << turn;
    /*pas de vérification de saisie utilisateur => pas de bufferOverflow*/
    std::string str;
    std::getline(std::cin, str);
    std::cin.clear();
    std::fflush(stdin);

    switch (str[0]) {
        case AFFICHERTOUCH:
            showMenu();
            break;
        case EMBARQUERTOUCH:
            embark(str.substr(2));
            break;
        case DEBARQUERTOUCH:
            debark(str.substr(2));
            break;
        case MOUVETOUCH:
            if (boat->hasDriver())
                booatpositionisleft = !booatpositionisleft;
            break;
        case REINISIALISETOUCH:
            reset();
            break;
        case QUITTOUCH:
            exit(0);
        case MENUTOUCH:
            showMenu();
            break;
        default:
            std::cout << INPUTERROR;
            break;

    }
    display();

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
    Container *containers[2];
    std::weak_ptr<Person> wp_person(persons.find(person)->second);

    containers[debark ? 1 : 0] = booatpositionisleft ? gauche : droite;

    containers[debark ? 0 : 1] = boat;
    containers[0]->removeMember(wp_person);
    containers[1]->addMember(wp_person);

    if (!(containers[0]->verifie() && containers[1]->verifie())) {
        containers[1]->removeMember(wp_person);
        containers[0]->addMember(wp_person);
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

