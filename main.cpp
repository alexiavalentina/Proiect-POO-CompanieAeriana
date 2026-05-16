#include <iostream>
#include <vector>
#include "Bilet.h"
#include "Zbor.h"
#include "Pilot.h"
#include "InsotitorZbor.h"
#include "Exceptii.h"

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
    std::cout << "-----------------------------------\n";

    return 0;
}