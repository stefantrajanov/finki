//
// Created by Stefan on 3/4/2023.
//
#include<iostream>
#include<cstring>

using namespace std;

class Patnik {
private:
    char name[105];
    int trainClass;
    bool bicycle;
public:
    Patnik(char *name = "", int trainClass = 1, bool bicycle = false) : trainClass(trainClass), bicycle(bicycle) {
        strcpy(this->name, name);
    }

    void setName(char *name) {
        strcpy(this->name, name);
    }

    const char *getName() const {
        return name;
    }

    int getTrainClass() const {
        return trainClass;
    }

    void setTrainClass(int trainClass) {
        Patnik::trainClass = trainClass;
    }

    bool hasBicycle() const {
        return bicycle;
    }

    void setBicycle(bool bicycle) {
        Patnik::bicycle = bicycle;
    }

    friend ostream &operator<<(ostream &os, const Patnik &object) {
        os << object.name << endl;
        os << object.trainClass << endl;
        os << object.bicycle << endl;
        return os;
    }

};

class Voz {
private:
    char finalDestination[105];
    Patnik *passengers;
    int numberOfPassengers;
    int allowedBicycles;
    int firstClassKickedOut = 0;
    int secondClassKickedOut = 0;
    int *secondTempArray;

    bool checkIfFirstClass(const Patnik &passenger) {
        if (passenger.getTrainClass() == 1) {
            return true;
        }
        return false;
    }

public:
    Voz() = default;

    Voz(char *finalDestination = "", int allowedBicycles = 0, Patnik *passengers = {}, int numberOfPassengers = 0) :
            numberOfPassengers(numberOfPassengers),
            allowedBicycles(allowedBicycles) {
        strcpy(this->finalDestination, finalDestination);
        this->passengers = new Patnik[numberOfPassengers];

        for (int i = 0; i < numberOfPassengers; ++i) {
            this->passengers[i] = passengers[i];
        }

        this->secondTempArray = new int[numberOfPassengers];
        for (int i = 0; i < numberOfPassengers; ++i) {
            secondTempArray[i] = 0;
        }
    }

    Voz operator+=(const Patnik &passenger) {
        if (passenger.hasBicycle()) {
            if (this->allowedBicycles > 0) {
                int currentNumberOfBicycles = 0;
                for (int i = 0; i < this->numberOfPassengers; ++i) {
                    if (this->passengers[i].hasBicycle()) {
                        currentNumberOfBicycles++;
                    }
                }

                if (currentNumberOfBicycles + 1 > allowedBicycles) {
                    if (checkIfFirstClass(passenger)) {
                        bool allFirstClass = false;
                        for (int i = 0; i < this->numberOfPassengers; ++i) {
                            if (!(checkIfFirstClass(this->passengers[i])) && this->passengers[i].hasBicycle()) {
                                if (secondTempArray[i] == 0) {
                                    int temp = passengers[i].getTrainClass();
                                    bool b = passengers[i].hasBicycle();
                                    secondTempArray[i] = 1;
                                    this->secondClassKickedOut++;
                                    allFirstClass = false;
                                    break;
                                }
                                allFirstClass = true;
                            }
                        }
                        if (allFirstClass) {
                            this->firstClassKickedOut++;
                        }
                    } else {
                        this->secondClassKickedOut++;
                    }
                }
            } else {
                return *this;
            }
        }

        Patnik *tempArray = new Patnik[this->numberOfPassengers];
        for (int i = 0; i < this->numberOfPassengers; ++i) {
            tempArray[i] = this->passengers[i];
        }

        this->passengers = new Patnik[this->numberOfPassengers + 1];

        for (int i = 0; i < this->numberOfPassengers; ++i) {
            this->passengers[i] = tempArray[i];
        }
        this->passengers[this->numberOfPassengers] = passenger;
        this->numberOfPassengers++;

        delete[] tempArray;
        return *this;
    }

    friend ostream &operator<<(ostream &os, const Voz &object) {

        os << object.finalDestination << endl;

        for (int i = 0; i < object.numberOfPassengers; ++i) {
            os << object.passengers[i] << endl;
        }

        return os;
    }

    void patniciNemaMesto() {
        cout << "Brojot na patnici od 1-va klasa koi ostanale bez mesto e: " << this->firstClassKickedOut << endl;
        cout << "Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: " << this->secondClassKickedOut << endl;

        delete[] secondTempArray;
    }
};


int main() {
    Patnik p;
    char ime[100], destinacija[100];
    int n;
    bool velosiped;
    int klasa;
    int maxv;
    cin >> destinacija >> maxv;
    cin >> n;
    Voz v(destinacija, maxv);
    //cout<<v<<endl;
    for (int i = 0; i < n; i++) {
        cin >> ime >> klasa >> velosiped;
        Patnik p(ime, klasa, velosiped);
        //cout<<p<<endl;
        v += p;
    }
    cout << v;
    v.patniciNemaMesto();

    return 0;
}
