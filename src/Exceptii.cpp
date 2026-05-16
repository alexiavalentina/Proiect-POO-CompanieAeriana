#include "Exceptii.h"

ExceptieCompanie::ExceptieCompanie(const std::string& msg) {
    this->mesaj = msg;
}

const char* ExceptieCompanie::what() const noexcept {
    return mesaj.c_str();
}

ExceptieCapacitate::ExceptieCapacitate(const std::string& msg)
    : ExceptieCompanie("[CAPACITATE DEPASITA] " + msg) {
}