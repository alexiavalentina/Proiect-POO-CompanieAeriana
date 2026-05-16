#ifndef ZBOR_H
#define ZBOR_H

#include <string>
#include <vector>
#include "Bilet.h"
#include "Exceptii.h"

class Zbor {
private:
    int capacitateMax;
    std::string destinatie;
    std::string indicativ;
    std::vector<Bilet> listaBilete;

public:
    Zbor(const std::string& dest, const std::string& ind, int capacitate);
    void adaugaBilet(const Bilet& bilet);
    void afisareZbor() const;
};

#endif