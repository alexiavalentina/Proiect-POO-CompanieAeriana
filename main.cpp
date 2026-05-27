#include <iostream>
#include <vector>
#include <list>
#include "Bilet.h"
#include "Zbor.h"
#include "Pilot.h"
#include "InsotitorZbor.h"
#include "Exceptii.h"
#include "ManagerCompanie.h"
#include "AngajatFactory.h"
#include "Registru.h"
using namespace std;

int main()
{
    const ManagerCompanie* manager = ManagerCompanie::getInstanta();
    manager->anuntaIncepereaZilei();
    vector<Angajat*> echipajZbor;
    echipajZbor.push_back(AngajatFactory::creazaAngajat("Pilot", "Marian Popescu", 101, "Boeing 737"));
    echipajZbor.push_back(AngajatFactory::creazaAngajat("Insotitor", "Ioana Radu", 202, "Business Class"));
    for (const Angajat* angajat : echipajZbor) {
        const Pilot* posibilPilot = dynamic_cast<const Pilot*>(angajat);
        if (posibilPilot != nullptr)
            posibilPilot->anuntaDecolare();
        const InsotitorZbor* posibilInsotitor = dynamic_cast<const InsotitorZbor*>(angajat);
        if (posibilInsotitor)
            posibilInsotitor->afisareRol();
    }
    Zbor zborParis("Paris", "RO-301", 1);
    Bilet bilet1("Popescu Ion", "Economic", 850.0, 14);
    Bilet bilet2("Ionescu Maria", "Business", 2100.0, 1);
    Zbor zborLondra("Londra", "RO-404", 150);
    Bilet bilet3("Gheorghe Vasile", "Economic", 400.0, 30);
    zborLondra.adaugaBilet(bilet3);
    list<Zbor> zborurileZilei;
    zborurileZilei.push_back(zborParis);
    zborurileZilei.push_back(zborLondra);
    cout << "\n--- TOATE ZBORURILE COMPANIEI DE AZI ---\n";
    for (const Zbor& z : zborurileZilei)
        z.afisareZbor();
    cout << "\nStatistica: Compania a emis in total "
         << Bilet::getNumarTotalBileteEmise() << " bilete.\n";
    Registru<Bilet> registruBilete;
    registruBilete.adauga(bilet1);
    registruBilete.adauga(bilet3);
    cout << "Registru de Bilete:\n";
    registruBilete.afiseazaTot();
    Registru <string> registruNotificari;
    registruNotificari.adauga("Notificare 1: Zborul spre Paris are intarziere.");
    registruNotificari.adauga("Notificare 2: Pilotul Popescu a intrat in tura.");
    cout << "\nRegistru de Notificari:\n";
    registruNotificari.afiseazaTot();
    try {
        cout << "Incercam sa adaugam primul bilet...\n";
        zborParis.adaugaBilet(bilet1);
        cout << "Bilet 1 adaugat cu succes!\n";
        cout << "Incercam sa adaugam al doilea bilet...\n";
        zborParis.adaugaBilet(bilet2);
    }
    catch (const ExceptieCompanie& e) {
        cout << "EROARE PRINSA: " << e.what() << "\n";
    }
    cout << "\n=======================================\n";
    cout << "       PORNIRE MENIU INTERACTIV        \n";
    cout << "=======================================\n";
    int optiune = -1;
    Zbor zborMeniu("Bucuresti", "RO-999", 50);
    while (optiune != 0) {
        cout << "\n1. Adauga Bilet in zbor (Citire de la tastatura)\n";
        cout << "2. Afiseaza detaliile zborului\n";
        cout << "3. Afiseaza numar total de bilete emise (Element static)\n";
        cout << "0. Iesire\n";
        cout << "Alegeti optiunea: ";
        cin >> optiune;
        if (optiune == 1) {
            Bilet bNou;
            cin >> bNou;
            try {
                zborMeniu.adaugaBilet(bNou);
                cout << "Bilet adaugat cu succes in zborul RO-999!\n";
            } catch (const ExceptieCompanie& e) {
                cerr << "EROARE LA ADAUGARE: " << e.what() << "\n";
            }
        }
        else if (optiune == 2)
            zborMeniu.afisareZbor();
        else if (optiune == 3)
            cout << "Pana acum, compania a emis: " << Bilet::getNumarTotalBileteEmise() << " bilete.\n";
        else if (optiune == 0)
            cout << "Sistemul se inchide. La revedere!\n";
        else
            cout << "Optiune invalida!\n";
    }
    for (Angajat* angajat : echipajZbor)
        delete angajat;
    echipajZbor.clear();
    ManagerCompanie::distrugeInstanta();

    return 0;
}