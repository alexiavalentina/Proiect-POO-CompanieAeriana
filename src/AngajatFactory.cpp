#include "AngajatFactory.h"
using namespace std;

Angajat* AngajatFactory::creazaAngajat(const string& tip, const string& nume, int id, const string& parametruExtra) {
    if (tip == "Pilot")
        return new Pilot(nume, id, parametruExtra, 1000);
    else if (tip == "Insotitor")
        return new InsotitorZbor(nume, id, parametruExtra);
    return nullptr;
}