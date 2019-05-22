//
// Created by chadanlo on 2019-05-16.
//

#ifndef POO2_LABO4_CONTAINER_H
#define POO2_LABO4_CONTAINER_H

#include <string>
#include <list>
#include <memory>
#include <ostream>
#include "../Person/Person.h"

class Container {

private:

protected:
    std::list<std::weak_ptr<Person>> persons;

    virtual std::string toString() const = 0;

    std::string name;
public:
    explicit Container(const std::string& name);

    virtual bool verifie();

    void removeMember(std::weak_ptr<Person>& person);

    friend std::ostream &operator<<(std::ostream &os, const Container &container);

    bool addMember(std::weak_ptr<Person>&);

    const std::list<std::weak_ptr<Person>> &getPersons() const;
};


#endif //POO2_LABO4_CONTAINER_H
