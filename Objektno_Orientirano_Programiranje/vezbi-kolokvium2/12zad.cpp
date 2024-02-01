//
// Created by Stefan on 5/4/2023.
//
#include <iostream>
#include <cstring>
using namespace std;

enum tip {SMARTPHONE, COMPUTER};

class InvalidProductionDate : public exception{
private:
    char _message[50];
public:
    InvalidProductionDate(char *message) {
        strcpy(this->_message,message);
    }

    const char* message() const{
        return _message;
    }

    const char *what() const noexcept override {
        return _message;
    }
};

class Device{
private:
    char model[120];
    tip deviceType;
    static float baseServiceTime;
    int manufactureDate;
public:
    Device(){
        strcpy(this->model, "");
        this->deviceType = SMARTPHONE;
        this->manufactureDate = 0;
    }
    Device(char *model, tip deviceType, int manufactureDate) : deviceType(deviceType), manufactureDate(manufactureDate){
        strcpy(this->model, model);
    }
    Device(const Device &object){
        strcpy(this->model, object.model);
        this->deviceType = object.deviceType;
        this->manufactureDate = object.manufactureDate;
    }
    Device &operator=(const Device &object){
        if (this == &object){
            return *this;
        }
        strcpy(this->model, object.model);
        this->deviceType = object.deviceType;
        this->manufactureDate = object.manufactureDate;
        return *this;
    }

    static void setPocetniCasovi(float serviceTime) {
        Device::baseServiceTime = serviceTime;
    }

    friend ostream &operator<<(ostream &os, const Device &object){
        char temp[50] = "Laptop";
        if (object.deviceType == 0){
            strcpy(temp, "Mobilen");
        }

        float time = baseServiceTime;

        if (object.manufactureDate > 2015){
            time +=2;
        }
        if (object.deviceType == 1){
            time +=2;
        }

        os << object.model << endl;
        os << temp << " " << time << endl;

        return os;
    }

    /// getters setters
    const char *getModel() const {
        return model;
    }

    tip getDeviceType() const {
        return deviceType;
    }

    static float getServiceTime() {
        return baseServiceTime;
    }

    int getManufactureDate() const {
        return manufactureDate;
    }
};

float Device::baseServiceTime = 1.0;

class MobileServis{
private:
    char address[120];
    Device *devices;
    int numberOfDevices;
public:
    MobileServis(){
        strcpy(this->address, "");
        this->devices = nullptr;
        this->numberOfDevices = 0;
    }
    MobileServis(char *address){
        strcpy(this->address, address);
        this->devices = nullptr;
        this->numberOfDevices = 0;
    }
    MobileServis(const MobileServis &object){
        strcpy(this->address, object.address);
        this->devices = new Device[object.numberOfDevices];
        for (int i = 0; i < object.numberOfDevices; ++i) {
            this->devices[i] = object.devices[i];
        }
        this->numberOfDevices = object.numberOfDevices;
    }
    MobileServis &operator=(const MobileServis &object){
        if (this == &object){
            return *this;
        }
        delete [] devices;

        strcpy(this->address, object.address);
        this->devices = new Device[object.numberOfDevices];
        for (int i = 0; i < object.numberOfDevices; ++i) {
            this->devices[i] = object.devices[i];
        }
        this->numberOfDevices = object.numberOfDevices;
        return *this;
    }
    ~MobileServis(){
        delete [] devices;
    }
    // methods

    void operator+=(const Device &newDevice){
        if (newDevice.getManufactureDate() > 2019 || newDevice.getManufactureDate() < 2000){
            char temp[100] = "Невалидна година на производство";
            InvalidProductionDate exp(temp);
            cout << exp.message() << endl;
            return;
        }

        Device *tempArray = new Device[this->numberOfDevices];
        for (int i = 0; i < this->numberOfDevices; ++i) {
            tempArray[i] = this->devices[i];
        }
        tempArray[this->numberOfDevices] = newDevice;

        delete [] devices;
        this->numberOfDevices++;
        this->devices = tempArray;
    }

    void pecatiCasovi(){
        cout << "Ime: "<<this->address << endl;
        for (int i = 0; i < this->numberOfDevices; ++i) {
            cout << this->devices[i];
        }
    }
};



int main()
{
    int testCase;
    cin >> testCase;
    char ime[100];
    int tipDevice;
    int godina;
    int n;
    Device devices[50];
    if (testCase == 1){
        cout << "===== Testiranje na klasite ======" << endl;
        cin >> ime;
        cin >> tipDevice;
        cin >> godina;
        Device ig(ime,(tip)tipDevice,godina);
        cin>>ime;
        MobileServis t(ime);
        cout<<ig;
    }
    if (testCase == 2){
        cout << "===== Testiranje na operatorot += ======" << endl;
        cin>>ime;
        cin >> n;
        MobileServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            t+=tmp;
        }
        t.pecatiCasovi();
    }
    if (testCase == 3){
        cout << "===== Testiranje na isklucoci ======" << endl;
        cin>>ime;
        cin >> n;
        MobileServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            t+=tmp;
        }
        t.pecatiCasovi();
    }
    if (testCase == 4){
        cout <<"===== Testiranje na konstruktori ======"<<endl;
        cin>>ime;
        cin >> n;
        MobileServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            t+=tmp;
        }
        MobileServis t2 = t;
        t2.pecatiCasovi();
    }
    if (testCase == 5){
        cout << "===== Testiranje na static clenovi ======" << endl;
        cin>>ime;
        cin >> n;
        MobileServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);

            t+=tmp;
        }
        t.pecatiCasovi();
        cout << "===== Promena na static clenovi ======" << endl;
        Device::setPocetniCasovi(2);
        t.pecatiCasovi();
    }

    if (testCase == 6){
        cout << "===== Testiranje na kompletna funkcionalnost ======" << endl;
        cin>>ime;
        cin >> n;
        MobileServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            t+=tmp;
        }
        Device::setPocetniCasovi(3);
        MobileServis t2 = t;
        t2.pecatiCasovi();
    }

    return 0;

}

