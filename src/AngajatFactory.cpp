#include "AngajatFactory.h"

Angajat* AngajatFactory::creazaAngajat(const std::string& tip, const std::string& nume, int id, const std::string& parametruExtra) {
    if (tip == "Pilot")
        return new Pilot(nume, id, parametruExtra, 1000);
    else if (tip == "Insotitor")
        return new InsotitorZbor(nume, id, parametruExtra);
    return nullptr;
}