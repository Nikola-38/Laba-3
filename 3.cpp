#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>

using namespace std;


int coffee(double Tv, double Tc, double Coefficient, int t, vector<double>& Coffee) {
    for (int i = 0; i <= t; i++) {
        Coffee.push_back(Tc); //добавляем изначальное значение
        Tc = Tc - Coefficient * (Tc - Tv); //высчитываем новое по формуле
    }
    return 0;
}

double aproxA(vector<double> Coffee) {

    double ETemperature = 0, Etime = 0, ETt = 0, Etime2 = 0;
    int len = Coffee.size(); //количество измерений

    for (int i = 0; i < len; i++) {
        ETemperature += Coffee[i]; //сумма по температуре
        Etime += i; //сумма по времени

        ETt += Coffee[i] * i; //сумма для произведения по оси температуры и времени
        Etime2 += i*i; //сумма для квадрата температуры
    }
    return (len * ETt - (Etime * ETemperature)) / (len * Etime2 - Etime * Etime);
}

double aproxB(vector<double> Coffee, double a) {

    double ETemperature = 0, Etime = 0;
    int len = Coffee.size(); //количество измерений

    for (int i = 0; i < len; i++) {
        ETemperature += Coffee[i]; //сумма по температуре
        Etime += i; //сумма по времени
    }
    return (ETemperature - a * Etime) / len;
}

double Correl(vector<double> Coffee) {

    double sumTemp = 0; //сумма температур
    for (double T : Coffee) {
        sumTemp += T;
    }

    int len = Coffee.size(); //количество измерений
    double TMedium = sumTemp / len; //среднее значение всех измеренных значений
    double tMedium = (len - 1) * len / 2;
    double sumNumbers = 0; //арифметическая сумма значений произведения температуры и времени
    double tSumSquare = 0; //арифметическая сумма квадрата времени
    double TSumSquare = 0; //арифметическая сумма квадрата температуры

    for (int i = 0; i < len; i++) {
        sumNumbers += ((i - tMedium) * (Coffee[i] - TMedium));
        tSumSquare += ((i - tMedium) * (i - tMedium));
        TSumSquare += ((Coffee[i] - TMedium) * (Coffee[i] - TMedium));
    }
    return sumNumbers / sqrt(TSumSquare * tSumSquare);
}


int main() {
   system("chcp 65001");
    double Tv, Tc, Coefficient; //температура среды, температура кофе, коэф.остывания
    int t; //время остывания

    cout << "Введите температуру воздуха" << endl;
    cin >> Tv;
    cout << "Введите температуру кофе" << endl;
    cin >> Tc;
    cout << "Введите  коэффициент охлаждения," << endl;
    cin >> Coefficient;
    cout << "максимальное время охлаждение в минутах" << endl;
    cin >> t;

    vector<double> Coffee;
    coffee(Tv, Tc, Coefficient, t, Coffee); //расчитываем температуру по времени

    cout << "Время" << "\t" << "Температура кофе" << endl;
    int time = 0;

    for (auto temperature : Coffee) {
        cout << time << "\t" << temperature << setprecision(4) << endl; //вывели все значение от 0 до времени
        time++;
    }

    double a = aproxA(Coffee); // в a помещаем отклонение по оси времени
    double b = aproxB(Coffee, a); //в b помещаем отклонение по оси температуры
    double correl = Correl(Coffee); //высчитываем коэф.корреляции

    cout << endl << "Линия апроксимации: " << "T = " << a << setprecision(3) << " * t + " << b << setprecision(4) << endl; //линия апроксимации
    cout << endl << "Коэффициент корреляции " << correl << setprecision(2) << endl; //погрешность измерений, нужно для вычисления погрешности
}
