//
// Created by Stefan on 3/5/2023.
//
#include <iostream>
#include <cstring>

using namespace std;

class Gitara {
private:
    char serialNumber[30];
    float factoryPrice;
    int dateOfManufacture;
    char type[50];
public:
    Gitara(char *type = "", char *serialNumber = "", int dateOfManufacture = 0, float factoryPrice = 0) :
            factoryPrice(factoryPrice),
            dateOfManufacture(dateOfManufacture) {

        strcpy(this->serialNumber, serialNumber);
        strcpy(this->type, type);
    }

    const char *getSeriski() const {
        return serialNumber;
    }

    float getNabavna() const {
        return factoryPrice;
    }

    int getGodina() const {
        return dateOfManufacture;
    }

    const char *getTip() const {
        return type;
    }

    void setSeriski(char *serialNumber) {
        strcpy(this->serialNumber, serialNumber);
    }

    void setTip(char *type) {
        strcpy(this->type, type);
    }

    void setDateOfManufacture(int dateOfManufacture) {
        Gitara::dateOfManufacture = dateOfManufacture;
    }

    void setFactoryPrice(float factoryPrice) {
        Gitara::factoryPrice = factoryPrice;
    }

    // methods

    bool operator==(const Gitara &object) {
        if (this == &object) {
            return true;
        }

        return false;
    }

    Gitara operator=(const Gitara &object) {
        if (this == &object) {
            return *this;
        }

        strcpy(this->serialNumber, object.getSeriski());
        strcpy(this->type, object.getTip());
        this->factoryPrice = object.factoryPrice;
        this->dateOfManufacture = object.dateOfManufacture;

        return *this;
    }


    bool daliIsti(const Gitara &object) {
        if (strcmp(this->serialNumber, object.getSeriski()) == 0) {
            return true;
        }

        return false;
    }

    void pecati() {
        printf("%s %s %.1f\n", this->serialNumber, this->type, this->factoryPrice);
    }
};

class Magacin {
private:
    char name[50];
    char location[70];
    Gitara *guitars;
    int numberOfGuitars;
    int openingDate;

    bool contains(int *array, int digit) {
        for (int i = 0; i < this->numberOfGuitars; ++i) {
            if (digit == array[i]) {
                return true;
            }
        }

        return false;
    }

public:
    Magacin(char *name = "", char *location = "", int openingDate = 0, Gitara *guitars = {}, int numberOfGuitars = 0) :
            numberOfGuitars(numberOfGuitars),
            openingDate(openingDate) {
        strcpy(this->name, name);
        strcpy(this->location, location);
        this->guitars = new Gitara[numberOfGuitars];
    }

    const char *getName() const {
        return name;
    }

    const char *getLocation() const {
        return location;
    }

    Gitara *getGuitars() const {
        return guitars;
    }

    int getNumberOfGuitars() const {
        return numberOfGuitars;
    }

    int getOpeningDate() const {
        return openingDate;
    }

    // methods

    void dodadi(Gitara &guitar) {
        Gitara *tempArray = new Gitara[this->numberOfGuitars];
        for (int i = 0; i < this->numberOfGuitars; ++i) {
            tempArray[i] = this->guitars[i];
        }

        this->guitars = new Gitara[this->numberOfGuitars + 1];
        for (int i = 0; i < this->numberOfGuitars; ++i) {
            this->guitars[i] = tempArray[i];
        }
        this->guitars[this->numberOfGuitars] = guitar;
        this->numberOfGuitars++;

        delete[] tempArray;
    }

