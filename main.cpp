#include <iostream>
#include <vector>
#include <list>
#include "Bilet.h"
#include "Zbor.h"
#include "Pilot.h"
#include "InsotitorZbor.h"
#include "Exceptii.h"
#include "Registru.h"

int main() {
    std::cout << "--- Sistem Gestiune Companie Aeriana ---\n\n";
    Pilot pilot1("Marian Popescu", 101, "Boeing 737", 5200);
    InsotitorZbor insotitor1("Ioana Radu", 202, "Business Class");
    std::vector<Angajat*> echipajZbor;
    echipajZbor.push_back(&pilot1);
    echipajZbor.push_back(&insotitor1);
    std::cout << "--- BAREM: Downcast ---\n";
    for (Angajat* angajat : echipajZbor) {
        Pilot* posibilPilot = dynamic_cast<Pilot*>(angajat);
        if (posibilPilot != nullptr) {
            posibilPilot->anuntaDecolare();
        }
    }
    std::cout << "-----------------------\n\n";
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
    for (const Zbor& z : zborurileZilei) {
        z.afisareZbor();
    }
    std::cout << "\nStatistica: Compania a emis in total "
              << Bilet::getNumarTotalBileteEmise() << " bilete.\n";
    std::cout << "--- BAREM: Tratarea Exceptiilor ---\n";
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

    return 0;
}