#include <iostream>
#include <fstream>  
#include <string> 
#include <limits> 

using namespace std;

struct tube {
    string km_mark;
    float length;
    float diameter;
    bool in_repair;
};

struct KS {
    string name;
    int workshops;
    int workshops_working;
    int station_class;
};

// Проверка на целое число
int CheckInt() {
    int num;
    while (true) {
        cin >> num;
        if (cin.fail() || num <= 0 || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка. Попробуйте снова: ";
        }
        else {
            return num;
        }
    }
}

// Проверка на вещественное число
float CheckFloat() {
    float num;
    while (true) {
        cin >> num;
        if (cin.fail() || num < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка. Попробуйте снова: ";
        }
        else {
            return num;
        }
    }
}

tube InputTube() {
    tube T;

    cout << "километровая отметка трубы: " << endl;
    cin.ignore();
    getline(cin, T.km_mark);
    cout << "длина (в км): " << endl;
    T.length = CheckFloat();
    cout << "диаметр (в мм): " << endl;
    T.diameter = CheckFloat();
    return T;
}

KS InputKS() {
    KS K;

    cout << "название КС: " << endl;
    cin.ignore();
    getline(cin, K.name);
    cout << "количество цехов: " << endl;
    K.workshops = CheckInt();
    cout << "количество цехов в работе: " << endl;
    K.workshops_working = CheckInt();
    while (true) {
        if (K.workshops_working > K.workshops) {
            cout << "Количество цехов в работе не может быть больше чем всего цехов" << endl;
            K.workshops_working = CheckInt();
        }
        else {
            break;
        }
    }
    cout << "класс станции: " << endl;
    K.station_class = CheckInt();

    return K;
}

void ShowTube(const tube& T) {
    cout << "километровая отметка: " << T.km_mark << endl;
    cout << "длина: " << T.length << " км" << endl;
    cout << "диаметр: " << T.diameter << " мм" << endl;
    if (T.in_repair) {
        cout << "статус: труба в ремонте" << endl;
    }
    else {
        cout << "статус: труба работает" << endl;
    }
}

void ShowKS(const KS& K) {
    cout << "название КС: " << K.name << endl;
    cout << "количество цехов: " << K.workshops << endl;
    cout << "количество цехов в работе: " << K.workshops_working << endl;
    cout << "класс станции: " << K.station_class << endl;
}

int main() {
    setlocale(LC_ALL, "RU");

    tube myTube = InputTube();
    ShowTube(myTube);

    KS myKS = InputKS();
    ShowKS(myKS);

    return 0;
}