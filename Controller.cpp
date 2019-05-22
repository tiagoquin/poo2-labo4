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
#define NONAMEFOUND "ce nom ne semble pas correct"
#define NOPERSONINSID "la personne n'est pas dans "


#define LIGNESEPARATOR '-'
#define CENTERSEPARATOR '='
#define LIGNESIZE 60


Controller::Controller() : turn(0), booatpositionisleft(true) {
    std::list<Person *> toBank;

    Person *papa = new Papa("papa");
    Person *mamam = new Mamam("mamam");
    Person *paul = new Fils("paul");
    Person *pierre = new Fils("pierre");
    Person *julie = new Fille("julie");
    Person *janne = new Fille("janne");
    Person *policier = new Policier("policier");
    Person *voleur = new Voleur("voleur");

    persons.insert(std::pair<std::string, Person *>(papa->getName(), papa));
    toBank.push_back(papa);
    persons.insert(std::pair<std::string, Person *>(mamam->getName(), mamam));
    toBank.push_back(mamam);
    persons.insert(std::pair<std::string, Person *>(paul->getName(), paul));
    toBank.push_back(paul);
    persons.insert(std::pair<std::string, Person *>(pierre->getName(), pierre));
    toBank.push_back(pierre);
    persons.insert(std::pair<std::string, Person *>(julie->getName(), julie));
    toBank.push_back(julie);
    persons.insert(std::pair<std::string, Person *>(janne->getName(), janne));
    toBank.push_back(janne);
    persons.insert(std::pair<std::string, Person *>(policier->getName(), policier));
    toBank.push_back(policier);
    persons.insert(std::pair<std::string, Person *>(voleur->getName(), voleur));
    toBank.push_back(voleur);

    gauche = new Bank(RIVEGAUCHE, toBank);
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
    Container *containers[2];
    auto it = persons.find(person);
    if (it != persons.end()) {

        Person *p = it->second;

        containers[debark ? 1 : 0] = booatpositionisleft ? gauche : droite;

        containers[debark ? 0 : 1] = boat;
       if(containers[0]->removeMember(p)) {
           containers[1]->addMember(p);
       } else {
           std::cout << NOPERSONINSID << containers[0]->getName()<< std::endl;
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

