#include "Pilot.h"

Pilot::Pilot(const std::string& nume, int id, const std::string& avion, int ore)
    : Angajat(nume, id) {
    this->tipAvion = avion;
    this->oreZbor = ore;
}

void Pilot::afisareRol() const {
    std::cout << "[Pilot] " << nume << " (ID: " << idAngajat 
              << ") zboara pe " << tipAvion << " si are " << oreZbor << " ore de zbor.\n";
}