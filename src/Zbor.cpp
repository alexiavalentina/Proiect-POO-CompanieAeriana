#include "Zbor.h"
#include <iostream>

Zbor::Zbor(const std::string& dest, const std::string& ind) {
    this->destinatie = dest;
    this->indicativ = ind;
}

void Zbor::adaugaBilet(const Bilet& bilet) {
    listaBilete.push_back(bilet);
}

void Zbor::afisareZbor() const {
    std::cout << "\n====== ZBOR " << indicativ << " SPRE " << destinatie << " ======\n";
    std::cout << "Numar de bilete vandute: " << listaBilete.size() << "\n\n";
    for (const Bilet& b : listaBilete)
        std::cout << b << "\n";
    std::cout << "========================================\n";
}