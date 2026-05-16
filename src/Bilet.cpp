#include "Bilet.h"

Bilet::Bilet() {
    numePasager = "Necunoscut";
    clasaZbor = "Economic";
    pret = 0.0;
    numarLoc = 0;
}

Bilet::Bilet(const std::string& nume, const std::string& clasaZ, double pret, int loc) {
    this->numePasager = nume;
    this->clasaZbor = clasaZ;
    this->pret = pret;
    this->numarLoc = loc;
}

void Bilet::afisareDetalii() const {
    std::cout << "--- Detalii Bilet ---\n"
              << "Pasager: " << numePasager << "\n"
              << "Clasa: " << clasaZbor << "\n"
              << "Loc: " << numarLoc << "\n"
              << "Pret: " << pret << " RON\n"
              << "---------------------\n";
}