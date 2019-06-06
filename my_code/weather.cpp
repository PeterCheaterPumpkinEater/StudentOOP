#include <iostream>
#include <string>
#include "weather.h"


using namespace std;

/*
 * A constructor for weather class.
 * */
Weather::Weather(std::string nm, GPS loc) :
    station_nm(nm), my_loc(loc) {}

string Weather::get_name()const {
    return station_nm;
}

ostream& operator<<(std::ostream& os, const Weather& w) {
    os << w.station_nm;
    return os;
}

int Weather::get_rating()const{
    return rating;
}

void Weather::set_rating(int new_rating) {
    rating = new_rating;
}