#include "Pilot.h"
#include <iostream>
using namespace std;

Pilot::Pilot(const string& nume, int id, const string& avion, int ore)
    : Angajat(nume, id), tipAvion(avion), oreZbor(ore) {
}

void Pilot::afisareRol() const {
    cout << "[Pilot] " << nume << " (ID: " << idAngajat
         << ") zboara pe " << tipAvion << " si are " << oreZbor << " ore de zbor.\n";
}

void Pilot::anuntaDecolare() const {
    cout << ">>> Pilotul " << nume << " anunta: Pregatiti-va de decolare!\n";
}