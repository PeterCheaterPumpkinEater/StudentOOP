#include <iostream>
#include <string>
#include "date.h"

using namespace std;

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {};

ostream& operator<<(ostream& os, const Date& date){
    os << "Day: " << date.day << " Month: " << date.month << " Year: " << date.year;
    return os;
}

