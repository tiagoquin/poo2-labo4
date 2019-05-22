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

protected:
    std::list<Person*> persons;

    virtual std::string toString() const = 0;

    std::string name;
public:
    explicit AbstractContainer(const std::string& name);

    virtual bool verifie();

    bool removeMember(const Person* person);

    friend std::ostream &operator<<(std::ostream &os, const AbstractContainer &container);

    bool addMember( Person* person);

    const std::list<Person*> &getPersons() const;

    const std::string &getName() const;
};


#endif //POO2_LABO4_CONTAINER_H
