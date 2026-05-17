#include <iostream>
#include <vector>
#include <list>
#include "Bilet.h"
#include "Zbor.h"
#include "Pilot.h"
#include "InsotitorZbor.h"
#include "Exceptii.h"
#include "ManagerCompanie.h" // Includem Singleton-ul
#include "AngajatFactory.h"   // Includem Fabrica
#include "Registru.h"

int main() {
    ManagerCompanie* manager = ManagerCompanie::getInstanta();
    manager->anuntaIncepereaZilei();
    std::vector<Angajat*> echipajZbor;
    echipajZbor.push_back(AngajatFactory::creazaAngajat("Pilot", "Marian Popescu", 101, "Boeing 737"));
    echipajZbor.push_back(AngajatFactory::creazaAngajat("Insotitor", "Ioana Radu", 202, "Business Class"));
    for (Angajat* angajat : echipajZbor) {
        Pilot* posibilPilot = dynamic_cast<Pilot*>(angajat);
        if (posibilPilot != nullptr)
            posibilPilot->anuntaDecolare();
    }
    Zbor zborParis("Paris", "RO-301", 1);
    Bilet bilet1("Popescu Ion", "Economic", 850.0, 14);
    Bilet bilet2("Ionescu Maria", "Business", 2100.0, 1);
    Zbor zborLondra("Londra", "RO-404", 150);
    Bilet bilet3("Gheorghe Vasile", "Economic", 400.0, 30);
    zborLondra.adaugaBilet(bilet3);
    std::list<Zbor> zborurileZilei;
    zborurileZilei.push_back(zborParis);
    zborurileZilei.push_back(zborLondra);
    std::cout << "\n--- TOATE ZBORURILE COMPANIEI DE AZI ---\n";
    for (const Zbor& z : zborurileZilei)
        z.afisareZbor();
    std::cout << "\nStatistica: Compania a emis in total "
              << Bilet::getNumarTotalBileteEmise() << " bilete.\n";
    Registru<Bilet> registruBilete;
    registruBilete.adauga(bilet1);
    registruBilete.adauga(bilet3);
    std::cout << "Registru de Bilete:\n";
    registruBilete.afiseazaTot();
    Registru<std::string> registruNotificari;
    registruNotificari.adauga("Notificare 1: Zborul spre Paris are intarziere.");
    registruNotificari.adauga("Notificare 2: Pilotul Popescu a intrat in tura.");
    std::cout << "\nRegistru de Notificari:\n";
    registruNotificari.afiseazaTot();
    try {
        std::cout << "Incercam sa adaugam primul bilet...\n";
        zborParis.adaugaBilet(bilet1);
        std::cout << "Bilet 1 adaugat cu succes!\n";
        std::cout << "Incercam sa adaugam al doilea bilet...\n";
        zborParis.adaugaBilet(bilet2);
        std::cout << "Acest text nu va fi afisat niciodata.\n";
    }
    catch (const ExceptieCompanie& e) {
        std::cerr << "EROARE PRINSA: " << e.what() << "\n";
    }
    for (Angajat* angajat : echipajZbor)
        delete angajat;
    echipajZbor.clear();

    return 0;
}