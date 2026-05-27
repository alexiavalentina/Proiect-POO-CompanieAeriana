#include "Bilet.h"
using namespace std;

int Bilet::contorBilete = 0;

Bilet::Bilet() : idBilet(++contorBilete), numePasager("Necunoscut"), clasaZbor("Economic"), pret(0.0), numarLoc(0) {
}

Bilet::Bilet(const string& nume, const string& clasaZ, double pret, int loc)
    : idBilet(++contorBilete), numePasager(nume), clasaZbor(clasaZ), pret(pret), numarLoc(loc) {
}

Bilet::Bilet(const Bilet& other)
    : idBilet(++contorBilete), numePasager(other.numePasager), clasaZbor(other.clasaZbor), pret(other.pret), numarLoc(other.numarLoc) {
}

Bilet& Bilet::operator=(const Bilet& other) {
    if (this != &other) {
        this->idBilet = other.idBilet;
        this->numePasager = other.numePasager;
        this->clasaZbor = other.clasaZbor;
        this->pret = other.pret;
        this->numarLoc = other.numarLoc;
    }
    return *this;
}

Bilet::~Bilet() {
}

double Bilet::getPret() const { return pret; }
void Bilet::setPret(double pretNou) { this->pret = pretNou; }

bool Bilet::operator==(const Bilet& other) const {
    return this->numarLoc == other.numarLoc;
}

ostream& operator<<(ostream& out, const Bilet& b) {
    out << "[ID: " << b.idBilet << "] " << "Pasager: " << b.numePasager << " | Clasa: " << b.clasaZbor
        << " | Loc: " << b.numarLoc << " | Pret: " << b.pret << " RON";
    return out;
}

istream& operator>>(istream& in, Bilet& b) {
    cout << "Nume pasager: ";
    in >> b.numePasager;
    cout << "Clasa zbor: ";
    in >> b.clasaZbor;
    cout << "Pret: ";
    in >> b.pret;
    cout << "Numar loc: ";
    in >> b.numarLoc;
    return in;
}

Bilet operator+(const Bilet& b, double taxa) {
    Bilet biletNou = b;
    biletNou.setPret(b.getPret() + taxa);
    return biletNou;
}

int Bilet::getNumarTotalBileteEmise() {
    return contorBilete;
}