    void prodadi(Gitara &guitar) {
        int thisGuitarIndex = -1;
        // nemozis da kompernis 2 objekti direktno, sekako nema da bidat isti oti sepak 2 razlicni objekti se
        // guitars[i] = guitar NEMA DA BIDAT ISTI
        for (int i = 0; i < this->numberOfGuitars; ++i) {
            if (this->guitars[i].daliIsti(guitar)) {
                thisGuitarIndex = i;
                break;
            }
        }
        if (thisGuitarIndex == (-1)) {
            return;
        }

        // switch to last place
        Gitara temp = this->guitars[this->numberOfGuitars - 1];
        this->guitars[this->numberOfGuitars - 1] = this->guitars[thisGuitarIndex];
        this->guitars[thisGuitarIndex] = temp;

        //remove
        Gitara *tempArray = new Gitara[this->numberOfGuitars - 1];

        for (int i = 0; i < this->numberOfGuitars - 1; ++i) {
            tempArray[i] = this->guitars[i];
        }

        this->guitars = new Gitara[this->numberOfGuitars - 1];

        for (int i = 0; i < this->numberOfGuitars - 1; ++i) {
            this->guitars[i] = tempArray[i];
        }
        this->numberOfGuitars--;

        for (int i = thisGuitarIndex; i < this->numberOfGuitars - 1; ++i) {
            temp = this->guitars[i + 1];
            this->guitars[i + 1] = this->guitars[thisGuitarIndex];
            this->guitars[thisGuitarIndex] = temp;
            thisGuitarIndex++;
        }

        // recursively remove all instances of the same guitar
        prodadi(guitar);
        delete[] tempArray;
    }

//    void prodadi(Gitara &gitara) {
//        for (int i = 0; i < this->numberOfGuitars; ++i) {
//            sell(gitara);
//        }
//    }

    void pecati(bool areNew) {
        printf("%s %s\n", this->name, this->location);

        if (!areNew) {
            for (int i = 0; i < this->numberOfGuitars; ++i) {

                this->guitars[i].pecati();
            }
            return;
        }

        for (int i = 0; i < this->numberOfGuitars; ++i) {
            if (this->guitars[i].getGodina() > this->getOpeningDate()) {

                this->guitars[i].pecati();
            }
        }
    }

    float vrednost() {
        float sum = 0;
        bool print = true;
        for (int i = 0; i < this->numberOfGuitars; ++i) {

            sum += this->guitars[i].getNabavna();
        }
        return sum;
    }
};

int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, godina;
    float cena;
    char seriski[50], tip[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Gitara ======" << endl;
        cin >> tip;
        cin >> seriski;
        cin >> godina;
        cin >> cena;
        Gitara g(tip, seriski, godina, cena);
        cout << g.getTip() << endl;
        cout << g.getSeriski() << endl;
        cout << g.getGodina() << endl;
        cout << g.getNabavna() << endl;
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata Magacin so metodot print() ======" << endl;
        Magacin kb("Magacin1", "Lokacija1");
        kb.pecati(false);
    } else if (testCase == 3) {
        cout << "===== Testiranje na klasata Magacin so metodot dodadi() ======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2005);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;
            Gitara g(tip, seriski, godina, cena);
            cout << "gitara dodadi" << endl;
            kb.dodadi(g);
        }
        kb.pecati(true);
    } else if (testCase == 4) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() ======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2012);
        cin >> n;
        Gitara brisi;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip, seriski, godina, cena);
            if (i == 2)
                brisi = g;
            cout << "gitara dodadi" << endl;
            kb.dodadi(g);
        }
        kb.pecati(false);
        kb.prodadi(brisi);
        kb.pecati(false);
    } else if (testCase == 5) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() i pecati(true) ======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2011);
        cin >> n;
        Gitara brisi;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip, seriski, godina, cena);
            if (i == 2)
                brisi = g;
            cout << "gitara dodadi" << endl;
            kb.dodadi(g);
        }
        kb.pecati(true);
        kb.prodadi(brisi);
        cout << "Po brisenje:" << endl;
        Magacin kb3;
        kb3 = kb;
        kb3.pecati(true);
    } else if (testCase == 6) {
        cout << "===== Testiranje na klasata Magacin so metodot vrednost()======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2011);
        cin >> n;
        Gitara brisi;
        for (int i = 0; i < n; i++) {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip, seriski, godina, cena);
            if (i == 2)
                brisi = g;
            kb.dodadi(g);
        }
        cout << kb.vrednost() << endl;
        kb.prodadi(brisi);
        cout << "Po brisenje:" << endl;
        cout << kb.vrednost();
        Magacin kb3;
        kb3 = kb;
    }
    return 0;
}
