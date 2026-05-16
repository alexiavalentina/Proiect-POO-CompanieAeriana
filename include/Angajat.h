#ifndef ANGAJAT_H
#define ANGAJAT_H

#include <string>
#include <iostream>

class Angajat {
protected:
    std::string nume;
    int idAngajat;

public:
    Angajat(const std::string& nume, int id);
    virtual ~Angajat();
    virtual void afisareRol() const = 0;
};

#endif