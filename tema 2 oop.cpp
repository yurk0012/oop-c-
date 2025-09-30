#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string surname;
    string name;
    string patronymic;
    double salaryRate;
    int experience;
    int workedDays;
    int totalDays;
    double allowances;
    double deductions;

public:
    
    Employee(int _id, string _surname, string _name, string _patronymic,
        double _salaryRate, int _experience, int _workedDays, int _totalDays,
        double _allowances, double _deductions)
        : id(_id),
        surname(_surname),
        name(_name),
        patronymic(_patronymic),
        salaryRate(_salaryRate),
        experience(_experience),
        workedDays(_workedDays),
        totalDays(_totalDays),
        allowances(_allowances),
        deductions(_deductions) {}


    void setWorkedDays(int days) { workedDays = days; }
    int getId() { return id; }
    string getFullName() { return surname + " " + name + " " + patronymic; }
    double calculateSalary() { return (salaryRate / totalDays) * workedDays + allowances - deductions; }

    void show() {
        cout << "Табельний номер: " << id << "\n";
        cout << "ПІБ: " << getFullName() << "\n";
        cout << "Оклад: " << salaryRate << "\n";
        cout << "Відпрацьовані дні: " << workedDays << "/" << totalDays << "\n";
        cout << "Надбавки: " << allowances << ", Утримання: " << deductions << "\n";
        cout << "Нарахована зарплата: " << calculateSalary() << "\n\n";
    }
};

class Salary {
private:
    Employee employees[3] = {
        Employee(1, "Іваненко", "Іван", "Іванович", 10000, 5, 20, 22, 500, 300),
        Employee(2, "Петренко", "Петро", "Петрович", 12000, 3, 22, 22, 300, 400),
        Employee(3, "Сидоренко", "Сидір", "Сидорович", 15000, 7, 21, 22, 700, 500)
    };
    int count = 3;

public:
    void showAll() {
        for (int i = 0; i < count; i++)
            employees[i].show();
    }

    void findEmployee(int id) {
        for (int i = 0; i < count; i++) {
            if (employees[i].getId() == id) {
                employees[i].show();
                return;
            }
        }
        cout << "Співробітника з таким ID не знайдено.\n";
    }

    void editWorkedDays(int id, int days) {
        for (int i = 0; i < count; i++) {
            if (employees[i].getId() == id) {
                employees[i].setWorkedDays(days);
                cout << "Відпрацьовані дні оновлено.\n";
                return;
            }
        }
        cout << "Співробітника з таким ID не знайдено.\n";
    }
};
int main() {
    setlocale(LC_ALL, "Ukrainian");
   
    Salary company;

    cout << "Список усіх співробітників:\n";
    company.showAll();

    int searchId = 2;
    cout << "Пошук співробітника з ID = " << searchId << ":\n";
    company.findEmployee(searchId);

    int editId = 1;
    int newWorkedDays = 21;
    cout << "Редагування відпрацьованих днів для співробітника ID = " << editId << ":\n";
    company.editWorkedDays(editId, newWorkedDays);

    cout << "Оновлений список співробітників:\n";
    company.showAll();
  
}