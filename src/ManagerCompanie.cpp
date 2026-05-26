#include "ManagerCompanie.h"
#include <iostream>
using namespace std;

ManagerCompanie* ManagerCompanie::instanta = nullptr;

ManagerCompanie::ManagerCompanie() : numeCompanie("Air-OOP Romania") {
}

ManagerCompanie* ManagerCompanie::getInstanta() {
    if (instanta == nullptr)
        instanta = new ManagerCompanie();
    return instanta;
}

void ManagerCompanie::anuntaIncepereaZilei() const {
    cout << ">>> Managerul companiei " << numeCompanie << " declara sistemul deschis! <<<\n\n";
}