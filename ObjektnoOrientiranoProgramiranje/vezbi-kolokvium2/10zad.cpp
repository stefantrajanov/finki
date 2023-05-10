//
// Created by Stefan on 5/2/2023.
//
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class NegativnaVrednost : public exception {
private:
    char _message[200];
public:
    explicit NegativnaVrednost(char *message) {
        strcpy(this->_message, message);
    }

    const char *message() const {
        return _message;
    }

    const char *what() const noexcept override {
        return _message;
    }
};

class Oglas {
private:
    char title[60];
    char category[40];
    char description[110];
    float price;
public:
    Oglas() {
        strcpy(this->title, "");
        strcpy(this->category, "");
        strcpy(this->description, "");
        this->price = 0;
    }

    Oglas(char *title, char *category, char *description, float price) : price(price) {
        strcpy(this->title, title);
        strcpy(this->category, category);
        strcpy(this->description, description);
    }

    Oglas(const Oglas &object) {
        strcpy(this->title, object.title);
        strcpy(this->category, object.category);
        strcpy(this->description, object.description);
        this->price = object.price;
    }

    Oglas &operator=(const Oglas &object) {
        if (this == &object) {
            return *this;
        }

        strcpy(this->title, object.title);
        strcpy(this->category, object.category);
        strcpy(this->description, object.description);
        this->price = object.price;

        return *this;
    }

    // methods;

    bool operator>(const Oglas &object) const {
        if (this->price > object.price) {
            return true;
        }

        return false;
    }

    friend ostream &operator<<(ostream &os, const Oglas &object) {
        os << object.title << endl;
        os << object.description << endl;
        os << object.price << " evra" << endl;

        return os;
    }

    float getPrice() const {
        return price;
    }

    const char *getTitle() const {
        return title;
    }

    const char *getCategory() const {
        return category;
    }

    const char *getDescription() const {
        return description;
    }
};

class Oglasnik {
private:
    char name[30];
    Oglas *auctions;
    int numberOfAuctions;
public:
    Oglasnik() {
        strcpy(this->name, "");
        this->auctions = nullptr;
        this->numberOfAuctions = 0;
    }

    Oglasnik(char *name) {
        strcpy(this->name, name);
        this->auctions = nullptr;
        this->numberOfAuctions = 0;
    }

    Oglasnik(const Oglasnik &object) {
        strcpy(this->name, object.name);
        this->auctions = new Oglas[object.numberOfAuctions];
        for (int i = 0; i < numberOfAuctions; ++i) {
            this->auctions[i] = auctions[i];
        }
        this->numberOfAuctions = object.numberOfAuctions;
    }

    Oglasnik &operator=(const Oglasnik &object) {
        if (this == &object) {
            return *this;
        }

        delete[] auctions;
        strcpy(this->name, object.name);
        this->auctions = new Oglas[object.numberOfAuctions];
        for (int i = 0; i < numberOfAuctions; ++i) {
            this->auctions[i] = auctions[i];
        }
        this->numberOfAuctions = object.numberOfAuctions;

        return *this;
    }

    ~Oglasnik() {
        delete[] auctions;
    }

    void operator+=(const Oglas &object) {
        if (object.getPrice() < 0) {
            char temp[200] = "Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!";
            cout << temp << endl;
            return;
        }

        Oglas *tempArray = new Oglas[this->numberOfAuctions + 1];
        for (int i = 0; i < this->numberOfAuctions; ++i) {
            tempArray[i] = this->auctions[i];
        }
        tempArray[this->numberOfAuctions] = object;

        delete[] auctions;

        this->auctions = tempArray;
        this->numberOfAuctions++;
    }

    friend ostream &operator<<(ostream &os, const Oglasnik &object) {
        os << object.name << endl;

        for (int i = 0; i < object.numberOfAuctions; ++i) {
            cout << object.auctions[i] << endl;
        }

        return os;
    }

    void oglasiOdKategorija(const char *category) const {
        for (int i = 0; i < this->numberOfAuctions; ++i) {
            if (strcmp(this->auctions[i].getCategory(), category) == 0) {
                cout << this->auctions[i] << endl;
            }
        }
    }

