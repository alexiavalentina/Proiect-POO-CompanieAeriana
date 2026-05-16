#ifndef BILET_H
#define BILET_H

#include <string>
#include <iostream>

class Bilet {
private:
    std::string numePasager;
    std::string clasaZbor;
    double pret;
    int numarLoc;

public:
    Bilet();
    Bilet(const std::string& nume, const std::string& clasaZ, double pret, int loc);
    void afisareDetalii() const;
};

#endif