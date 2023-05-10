//
// Created by Stefan on 4/25/2023.
//
// vashiot kod ovde
#include <iostream>
#include <cstring>

using namespace std;

class Vozac {
protected:
    char name[110];
    int age;
    int numberOfRaces;
    bool isVeteran;
    int pricePerRace;
public:
    Vozac(char *name, int age, int numberOfRaces, bool isVeteran) : age(age), numberOfRaces(numberOfRaces),
                                                                    isVeteran(isVeteran) {
        strcpy(this->name, name);
    }

    friend ostream &operator<<(ostream &os, const Vozac &object) {
        os << object.name << endl;
        os << object.age << endl;
        os << object.numberOfRaces << endl;
        if (object.isVeteran) {
            os << "VETERAN" << endl;
        }

        return os;
    }

    virtual void calculatePrice() = 0;
    virtual int danok() = 0;

    virtual bool operator==(const Vozac &object) {
        if (this->pricePerRace == object.pricePerRace) {
            return true;
        }

        return false;
    };
};

class Avtomobilist : public Vozac {
private:
    int autoPrice;
public:
    Avtomobilist(char *name, int age, int numberOfRaces, bool isVeteran, int autoPrice) : Vozac(name, age,
                                                                                                numberOfRaces,
                                                                                                isVeteran),
                                                                                          autoPrice(autoPrice) {
        calculatePrice();
    }

    void calculatePrice() override {
        this->pricePerRace = autoPrice / 5;
    }

    int danok() override{
        int tax;
        if (this->numberOfRaces > 10){
            tax = this->pricePerRace * 0.15;
        }else{
            tax = this->pricePerRace * 0.15;

        }

        return tax;
    }

};

class Motociklist : public Vozac {
private:
    int motorPower;
public:
    Motociklist(char *name, int age, int numberOfRaces, bool isVeteran, int motorPower) : Vozac(name, age,
                                                                                                numberOfRaces,
                                                                                                isVeteran),
                                                                                          motorPower(motorPower) {
        calculatePrice();
    }

    void calculatePrice() override {
        this->pricePerRace = motorPower * 20;
    }

    int danok() override{
        int tax;
        if (this->isVeteran){
            tax = this->pricePerRace * 0.25;
        }else{
            tax = this->pricePerRace * 0.20;
        }

        return tax;
    }
};

int soIstaZarabotuvachka(Vozac **drivers, int n, Vozac *object){
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        if (*drivers[i] == *object){
            counter++;
        }
    }

    return counter;
}

int main() {
    int n, x;
    cin >> n >> x;
    Vozac **v = new Vozac *[n];
    char ime[100];
    int vozrast;
    int trki;
    bool vet;
    for (int i = 0; i < n; ++i) {
        cin >> ime >> vozrast >> trki >> vet;
        if (i < x) {
            float cena_avto;
            cin >> cena_avto;
            v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto);
        } else {
            int mokjnost;
            cin >> mokjnost;
            v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost);
        }
    }
    cout << "=== DANOK ===" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *v[i];
        cout << v[i]->danok() << endl;
    }
    cin >> ime >> vozrast >> trki >> vet;
    int mokjnost;
    cin >> mokjnost;
    Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
    cout << "=== VOZAC X ===" << endl;
    cout << *vx;
    cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
    cout << soIstaZarabotuvachka(v, n, vx);
    for (int i = 0; i < n; ++i) {
        delete v[i];
    }
    delete[] v;
    delete vx;
    return 0;
}