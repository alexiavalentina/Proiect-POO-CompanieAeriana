#include <iostream>
#include <vector>
#include "Bilet.h"
#include "Zbor.h"
#include "Pilot.h"
#include "InsotitorZbor.h"

int main() {
    std::cout << "--- Sistem Gestiune Companie Aeriana ---\n\n";
    Pilot pilot1("Marian Popescu", 101, "Boeing 737", 5200);
    InsotitorZbor insotitor1("Ioana Radu", 202, "Business Class");
    InsotitorZbor insotitor2("Andrei Vasile", 203, "Economic Class");
    std::vector<Angajat*> echipajZbor;
    echipajZbor.push_back(&pilot1);
    echipajZbor.push_back(&insotitor1);
    echipajZbor.push_back(&insotitor2);
    std::cout << "--- Echipaj Curent ---\n";
    for (Angajat* angajat : echipajZbor)
        angajat->afisareRol();
    std::cout << "----------------------\n\n";
    Zbor zborParis("Paris", "RO-301");
    Bilet bilet1("Popescu Ion", "Economic", 850.0, 14);
    Bilet bilet2("Ionescu Maria", "Business", 2100.0, 1);
    Bilet bilet1CuTaxa = bilet1 + 150.0;
    zborParis.adaugaBilet(bilet1CuTaxa);
    zborParis.adaugaBilet(bilet2);
    zborParis.afisareZbor();

    return 0;
}