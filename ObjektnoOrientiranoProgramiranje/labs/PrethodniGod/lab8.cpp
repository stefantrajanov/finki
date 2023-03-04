#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Igrachka {

public:
    virtual double getMasa() = 0;

    virtual double getVolumen() = 0;
};


class Forma {
protected:
    char *boja;
    int gustina;
public:
    Forma(char *boja = "", int gustina = 0) {
        boja = new char[strlen(boja) + 1];
        strcpy(this->boja, boja);
        this->gustina = gustina;
    }
    ~Forma() {
        delete[] boja;
    }
};

class Topka : public Forma, public Igrachka {
private:
    int radius;
public:
    Topka(char *boja = "", int gustina = 0, int radius = 0) : Forma(boja, gustina), radius(radius) {
    }

    double getVolumen() override {
        return 3.14 * 4 / 3 * radius * radius * radius;
    }

    double getMasa() override {
        return (getVolumen() * gustina);
    }
};

class Kocka : public Forma, public Igrachka {
private:
    int visina;
    int sirocina;
    int dlabocina;
public:
    Kocka(char *boja = "", int gustina = 0, int visina = 0, int sirocina = 0, int dlabocina = 0) :
            Forma(boja, gustina),
            sirocina(sirocina),
            dlabocina(dlabocina) {}

    double getVolumen() override {
        return (visina * dlabocina * sirocina);
    }

    double getMasa() override {
        return (getVolumen() * gustina);
    }
};

int main() {
    int n, p;
    cin >> n;
    char boja[50];
    int gustina, radius, visina, sirina, dlabocina;
    Igrachka **kupche = new Igrachka *[n];
    for (int i = 0; i < n; i++) {
        cin >> p;
        if (p == 1) {
            cin >> boja >> gustina >> radius;
            kupche[i] = new Topka(boja, gustina, radius);
        }
        if (p == 2) {
            cin >> boja >> gustina >> visina >> sirina >> dlabocina;
            kupche[i] = new Kocka(boja, gustina, visina, sirina, dlabocina);
        }
    }
    cin >> boja >> gustina >> visina >> sirina >> dlabocina;
    Kocka petra(boja, gustina, visina, sirina, dlabocina);

    double vkp = 0;
    for (int i = 0; i < n; i++) {
        vkp = vkp + kupche[i]->getMasa();
    }
    if (vkp > petra.getMasa())
        cout << "DA" << endl;
    else
        cout << "NE" << endl;
    double maxvolumen = kupche[0]->getVolumen();
    for (int i = 1; i < n; i++) {
        if (maxvolumen < kupche[i]->getVolumen()) {
            maxvolumen = kupche[i]->getVolumen();
        }
    }
    cout << "Razlikata e: " << abs(maxvolumen - petra.getVolumen());
    return 0;
}