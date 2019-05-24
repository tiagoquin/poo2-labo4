/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Controller.h
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2018

 But         : déclaration des méthodes de la classe Controller.
 Cette classe gère le control de notre application, lorsque le 1er tour est relancer
 elle relance automatiquement les tours suivants jusqu'à ce que l'utilisateur décide
 de quitter le programme. Il n'y a pas de condition de victoire
 -----------------------------------------------------------------------------------
*/

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
    typedef std::pair<std::string, Person *> name_person;
private:
    int turn;
    Bank *gauche;
    Bank *droite;
    Boat *boat;
    bool booatpositionisleft;
    std::map<std::string, Person *> persons;


public:
    /**
     * Constructeur de la classe Controller
     * @param persons contients les personnes avec lequel nous désirons jouer
     */
    Controller(std::initializer_list<Person *> persons);

    /**
     * Destructeur de la classe Controller
     */
    ~Controller();

    /**
     * joue un tour et relance un nouveau automatiquement à la fin du tour
     */
    void nextTurn();

private:
    /**
    * embarque une personne
    * @param person nom de la personne a embarquer
    * @return si on a pu réaliser l'action
    */
    bool embark(const std::string &person);

    /**
     * debarque une personne
     * @param person nom de la personne a debarquer
     * @return si on a pu réaliser l'action
     */
    bool debark(const std::string &person);

    /**
     * cette classe fait embarque/debark une persone d'une rive au bateau
     * @param person le nom de la personne que l'on désire
     * @param debark si true on débarque si false on embarque
     * @return  si on a pu réaliser l'action
     */
    bool movePeople(const std::string &person, bool debark);

    /**
     * cette méthode réinitialise le jeu
     */
    void reset();

    /**
     * Methode qui affiche le menu du programme
     */
    void showMenu();

    /**
     * Methode qui affiche le bateau et les deux rives
     */
    void display();
};


#endif //POO2_LABO4_CONTROLLER_H
