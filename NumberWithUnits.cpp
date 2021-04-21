//
// AUTHOR: Tal Zichlinsky
// This file will be used to build the NumberWithUnits class, as described in this asignment's README file
// (https://github.com/talzich/CPP-EX3-A/blob/master/README.md)

#include <iostream>

#include "NumberWithUnits.hpp"

using namespace ariel;
using namespace std;

NumberWithUnits::NumberWithUnits(double num, string unit){
    
}

void NumberWithUnits::read_units(std::ifstream &u_fle){

}

//-----------------------------
// Arithmetic Operators
//-----------------------------

NumberWithUnits NumberWithUnits::operator-(){
    return *this;
}

NumberWithUnits NumberWithUnits::operator-(NumberWithUnits num){
    return *this;
}
NumberWithUnits NumberWithUnits::operator-=(NumberWithUnits num){
    return *this;
}

NumberWithUnits NumberWithUnits::operator+(){
    return *this;
}
NumberWithUnits NumberWithUnits::operator+(NumberWithUnits num){
    return *this;
}
NumberWithUnits NumberWithUnits::operator+=(NumberWithUnits num){
    return *this;
}

//-----------------------------
// Comparison Operators
//-----------------------------

bool NumberWithUnits::operator!=(NumberWithUnits num){
    return false;
}
bool NumberWithUnits::operator==(NumberWithUnits num){
    return false;
}

bool NumberWithUnits::operator<=(NumberWithUnits num){
    return false;
}
bool NumberWithUnits::operator>=(NumberWithUnits num){
    return false;
}

bool NumberWithUnits::operator<(NumberWithUnits num){
    return false;
}
bool NumberWithUnits::operator>(NumberWithUnits num){
    return false;
}

//-----------------------------
// Increment Decrement Operators
//-----------------------------

NumberWithUnits NumberWithUnits::operator--(){
    return *this;
}
NumberWithUnits NumberWithUnits::operator--(int dummy){
    return *this;
}

NumberWithUnits NumberWithUnits::operator++(){
    return *this;
}
NumberWithUnits NumberWithUnits::operator++(int dummy){
    return *this;
}

//-----------------------------
// Friend Operators
//-----------------------------

NumberWithUnits operator*(double d, NumberWithUnits num){
    return num;
}

//-----------------------------
// I/O Operators
//-----------------------------
ostream& operator<<(ostream &out, NumberWithUnits num){
    return out;
}
istream& operator>>(istream &in, NumberWithUnits num){
    return in;
}