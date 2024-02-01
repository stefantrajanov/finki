//
// Created by Stefan on 3/6/2023.
//
#include <iostream>
#include <cstring>

using namespace std;

enum Tip {
    LINUX, UNIX, WINDOWS
};

class OperativenSistem {
private:
    char *name;
    float version;
    Tip type;
    float size;
public:
    OperativenSistem(char *name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    OperativenSistem(char *name="", float version = 0, Tip type = WINDOWS, float size = 0) : version(version),
                                                                                          type(type),
                                                                                          size(size) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    OperativenSistem &operator=(const OperativenSistem &object) {
        if (this == &object) {
            return *this;
        }
        this->name = new char[strlen(object.name) + 1];
        strcpy(this->name, object.name);
        this->type = object.type;
        this->size = object.size;
        this->version = object.version;

        return *this;
    }

    bool ednakviSe(const OperativenSistem &os) {
        return (
                (strcmp(this->name, os.name) == 0)
                &&
                this->version == os.version
                &&
                this->type == os.type
                &&
                this->size == os.size
        );
    }

    int sporediVerzija(const OperativenSistem &os) {
        if (this->version == os.version) {
            return 0;
        } else if (this->version > os.version) {
            return 1;
        }
        return (-1);
    }

    bool istaFamilija(const OperativenSistem &os) {
        return ((strcmp(this->name, os.name) == 0) && this->type == os.type);
    }

    char *getName() const {
        return name;
    }

    void pecati() {
//        printf("Ime: %s Verzija: %.2f Tip: %d Golemina:%.2fGB\n", this->name, this->version, this->type, this->size);
        cout << "Ime: " << this->name;
        cout << " Verzija: " << this->version;
        cout << " Tip: " <<this->type;
        cout << " Golemina:"<< this->size << "GB" << endl;
    }

//    virtual ~OperativenSistem() {
//        delete[] this->name;
//    }
};

class Repozitorium {
private:
    char name[30];
    OperativenSistem *operatingSystems;
    int numberOf_OS;
public:
    Repozitorium(char *name = "", OperativenSistem *operatingSystems = {}, int numberOf_OS = 0) : numberOf_OS
                                                                                                          (numberOf_OS) {
        strcpy(this->name, name);
        this->operatingSystems = new OperativenSistem[numberOf_OS];

        for (int i = 0; i < numberOf_OS; ++i) {
            this->operatingSystems[i] = operatingSystems[i];
        }
    }

    void pecatiOperativniSistemi() {
        printf("Repozitorium: %s\n", this->name);
        for (int i = 0; i < this->numberOf_OS; ++i) {
            this->operatingSystems[i].pecati();
        }
    }

    void izbrishi(const OperativenSistem &operativenSistem) {
        int osIndex = (-1);
        for (int i = 0; i < this->numberOf_OS; ++i) {
            if (this->operatingSystems[i].ednakviSe(operativenSistem)) {
                osIndex = i;
                break;
            }
        }

        if (osIndex == (-1)) {
            return;
        }

        // switch
        OperativenSistem temp = this->operatingSystems[this->numberOf_OS - 1];
        this->operatingSystems[this->numberOf_OS - 1] = this->operatingSystems[osIndex];
        this->operatingSystems[osIndex] = temp;

        // delete
        OperativenSistem *tempArray = new OperativenSistem[this->numberOf_OS - 1];
        for (int i = 0; i < this->numberOf_OS - 1; ++i) {
            tempArray[i] = this->operatingSystems[i];
        }

        this->operatingSystems = new OperativenSistem[this->numberOf_OS - 1];
        for (int i = 0; i < this->numberOf_OS - 1; ++i) {
            this->operatingSystems[i] = tempArray[i];
        }
        this->numberOf_OS--;

        // reorder because of test cases
        for (int i = osIndex; i < this->numberOf_OS - 1; ++i) {
            temp = this->operatingSystems[i + 1];
            this->operatingSystems[i + 1] = this->operatingSystems[i];
            this->operatingSystems[i] = temp;
        }

        delete[] tempArray;
    }

    void dodadi(const OperativenSistem &newOs) {
        for (int i = 0; i < this->numberOf_OS; ++i) {
            if (this->operatingSystems[i].istaFamilija(newOs)) {
                if (this->operatingSystems[i].sporediVerzija(newOs) == (-1)) {
                    this->operatingSystems[i] = newOs;
                    return;
                }
            }
        }
        OperativenSistem *tempArray = new OperativenSistem[this->numberOf_OS];
        for (int i = 0; i < this->numberOf_OS; ++i) {
            tempArray[i] = this->operatingSystems[i];
        }

        this->operatingSystems = new OperativenSistem[this->numberOf_OS + 1];

        for (int i = 0; i < this->numberOf_OS; ++i) {
            this->operatingSystems[i] = tempArray[i];
        }
        this->operatingSystems[this->numberOf_OS] = newOs;
        this->numberOf_OS++;

        delete[] tempArray;
    }
};

int main() {
    char repoName[20];
    cin >> repoName;
    Repozitorium repozitorium = Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin >> brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i < brojOperativniSistemi; i++) {
        cin >> ime;
        cin >> verzija;
        cin >> tip;
        cin >> golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip) tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();
    cin >> ime;
    cin >> verzija;
    cin >> tip;
    cin >> golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip) tip, golemina);
    cout << "=====Brishenje na operativen sistem=====" << endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}