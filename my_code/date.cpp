#include <iostream>
#include <string>
#include "date.h"

using namespace std;

ostream& operator<<(ostream& os, const Date& date){
    os << "Day: " << date.day << " Month: " << date.month << " Year: " << date.year;
    return os;
}

