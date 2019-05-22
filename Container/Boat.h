//
// Created by chadanlo on 2019-05-16.
//

#ifndef POO2_LABO4_BOAT_H
#define POO2_LABO4_BOAT_H


#include <ostream>
#include "Container.h"

#define MAXBOATCAPACITY 2
class Boat : public Container {


public:

    bool verifie() override;

    explicit Boat(const std::string& string);

    std::string toString() const override;

    bool hasDriver();

    friend std::ostream &operator<<(std::ostream &os, const Boat &boat);

};


#endif //POO2_LABO4_BOAT_H
