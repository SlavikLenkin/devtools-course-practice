// Copyright 2018 Lenkin Slava

#include "include/Calculation_Rent.h"
#include "include/Calculation_Rent_App.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

Calculation_Rent_App::Calculation_Rent_App() : message_("") {}

void Calculation_Rent_App::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a rent calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <amount_payment> <rent_term> " +
          "<interest_rate> <operation>\n\n" +

          "Where all arguments are double-precision positive numbers, and " +
          "<operation> is one of -aph, -ape, -aprh, -apre, -mph, -mpe, " +
          "-mprh, -mpre.\n" +

          "* -aph - accumulated yearly postnumerando hard rate\n" +
          "* -ape - accumulated yearly postnumerando easy rate\n" +
          "* -aprh - accumulated yearly prenumerando hard rate\n" +
          "* -apre - accumulated yearly prenumerando easy rate\n" +
          "* -mph - modern yearly postnumerando hard rate\n" +
          "* -mpe - modern yearly postnumerando easy rate\n" +
          "* -mprh - modern yearly prenumerando hard rate\n" +
          "* -mpre - modern yearly prenumerando easy rate\n";
}

bool Calculation_Rent_App::validateNumberOfArguments(int argc,
    const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 5) {
        help(argv[0], "ERROR: Should be 4 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string parseOperation(const char* arg) {
    std::string op;

    if (strcmp(arg, "-aph") == 0) {
        op = "-aph";
    } else if (strcmp(arg, "-ape") == 0) {
        op = "-ape";
    } else if (strcmp(arg, "-aprh") == 0) {
        op = "-aprh";
    } else if (strcmp(arg, "-apre") == 0) {
        op = "-apre";
    } else if (strcmp(arg, "-mph") == 0) {
        op = "-mph";
    } else if (strcmp(arg, "-mpe") == 0) {
        op = "-mpe";
    } else if (strcmp(arg, "-mprh") == 0) {
        op = "-mprh";
    } else if (strcmp(arg, "-mpre") == 0) {
        op = "-mpre";
    } else {
        throw std::string("Wrong operation format!");
    }

    return op;
}

std::string Calculation_Rent_App::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.amount_payment = parseDouble(argv[1]);
        args.rent_term      = parseDouble(argv[2]);
        args.interest_rate  = parseDouble(argv[3]);
        args.operation      = parseOperation(argv[4]);
    }
    catch(std::string& str) {
        return str;
    }

    Calculation_Rent calculator(args.amount_payment, args.rent_term,
                                args.interest_rate);
    std::ostringstream stream;

    if (args.operation == "-aph") {
        stream << "Accumulated yearly postnumerando hard rate = " <<
        calculator.Rent_Accum_Year_postnum_hard_rate() << std::endl;
    } else if (args.operation == "-ape") {
        stream << "Accumulated yearly postnumerando easy rate = " <<
        calculator.Rent_Accum_Year_postnum_easy_rate() << std::endl;
    } else if (args.operation == "-aprh") {
        stream << "Accumulated yearly prenumerando hard rate = " <<
        calculator.Rent_Accum_Year_prenum_hard_rate() << std::endl;
    } else if (args.operation == "-apre") {
        stream << "Accumulated yearly prenumerando easy rate = " <<
        calculator.Rent_Accum_Year_prenum_easy_rate() << std::endl;
    } else if (args.operation == "-mph") {
        stream << "Modern yearly postnumerando hard rate = " <<
        calculator.Rent_Modern_Year_postnum_hard_rate() << std::endl;
    } else if (args.operation == "-mpe") {
        stream << "Modern yearly postnumerando easy rate = " <<
        calculator.Rent_Modern_Year_postnum_easy_rate() << std::endl;
    } else if (args.operation == "-mprh") {
        stream << "Modern yearly prenumerando hard rate = " <<
        calculator.Rent_Modern_Year_prenum_hard_rate() << std::endl;
    } else if (args.operation == "-mpre") {
        stream << "Modern yearly prenumerando easy rate = " <<
        calculator.Rent_Modern_Year_prenum_easy_rate() << std::endl;
    }

    message_ = stream.str();

    return message_;
}
