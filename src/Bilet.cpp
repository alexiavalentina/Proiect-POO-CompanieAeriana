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

Bilet::Bilet(const Bilet& other) {
    this->numePasager = other.numePasager;
    this->clasaZbor = other.clasaZbor;
    this->pret = other.pret;
    this->numarLoc = other.numarLoc;
}

Bilet& Bilet::operator=(const Bilet& other) {
    if (this != &other) {
        this->numePasager = other.numePasager;
        this->clasaZbor = other.clasaZbor;
        this->pret = other.pret;
        this->numarLoc = other.numarLoc;
    }
    return *this;
}

Bilet::~Bilet() {
    // std::cout << "Bilet distrus!\n"; (opțional, doar pentru test)
}

double Bilet::getPret() const { return pret; }
void Bilet::setPret(double pretNou) { this->pret = pretNou; }

bool Bilet::operator==(const Bilet& other) const {
    return this->numarLoc == other.numarLoc;
}

std::ostream& operator<<(std::ostream& out, const Bilet& b) {
    out << "Pasager: " << b.numePasager << " | Clasa: " << b.clasaZbor
        << " | Loc: " << b.numarLoc << " | Pret: " << b.pret << " RON";
    return out;
}

std::istream& operator>>(std::istream& in, Bilet& b) {
    std::cout << "Nume pasager: ";
    in >> b.numePasager;
    std::cout << "Clasa zbor: ";
    in >> b.clasaZbor;
    std::cout << "Pret: ";
    in >> b.pret;
    std::cout << "Numar loc: ";
    in >> b.numarLoc;
    return in;
}

Bilet operator+(const Bilet& b, double taxa) {
    Bilet biletNou = b;
    biletNou.setPret(b.getPret() + taxa);
    return biletNou;
}