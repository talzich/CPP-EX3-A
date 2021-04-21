//
// AUTHOR: Tal Zichlinsky
// This is a test file made to test NumberWithUnits class and it's method

#include <iostream>
#include <fstream>

#include "doctest.h"
#include "NumberWithUnits.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("Construct before read"){

    CHECK_THROWS( NumberWithUnits km1(1, "km") );
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    CHECK_NOTHROW( NumberWithUnits km1(1, "km") );
}
NumberWithUnits *km1;
NumberWithUnits *m1;
NumberWithUnits *cm1;
NumberWithUnits *ton1;
NumberWithUnits *kg1;
NumberWithUnits *g1;
NumberWithUnits *hour1;
NumberWithUnits *min1;
NumberWithUnits *sec1;
NumberWithUnits *USD1;
NumberWithUnits *ILS1;

TEST_CASE("Initialize"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    km1 = new NumberWithUnits(1, "km");
    m1 = new NumberWithUnits(1, "m");
    cm1 = new NumberWithUnits(1, "cm");
    ton1 = new NumberWithUnits(1, "ton");
    kg1 = new NumberWithUnits(1, "kg");
    g1 = new NumberWithUnits(1, "g");
    hour1 = new NumberWithUnits(1, "hour");
    min1 = new NumberWithUnits(1, "min");
    sec1 = new NumberWithUnits(1, "sec");
    USD1 = new NumberWithUnits(1, "USD");
    ILS1 = new NumberWithUnits(1, "ILS");
}

