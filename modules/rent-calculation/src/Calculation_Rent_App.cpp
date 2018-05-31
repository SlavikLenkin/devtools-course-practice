// Copyright 2018 Lenkin Slava

#include "include/Calculation_Rent.h"
#include "include/Calculation_Rent_App.h"
// #include "Calculation_Rent.h"
// #include "Calculation_Rent_App.h"

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
          "<operation> is one of 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12.\n" +

          "* 1 - postnumerando hard rate\n" +
          "* 2 - postnumerando easy rate\n" +
          "* 3 - prenumerando hard rate\n" +
          "* 4 - prenumerando easy rate\n" +
          "* 5 - modern year postnumerando hard rate\n" +
          "* 6 - modern year postnumerando easy rate\n" +
          "* 7 - modern year prenumerando hard rate\n" +
          "* 8 - modern year prenumerando easy rate\n" +
          "* 9 - postnumerando hard rate\n" +
          "* 10 - postnumerando easy rate\n" +
          "* 11 - prenumerando hard rate\n" +
          "* 12 - prenumerando easy rate\n";
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

// std::string parseOperation(const char* arg) {
//     std::string op;
//     if (strcmp(arg, "roubleToDollar") == 0) {
//         op = "roubleToDollar";
//     } else if (strcmp(arg, "dollarToRouble") == 0) {
//         op = "dollarToRouble";
//     } else if (strcmp(arg, "roubleToEuro") == 0) {
//         op = "roubleToEuro";
//     } else if (strcmp(arg, "euroToRouble") == 0) {
//         op = "euroToRouble";
//     } else if (strcmp(arg, "dollarToEuro") == 0) {
//         op = "dollarToEuro";
//     } else if (strcmp(arg, "euroToDollar") == 0) {
//         op = "euroToDollar";
//     } else {
//         throw std::string("Wrong operation format!");
//     }
//     return op;
// }

int parseOperation(const char* arg) {
    int op;

    if (strcmp(arg, "1") == 0) {
        op = 1;
    } else if (strcmp(arg, "2") == 0) {
        op = 2;
    } else if (strcmp(arg, "3") == 0) {
        op = 3;
    } else if (strcmp(arg, "4") == 0) {
        op = 4;
    } else if (strcmp(arg, "5") == 0) {
        op = 5;
    } else if (strcmp(arg, "6") == 0) {
        op = 6;
    } else if (strcmp(arg, "7") == 0) {
        op = 7;
    } else if (strcmp(arg, "8") == 0) {
        op = 8;
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
        // FIXME: add additional fields in this struct
        args.operation      = parseOperation(argv[4]);
    }
    catch(std::string& str) {
        return str;
    }

    Calculation_Rent calculator(args.amount_payment, args.rent_term,
                            args.interest_rate);

    std::ostringstream stream;
    switch (args.operation) {
     case 1:
        stream << "Postnumerando hard rate = " <<
        calculator.Rent_Accum_Year_postnum_hard_rate() << std::endl;
        break;
     case 2:
        stream << "Postnumerando easy rate = " <<
        calculator.Rent_Accum_Year_postnum_easy_rate() << std::endl;
        break;
     case 3:
        stream << "Prenumerando hard rate = " <<
        calculator.Rent_Accum_Year_prenum_hard_rate() << std::endl;
        break;
     case 4:
        stream << "Prenumerando easy rate = " <<
        calculator.Rent_Accum_Year_prenum_easy_rate() << std::endl;

     case 5:
        stream << "Modern year postnumerando hard rate = " <<
        calculator.Rent_Modern_Year_postnum_hard_rate() << std::endl;
        break;
     case 6:
        stream << "Modern year postnumerando easy rate = " <<
        calculator.Rent_Modern_Year_postnum_easy_rate() << std::endl;
     case 7:
        stream << "Modern year prenumerando hard rate = " <<
        calculator.Rent_Modern_Year_prenum_hard_rate() << std::endl;
        break;
     case 8:
        stream << "Modern year prenumerando easy rate = " <<
        calculator.Rent_Modern_Year_prenum_easy_rate() << std::endl;
        break;
    //  case 5:
    //     stream << "Accum period postnumerando = " <<
    //     calculator.Rent_Accum_Year_postnum_hard_rate() << std::endl;
    //     break;
    //  case 6:
    //     stream << "Postnumerando easy rate = " <<
    //     calculator.Rent_Accum_Year_postnum_easy_rate() << std::endl;
    //     break;
    //  case 11:
    //     stream << "Prenumerando hard rate = " <<
    //     calculator.Rent_Accum_Year_prenum_hard_rate() << std::endl;
    //     break;
    //  case 12:
    //     stream << "Prenumerando easy rate = " <<
    //     calculator.Rent_Accum_Year_prenum_easy_rate() << std::endl;
    }

    message_ = stream.str();

    return message_;
}
