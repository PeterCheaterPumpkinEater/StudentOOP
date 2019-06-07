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

int Weather::get_rating()const{
    return rating;
}

void Weather::set_rating(int new_rating) {
    rating = new_rating;
}

void Weather::add_reading(WReading wr) {
    wreadings.push_back(wr);
}

ostream& operator<<(ostream& os, const GPS& gps){
    os << "latitude: " << gps.latitude << " longitude: " << gps.longitude;
    return os;
}

ostream& operator<<(ostream& os, const Date& date){
    os << "Day: " << date.day << " Month: " << date.month << " Year: " << date.year;
    return os;
}

ostream& operator<<(ostream& os, const WReading& wr) {
    os << wr.date << ' ' << wr.temperature << ' ' << wr.humidity << ' ' << wr.windspeed;
    return os;
}

ostream& operator<<(ostream& os, const Weather& w) {
    os << w.station_nm << ' ' << w.rating << ' ' << w.my_loc;
    return os;
}

