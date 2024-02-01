//
// Created by Stefan on 3/5/2023.
//
#include<iostream>
#include<cstring>

using namespace std;

// vasiot kod za klasite ovde

class StockRecord {
private:
    char ID[20];
    char name[60];
    double boughtPrice;
    double currentStockPrice;
    int numberOfStocksBought;
public:
    StockRecord(char *ID = "", char *name = "", double boughtPrice = 0,  int
    numberOfStocksBought = 0, double currentStockPrice = 0) {
        this->numberOfStocksBought = numberOfStocksBought;
        this->currentStockPrice = currentStockPrice;
        this->boughtPrice = boughtPrice;
        strcpy(this->ID, ID);
        strcpy(this->name, name);
    }

    const char *getId()  {
        return ID;
    }

    const char *getName()  {
        return name;
    }

    double getTotalstockPrice()  {
        return boughtPrice;
    }

    void setTotalstockPrice(double totalstockPrice) {
        StockRecord::boughtPrice = totalstockPrice;
    }

    double getCurrentStockPrice()  {
        return currentStockPrice;
    }

    void setNewPrice(double currentStockPrice) {
        this->currentStockPrice = currentStockPrice;
    }

    int getNumberOfStocksBought()  {
        return numberOfStocksBought;
    }

    void setNumberOfStocksBought(int numberOfStocksBought) {
        StockRecord::numberOfStocksBought = numberOfStocksBought;
    }


    double value() {
        return (this->numberOfStocksBought * this->currentStockPrice);
    }

    double profit() {
        return (this->numberOfStocksBought * (this->currentStockPrice - this->boughtPrice));
    }

    friend ostream &operator<<(ostream &os, StockRecord &object) {

        os << object.name << " " << object.numberOfStocksBought << " " << object.boughtPrice <<
           " " << object.currentStockPrice << " " << object.profit() << endl;

        return os;
    }
};

class Client {
private:
    char name[70];
    int clientID;
    StockRecord *stocks;
    int numberOfStocks;
public:
    Client(char *name = "", int clientId = 0, StockRecord *stocks = {}, int numberOfStocks = 0) : clientID(clientId),
                                                                                                   numberOfStocks(
                                                                                                           numberOfStocks) {
        strcpy(this->name, name);
        this->stocks = new StockRecord[numberOfStocks];

        for (int i = 0; i < numberOfStocks; ++i) {
            this->stocks[i] = stocks[i];
        }
    }

    const char *getName() const {
        return name;
    }

    int getClientId() const {
        return clientID;
    }

    void setClientId(int clientId) {
        clientID = clientId;
    }

    StockRecord *getStocks() const {
        return stocks;
    }

    void setStocks(StockRecord *stocks) {
        Client::stocks = stocks;
    }

    int getNumberOfStocks() const {
        return numberOfStocks;
    }

    void setNumberOfStocks(int numberOfStocks) {
        Client::numberOfStocks = numberOfStocks;
    }

    double totalValue() {
        double sum = 0;
        for (int i = 0; i < this->numberOfStocks; ++i) {
            sum += this->stocks[i].value();
        }

        return sum;
    }

    Client operator+=(StockRecord &stock) {
        StockRecord *tempArray = new StockRecord[this->numberOfStocks];
        for (int i = 0; i < this->numberOfStocks; ++i) {
            tempArray[i] = this->stocks[i];
        }

        this->stocks = new StockRecord[this->numberOfStocks + 1];
        for (int i = 0; i < this->numberOfStocks; ++i) {
            this->stocks[i] = tempArray[i];
        }
        this->stocks[this->numberOfStocks] = stock;
        this->numberOfStocks++;

        delete[] tempArray;
        return *this;
    }

    friend ostream &operator<<(ostream &os, Client &object) {
        os << object.getClientId() << " " << object.totalValue() << endl;
        for (int i = 0; i < object.getNumberOfStocks(); ++i) {
            os << object.stocks[i];
        }

        return os;
    }
};


// ne menuvaj vo main-ot

int main() {

    int test;
    cin >> test;

    if (test == 1) {
        double price;
        cout << "=====TEST NA KLASATA StockRecord=====" << endl;
        StockRecord sr("1", "Microsoft", 60.0, 100);
        cout << "Konstruktor OK" << endl;
        cin >> price;
        sr.setNewPrice(price);
        cout << "SET metoda OK" << endl;
    } else if (test == 2) {
        cout << "=====TEST NA METODITE I OPERATOR << OD KLASATA StockRecord=====" << endl;
        char id[12], company[50];
        double price, newPrice;
        int n, shares;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> id;
            cin >> company;
            cin >> price;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(id, company, price, shares);
            sr.setNewPrice(newPrice);
            cout << sr.value() << endl;
            cout << sr;
        }
    } else if (test == 3) {
        cout << "=====TEST NA KLASATA Client=====" << endl;
        char companyID[12], companyName[50], clientName[50];
        int clientID, n, shares;
        double oldPrice, newPrice;
        bool flag = true;
        cin >> clientName;
        cin >> clientID;
        cin >> n;
        Client c(clientName, clientID);
        cout << "Konstruktor OK" << endl;
        for (int i = 0; i < n; ++i) {
            cin >> companyID;
            cin >> companyName;
            cin >> oldPrice;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(companyID, companyName, oldPrice, shares);
            sr.setNewPrice(newPrice);
            c += sr;
            if (flag) {
                cout << "Operator += OK" << endl;
                flag = false;
            }
        }
        cout << c;
        cout << "Operator << OK" << endl;
    }
    return 0;

}