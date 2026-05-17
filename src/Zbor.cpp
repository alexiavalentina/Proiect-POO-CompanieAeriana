#include "Zbor.h"
#include <iostream>
#include <algorithm>

Zbor::Zbor(const std::string& dest, const std::string& ind, int capacitate) {
    this->destinatie = dest;
    this->indicativ = ind;
    this->capacitateMax = capacitate;
}

void Zbor::adaugaBilet(const Bilet& bilet) {
    if (listaBilete.size() >= capacitateMax) {
        throw ExceptieCapacitate("Nu mai sunt locuri pe zborul " + indicativ + "!");
    }
    listaBilete.push_back(bilet);
}

void Zbor::afisareZbor() const {
    std::cout << "\n====== ZBOR " << indicativ << " SPRE " << destinatie << " ======\n";
    std::cout << "Numar de bilete vandute: " << listaBilete.size() << "\n\n";
    std::vector<Bilet> copieBilete = listaBilete;
    std::sort(copieBilete.begin(), copieBilete.end(), [](const Bilet& a, const Bilet& b) {
        return a.getPret() > b.getPret();
    });
    for (const Bilet& b : copieBilete)
        std::cout << b << "\n";
    std::cout << "========================================\n";
}