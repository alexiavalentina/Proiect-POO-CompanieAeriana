#ifndef ANGAJATFACTORY_H
#define ANGAJATFACTORY_H

#include "Angajat.h"
#include "Pilot.h"
#include "InsotitorZbor.h"
#include <string>

class AngajatFactory {
public:
    static Angajat* creazaAngajat(const std::string& tip, const std::string& nume,
        int id, const std::string& parametruExtra);
};

#endif