    void najniskaCena() {
        float maxPrice = 0.0;
        int index;

        for (int i = 0; i < this->numberOfAuctions; ++i) {
            if (maxPrice == 0.0) {
                maxPrice = this->auctions[i].getPrice();
                index = i;
                continue;
            }
            if (maxPrice > this->auctions[i].getPrice()) {
                maxPrice = this->auctions[i].getPrice();
                index = i;
            }
        }

        cout << this->auctions[index];
    }
};



//место за вашиот код


int main() {

    char naslov[50];
    char kategorija[30];
    char opis[100];
    float cena;
    char naziv[50];
    char k[30];
    int n;

    int tip;
    cin >> tip;

    if (tip == 1) {
        cout << "-----Test Oglas & operator <<-----" << endl;
        cin.get();
        cin.getline(naslov, 49);
        cin.getline(kategorija, 29);
        cin.getline(opis, 99);
        cin >> cena;
        Oglas o(naslov, kategorija, opis, cena);
        cout << o;
    } else if (tip == 2) {
        cout << "-----Test Oglas & operator > -----" << endl;
        cin.get();
        cin.getline(naslov, 49);
        cin.getline(kategorija, 29);
        cin.getline(opis, 99);
        cin >> cena;
        Oglas o1(naslov, kategorija, opis, cena);
        cin.get();
        cin.getline(naslov, 49);
        cin.getline(kategorija, 29);
        cin.getline(opis, 99);
        cin >> cena;
        Oglas o2(naslov, kategorija, opis, cena);
        if (o1 > o2) cout << "Prviot oglas e poskap." << endl;
        else cout << "Prviot oglas ne e poskap." << endl;
    } else if (tip == 3) {
        cout << "-----Test Oglasnik, operator +=, operator << -----" << endl;
        cin.get();
        cin.getline(naziv, 49);
        cin >> n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++) {
            cin.get();
            cin.getline(naslov, 49);
            cin.getline(kategorija, 29);
            cin.getline(opis, 99);
            cin >> cena;
            Oglas o(naslov, kategorija, opis, cena);
            ogl += o;
        }
        cout << ogl;
    } else if (tip == 4) {
        cout << "-----Test oglasOdKategorija -----" << endl;
        cin.get();
        cin.getline(naziv, 49);
        cin >> n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++) {
            cin.get();
            cin.getline(naslov, 49);
            cin.getline(kategorija, 29);
            cin.getline(opis, 99);
            cin >> cena;
            Oglas o(naslov, kategorija, opis, cena);
            ogl += o;
        }
        cin.get();
        cin.getline(k, 29);
        cout << "Oglasi od kategorijata: " << k << endl;
        ogl.oglasiOdKategorija(k);

    } else if (tip == 5) {
        cout << "-----Test Exception -----" << endl;
        cin.get();
        cin.getline(naziv, 49);
        cin >> n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++) {
            cin.get();
            cin.getline(naslov, 49);
            cin.getline(kategorija, 29);
            cin.getline(opis, 99);
            cin >> cena;
            Oglas o(naslov, kategorija, opis, cena);
            ogl += o;
        }
        cout << ogl;

    } else if (tip == 6) {
        cout << "-----Test najniskaCena -----" << endl;
        cin.get();
        cin.getline(naziv, 49);
        cin >> n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++) {
            cin.get();
            cin.getline(naslov, 49);
            cin.getline(kategorija, 29);
            cin.getline(opis, 99);
            cin >> cena;
            Oglas o(naslov, kategorija, opis, cena);
            ogl += o;
        }
        cout << "Oglas so najniska cena:" << endl;
        ogl.najniskaCena();

    } else if (tip == 7) {
        cout << "-----Test All -----" << endl;
        cin.get();
        cin.getline(naziv, 49);
        cin >> n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++) {
            cin.get();
            cin.getline(naslov, 49);
            cin.getline(kategorija, 29);
            cin.getline(opis, 99);
            cin >> cena;
            Oglas o(naslov, kategorija, opis, cena);
            ogl += o;
        }
        cout << ogl;

        cin.get();
        cin.get();
        cin.getline(k, 29);
        cout << "Oglasi od kategorijata: " << k << endl;
        ogl.oglasiOdKategorija(k);

        cout << "Oglas so najniska cena:" << endl;
        ogl.najniskaCena();

    }

    return 0;
}
