//
// Created by Stefan on 3/4/2023.
//
// vashiot kod ovde
#include <iostream>
#include <cstring>

using namespace std;


class Ucesnik {
private:
    char *name;
    bool gender;
    int age;
public:
    Ucesnik() {}

    Ucesnik(char *name, bool gender, int age) : gender(gender), age(age) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    bool operator>(const Ucesnik &object) const {
        if (this->age > object.age) {
            return true;
        }
        return false;
    }

    friend ostream &operator<<(ostream &os, const Ucesnik &object) {
        os << object.name << endl;
        if (object.gender) {
            os << "mashki " << endl;
        } else {
            os << "zhenski " << endl;
        }
        os << object.age << endl;

        return os;
    }

    char *getName() const {
        return name;
    }

    bool isGender() const {
        return gender;
    }

    int getAge() const {
        return age;
    }

//    ~Ucesnik() {
//        delete[] name;
//    }
};

class Maraton {
private:
    char location[105];
    Ucesnik *competitors;
    int numberOfCompetitors;
public:
    Maraton(){}
    Maraton(char *location = "", Ucesnik *competitors = {}, int numberOfCompetitors = 0) : numberOfCompetitors
                                                                                                   (numberOfCompetitors) {
        strcpy(this->location, location);

        this->competitors = new Ucesnik[numberOfCompetitors];
        for (int i = 0; i < numberOfCompetitors; ++i) {
            this->competitors[i] = competitors[i];
        }
    }

    Maraton operator+=(Ucesnik &object) {
        Ucesnik *tempArray = new Ucesnik[this->numberOfCompetitors];
        for (int i = 0; i < this->numberOfCompetitors; ++i) {
            tempArray[i] = this->competitors[i];
        }

        this->competitors = new Ucesnik[this->numberOfCompetitors + 1];

        for (int i = 0; i < this->numberOfCompetitors; ++i) {
            this->competitors[i] = tempArray[i];
        }
        this->competitors[numberOfCompetitors] = object;
        this->numberOfCompetitors++;

        delete[] tempArray;
        return *this;
    }

    float prosecnoVozrast() {
        float averageAge = 0;
        int ageSum = 0;

        for (int i = 0; i < this->numberOfCompetitors; ++i) {
            ageSum += this->competitors[i].getAge();
        }
        averageAge = (float) ageSum / (float) this->numberOfCompetitors;

        return averageAge;
    }

    void pecatiPomladi(Ucesnik &ucesnik) {
        int compareAge = ucesnik.getAge();

        for (int i = 0; i < this->numberOfCompetitors; ++i) {
            if (this->competitors[i].getAge() < compareAge) {
                cout << competitors[i];
            }
        }
    }

//    ~Maraton() {
//        delete[] competitors;
//    }
};


int main() {
    char ime[100];
    bool maski;
    int vozrast, n;
    cin >> n;
    char lokacija[100];
    cin >> lokacija;
    Maraton m(lokacija);
    Ucesnik **u = new Ucesnik *[n];
    for (int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
        u[i] = new Ucesnik(ime, maski, vozrast);
        m += *u[i];
    }
    m.pecatiPomladi(*u[n - 1]);
    cout << m.prosecnoVozrast() << endl;
    for (int i = 0; i < n; ++i) {
        delete u[i];
    }
    delete[] u;
    return 0;
}