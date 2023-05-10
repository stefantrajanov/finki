//
// Created by Stefan on 4/27/2023.
//
#include <iostream>
#include <cstring>
#define MAX 50

using namespace std;

enum typeC {
    S, L, V
};

class UserExistsException : public exception{
public:
    UserExistsException() {
        strcpy(this->message,"The user already exists in the list!");
    }

    const char* what() const noexcept override {
        return message;
    }

private:
    char message[100];
};

class Customer {
private:
    char name[60];
    char email[60];
    typeC typeOfCustomer;
    int baseDiscount;
    int extraDiscount;
    int numberOfBoughtProducts;
public:
    Customer(){
        strcpy(this->name, "");
        strcpy(this->email, "");
        this->typeOfCustomer = S;
        this->baseDiscount = 0;
        this->extraDiscount = 0;
        this->numberOfBoughtProducts = 0;
        calculateDiscount();
    }
    Customer(char *name, char *email, typeC typeOfCustomer, int numberOfBoughtProducts)
            : typeOfCustomer(typeOfCustomer),
              baseDiscount(baseDiscount),
              extraDiscount(extraDiscount),
              numberOfBoughtProducts(numberOfBoughtProducts) {
        strcpy(this->name, name);
        strcpy(this->email, email);
        this->baseDiscount = 0;
        this->extraDiscount = 0;
        calculateDiscount();
    }

    Customer(const Customer &object) {
        strcpy(this->name, object.name);
        strcpy(this->email, object.email);
        this->typeOfCustomer = object.typeOfCustomer;
        this->baseDiscount = object.baseDiscount;
        this->extraDiscount = object.extraDiscount;
        this->numberOfBoughtProducts = object.numberOfBoughtProducts;
    }

    Customer &operator=(const Customer &object) {
        if (this == &object) {
            return *this;
        }
        strcpy(this->name, object.name);
        strcpy(this->email, object.email);
        this->typeOfCustomer = object.typeOfCustomer;
        this->baseDiscount = object.baseDiscount;
        this->extraDiscount = object.extraDiscount;
        this->numberOfBoughtProducts = object.numberOfBoughtProducts;

        return *this;
    }

    //methods

    void calculateDiscount() {
        if (this->typeOfCustomer == S) {
            this->baseDiscount = 0;
            this->extraDiscount = 0;
        } else if (this->typeOfCustomer == L) {
            this->baseDiscount = 10;
            this->extraDiscount = 0;
        } else {
            this->baseDiscount = 10;
            this->extraDiscount = 20;
        }
    };

    friend ostream &operator<<(ostream &os, const Customer &object) {
        char temp[30];
        if (object.typeOfCustomer == S) {
            strcpy(temp, "standard");
        } else if (object.typeOfCustomer == L) {
            strcpy(temp, "loyal");

        } else {
            strcpy(temp, "vip");
        }

        os << object.name << endl;
        os << object.email << endl;
        os << object.numberOfBoughtProducts << endl;
        os << temp << " " << object.extraDiscount + object.baseDiscount << endl;

        return os;
    }

    bool operator==(const Customer &object){
        if (strcmp(this->email, object.email) == 0){
            return true;
        }

        return false;
    }

    int getNumberOfBoughtProducts() const {
        return numberOfBoughtProducts;
    }

    void setTypeOfCustomer(typeC typeOfCustomer) {
        Customer::typeOfCustomer = typeOfCustomer;
    }
    void setDiscount1(int _discount){
        this->baseDiscount = _discount;
    }

    typeC getTypeOfCustomer() const {
        return typeOfCustomer;
    }

};

class FINKI_bookstore {
private:
    Customer *registeredCustomers;
    int numberOfCustomers;
public:
    FINKI_bookstore(Customer *registeredCustomers = nullptr, int numberOfCustomers = 0) : numberOfCustomers(
            numberOfCustomers) {
        this->registeredCustomers = new Customer[numberOfCustomers];
        for (int i = 0; i < numberOfCustomers; ++i) {
            this->registeredCustomers[i] = registeredCustomers[i];
        }
    }

