#include <iostream>
#include "Bilet.h"
#include "Zbor.h"

int main() {
    std::cout << "--- Sistem Gestiune Companie Aeriana ---\n";
    Zbor zborParis("Paris", "RO-301");
    Bilet bilet1("Popescu Ion", "Economic", 850.0, 14);
    Bilet bilet2("Ionescu Maria", "Business", 2100.0, 1);
    Bilet bilet3("Vasile Andrei", "Economic", 850.0, 15);
    zborParis.adaugaBilet(bilet1);
    zborParis.adaugaBilet(bilet2);
    zborParis.adaugaBilet(bilet3);
    zborParis.afisareZbor();

    return 0;
}