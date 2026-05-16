#ifndef INSOTITORZBOR_H
#define INSOTITORZBOR_H

#include "Angajat.h"

class InsotitorZbor : public Angajat {
private:
    std::string sectorRepartizat;

public:
    InsotitorZbor(const std::string& nume, int id, const std::string& sector);

    void afisareRol() const override;
};

#endif