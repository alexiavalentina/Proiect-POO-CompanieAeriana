#include "Zbor.h"
#include <iostream>
#include <algorithm>
using namespace std;

Zbor::Zbor(const string& dest, const string& ind, int capacitate)
    : capacitateMax(capacitate), destinatie(dest), indicativ(ind) {
}

void Zbor::adaugaBilet(const Bilet& bilet) {
    if (listaBilete.size() >= static_cast<size_t>(capacitateMax)) {
        throw ExceptieCapacitate("Nu mai sunt locuri pe zborul " + indicativ + "!");
    }
    listaBilete.push_back(bilet);
}

void Zbor::afisareZbor() const {
    cout << "\n====== ZBOR " << indicativ << " SPRE " << destinatie << " ======\n";
    cout << "Numar de bilete vandute: " << listaBilete.size() << "\n\n";
    vector<Bilet> copieBilete = listaBilete;
    sort(copieBilete.begin(), copieBilete.end(), [](const Bilet& a, const Bilet& b) {
        return a.getPret() > b.getPret();
    });
    for (const Bilet& b : copieBilete)
        cout << b << "\n";
}