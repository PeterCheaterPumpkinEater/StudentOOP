#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

const double F_TO_C = 5 / 9;
const double C_TO_F = 9 / 5;

Image::Image(int w, int h, std::string flnm)
: width(w), height(h)
{
    filename = flnm;
    image_buf = new char[image_sz()];
}

// copy constructor:
Image::Image(const Image& img2) {
    width = img2.width;
    height = img2.height;
    filename = img2.filename;
    image_buf = new char[image_sz()];
    for (int i = 0; i < image_sz(); i++) {
        image_buf[i] = img2.image_buf[i];
    }
}

// destructor
Image::~Image() {
    if (image_buf != nullptr) {
        delete image_buf;
    }
}

// assignment operator:
Image& Image::operator=(const Image& img2) {
    if (&img2 == this) {
        return *this;
    }
    width = img2.width;
    height = img2.height;
    filename = img2.filename;
    
    delete image_buf;
    image_buf = new char[image_sz()];
    for (int i = 0; i < image_sz(); i++) {
        image_buf[i] = img2.image_buf[i];
    }
    
    return *this;
}

int Image::image_sz() {
    return width * height;
}


void Image::copy_fields(const Image& img2) {
    width = img2.width;
    height = img2.height;
    filename = img2.filename;
}

void Image::display() {
    cout << "Displaying Image" << endl;
}

void Gif::display() {
    cout << "Displaying Gif" << endl;
}

void Png::display() {
    cout << "Displaying Png" << endl;
}

void Jpeg::display() {
    cout << "Displaying Jpeg" << endl;
}

void WReading::display_image() {
    images -> display();
}
void Weather::display_images() {
    for (WReading i: wreadings) {
        i.display_image();
    }
}
//--------------------------------------------------------

/*
 * Setting `display() = 0` here makes this an abstract
 * class that can't be implemented.
 * */
                      
//string Image::display(string s) {
//    return "Displaying image " + s;
//}

/*
 * A constructor for weather class.
 * */

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {};

ostream& operator<<(ostream& os, const Date& date){
    os << "Day: " << date.day << " Month: " << date.month << " Year: " << date.year;
    return os;
}

Weather::Weather(std::string nm, GPS loc) :
    station_nm(nm), my_loc(loc) {}

string Weather::get_name()const {
    return station_nm;
}

int Weather::get_rating()const{
    return rating;
}

pair<double, double> WReading::get_heat_index()const{
    return make_pair(temperature, humidity);
}

pair<double, double> WReading::get_wind_chill()const{
    return make_pair(temperature, windspeed);
}

double WReading::get_temp()const{
    return temperature;
}

double WReading::get_tempF()const{
    return temperature * 9/5 + 32;
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

ostream& operator<<(ostream& os, const WReading& wr) {
    os << wr.date << ' ' << wr.temperature << ' ' << wr.humidity << ' ' << wr.windspeed;
    return os;
}

ostream& operator<<(ostream& os, const Weather& w) {
    os << w.station_nm << ' ' << w.rating << ' ' << w.my_loc << endl;
    for (WReading wr : w.wreadings) {
        os << wr << endl;
    }
    return os;
}

