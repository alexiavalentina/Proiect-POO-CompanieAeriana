#include "Exceptii.h"
using namespace std;

ExceptieCompanie::ExceptieCompanie(const string& msg) : mesaj(msg) {
}

const char* ExceptieCompanie::what() const noexcept {
    return mesaj.c_str();
}

ExceptieCapacitate::ExceptieCapacitate(const string& msg)
    : ExceptieCompanie("[CAPACITATE DEPASITA] " + msg) {
}