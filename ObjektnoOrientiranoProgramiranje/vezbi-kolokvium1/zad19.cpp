//
// Created by Stefan on 3/4/2023.
//
#include <iostream>
#include <cstring>
using namespace std;
// vashiot kod ovde
class IceCream {
private:
    char *name;
    char ingridents[105];
    float price;
    int discount = 0;

public:
    IceCream(const IceCream &object) {
        this->name = new char[strlen(object.name) + 1];
        strcpy(this->name, object.name);
        strcpy(this->ingridents, object.ingridents);
        this->price = object.price;
        this->discount = object.discount;
    }

    IceCream(char *name = "", char *ingridents = "", float price = 0, int discount = 0) : price(price), discount
            (discount) {
        strcpy(this->ingridents, ingridents);
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

    }

    friend ostream &operator<<(ostream &os, const IceCream &object) {
        if (object.discount > 0) {
            int discountPrice = (float) object.price * ((float) object.discount / 100);
            os << object.name << ": " << object.ingridents << " " << object.price << " " << "(" << (int) (object.price -
                                                                                                          discountPrice)
               << ")";
        } else {
            os << object.name << ": " << object.ingridents << " " << object.price << " ";
        }
        return os;
    }

    IceCream operator+(const char *string) {
        char *newName = new char[strlen(this->name) + 4];
        strcat(newName, name);
        strcat(newName, " + ");
        strcat(newName, string);

        IceCream newObject(newName, this->ingridents, this->price + 10, this->discount);
        return newObject;
    }

    IceCream operator=(const IceCream &object) {
        if (this == &object){return *this;};
        delete [] name;

        this->name = new char[strlen(object.name) + 1];
        strcpy(this->name, object.name);
        strcpy(this->ingridents, object.ingridents);
        this->price = object.price;
        this->discount = object.discount;

        return *this;
    }

    void setDiscount(int discount) {
        if (discount >= 0 && discount < 100) {
            this->discount = discount;
        }
    }

    void setName(char *name) {
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void printName() {
        cout << this->name;
    }

    IceCream operator++() {

        this->discount += 5;
        return *this;
    }


    ~IceCream() {
        delete[] name;
    }
};

class IceCreamShop {
private:
    char name[55];
    IceCream *iceCreams;
    int numberOfIceCreams = 0;
public:
    IceCreamShop() {

    }

    IceCreamShop(char *name) {
        strcpy(this->name, name);
    }

    IceCreamShop(IceCream *iceCreams = {}, char *name = "", int numberOfIceCreams = 0) {
        strcpy(this->name, name);
        this->numberOfIceCreams = numberOfIceCreams;

        this->iceCreams = new IceCream[numberOfIceCreams];
        for (int i = 0; i < numberOfIceCreams; ++i) {
            this->iceCreams[i] = iceCreams[i];
        }
    }

    IceCreamShop operator+=(const IceCream &object) {
        IceCream *tempArray = new IceCream[this->numberOfIceCreams];

        for (int i = 0; i < this->numberOfIceCreams; ++i) {
            tempArray[i] = this->iceCreams[i];
        }

//        delete[] iceCreams;

        this->iceCreams = new IceCream[this->numberOfIceCreams + 1];

        for (int i = 0; i < this->numberOfIceCreams; ++i) {
            this->iceCreams[i] = tempArray[i];
        }

        this->iceCreams[numberOfIceCreams] = object;
        numberOfIceCreams++;

        delete [] tempArray;
        return *this;
    }

    const char *getName() const {
        return name;
    }

    IceCream *getIceCreams() const {
        return iceCreams;
    }

    int getNumberOfIceCreams() const {
        return numberOfIceCreams;
    }

    IceCreamShop operator=(const IceCreamShop &object) {
        if (this == &object) { return *this;}
        delete[] this->iceCreams;

        strcpy(this->name, object.getName());
        this->numberOfIceCreams = object.getNumberOfIceCreams();

        this->iceCreams = new IceCream[this->numberOfIceCreams];
        for (int i = 0; i < this->numberOfIceCreams; ++i) {
            this->iceCreams[i] = (object.getIceCreams())[i];
        }

        return *this;
    }

    friend ostream &operator<<(ostream &os, const IceCreamShop &object) {
        os << object.name << endl;
        for (int i = 0; i < object.numberOfIceCreams; ++i) {
            os << object.iceCreams[i] << endl;
        }

        return os;
    }


//    ~IceCreamShop() {
//        delete[] iceCreams;
//    }
};


// zabraneto e menuvanje na main funkcijata

int main() {
    char name[100];
    char ingr[100];
    float price;
    int discount;

    int testCase;

    cin >> testCase;
    cin.get();
    if (testCase == 1) {
        cout << "====== TESTING IceCream CLASS ======" << endl;
        cin.getline(name, 100);
        cin.getline(ingr, 100);
        cin >> price;
        cin >> discount;
        cout << "CONSTRUCTOR" << endl;
        IceCream ic1(name, ingr, price);
        ic1.setDiscount(discount);
        cin.get();
        cin.getline(name, 100);
        cin.getline(ingr, 100);
        cin >> price;
        cin >> discount;
        IceCream ic2(name, ingr, price);
        ic2.setDiscount(discount);
        cout << "OPERATOR <<" << endl;
        cout << ic1 << endl;
        cout << ic2 << endl;
        cout << "OPERATOR ++" << endl;
        ++ic1;
        cout << ic1 << endl;
        cout << "OPERATOR +" << endl;
        IceCream ic3 = ic2 + "chocolate";
        cout << ic3 << endl;
    } else if (testCase == 2) {
        cout << "====== TESTING IceCream CONSTRUCTORS ======" << endl;
        cin.getline(name, 100);
        cin.getline(ingr, 100);
        cin >> price;
        cout << "CONSTRUCTOR" << endl;
        IceCream ic1(name, ingr, price);
        cout << ic1 << endl;
        cout << "COPY CONSTRUCTOR" << endl;
        IceCream ic2(ic1);
        cin.get();
        cin.getline(name, 100);
        ic2.setName(name);
        cout << ic1 << endl;
        cout << ic2 << endl;
        cout << "OPERATOR =" << endl;
        ic1 = ic2;
        cin.getline(name, 100);
        ic2.setName(name);
        cout << ic1 << endl;
        cout << ic2 << endl;

        cin >> discount;
        ic1.setDiscount(discount);


    } else if (testCase == 3) {
        cout << "====== TESTING IceCreamShop ======" << endl;
        char icsName[50];
        cin.getline(icsName, 100);
        cout << "CONSTRUCTOR" << endl;
        IceCreamShop ics(icsName);
        int n;
        cin >> n;
        cout << "OPERATOR +=" << endl;
        for (int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name, 100);
            cin.getline(ingr, 100);
            cin >> price;
            IceCream ic(name, ingr, price);
            ics += ic;
        }
        cout << ics;
    } else if (testCase == 4) {
        cout << "====== TESTING IceCreamShop CONSTRUCTORS ======" << endl;
        char icsName[50];
        cin.getline(icsName, 100);
        IceCreamShop ics(icsName);
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name, 100);
            cin.getline(ingr, 100);
            cin >> price;
            IceCream ic(name, ingr, price);
            ics += ic;
        }
        IceCream x("FINKI fruits", "strawberry ice cream, raspberry ice cream, blueberry ice cream", 60);
        IceCreamShop icp = ics;
        ics += x;
        cout << ics << endl;
        cout << icp << endl;
    }


    return 0;
}