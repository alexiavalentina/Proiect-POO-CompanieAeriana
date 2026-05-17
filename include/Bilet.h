#ifndef BILET_H
#define BILET_H

#include <string>
#include <iostream>

class Bilet {
private:
    int idBilet;
    static int contorBilete;
    std::string numePasager;
    std::string clasaZbor;
    double pret;
    int numarLoc;

public:
    Bilet();
    Bilet(const std::string& nume, const std::string& clasaZ, double pret, int loc);
    Bilet(const Bilet& other);
    static int getNumarTotalBileteEmise();
    Bilet& operator=(const Bilet& other);
    ~Bilet();
    double getPret() const;
    void setPret(double pretNou);
    bool operator==(const Bilet& other) const;
    friend std::ostream& operator<<(std::ostream& out, const Bilet& b);
    friend std::istream& operator>>(std::istream& in, Bilet& b);
};

Bilet operator+(const Bilet& b, double taxa);

#endif