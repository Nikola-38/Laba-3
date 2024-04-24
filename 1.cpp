#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double y;
double func1(double x) {
    y = -x - 2;
    return y;
}

double func2(double x) {
    y = sqrt(1 - pow((x+1), 2)) ;
    return y;
}

double func3(double x) {
    y = 0 * x + 1;
    return y;
}

double func4(double x) {
    y = -2 * x + 3;
    return y;
}

double func5(double x) {
    y = x * 0 - 1;
    return y;
}


int main()
{
    cout << "Funktionswert" << endl;
    cout << "X" << "\t" << "Y" << endl;

    
    double dx = 0.5;
    for (double x = -3; x <= 5; x += dx) {

        if (x >= -3 & x <= -2) {
            cout << fixed << setprecision(2) << x << "  " << func1(x) << endl;
        }
        if (x > -2 & x <= -1) {
            cout << fixed << setprecision(2) << x << "  " << func2(x) << endl;
        }
        if (x > -1 & x <= 1) {
            cout << fixed << setprecision(2) << x << "  " << func3(x) << endl;
        }
        if (x > 1 & x <= 2) {
            cout << fixed << setprecision(2) << x << "  " << func4(x) << endl;
        }
        if (x > 2 & x <= 5) {
            cout << fixed << setprecision(2) << x << "  " << func5(x) << endl;
        }
    }
    return 0;
}
