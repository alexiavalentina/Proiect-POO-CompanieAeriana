#ifndef ZBOR_H
#define ZBOR_H

#include <string>
#include <vector>
#include "Bilet.h"

class Zbor {
private:
    std::string destinatie;
    std::string indicativ;
    std::vector<Bilet> listaBilete;

public:
    Zbor(const std::string& dest, const std::string& ind);
    void adaugaBilet(const Bilet& bilet);
    void afisareZbor() const;
};

#endif