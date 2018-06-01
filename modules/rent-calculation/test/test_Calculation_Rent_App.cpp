// Copyright 2018 Lenkin Slava

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/Calculation_Rent_App.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class Calculation_Rent_App_Test : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    Calculation_Rent_App app_;
    string output_;
};

TEST_F(Calculation_Rent_App_Test, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a rent calculator application\\..*");
}

TEST_F(Calculation_Rent_App_Test, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"123.45", "4"};

    Act(args);

    Assert("ERROR: Should be 4 arguments\\..*");
}

TEST_F(Calculation_Rent_App_Test, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"1", "three", "2", "-aph"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(Calculation_Rent_App_Test, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = {"1", "2", "3", "trash"};

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(Calculation_Rent_App_Test, Can_Calc_Rent_Accum_Year_Postnum_Hard_Rate) {
    vector<string> args = {"50", "2", "3", "-aph"};

    Act(args);

    Assert("Accumulated yearly postnumerando hard rate = 250");
}

TEST_F(Calculation_Rent_App_Test, Can_Calc_Rent_Accum_Year_Postnum_Easy_Rate) {
    vector<string> args = {"150.4", "20", "10", "-ape"};

    Act(args);

    Assert("Accumulated yearly postnumerando easy rate = 288768");
}

TEST_F(Calculation_Rent_App_Test, Can_Calc_Rent_Accum_Year_Prenum_Hard_Rate) {
    vector<string> args = {"100", "5", "2", "-aprh"};

    Act(args);

    Assert("Accumulated yearly prenumerando hard rate = 36300");
}

TEST_F(Calculation_Rent_App_Test, Can_Calc_Rent_Accum_Year_Prenum_Easy_Rate) {
    vector<string> args = {"1200", "10", "5", "-apre"};

    Act(args);

    Assert("Accumulated yearly prenumerando easy rate = 342000");
}

TEST_F(Calculation_Rent_App_Test, Can_Calc_Rent_Modern_Year_Postnum_Hard_Rate) {
    vector<string> args = {"80", "1", "4", "-mph"};

    Act(args);

    Assert("Modern yearly postnumerando hard rate = 16");
}
TEST_F(Calculation_Rent_App_Test, Can_Calc_Rent_Modern_Year_Postnum_Easy_Rate) {
    vector<string> args = {"10000", "2", "10", "-mpe"};

    Act(args);

    Assert("Modern yearly postnumerando easy rate = 1385.28");
}
TEST_F(Calculation_Rent_App_Test, Can_Calc_Rent_Modern_Year_Prenum_Hard_Rate) {
    vector<string> args = {"50", "200", "3", "-mprh"};

    Act(args);

    Assert("Modern yearly prenumerando hard rate = 66.6667");
}
TEST_F(Calculation_Rent_App_Test, Can_Calc_Rent_Modern_Year_Prenum_Easy_Rate) {
    vector<string> args = {"50", "2", "30000", "-mpre"};

    Act(args);

    Assert("Modern yearly prenumerando easy rate = 50");
}
