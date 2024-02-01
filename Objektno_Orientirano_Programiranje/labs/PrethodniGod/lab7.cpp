//
// Created by Stefan on 2/19/2023.
//
#include <cstring>
#include <iostream>

using namespace std;

class Vozilo {
protected:
    float masa;
    int sirina;
    int visina;
public:
    Vozilo(float masa = 0, int sirina = 0, int visina = 0) : masa(masa), sirina(sirina), visina(visina) {}

    void setMasa(float masa) {
        this->masa = masa;
    }

    void setSirina(float sirina) {
        this->sirina = sirina;
    }

    void setVisina(float visina) {
        this->visina = visina;
    }

    float getMasa() const {
        return masa;
    }

    int getSirina() const {
        return sirina;
    }

    int getVisina() const {
        return visina;
    }

    virtual int vratiDnevnaCena() {}
};

class Avtomobil : public Vozilo {
protected:
    int vrati;

public:
    Avtomobil(float masa = 0, int sirina = 0, int visina = 0, int vrati = 0) : Vozilo(masa, sirina, visina),
                                                                               vrati(vrati) {};

    int getVrati() const {
        return vrati;
    }

    void setVrati(int vrati) {
        Avtomobil::vrati = vrati;
    }

    int vratiDnevnaCena() override{
        int price = 100;

        if (this->vrati >= 5){
            price = 130;
        }

        return price;
    }
};

class Avtobus : public Vozilo {
protected:
    int nosivost;
public:
    Avtobus(float masa = 0, int sirina = 0, int visina = 0, int nosivost = 0) : Vozilo(masa, sirina, visina),
                                                                                nosivost(nosivost) {};

    int getNosivost() const {
        return nosivost;
    }

    void setNosivost(int nosivost) {
        Avtobus::nosivost = nosivost;
    }

    int vratiDnevnaCena() override{
        int price = 0;

        for (int i = 0; i < nosivost; ++i) {
            price+=5;
        }

        return price;
    }
};

class Kamion : public Vozilo {
protected:
    float maxMasa;
public:
    Kamion(float masa = 0, int sirina = 0, int visina = 0, float maxMasa = 0) : Vozilo(masa, sirina, visina),
                                                                                maxMasa(maxMasa) {};

    float getMaxMasa() const {
        return maxMasa;
    }

    void setMaxMasa(float maxMasa) {
        Kamion::maxMasa = maxMasa;
    }

    int vratiDnevnaCena() override{
        int price = (this->masa + this->maxMasa) * 0.02;

        return price;
    }

};

class ParkingPlac {
protected:
    int brojNaVozila;
    Vozilo **vozila;

public:

    ParkingPlac() {
        vozila = new Vozilo *[100];
        this->brojNaVozila = 0;
    }

    ParkingPlac(Vozilo **vozila, int brojNaVozila = 0) : brojNaVozila(brojNaVozila) {
        this->brojNaVozila = brojNaVozila;

        for (int i = 0; i < brojNaVozila; ++i) {
            this->vozila[i] = vozila[i];
        }
    }

    ~ParkingPlac() { delete[] vozila; }

    ParkingPlac &operator+=(Vozilo *object) {

        vozila[brojNaVozila++] = object;

        return *this;
    }

    float presmetajVkupnaMasa() {
        float mass = 0;
        for (int i = 0; i < this->brojNaVozila; ++i) {
            mass += this->vozila[i]->getMasa();
        }

        return mass;
    }

    int brojVozilaPoshirokiOd(int length) {
        int counter = 0;

        for (int i = 0; i < this->brojNaVozila; ++i) {
            if (this->vozila[i]->getSirina() > length) {
                counter++;
            }
        }

        return counter;
    }

    void pecati() {

        int autoCounter = 0;
        int truckCounter = 0;
        int busCounter = 0;

        for (int i = 0; i < this->brojNaVozila; ++i) {
            Avtomobil *autoTemp = dynamic_cast<Avtomobil *>(vozila[i]);
            if (autoTemp) {
                autoCounter++;
            }
            Avtobus *busTemp = dynamic_cast<Avtobus *>(vozila[i]);
            if (busTemp) {
                busCounter++;
            }
            Kamion *truckTemp = dynamic_cast<Kamion *>(vozila[i]);
            if (truckTemp) {
                truckCounter++;
            }
        }

        cout << "Broot na avtomobili e " << autoCounter << ", brojot na avtobusi e " << busCounter
             << " i brojot na kamioni e "
                "" << truckCounter << "." << endl;
    }

    int pogolemaNosivostOd(Vozilo& v){

        int counter = 0;
        for (int i = 0; i < this->brojNaVozila; ++i) {
            Kamion *truckTemp = dynamic_cast<Kamion*>(vozila[i]);
            if (truckTemp){

                if(truckTemp->getMaxMasa() > v.getMasa()){
                    counter++;
                }
            }
        }

        return counter;
    }

    int vratiDnevnaZarabotka(){
        int profit = 0;

        for (int i = 0; i < brojNaVozila; ++i) {
            profit += vozila[i]->vratiDnevnaCena();
        }

        return profit;
    }
};


int main() {
    ParkingPlac p;

    int n;
    cin >> n;
    int shirina, visina, broj;
    float masa, nosivost;
    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            cin >> masa >> shirina >> visina >> broj;
            Avtomobil *a = new Avtomobil(masa, shirina, visina, broj);
            p += a;
        }
        if (type == 2) {
            cin >> masa >> shirina >> visina >> broj;
            p += new Avtobus(masa, shirina, visina, broj);
        }
        if (type == 3) {
            cin >> masa >> shirina >> visina >> nosivost;
            p += new Kamion(masa, shirina, visina, nosivost);
        }
    }
    p.pecati();

    cout << "\nZarabotkata e " << p.vratiDnevnaZarabotka() << endl;
    cout << "Vkupnata masa e " << p.presmetajVkupnaMasa() << endl;
    cout << "Brojot poshiroki od 5 e " << p.brojVozilaPoshirokiOd(5) << endl;
    Avtomobil a(1200, 4, 3, 5);
    cout << "Brojot na kamioni so nosivost pogolema od avtomobilot e " << p.pogolemaNosivostOd(a) << endl;
    return 0;
}