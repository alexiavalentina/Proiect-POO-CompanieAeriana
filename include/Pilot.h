#ifndef PILOT_H
#define PILOT_H

#include "Angajat.h"

class Pilot : public Angajat {
private:
    std::string tipAvion;
    int oreZbor;

public:
    Pilot(const std::string& nume, int id, const std::string& avion, int ore);
    void afisareRol() const override;
    void anuntaDecolare() const;
};

#endif