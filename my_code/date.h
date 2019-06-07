#ifndef date_h
#define date_h

class Date {
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {};
private:
    int day;
    int month;
    int year;
};

#endif 
