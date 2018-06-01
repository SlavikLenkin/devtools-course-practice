// Copyright 2018 Lenkin Slava

#ifndef MODULES_RENT_CALCULATION_INCLUDE_CALCULATION_RENT_APP_H_
#define MODULES_RENT_CALCULATION_INCLUDE_CALCULATION_RENT_APP_H_

#include <string>

class Calculation_Rent_App {
 public:
    Calculation_Rent_App();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double amount_payment;
        double rent_term;
        double interest_rate;
        std::string operation;
    } Arguments;
};

#endif  // MODULES_RENT_CALCULATION_INCLUDE_CALCULATION_RENT_APP_H_
