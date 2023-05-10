//
// Created by Stefan on 5/2/2023.
//
#include <iostream>
#include <cstring>
using namespace std;

class Koncert{
protected:
    char name[30];
    char location[30];
    float seasonDiscount;
    float price;
public:
    Koncert(char *name, char *location, float price) : price
    (price) {
        strcpy(this->name,name);
        strcpy(this->location,location);
        this->seasonDiscount = 20;
    }
    Koncert(const Koncert &object){
        strcpy(this->name,object.name);
        strcpy(this->location,object.location);
        this->seasonDiscount = object.seasonDiscount;
        this->price = object.price;
    }
    Koncert &operator=(const Koncert &object) {
        if(this == &object){
            return *this;
        }
        strcpy(this->name,object.name);
        strcpy(this->location,object.location);
        this->seasonDiscount = object.seasonDiscount;
        this->price = object.price;

        return *this;
    }

    // methods


    // get
    const char *getNaziv() const {
        return name;
    }

    const char *getLocation() const {
        return location;
    }

    float getSezonskiPopust() const {
        return (seasonDiscount/100);
    }

    float getPrice() const {
        return price;
    }
    // get

    void setSezonskiPopust(float seasonDiscount) {
        if (seasonDiscount < 1){
            seasonDiscount *= 100;
        }

        Koncert::seasonDiscount = seasonDiscount;
    }

    virtual float cena(){
        float discount = this->price * (this->seasonDiscount/100);

        return (this->price - discount);
    }

};

class ElektronskiKoncert : public Koncert{
private:
    char *nameDJ;
    float timeLength;
    bool isDayConcert;
public:
    ElektronskiKoncert(char *name, char *location, float price, char *nameDj, float timeLength, bool isDayConcert)
            : Koncert(name, location, price), timeLength(timeLength), isDayConcert(isDayConcert) {
        this->nameDJ = new char[strlen(nameDj) + 1];
        strcpy(this->nameDJ, nameDj);
    }
    ElektronskiKoncert &operator=(const ElektronskiKoncert &object){
        if (this == &object){
            return *this;
        }
        delete [] nameDJ;

        strcpy(this->name,object.name);
        strcpy(this->location,object.location);
        this->seasonDiscount = object.seasonDiscount;
        this->price = object.price;
        this->nameDJ = new char[strlen(object.nameDJ) + 1];
        strcpy(this->nameDJ, object.nameDJ);
        this->timeLength = object.timeLength;
        this->isDayConcert = object.isDayConcert;

        return *this;
    }
    ~ElektronskiKoncert(){
        delete [] nameDJ;
    }

    // methods


    float cena() override{
        float discount = (this->price * (this->seasonDiscount/100));

        float discountedPrice = (this->price - discount);

        if (this->timeLength > 5 && this->timeLength < 7 ){
            discountedPrice += 150;
        }else if (this->timeLength >= 7){
            discountedPrice += 360;
        }

        if(this->isDayConcert){
            discountedPrice -= 50;
        }else{
            discountedPrice += 100;
        }


        return discountedPrice;
    }


};

void najskapKoncert(Koncert ** concerts, int n){
    float maxPrice = 0;
    int allCounter = 0;
    int index;
    int electronicConcertCounter = 0;
    for (int i = 0; i < n; ++i) {
        if (dynamic_cast<ElektronskiKoncert *>(concerts[i])){
            electronicConcertCounter++;
        }
        allCounter++;
        if(maxPrice < concerts[i]->cena()){
            maxPrice = concerts[i]->cena();
            index = i;
        }
    }

    cout << "Najskap koncert: "<<concerts[index]->getNaziv() << " "<< maxPrice << endl;
    cout << "Elektronski koncerti: " << electronicConcertCounter << " od vkupno " << allCounter << endl;
}

bool prebarajKoncert(Koncert ** concerts, int n, char * name, bool elec){
    if (elec) {
        for (int i = 0; i < n; ++i) {
            if (dynamic_cast<ElektronskiKoncert *>(concerts[i])){
                if (strcmp(concerts[i]->getNaziv(), name) == 0){
                    cout <<concerts[i]->getNaziv() << " "<< concerts[i]->cena() << endl;
                    return true;
                }
            }
        }

        return false;
    }

    for (int i = 0; i < n; ++i) {
        if (strcmp(concerts[i]->getNaziv(), name) == 0){
            cout <<concerts[i]->getNaziv() << " "<< concerts[i]->cena() << endl;
            return true;
        }
    }
    return false;
}

int main(){

    int tip,n,novaCena;
    char naziv[100], lokacija[100], imeDJ[40];
    bool dnevna;
    float cenaBilet, novPopust;
    float casovi;

    cin>>tip;
    if (tip==1){//Koncert
        cin>>naziv>>lokacija>>cenaBilet;
        Koncert k1(naziv,lokacija,cenaBilet);
        cout<<"Kreiran e koncert so naziv: "<<k1.getNaziv()<<endl;
    }
    else if (tip==2){//cena - Koncert
        cin>>naziv>>lokacija>>cenaBilet;
        Koncert k1(naziv,lokacija,cenaBilet);
        cout<<"Osnovna cena na koncertot so naziv "<<k1.getNaziv()<< " e: " <<k1.cena()<<endl;
    }
    else if (tip==3){//ElektronskiKoncert
        cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
        ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
        cout<<"Kreiran e elektronski koncert so naziv "<<s.getNaziv()<<" i sezonskiPopust "<<s.getSezonskiPopust()<<endl;
    }
    else if (tip==4){//cena - ElektronskiKoncert
        cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
        ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
        cout<<"Cenata na elektronskiot koncert so naziv "<<s.getNaziv()<<" e: "<<s.cena()<<endl;
    }
    else if (tip==5) {//najskapKoncert

    }
    else if (tip==6) {//prebarajKoncert
        Koncert ** koncerti = new Koncert *[5];
        int n;
        koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
        koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
        koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
        koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
        koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
        char naziv[100];
        najskapKoncert(koncerti,5);
    }
    else if (tip==7){//prebaraj
        Koncert ** koncerti = new Koncert *[5];
        int n;
        koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
        koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
        koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
        koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
        koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
        char naziv[100];
        bool elektronski;
        cin>>elektronski;
        if(prebarajKoncert(koncerti,5, "Area",elektronski))
            cout<<"Pronajden"<<endl;
        else cout<<"Ne e pronajden"<<endl;

        if(prebarajKoncert(koncerti,5, "Area",!elektronski))
            cout<<"Pronajden"<<endl;
        else cout<<"Ne e pronajden"<<endl;

    }
    else if (tip==8){//smeni cena
        Koncert ** koncerti = new Koncert *[5];
        int n;
        koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
        koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
        koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
        koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
        koncerti[2] -> setSezonskiPopust(0.9);
        koncerti[1] -> setSezonskiPopust(0.9);
        najskapKoncert(koncerti,4);
    }

    return 0;
}
