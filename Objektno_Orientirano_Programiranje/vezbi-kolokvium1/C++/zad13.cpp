//
// Created by Stefan on 3/5/2023.
//
#include<iostream>
#include <utility>
#include<cstring>
using namespace std;

//ова е место за вашиот код

class Zichara{
private:
    char *place;
    int price;
public:
    Zichara() = default;
    Zichara(char *place, int price) : price(price) {
        this->place = new char[strlen(place) + 1];
        strcpy(this->place,place);
    }

    const string &getPlace() const {
        return place;
    }

    int getPrice() const {
        return price;
    }

    void setPrice(int price) {
        Zichara::price = price;
    }

    Zichara& operator= (const Zichara &object){
        if (this == &object){
            return *this;
        }
        this->price = object.price;
        this->place = object.place;

        return *this;
    }

//    ~Zichara(){
//        delete[] this->place;
//    }
};


class PlaninarskiDom {
private:
    char *name;
    int pricePerSeason[2]; // 0 - letna sezona, 1 - zimska
    char residentClass;
    bool hasZichara;
    Zichara zichara;
public:
    PlaninarskiDom() = default;
    PlaninarskiDom(char *name, int *pricePerSeason, char residentClass): residentClass(residentClass){
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->pricePerSeason[0] = pricePerSeason[0];
        this->pricePerSeason[1] = pricePerSeason[1];
    }

    PlaninarskiDom(char *name, int *pricePerSeason, char residentClass, bool hasZichara, Zichara &zichara)
            : residentClass(residentClass), hasZichara(hasZichara),
              zichara(zichara) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name,name);
        this->pricePerSeason[0] = pricePerSeason[0];
        this->pricePerSeason[1] = pricePerSeason[1];
    }

    const Zichara &getZichara() const {
        return zichara;
    }

    void setZichara(const Zichara &zichara) {
        PlaninarskiDom::zichara = zichara;
    }

    // get

    bool checkIfHasZichara() const {
        return hasZichara;
    }

    char getResidentClass() const {
        return residentClass;
    }

    const int *getPricePerSeason() const {
        return pricePerSeason;
    }

    const string &getName() const {
        return name;
    }

    // set
    void setPricePerSeason(int *pricePerSeason){
        this->pricePerSeason[0] = pricePerSeason[0];
        this->pricePerSeason[1] = pricePerSeason[1];
    }


    void setResidentClass(char residentClass) {
        PlaninarskiDom::residentClass = residentClass;
    }

    void setHasZichara(bool hasZichara) {
        PlaninarskiDom::hasZichara = hasZichara;
    }

    PlaninarskiDom& operator= (const PlaninarskiDom &object){
        if (this == &object){
            return *this;
        }

        this->name = object.name;
        this->pricePerSeason[0] = object.pricePerSeason[0];
        this->pricePerSeason[1] = object.pricePerSeason[1];
        this->zichara = object.zichara;
        this->residentClass = object.residentClass;
        this->hasZichara = object.hasZichara;

        return *this;
    }

    PlaninarskiDom operator--(){
        if (this->residentClass == 'F'){
            return *this;
        }

        this->residentClass++;
        return *this;
    }

    friend ostream& operator << (ostream &os, const PlaninarskiDom &object){
        os << object.name << " klasa:" << object.residentClass;

        if (object.checkIfHasZichara()){
            os << " so Zichara";
        }

        os << endl;

        return os;
    }

    bool operator <=(char compareClass){
        if (this->getResidentClass() < compareClass){
            return false;
        }

        return true;
    }

    void presmetajDnevenPrestoj(int day, int mounth, int &price){
        if (day > 31 || day < 1 || mounth < 1 || mounth > 12){
            throw 1;
        }

        if (mounth == 9 && day > 1){
            if (this->checkIfHasZichara()) {
                price = this->pricePerSeason[1] + this->getZichara().getPrice();
            }
            else {
                price = this->pricePerSeason[1];
            }
            return;
        }

        if (mounth <= 8 && mounth >= 4){
            if (this->checkIfHasZichara()) {
                price = this->pricePerSeason[0] + this->getZichara().getPrice();
            }
            else {
                price = this->pricePerSeason[0];
            }
        }else{
            if (this->checkIfHasZichara()) {
                price = this->pricePerSeason[1] + this->getZichara().getPrice();
            }
            else {
                price = this->pricePerSeason[1];
            }
        }
    }
};

int main(){

    PlaninarskiDom p; //креирање на нов објект од класата планинарски дом

    //во следниот дел се вчитуваат информации за планинарскиот дом
    char imePlaninarskiDom[15],mestoZichara[30],klasa;
    int ceni[12];
    int dnevnakartaZichara;
    bool daliZichara;
    cin>>imePlaninarskiDom;
    for (int i=0;i<2;i++) cin>>ceni[i];
    cin>>klasa;
    cin>>daliZichara;

    //во следниот дел се внесуваат информации и за жичарата ако постои
    if (daliZichara) {
        cin>>mestoZichara>>dnevnakartaZichara;
        PlaninarskiDom pom(imePlaninarskiDom,ceni,klasa);
        Zichara r(mestoZichara,dnevnakartaZichara);
        pom.setZichara(r);
        p=pom;
    }
    else{
        PlaninarskiDom *pok=new PlaninarskiDom(imePlaninarskiDom,ceni,klasa);
        p=*pok;
    }

    //се намалува класата на планинарскиот дом за 2
    --p;
    --p;

    int cena;
    int den,mesec;
    cin>>den>>mesec;
    try{
        p.presmetajDnevenPrestoj(den,mesec,cena); //тука се користи функцијата presmetajDnevenPrestoj
        cout<<"Informacii za PlaninarskiDomot:"<<endl;
        cout<<p;
        if (p<='D')
            cout<<"Planinarskiot dom za koj se vneseni informaciite ima klasa poniska ili ista so D\n";

        cout<<"Cenata za "<<den<<"."<<mesec<<" e "<<cena; //се печати цената за дадениот ден и месец
    }
    catch (int){
        cout<<"Mesecot ili denot e greshno vnesen!";
    }
}
