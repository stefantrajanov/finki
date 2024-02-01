//
// Created by Stefan on 5/3/2023.
//
#include<iostream>
#include<string.h>
using namespace std;

//место за вашиот код
class Delo{
protected:
    char name[60];
    int yearDate;
    char countryOfOrigin[60];
public:
    Delo(){
        strcpy(this->name,"");
        strcpy(this->countryOfOrigin,"");
        this->yearDate = 0;
    }
    Delo(char *name, int yearDate, char *countryOfOrigin) : yearDate(yearDate){
        strcpy(this->name,name);
        strcpy(this->countryOfOrigin,countryOfOrigin);
    }
    Delo(const Delo &object){
        strcpy(this->name,object.name);
        strcpy(this->countryOfOrigin,object.countryOfOrigin);
        this->yearDate = object.yearDate;
    }
    Delo &operator=(const Delo &object){
        if (this == &object){
            return *this;
        }

        strcpy(this->name,object.name);
        strcpy(this->countryOfOrigin,object.countryOfOrigin);
        this->yearDate = object.yearDate;

        return *this;
    }

    void setYearDate(int yearDate) {
        Delo::yearDate = yearDate;
    }

    const char *getName() const {
        return name;
    }

    int getYearDate() const {
        return yearDate;
    }

    const char *getCountryOfOrigin() const {
        return countryOfOrigin;
    }

    // methods

    bool operator==(const Delo &object) const{
        if (strcmp(this->name, object.name) == 0){
            return true;
        }

        return false;
    }


};

class Pretstava{
protected:
    Delo creation;
    int numberOfTicketsSold;
    char dateOfOpening[20];
public:
    Pretstava(){
        this->creation = Delo();
        this->numberOfTicketsSold = 0;
        strcpy(this->dateOfOpening, "");
    }
    Pretstava(const Delo &creation, int numberOfTicketsSold, char *dateOfOpening) : creation(creation),numberOfTicketsSold(numberOfTicketsSold) {
        strcpy(this->dateOfOpening, dateOfOpening);
    }
    Pretstava(const Pretstava &object){
        this->creation = object.creation;
        this->numberOfTicketsSold = object.numberOfTicketsSold;
        strcpy(this->dateOfOpening, object.dateOfOpening);
    }
    Pretstava &operator=(const Pretstava &object){
        if (this == &object){
            return *this;
        }
        this->creation = object.creation;
        this->numberOfTicketsSold = object.numberOfTicketsSold;
        strcpy(this->dateOfOpening, object.dateOfOpening);
        return *this;
    }

    const Delo &getDelo() const {
        return creation;
    }

    int getNumberOfTicketsSold() const {
        return numberOfTicketsSold;
    }

    const char *getDateOfOpening() const {
        return dateOfOpening;
    }

    // methods
     virtual int cena(){
        int yearPrice;
        int countryPrice;

        int yearTemp = creation.getYearDate() / 100;
        char countryTemp[70];
        strcpy(countryTemp, creation.getCountryOfOrigin());

        if (yearTemp == 19 || yearTemp == 20 ){
            yearPrice = 50; //21 20
        }else if(yearTemp == 18){
            yearPrice = 75; // 19
        }else {
            yearPrice = 100; // <19
        }

        if (strcmp(countryTemp, "Italija") == 0){
            countryPrice = 100;
        }else if (strcmp(countryTemp, "Rusija") == 0){
            countryPrice = 150;
        }else {
            countryPrice = 80;
        }

        return (countryPrice + yearPrice);
    }
};

class Opera : public Pretstava{
public:
    Opera(){
        this->creation = Delo();
        this->numberOfTicketsSold = 0;
        strcpy(this->dateOfOpening, "");
    }
    Opera(const Delo &creation, int numberOfTicketsSold, char *dateOfOpening) {
        this->creation = creation;
        this->numberOfTicketsSold = numberOfTicketsSold;
        strcpy(this->dateOfOpening, dateOfOpening);
    }
    Opera(const Opera &object){
        this->creation = object.creation;
        this->numberOfTicketsSold = object.numberOfTicketsSold;
        strcpy(this->dateOfOpening, object.dateOfOpening);
    }
    Opera &operator=(const Opera &object){
        if (this == &object){
            return *this;
        }
        this->creation = object.creation;
        this->numberOfTicketsSold = object.numberOfTicketsSold;
        strcpy(this->dateOfOpening, object.dateOfOpening);
        return *this;
    }
};