TEST_CASE("Valid == Operator"){

    // Operator ==
    CHECK(*km1 == NumberWithUnits(1, "km"));
    CHECK(*m1 == NumberWithUnits(1, "m"));
    CHECK(*cm1 == NumberWithUnits(1, "cm"));
    CHECK(*ton1 == NumberWithUnits(1, "ton"));
    CHECK(*kg1 == NumberWithUnits(1, "kg"));
    CHECK(*g1 == NumberWithUnits(1, "g"));
    CHECK(*hour1 == NumberWithUnits(1, "hour"));
    CHECK(*min1 == NumberWithUnits(1, "min"));
    CHECK(*sec1 == NumberWithUnits(1, "sec"));
    CHECK(*USD1 == NumberWithUnits(1, "USD"));
    CHECK(*ILS1 == NumberWithUnits(1, "ILS"));

    CHECK(*km1 == NumberWithUnits(1000, "m"));
    CHECK(*m1 == NumberWithUnits(100, "cm"));
    CHECK(*ton1 == NumberWithUnits(1000, "kg"));
    CHECK(*kg1 == NumberWithUnits(1000, "g"));
    CHECK(*hour1 == NumberWithUnits(60, "min"));
    CHECK(*min1 == NumberWithUnits(60, "sec"));
    CHECK(*USD1 == NumberWithUnits(3.33, "ILS"));

    CHECK(*km1 == NumberWithUnits(100000, "cm"));
    CHECK(*ton1 == NumberWithUnits(1000000, "g"));
    CHECK(*hour1 == NumberWithUnits(3600, "sec"));

    // Operator <=
    CHECK(*km1 <= NumberWithUnits(1000, "m"));
    CHECK(*km1 <= NumberWithUnits(2000, "m"));
    CHECK(*km1 <= NumberWithUnits(1, "km"));
    CHECK(*km1 <= NumberWithUnits(2, "km"));

    CHECK(*m1 <= NumberWithUnits(100, "cm"));
    CHECK(*m1 <= NumberWithUnits(1000, "cm"));
    CHECK(*m1 <= NumberWithUnits(1, "m"));
    CHECK(*m1 <= NumberWithUnits(2, "cm"));

    CHECK(*ton1 <= NumberWithUnits(1000, "kg"));
    CHECK(*ton1 <= NumberWithUnits(2000, "kg"));
    CHECK(*ton1 <= NumberWithUnits(1, "ton"));
    CHECK(*ton1 <= NumberWithUnits(2, "ton"));

    CHECK(*kg1 <= NumberWithUnits(1000, "g"));
    CHECK(*kg1 <= NumberWithUnits(2000, "g"));
    CHECK(*kg1 <= NumberWithUnits(1, "kg"));
    CHECK(*kg1 <= NumberWithUnits(2, "kg"));

    CHECK(*hour1 <= NumberWithUnits(60, "min"));
    CHECK(*hour1 <= NumberWithUnits(600, "min"));
    CHECK(*hour1 <= NumberWithUnits(1, "hour"));
    CHECK(*hour1 <= NumberWithUnits(2, "hour"));

    CHECK(*km1 <= NumberWithUnits(100000, "cm"));
    CHECK(*km1 <= NumberWithUnits(1000, "m"));
    CHECK(*km1 <= NumberWithUnits(2000, "m"));
    CHECK(*km1 <= NumberWithUnits(1, "km"));
    CHECK(*km1 <= NumberWithUnits(2, "km"));

    // Operator >=
    CHECK(*km1 >= NumberWithUnits(100, "m"));
    CHECK(*km1 >= NumberWithUnits(200, "m"));
    CHECK(*km1 >= NumberWithUnits(1, "km"));
    CHECK(*km1 >= NumberWithUnits(0.2, "km"));

    CHECK(*m1 >= NumberWithUnits(10, "cm"));
    CHECK(*m1 >= NumberWithUnits(1000, "cm"));
    CHECK(*m1 >= NumberWithUnits(1, "m"));
    CHECK(*m1 >= NumberWithUnits(2, "cm"));

    CHECK(*ton1 >= NumberWithUnits(1000, "kg"));
    CHECK(*ton1 >= NumberWithUnits(2000, "kg"));
    CHECK(*ton1 >= NumberWithUnits(1, "ton"));
    CHECK(*ton1 >= NumberWithUnits(2, "ton"));

    CHECK(*kg1 >= NumberWithUnits(1000, "g"));
    CHECK(*kg1 >= NumberWithUnits(2000, "g"));
    CHECK(*kg1 >= NumberWithUnits(1, "kg"));
    CHECK(*kg1 >= NumberWithUnits(2, "kg"));

    CHECK(*hour1 >= NumberWithUnits(60, "min"));
    CHECK(*hour1 >= NumberWithUnits(600, "min"));
    CHECK(*hour1 >= NumberWithUnits(1, "hour"));
    CHECK(*hour1 >= NumberWithUnits(2, "hour"));

    CHECK(*km1 >= NumberWithUnits(100000, "cm"));
    CHECK(*km1 >= NumberWithUnits(1000, "m"));
    CHECK(*km1 >= NumberWithUnits(2000, "m"));
    CHECK(*km1 >= NumberWithUnits(1, "km"));
    CHECK(*km1 >= NumberWithUnits(2, "km"));

}

TEST_CASE("Invalid Comparison Operator"){
    
    bool b;

    // Operator ==
    CHECK_THROWS(b = *km1 == *kg1);
    CHECK_THROWS(b = *km1 == *hour1);
    CHECK_THROWS(b = *km1 == *USD1);

    CHECK_THROWS(b = *kg1 == *hour1);
    CHECK_THROWS(b = *kg1 == *USD1);

    CHECK_THROWS(b = *USD1 == *hour1);

    // Operator <=
    CHECK_THROWS(b = *km1 <= *kg1);
    CHECK_THROWS(b = *km1 <= *hour1);
    CHECK_THROWS(b = *km1 <= *USD1);

    CHECK_THROWS(b = *kg1 <= *hour1);
    CHECK_THROWS(b = *kg1 <= *USD1);

    CHECK_THROWS(b = *USD1 <= *hour1);

    // Operator >=
    CHECK_THROWS(b = *km1 >= *kg1);
    CHECK_THROWS(b = *km1 >= *hour1);
    CHECK_THROWS(b = *km1 >= *USD1);

    CHECK_THROWS(b = *kg1 >= *hour1);
    CHECK_THROWS(b = *kg1 >= *USD1);

    CHECK_THROWS(b = *USD1 >= *hour1);

}

