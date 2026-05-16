#include "InsotitorZbor.h"

InsotitorZbor::InsotitorZbor(const std::string& nume, int id, const std::string& sector)
    : Angajat(nume, id) {
    this->sectorRepartizat = sector;
}

void InsotitorZbor::afisareRol() const {
    std::cout << "[Insotitor Zbor] " << nume << " (ID: " << idAngajat 
              << ") se ocupa de sectorul " << sectorRepartizat << ".\n";
}