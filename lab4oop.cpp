#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Transport {
protected:
    string name;
    double speed;
    double weight;

public:
    Transport(string n = "Невідомо", double s = 0, double w = 0)
        : name(n), speed(s),     weight(w) {
        cout << "Створено транспортний засіб: " << name << endl;
    }

    ~Transport() {
        cout << "Знищено транспортний засіб: " << name << endl;
    }

    void ShowInfo() const {
        cout << "Назва: " << name << "\n"
            << "Швидкість: " << speed << " км/год\n"
            << "Вага: " << weight << " кг\n";
    }

    void SaveToFile(ofstream& fout) const {
        fout << "Назва: " << name << "\n"
            << "Швидкість: " << speed << "\n"
            << "Вага: " << weight << "\n";
    }
};

class Car : public Transport {
protected:
    string fuelType;

public:
    Car(string n = "Авто", double s = 0, double w = 0, string fuel = "Бензин")
        : Transport(n, s, w), fuelType(fuel) {
        cout << "Створено автомобіль: " << name << endl;
    }

    ~Car() {
        cout << "Знищено автомобіль: " << name << endl;
    }

    void ShowInfo() const {
        Transport::ShowInfo();
        cout << "Тип пального: " << fuelType << "\n";
    }

    void SaveToFile(ofstream& fout) const {
        fout << "[Автомобіль]\n";
        Transport::SaveToFile(fout);
        fout << "Тип пального: " << fuelType << "\n\n";
    }
};


class Truck : public Car {
    double capacity; 
public:
    Truck(string n = "Вантажівка", double s = 0, double w = 0, string fuel = "Дизель", double c = 0)
        : Car(n, s, w, fuel), capacity(c) {
        cout << "Створено вантажівку: " << name << endl;
    }

    ~Truck() {
        cout << "Знищено вантажівку: " << name << endl;
    }

    void ShowInfo() const {
        Car::ShowInfo();
        cout << "Вантажопідйомність: " << capacity << " т\n";
    }

    void SaveToFile(ofstream& fout) const {
        fout << "[Вантажівка]\n";
        Transport::SaveToFile(fout);
        fout << "Тип пального: " << fuelType << "\n"
            << "Вантажопідйомність: " << capacity << "\n\n";
    }
};


class Ship : public Transport {
    int passengers;
public:
    Ship(string n = "Пароплав", double s = 0, double w = 0, int p = 0)
        : Transport(n, s, w), passengers(p) {
        cout << "Створено пароплав: " << name << endl;
    }

    ~Ship() {
        cout << "Знищено пароплав: " << name << endl;
    }

    void ShowInfo() const {
        Transport::ShowInfo();
        cout << "Кількість пасажирів: " << passengers << "\n";
    }

    void SaveToFile(ofstream& fout) const {
        fout << "[Пароплав]\n";
        Transport::SaveToFile(fout);
        fout << "Кількість пасажирів: " << passengers << "\n\n";
    }
};


class Airplane : public Transport {
    double altitude; 
public:
    Airplane(string n = "Літак", double s = 0, double w = 0, double a = 0)
        : Transport(n, s, w), altitude(a) {
        cout << "Створено літак: " << name << endl;
    }

    ~Airplane() {
        cout << "Знищено літак: " << name << endl;
    }

    void ShowInfo() const {
        Transport::ShowInfo();
        cout << "Максимальна висота польоту: " << altitude << " м\n";
    }

    void SaveToFile(ofstream& fout) const {
        fout << "[Літак]\n";
        Transport::SaveToFile(fout);
        fout << "Висота польоту: " << altitude << "\n\n";
    }
};


int main() {
    setlocale(0, "ukr");

    Car car("Toyota Corolla", 180, 1300, "Бензин");
    Truck truck("MAN TGX", 140, 7000, "Дизель", 20);
    Ship ship("Odessa Star", 60, 50000, 1200);
    Airplane plane("Boeing 737", 850, 41000, 12000);

    cout << "\n=== Інформація про транспорт ===\n";
    car.ShowInfo();
    cout << endl;
    truck.ShowInfo();
    cout << endl;
    ship.ShowInfo();
    cout << endl;
    plane.ShowInfo();

    ofstream fout("transport.txt");
    if (!fout) {
        cerr << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    car.SaveToFile(fout);
    truck.SaveToFile(fout);
    ship.SaveToFile(fout);
    plane.SaveToFile(fout);

    fout.close();
    cout << "\nДані збережено у файл transport.txt\n";

    return 0;
}
