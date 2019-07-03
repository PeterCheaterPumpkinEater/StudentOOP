#include <iostream>
#include <functional>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

class Sin {
    public:
        double operator()(double r) {
            return sin(r);
        }
};

struct Cos {
    double operator()(double r) {return cos(r);}
};

struct Tan {
    double operator()(double r) {return tan(r);}
};

struct negative : public exception {
    negative(long long int num) : n(num) {}
    const char* what() const throw() {return "negative num: ";}
    long long int n;
};

class Fib {
    public:
    Fib():memo(new long long int[MAX_FIB]) {
        for (long long int i = 0; i < MAX_FIB; ++i) memo[i] = NOT_CALCED;
        memo[0] = 0;
        memo[1] = 1;
    }
        const int MAX_FIB = 100;
        const int NOT_CALCED = -1;
    
        long long int operator()(long long int n) {
            if (n < 0) {throw negative(n);}
            if (memo[n] != NOT_CALCED) {return memo[n];}
            else {
                memo[n] = operator()(n-1) + operator()(n-2);
                return memo[n];
                }
            }
    ~Fib() {delete [] memo;}
    
    private:
    long long int *memo;
};


double your_func(double d, function<double(double)> f) {
    return f(d) * f(d);  // ????
}


double your_func2(double d, function<double(double)> f) {
    return f(d) * 2*f(d);  // ????
}


double your_func3(double d, function<double(double)> f) {
    return f(d) * 3*f(d);  // ????
}

double square_func(double d, function<double(double)> f) {
    return f(d) * f(d);
}


int main() {
    const long long int FIB_NUM = -1;
    try {
    // first functors:
    Sin sine = Sin();
    double d = sine(PI / 2);
    cout << "sin pi / 2 == " << d << endl;
    d = sine(0);
    cout << "sin 0 == " << d << endl;
    Fib fib = Fib();
    long long int f = fib(FIB_NUM);
    cout << "fib(" << FIB_NUM << ") == " << f << endl;

    // then lambdas -- use several functions from cmath here:
    d = square_func(0, [](double arg) { return sin(arg); });
    cout << "Square of sin 0 = " << d << endl;
    d = square_func(1, [](double arg) { return sin(arg); });
    cout << "Square of sin 1 = " << d << endl;
    
    // you're call here!
    cout << "Square of cos 1 = " << d << endl;
    d = your_func3(1, [](double arg) { return cos(arg); });
    // you're call here!
    cout << "Square of tan 0 = " << d << endl;
    d = your_func(0, [](double arg) { return tan(arg); });
    // you're call here!
    d = your_func2(1, [](double arg) { return cos(arg); });
    // you're call here!d = your_func(1, [](double arg) { return cos(arg); });
    // you're call here!
    }
    
    catch (negative& exc) {cerr << exc.what() << exc.n << endl;}
}