TEST_CASE("Unary Arithmetic Operators"){

    // Unary minus
    CHECK(-(*km1) == NumberWithUnits(-1, "km"));
    CHECK(-(*m1) == NumberWithUnits(-1, "m"));
    CHECK(-(*cm1) == NumberWithUnits(-1, "cm"));
    CHECK(-(*ton1) == NumberWithUnits(-1, "ton"));
    CHECK(-(*kg1) == NumberWithUnits(-1, "kg"));
    CHECK(-(*g1) == NumberWithUnits(-1, "g"));
    CHECK(-(*hour1) == NumberWithUnits(-1, "hour"));
    CHECK(-(*min1) == NumberWithUnits(-1, "min"));
    CHECK(-(*sec1) == NumberWithUnits(-1, "sec"));
    CHECK(-(*USD1) == NumberWithUnits(-1, "USD"));
    CHECK(-(*ILS1) == NumberWithUnits(-1, "ILS"));

    CHECK(*km1 == -NumberWithUnits(-1, "km"));
    CHECK((*m1) == -NumberWithUnits(-1, "m"));
    CHECK((*cm1) == -NumberWithUnits(-1, "cm"));
    CHECK((*ton1) == -NumberWithUnits(-1, "ton"));
    CHECK((*kg1) == -NumberWithUnits(-1, "kg"));
    CHECK((*g1) == -NumberWithUnits(-1, "g"));
    CHECK((*hour1) == -NumberWithUnits(-1, "hour"));
    CHECK((*min1) == -NumberWithUnits(-1, "min"));
    CHECK((*sec1) == -NumberWithUnits(-1, "sec"));
    CHECK((*USD1) == -NumberWithUnits(-1, "USD"));
    CHECK((*ILS1) == -NumberWithUnits(-1, "ILS"));

    // Unary Plus
    CHECK(+(*km1) == *km1);
    CHECK(+(*m1) == *m1);
    CHECK(+(*cm1) == *cm1);
    CHECK(+(*ton1) == *ton1);
    CHECK(+(*kg1) == *kg1);
    CHECK(+(*g1) == *g1);
    CHECK(+(*hour1) == *hour1);
    CHECK(+(*min1) == *min1);
    CHECK(+(*sec1) == *sec1);
    CHECK(+(*USD1) == *USD1);
    CHECK(+(*ILS1) == *ILS1);
}

TEST_CASE("Invalid Arithmetic Operators"){

    NumberWithUnits dummy (1, "m");

    NumberWithUnits kg2(2, "kg");
    NumberWithUnits km2(2, "km");
    NumberWithUnits hour2(2, "hour");
    NumberWithUnits USD2(2, "USD");

    // Binary Plus
    CHECK_THROWS(dummy = *km1 + kg2);
    CHECK_THROWS(dummy = *km1 + hour2);
    CHECK_THROWS(dummy = *km1 + USD2);

    CHECK_THROWS(dummy = *hour1 + kg2);
    CHECK_THROWS(dummy = *hour1 + USD2);

    CHECK_THROWS(dummy = *kg1 + USD2);

    // Binary Minus
    CHECK_THROWS(dummy = *km1 - kg2);
    CHECK_THROWS(dummy = *km1 - hour2);
    CHECK_THROWS(dummy = *km1 - USD2);

    CHECK_THROWS(dummy = *hour1 - kg2);
    CHECK_THROWS(dummy = *hour1 - USD2);

    CHECK_THROWS(dummy = *kg1 - USD2);

}

TEST_CASE("Valid Arithmetic Operators"){

    NumberWithUnits *dummy;

    NumberWithUnits kg2(2, "kg");
    NumberWithUnits km2(2, "km");
    NumberWithUnits hour2(2, "hour");
    NumberWithUnits USD2(2, "USD");

    // Binary Plus
   CHECK((*km1 + *m1) == NumberWithUnits(1001, "m"));
   CHECK((*km1 + *km1) == NumberWithUnits(2, "km"));
   CHECK((*km1 + *m1) == NumberWithUnits(1001, "m"));
   CHECK((*km1 + *m1) == NumberWithUnits(1001, "m"));

}