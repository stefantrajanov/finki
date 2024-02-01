//
// Created by Stefan on 5/6/2023.
//
// вашиот код треба да биде тука

#include <iostream>
#include <cstring>
using namespace std;

class Transport{
protected:
    char destination[50];
    int basePrice;
    int distance;
public:
    const char *getDestination() const {
        return destination;
    }

    int getBasePrice() const {
        return basePrice;
    }

    int getDistance() const {
        return distance;
    }

    void setBasePrice(int _basePrice) {
        Transport::basePrice = _basePrice;
    }

    void setDistance(int _distance) {
        Transport::distance = _distance;
    }

    void setDestination(char *_dest){
        strcpy(this->destination, _dest);
    }

    //methods

    virtual int cenaTransport() const = 0;

    bool operator<(const Transport &object) const{
        if (this->distance < object.distance){
            return true;
        }

        return false;
    }

    friend ostream &operator<<(ostream &os, const Transport &transport) {
        os << transport.destination << " " << transport.distance << " " << transport.cenaTransport() << endl;
        return os;
    }
};

class AvtomobilTransport : public Transport{
private:
    bool hasPaidDriver;
public:
    AvtomobilTransport(char *destination, int basePrice, int distance, bool hasPaidDriver){
        strcpy(this->destination,destination);
        this->basePrice = basePrice;
        this->distance = distance;
        this->hasPaidDriver = hasPaidDriver;
    }

    bool isHasPaidDriver() const {
        return hasPaidDriver;
    }

    void setHasPaidDriver(bool _hasPaidDriver) {
        AvtomobilTransport::hasPaidDriver = _hasPaidDriver;
    }
    // method

    int cenaTransport() const override {
        int totalPrice = this->basePrice;

        if (this->hasPaidDriver){
            totalPrice *= 1.2;
        }

        return totalPrice;
    }
};


class KombeTransport  : public Transport{
private:
    int capacity;
public:
    KombeTransport(char *destination, int basePrice, int distance, int capacity){
        strcpy(this->destination,destination);
        this->basePrice = basePrice;
        this->distance = distance;
        this->capacity = capacity;
    }

    int getCapacity() const {
        return capacity;
    }

    void setCapacity(int _capacity) {
        KombeTransport::capacity = _capacity;
    }

    // method

    int cenaTransport() const override{
        int totalPrice = this->basePrice;

        for (int i = 0; i < capacity; ++i) {
            totalPrice -= 200;
        }

        return totalPrice;
    }

};

void pecatiPoloshiPonudi(Transport **offers, int n, AvtomobilTransport &transport){
    Transport **tempArray = new Transport * [n];
    for (int i = 0; i < n; ++i) {
        tempArray[i] = offers[i];
    }
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if(tempArray[minIndex]->cenaTransport() > tempArray[j]->cenaTransport()){
                minIndex = j;
            }
        }
        if (minIndex != i){
            Transport* temp = tempArray[i];
            tempArray[i] = tempArray[minIndex];
            tempArray[minIndex] = temp;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (tempArray[i]->cenaTransport() > transport.cenaTransport()){
            cout << *tempArray[i];
        }
    }
}

int main(){

    char destinacija[20];
    int tip,cena,rastojanie,lugje;
    bool shofer;
    int n;
    cin>>n;
    Transport  **ponudi;
    ponudi=new Transport *[n];

    for (int i=0;i<n;i++){

        cin>>tip>>destinacija>>cena>>rastojanie;
        if (tip==1) {
            cin>>shofer;
            ponudi[i]=new AvtomobilTransport(destinacija,cena,rastojanie,shofer);

        }
        else {
            cin>>lugje;
            ponudi[i]=new KombeTransport(destinacija,cena,rastojanie,lugje);
        }


    }

    AvtomobilTransport nov("Ohrid",2000,600,false);
    pecatiPoloshiPonudi(ponudi,n,nov);

    for (int i=0;i<n;i++) delete ponudi[i];
    delete [] ponudi;
    return 0;
}
