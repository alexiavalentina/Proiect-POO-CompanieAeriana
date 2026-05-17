#ifndef REGISTRU_H
#define REGISTRU_H

#include <iostream>
#include <vector>

template <typename T>

class Registru {
private:
    std::vector<T> elemente;

public:
    void adauga(const T& element) {
        elemente.push_back(element);
    }
    void afiseazaTot() const {
        std::cout << "=== CONTINUT REGISTRU ===\n";
        for (const T& el : elemente)
            std::cout << el << "\n";
        std::cout << "=========================\n";
    }
};

#endif