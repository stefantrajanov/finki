//
// Created by Stefan on 3/4/2023.
//
#include <iostream>
#include <cstring>

using namespace std;

class Pica {
private:
    char name[20];
    int price;
    char *ingridients;
    int discount;
public:
    Pica(char *name = "", char *ingridients = "", int price = 0, int discount = 0) : price(price) {
        this->discount = discount;
        strcpy(this->name, name);
        this->ingridients = new char[strlen(ingridients) + 1];
        strcpy(this->ingridients, ingridients);

    }

    void pecati() {
        cout << this->name << " - " << this->ingridients << this->price;
    }

    bool istiSe(const Pica &pizza) {
        if (this == &pizza) {
            return true;
        }
        return false;
    }

//    virtual ~Pica() {
//        if (this != nullptr) {
//            delete[] ingridients;
//        }
//    }

    const char *getName() const {
        return name;
    }

    int getPrice() const {
        return price;
    }

    char *getIngridients() const {
        return ingridients;
    }

    int getDiscount() const {
        return discount;
    }

};

class Picerija {
private:
    char name[20];
    Pica *pizzas;
    int numberOfPizzas = 0;

public:
    Picerija(char *name) {
        strcpy(this->name, name);
    }

    Picerija(Pica *pizzas = {}, char *name = "", int numberOfPizzas = 0) : numberOfPizzas(numberOfPizzas) {
        strcpy(this->name, name);

        this->pizzas = new Pica[numberOfPizzas];

        for (int i = 0; i < numberOfPizzas; ++i) {
            this->pizzas[i] = pizzas[i];
        }
    }

    void dodadi(Pica &newPizza) {
        for (int i = 0; i < this->numberOfPizzas; ++i) {
            if (strcmp(this->pizzas[i].getIngridients(), newPizza.getIngridients()) == 0) {
                return;
            }
        }

        Pica *tempArray = new Pica[this->numberOfPizzas];
        for (int i = 0; i < this->numberOfPizzas; ++i) {
            tempArray[i] = this->pizzas[i];
        }

        this->pizzas = new Pica[this->numberOfPizzas + 1];

        for (int i = 0; i < this->numberOfPizzas; ++i) {
            this->pizzas[i] = tempArray[i];
        }
        this->pizzas[this->numberOfPizzas] = newPizza;
        this->numberOfPizzas++;
    }

    Picerija operator +=(Pica &object){

        dodadi(object);
        return *this;
    }

    void piciNaPromocija() {
        for (int i = 0; i < this->numberOfPizzas; ++i) {
            if (this->pizzas[i].getDiscount() > 0) {
                int discountPrice = (float) this->pizzas[i].getPrice() * (float) ((float)this->pizzas[i].getDiscount
                        () /
                        100.0);
                cout << this->pizzas[i].getName() << " - " << this->pizzas[i].getIngridients() << ", "
                     << this->pizzas[i].getPrice() << " " << this->pizzas[i].getPrice() - discountPrice << endl;
            }
        }
    }

    void setName(char *name) {
        strcpy(this->name, name);
    }

    const char *getName() const {
        return name;
    }

    Pica *getPizzas() const {
        return pizzas;
    }

    void setPizzas(Pica *pizzas) {
        Picerija::pizzas = pizzas;
    }

    int getNumberOfPizzas() const {
        return numberOfPizzas;
    }

    void setNumberOfPizzas(int numberOfPizzas) {
        Picerija::numberOfPizzas = numberOfPizzas;
    }


//    virtual ~Picerija() {
//        delete[] pizzas;
//    }
};

int main() {

    int n;
    char ime[15];
    cin >> ime;
    cin >> n;

    Picerija p1(ime);
    for (int i = 0; i < n; i++) {
        char imp[100];
        cin.get();
        cin.getline(imp, 100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki, 100);
        int popust;
        cin >> popust;
        Pica p(imp, sostojki, cena, popust);
        p1 += p;
    }

    Picerija p2 = p1;
    cin >> ime;
    p2.setName(ime);
    char imp[100];
    cin.get();
    cin.getline(imp, 100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki, 100);
    int popust;
    cin >> popust;
    Pica p(imp, sostojki, cena, popust);
    p2 += p;

    cout << p1.getName() << endl;
    cout << "Pici na promocija:" << endl;
    p1.piciNaPromocija();

    cout << p2.getName() << endl;
    cout << "Pici na promocija:" << endl;
    p2.piciNaPromocija();

    return 0;
}