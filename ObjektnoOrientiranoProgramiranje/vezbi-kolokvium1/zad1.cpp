//
// Created by Stefan on 3/3/2023.
//
#include <iostream>
#include <cstring>

using namespace std;

enum tip {
    Pop = 0, Rok = 1, Rap = 2
};

class Pesna {
private:
    char *ime = new char[100];
    int minuti;
    tip kojtip;
public:
    Pesna(char *ime = "", int minuti = 0, tip kojtip = (tip) 0) : minuti(minuti), kojtip(kojtip) {
        strcpy(this->ime, ime);
    }

    ~Pesna() {
        if (this == nullptr) {
            delete[] ime;
        }
    }

    void pecati() {
        cout << "\"" << this->ime << "\"-" << this->minuti << "min" << endl;
    }

    int getMinuti() const {
        return minuti;
    }

    tip getTip(){
        return this->kojtip;
    }

};

class CD {
private:
    Pesna pesni[10];
    int brojNaSnimeniPesni = 0;
    int maxVremeNaPesnite;
public:
    CD(int maxVremeNaPesnite) {
        this->maxVremeNaPesnite = maxVremeNaPesnite;
    }

    CD(Pesna *pesni, int brojNaSnimeniPesni = 0, int maxVremeNaPesnite = 0) {
        for (int i = 0; i < brojNaSnimeniPesni; ++i) {
            this->pesni[i] = pesni[i];
        }
        this->brojNaSnimeniPesni = brojNaSnimeniPesni;
        this->maxVremeNaPesnite = maxVremeNaPesnite;
    }

    ~CD() = default;

    void setPesni(Pesna *pesni) {
        for (int i = 0; i < brojNaSnimeniPesni; ++i) {
            this->pesni[i] = pesni[i];
        }
    }

    /// !IMPORTANT

    void dodadiPesna(const Pesna &newPesna) {
        if (this->brojNaSnimeniPesni >= 10) {
            return;
        }
        int currentMinutes = 0;
        for (int i = 0; i < this->brojNaSnimeniPesni; ++i) {
            currentMinutes += this->pesni[i].getMinuti();
        }

        if (newPesna.getMinuti() + currentMinutes > this->maxVremeNaPesnite) {
            return;
        }
        brojNaSnimeniPesni++;
        pesni[brojNaSnimeniPesni - 1] = newPesna;

    }

    Pesna getPesna(int index) {
        return pesni[index];
    }
    void pecatiPesniPoTip(tip t) {
        for (int i = 0; i < this->brojNaSnimeniPesni; ++i) {
            if (this->pesni[i].getTip() == t){
                this->pesni[i].pecati();
            }
        }
    }

    int getBrojNaSnimeniPesni(){

        return this->brojNaSnimeniPesni;
    }
};


int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, minuti, kojtip;
    char ime[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime, minuti, (tip) kojtip);
        p.pecati();
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i = 0; i < n; i++) {
            (omileno.getPesna(i)).pecati();
        }
    }
    else if (testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i = 0; i < omileno.getBrojNaSnimeniPesni(); i++)
            (omileno.getPesna(i)).pecati();
    }
    else if (testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        cin >> kojtip;
        omileno.pecatiPesniPoTip((tip) kojtip);

    }
    else if (testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        cin >> kojtip;
        omileno.pecatiPesniPoTip((tip) kojtip);

    }

    return 0;
}