class Balet : public Pretstava{
private:
    static int price;
public:
    Balet(){
        this->creation = Delo();
        this->numberOfTicketsSold = 0;
        strcpy(this->dateOfOpening, "");
//        this->price = 150;
    }
    Balet(const Delo &creation, int numberOfTicketsSold, char *dateOfOpening){
        this->creation = creation;
        this->numberOfTicketsSold = numberOfTicketsSold;
        strcpy(this->dateOfOpening, dateOfOpening);
//        this->price = 150;

    }
    Balet(const Balet &object){
        this->creation = object.creation;
        this->numberOfTicketsSold = object.numberOfTicketsSold;
        strcpy(this->dateOfOpening, object.dateOfOpening);
//        this->price = 150;


    }
    Balet &operator=(const Balet &object){
        if (this == &object){
            return *this;
        }
        this->creation = object.creation;
        this->numberOfTicketsSold = object.numberOfTicketsSold;
        strcpy(this->dateOfOpening, object.dateOfOpening);
//        this->price = 150;

        return *this;
    }
    int cena() override{
        int yearPrice;
        int countryPrice;

        int yearTemp = creation.getYearDate() / 100;
        char countryTemp[70];
        strcpy(countryTemp, creation.getCountryOfOrigin());

        if (yearTemp == 19 || yearTemp == 20 ){
            yearPrice = 50; //21 20
        }else if(yearTemp == 18){
            yearPrice = 75; // 19
        }else {
            yearPrice = 100; // <19
        }

        if (strcmp(countryTemp, "Italija\0") == 0){
            countryPrice = 100;
        }else if (strcmp(countryTemp, "Rusija\0") == 0){
            countryPrice = 150;
        }else {
            countryPrice = 80;
        }

        return (countryPrice + yearPrice + price);
    }

    static void setCenaBalet(int _price) {
        price = _price;
    }
};
int Balet::price = 150;


int prihod(Pretstava **presentations, int n){
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += (presentations[i]->getNumberOfTicketsSold() * presentations[i]->cena());
    }

    return sum;
}
int brojPretstaviNaDelo(Pretstava **presentations, int n, const Delo &creation){
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        if (presentations[i]->getDelo() == creation){
            counter++;
        }
    }

    return counter;
}

//citanje na delo
Delo readDelo(){
    char ime[50];
    int godina;
    char zemja[50];
    cin>>ime>>godina>>zemja;
    return Delo(ime,godina,zemja);
}
//citanje na pretstava
Pretstava* readPretstava(){
    int tip; //0 za Balet , 1 za Opera
    cin>>tip;
    Delo d=readDelo();
    int brojProdadeni;
    char data[15];
    cin>>brojProdadeni>>data;
    if (tip==0)  return new Balet(d,brojProdadeni,data);
    else return new Opera(d,brojProdadeni,data);
}
int main(){
    int test_case;
    cin>>test_case;

    switch(test_case){
        case 1:
            //Testiranje na klasite Opera i Balet
        {
            cout<<"======TEST CASE 1======="<<endl;
            Pretstava* p1=readPretstava();
            cout<<p1->getDelo().getName()<<endl;
            Pretstava* p2=readPretstava();
            cout<<p2->getDelo().getName()<<endl;
        }break;

        case 2:
            //Testiranje na  klasite Opera i Balet so cena
        {
            cout<<"======TEST CASE 2======="<<endl;
            Pretstava* p1=readPretstava();
            cout<<p1->cena()<<endl;
            Pretstava* p2=readPretstava();
            cout<<p2->cena()<<endl;
        }break;

        case 3:
            //Testiranje na operator ==
        {
            cout<<"======TEST CASE 3======="<<endl;
            Delo f1=readDelo();
            Delo f2=readDelo();
            Delo f3=readDelo();

            if (f1==f2) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;
            if (f1==f3) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;

        }break;

        case 4:
            //testiranje na funkcijata prihod
        {
            cout<<"======TEST CASE 4======="<<endl;
            int n;
            cin>>n;
            Pretstava **pole=new Pretstava*[n];
            for (int i=0;i<n;i++){
                pole[i]=readPretstava();

            }
            cout<<prihod(pole,n);
        }break;

        case 5:
            //testiranje na prihod so izmena na cena za 3d proekcii
        {
            cout<<"======TEST CASE 5======="<<endl;
            int cenaBalet;
            cin>>cenaBalet;
            Balet::setCenaBalet(cenaBalet);
            int n;
            cin>>n;
            Pretstava **pole=new Pretstava*[n];
            for (int i=0;i<n;i++){
                pole[i]=readPretstava();
            }
            cout<<prihod(pole,n);
        }break;

        case 6:
            //testiranje na brojPretstaviNaDelo
        {
            cout<<"======TEST CASE 6======="<<endl;
            int n;
            cin>>n;
            Pretstava **pole=new Pretstava*[n];
            for (int i=0;i<n;i++){
                pole[i]=readPretstava();
            }

            Delo f=readDelo();
            cout<<brojPretstaviNaDelo(pole,n,f);
        }break;

    };


    return 0;
}
