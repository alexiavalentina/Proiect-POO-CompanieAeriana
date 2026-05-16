#ifndef EXCEPTII_H
#define EXCEPTII_H

#include <exception>
#include <string>

class ExceptieCompanie : public std::exception {
protected:
    std::string mesaj;
public:
    explicit ExceptieCompanie(const std::string& msg);
    const char* what() const noexcept override;
};

class ExceptieCapacitate : public ExceptieCompanie {
public:
    explicit ExceptieCapacitate(const std::string& msg);
};

#endif