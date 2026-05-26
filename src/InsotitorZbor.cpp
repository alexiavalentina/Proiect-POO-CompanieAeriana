#include "InsotitorZbor.h"
#include <iostream>
using namespace std;

InsotitorZbor::InsotitorZbor(const string& nume, int id, const string& sector)
    : Angajat(nume, id), sectorRepartizat(sector) {
}

void InsotitorZbor::afisareRol() const {
    cout << "[Insotitor Zbor] " << nume << " (ID: " << idAngajat
         << ") se ocupa de sectorul " << sectorRepartizat << ".\n";
}