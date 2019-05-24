/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : AbstactContainer.h
 Auteur(s)   : Gabrielli Alexandre , Povoà Tiago
 Date        : 22.05.2019

 But         : Déclaration des méthode de la classe AbstactContainer. Cette classe abstraite
 stoque une list de personne et permet de vérifier des régles elle demande à ces sous-class
 d'offrir un affichage avec la méthode toString.
 -----------------------------------------------------------------------------------
*/

#ifndef POO2_LABO4_CONTAINER_H
#define POO2_LABO4_CONTAINER_H

#include <string>
#include <list>
#include <memory>
#include <ostream>
#include "../Person/Person.h"

class AbstractContainer {

public:

    /**
     * Constructeur de la classe Container
     * @param name nom du container
     */
    explicit AbstractContainer(const std::string &name);

    /**
     * verifie si l'état actuel correspond au regle
     */
    virtual bool verifie();

    /**
     * retire une personne du containeur
     * @param person
     * @return si la personne était dans le containeur
     */
    bool removeMember(const Person *person);

    /**
     * ajoute une personne au containeur
     * @param person a ajouter
     */
    void addMember(Person *person);

    /**
     * Methode permettant de récupérer la liste de person
     * @return liste de personne
     */
    const std::list<Person *> &getPersons() const;

    /**
     * Methode permettant de récupérer le nom du container
     * @return nom du container
     */
    const std::string &getName() const;

    friend std::ostream &operator<<(std::ostream &os, const AbstractContainer &container);

protected:
    std::list<Person *> persons;

    virtual std::string toString() const = 0;

    std::string name;
};


#endif //POO2_LABO4_CONTAINER_H