    FINKI_bookstore(const FINKI_bookstore &object) {
        this->numberOfCustomers = object.numberOfCustomers;
        this->registeredCustomers = new Customer[object.numberOfCustomers];
        for (int i = 0; i < object.numberOfCustomers; ++i) {
            this->registeredCustomers[i] = object.registeredCustomers[i];
        }
    }

    FINKI_bookstore &operator=(const FINKI_bookstore &object) {
        if (this == &object) {
            return *this;
        }
        this->numberOfCustomers = object.numberOfCustomers;
        this->registeredCustomers = new Customer[object.numberOfCustomers];
        for (int i = 0; i < object.numberOfCustomers; ++i) {
            this->registeredCustomers[i] = object.registeredCustomers[i];
        }

        return *this;
    }

    ~FINKI_bookstore(){
        delete[] registeredCustomers;
    }

    // methods

    void operator+=(const Customer &newCustomer){
        for (int i = 0; i < this->numberOfCustomers; ++i) {
            if (this->registeredCustomers[i] == newCustomer){
                UserExistsException exp;
                cout <<exp.what() << endl;
                return;
            }
        }

        Customer *tempArray = new Customer[this->numberOfCustomers + 1];

        for (int i = 0; i < this->numberOfCustomers; ++i) {
            tempArray[i] = this->registeredCustomers[i];
        }

        tempArray[this->numberOfCustomers] = newCustomer;

        delete[] registeredCustomers;
        this->numberOfCustomers++;
        this->registeredCustomers = tempArray;
    }

    void update(){
        for (int i = 0; i < this->numberOfCustomers; ++i) {
            int temp = this->registeredCustomers[i].getTypeOfCustomer();
            if (this->registeredCustomers[i].getNumberOfBoughtProducts() >= 5 && this->registeredCustomers[i]
            .getNumberOfBoughtProducts() < 10){
                this->registeredCustomers[i].setTypeOfCustomer((typeC)(temp + 1));
            } else if(this->registeredCustomers[i].getNumberOfBoughtProducts() > 10){
                this->registeredCustomers[i].setTypeOfCustomer((typeC)(temp + 1));
            }

            this->registeredCustomers[i].calculateDiscount();
        }
    }

    friend ostream &operator<<(ostream &os, const FINKI_bookstore &object){
        for (int i = 0; i < object.numberOfCustomers; ++i) {
            cout << object.registeredCustomers[i];
        }

        return os;
    }

    void setCustomers(Customer *_registeredCustomers, int number) {
        delete[] registeredCustomers;
        this->numberOfCustomers = number;
        this->registeredCustomers = new Customer[number];
        for (int i = 0; i < number; ++i) {
            this->registeredCustomers[i] = _registeredCustomers[i];
        }
    }
};

int main(){
    int testCase;
    cin >> testCase;

    char name[MAX];
    char email[MAX];
    int tC;
    int discount;
    int numProducts;


    if (testCase == 1){
        cout << "===== Test Case - Customer Class ======" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (typeC) tC, numProducts);
        cout << c;

    }

    if (testCase == 2){
        cout << "===== Test Case - Static Members ======" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (typeC) tC, numProducts);
        cout << c;

        c.setDiscount1(5);

        cout << c;
    }

    if (testCase == 3){
        cout << "===== Test Case - FINKI-bookstore ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);

        cout << fc <<endl;
    }

    if (testCase == 4){
        cout << "===== Test Case - operator+= ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        Customer c(name, email, (typeC) tC, numProducts);
        fc+=c;

        cout << fc;
    }

    if (testCase == 5){
        cout << "===== Test Case - operator+= (exception) ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        Customer c(name, email, (typeC) tC, numProducts);

        fc+=c;

        cout << fc;
    }

    if (testCase == 6){
        cout << "===== Test Case - update method  ======" << endl << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);

        cout << "Update:" << endl;
        fc.update();
        cout << fc;
    }
    return 0;

}

