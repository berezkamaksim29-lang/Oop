#include <iostream>
#include <string>
#include <locale>
#include <limits>

#ifdef _WIN32
#define NOMINMAX
#include <windows.h>
#endif

using namespace std;

class PostalAddress {
private:
    string organization;
    string country;
    string region;
    string city;
    string street;
    string building;
    string postalCode;

public:

    // Конструктор за замовчуванням
    PostalAddress() {
        organization = "";
        country = "";
        region = "";
        city = "";
        street = "";
        building = "";
        postalCode = "";

        cout << "\n[+] Об'єкт створено\n";
    }

    // Конструктор з параметрами
    PostalAddress(
        string org,
        string c,
        string r,
        string ci,
        string s,
        string b,
        string p
    ) {
        organization = org;
        country = c;
        region = r;
        city = ci;
        street = s;
        building = b;
        postalCode = p;

        cout << "\n[+] Об'єкт створено\n";
    }

    // Конструктор копіювання
    PostalAddress(const PostalAddress& other) {

        organization = other.organization;
        country = other.country;
        region = other.region;
        city = other.city;
        street = other.street;
        building = other.building;
        postalCode = other.postalCode;

        cout << "\n[+] Створено копію об'єкта\n";
    }

    // -------- Сеттери --------

    void setOrganization(const string& org) {
        organization = org;
    }

    void setCountry(const string& c) {
        country = c;
    }

    void setRegion(const string& r) {
        region = r;
    }

    void setCity(const string& ci) {
        city = ci;
    }

    void setStreet(const string& s) {
        street = s;
    }

    void setBuilding(const string& b) {
        building = b;
    }

    void setPostalCode(const string& p) {
        postalCode = p;
    }

    // -------- Виведення --------

    void display() const {

        cout << "\n=====================================\n";
        cout << "      ПОШТОВА АДРЕСА ОРГАНІЗАЦІЇ\n";
        cout << "=====================================\n";

        cout << "Організація     : " << organization << endl;
        cout << "Країна          : " << country << endl;
        cout << "Область         : " << region << endl;
        cout << "Місто           : " << city << endl;
        cout << "Вулиця          : " << street << endl;
        cout << "Будинок / офіс  : " << building << endl;
        cout << "Поштовий індекс : " << postalCode << endl;

        cout << "=====================================\n";
    }

    // Деструктор
    ~PostalAddress() {
        cout << "\n[-] Об'єкт адреси знищено\n";
    }
};

int main() {

    setlocale(LC_ALL, "Ukrainian");

    PostalAddress address;

    string input;

    // ----- Ввід даних -----

    cout << "\nВведіть назву організації: ";
    getline(cin, input);
    address.setOrganization(input);

    cout << "Введіть країну: ";
    getline(cin, input);
    address.setCountry(input);

    cout << "Введіть область: ";
    getline(cin, input);
    address.setRegion(input);

    cout << "Введіть місто: ";
    getline(cin, input);
    address.setCity(input);

    cout << "Введіть вулицю: ";
    getline(cin, input);
    address.setStreet(input);

    cout << "Введіть будинок / офіс: ";
    getline(cin, input);
    address.setBuilding(input);

    cout << "Введіть поштовий індекс: ";
    getline(cin, input);
    address.setPostalCode(input);

    // ----- Показ адреси -----

    address.display();

    int choice;

    do {

        cout << "\n========== МЕНЮ ==========\n";
        cout << "1 - Змінити організацію\n";
        cout << "2 - Змінити країну\n";
        cout << "3 - Змінити область\n";
        cout << "4 - Змінити місто\n";
        cout << "5 - Змінити вулицю\n";
        cout << "6 - Змінити будинок\n";
        cout << "7 - Змінити індекс\n";
        cout << "8 - Показати адресу\n";
        cout << "0 - Вихід\n";

        cout << "Ваш вибір: ";
        cin >> choice;

        // Очищення буфера
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {

        case 1:
            cout << "Нова організація: ";
            getline(cin, input);
            address.setOrganization(input);
            break;

        case 2:
            cout << "Нова країна: ";
            getline(cin, input);
            address.setCountry(input);
            break;

        case 3:
            cout << "Нова область: ";
            getline(cin, input);
            address.setRegion(input);
            break;

        case 4:
            cout << "Нове місто: ";
            getline(cin, input);
            address.setCity(input);
            break;

        case 5:
            cout << "Нова вулиця: ";
            getline(cin, input);
            address.setStreet(input);
            break;

        case 6:
            cout << "Новий будинок / офіс: ";
            getline(cin, input);
            address.setBuilding(input);
            break;

        case 7:
            cout << "Новий індекс: ";
            getline(cin, input);
            address.setPostalCode(input);
            break;

        case 8:
            address.display();
            break;

        case 0:
            cout << "\nЗавершення програми...\n";
            break;

        default:
            cout << "\nНевірний вибір!\n";
        }

    } while (choice != 0);

    // ----- Копія об'єкта -----

    PostalAddress copyAddress(address);

    cout << "\nКопія адреси:\n";

    copyAddress.display();

    return 0;
}
