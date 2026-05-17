#include "Bilet.h"

int Bilet::contorBilete = 0;

Bilet::Bilet() {
    numePasager = "Necunoscut";
    clasaZbor = "Economic";
    pret = 0.0;
    numarLoc = 0;
    contorBilete++;
    this->idBilet = contorBilete;
}

Bilet::Bilet(const std::string& nume, const std::string& clasaZ, double pret, int loc) {
    this->numePasager = nume;
    this->clasaZbor = clasaZ;
    this->pret = pret;
    this->numarLoc = loc;
    contorBilete++;
    this->idBilet = contorBilete;
}

Bilet::Bilet(const Bilet& other) {
    contorBilete++;
    this->idBilet = contorBilete;
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

}

double Bilet::getPret() const { return pret; }
void Bilet::setPret(double pretNou) { this->pret = pretNou; }

bool Bilet::operator==(const Bilet& other) const {
    return this->numarLoc == other.numarLoc;
}

std::ostream& operator<<(std::ostream& out, const Bilet& b) {
    out << "[ID: " << b.idBilet << "] " << "Pasager: " << b.numePasager << " | Clasa: " << b.clasaZbor
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

int Bilet::getNumarTotalBileteEmise() {
    return contorBilete;
}