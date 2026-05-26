#ifndef MANAGERCOMPANIE_H
#define MANAGERCOMPANIE_H

#include <iostream>
#include <string>

class ManagerCompanie {
private:
    static ManagerCompanie* instanta;
    std::string numeCompanie;
    ManagerCompanie();

public:
    static ManagerCompanie* getInstanta();
    ManagerCompanie(const ManagerCompanie&) = delete;
    ManagerCompanie& operator=(const ManagerCompanie&) = delete;
    void anuntaIncepereaZilei() const;
    static void distrugeInstanta();
};

#endif