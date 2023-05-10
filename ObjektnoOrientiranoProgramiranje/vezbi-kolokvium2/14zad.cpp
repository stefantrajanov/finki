//
// Created by Stefan on 5/6/2023.
//
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class SMS {
protected:
    float basePrice;
    char sendNumber[15];
public:
    virtual float SMS_cena() const = 0;

    friend ostream &operator<<(ostream &os, const SMS &sms) {
        os << "Tel: " << sms.sendNumber << " - cena: " << sms.SMS_cena() << "den." << endl;
        return os;
    }

};

class RegularSMS : public SMS {
private:
    char *text;
    bool isRoamingUsed;
    static float roamingFee;
public:
    RegularSMS() {
        strcpy(this->sendNumber, "");
        this->basePrice = 0;
        this->text = nullptr;
        this->isRoamingUsed = false;
    }

    RegularSMS(char *sendNumber, float basePrice, char *text, bool isRoamingUsed) {
        strcpy(this->sendNumber, sendNumber);
        this->basePrice = basePrice;
        this->text = new char[strlen(text) + 1];
        strcpy(this->text, text);
        this->isRoamingUsed = isRoamingUsed;
    }

    RegularSMS(const RegularSMS &object) {
        strcpy(this->sendNumber, object.sendNumber);
        this->basePrice = object.basePrice;
        this->text = new char[strlen(object.text) + 1];
        strcpy(this->text, object.text);
        this->isRoamingUsed = object.isRoamingUsed;
    }

    RegularSMS &operator=(const RegularSMS &object) {
        if (this == &object) {
            return *this;
        }

        delete[] text;
        strcpy(this->sendNumber, object.sendNumber);
        this->basePrice = object.basePrice;
        this->text = new char[strlen(object.text) + 1];
        strcpy(this->text, object.text);
        this->isRoamingUsed = object.isRoamingUsed;

        return *this;

    }

    ~RegularSMS() {
        delete[] text;
    }

    //method

    float SMS_cena() const override{
        float totalPrice = this->basePrice;

        if (this->isRoamingUsed){
            totalPrice *= ((RegularSMS::roamingFee / 100) + 1);
        } else{
            totalPrice *= 1.18;
        }

        int textLength = (int)strlen(this->text);

        int multiplier = ceil((double)textLength / 160.0);

        return (totalPrice * (float)multiplier);
    }


    //static
    static void set_rProcent(float fee){
        roamingFee = fee;
    }
};

float RegularSMS::roamingFee = 300;

class SpecialSMS : public SMS {
private:
    bool isForDonation;
    static float nonDonationFee;
public:
    SpecialSMS() {
        strcpy(this->sendNumber, "");
        this->basePrice = 0;
        this->isForDonation = false;
    }

    SpecialSMS(char *sendNumber, float basePrice, bool isForDonation) {
        strcpy(this->sendNumber, sendNumber);
        this->basePrice = basePrice;
        this->isForDonation = isForDonation;
    }

    SpecialSMS(const SpecialSMS &object) {
        strcpy(this->sendNumber, object.sendNumber);
        this->basePrice = object.basePrice;
        this->isForDonation = object.isForDonation;
    }

    SpecialSMS &operator=(const SpecialSMS &object) {
        if (this == &object) {
            return *this;
        }

        strcpy(this->sendNumber, object.sendNumber);
        this->basePrice = object.basePrice;
        this->isForDonation = object.isForDonation;
        return *this;
    }
    // method

    float SMS_cena() const override{
        float totalPrice = this->basePrice;

        if(!this->isForDonation){
            totalPrice *= ((SpecialSMS::nonDonationFee / 100) + 1);
        }

        return totalPrice;
    }

    static void set_sProcent(float fee){
        nonDonationFee = fee;
    }
};

float SpecialSMS::nonDonationFee = 150.0;


void vkupno_SMS(SMS** messages, int n){
    int regularCounter = 0;
    int specialCounter = 0;

    float regularPrice = 0;
    float specialPrice = 0;

    for (int i = 0; i < n; ++i) {
        if(dynamic_cast<RegularSMS*>(messages[i])){
            regularCounter++;
            regularPrice += messages[i]->SMS_cena();
        }else{
            specialCounter++;
            specialPrice += messages[i]->SMS_cena();
        }
    }

    cout << "Vkupno ima "<< regularCounter <<" regularni SMS poraki i nivnata cena e: " << regularPrice << endl;
    cout << "Vkupno ima "<< specialCounter << " specijalni SMS poraki i nivnata cena e: " << specialPrice << endl;
}

int main() {

    char tel[20], msg[1000];
    float cena;
    float price;
    int p;
    bool roam, hum;
    SMS **sms;
    int n;
    int tip;

    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "====== Testing RegularSMS class ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i < n; i++) {
            cin >> tel;
            cin >> cena;
            cin.get();
            cin.getline(msg, 1000);
            cin >> roam;
            cout << "CONSTRUCTOR" << endl;
            sms[i] = new RegularSMS(tel, cena, msg, roam);
            cout << "OPERATOR <<" << endl;
            cout << *sms[i];
        }
        for (int i = 0; i < n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 2) {
        cout << "====== Testing SpecialSMS class ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i < n; i++) {
            cin >> tel;
            cin >> cena;
            cin >> hum;
            cout << "CONSTRUCTOR" << endl;
            sms[i] = new SpecialSMS(tel, cena, hum);
            cout << "OPERATOR <<" << endl;
            cout << *sms[i];
        }
        for (int i = 0; i < n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 3) {
        cout << "====== Testing method vkupno_SMS() ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i < n; i++) {

            cin >> tip;
            cin >> tel;
            cin >> cena;
            if (tip == 1) {

                cin.get();
                cin.getline(msg, 1000);
                cin >> roam;

                sms[i] = new RegularSMS(tel, cena, msg, roam);

            } else {
                cin >> hum;

                sms[i] = new SpecialSMS(tel, cena, hum);
            }
        }

        vkupno_SMS(sms, n);
        for (int i = 0; i < n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 4) {
        cout << "====== Testing RegularSMS class with a changed percentage======" << endl;
        SMS *sms1, *sms2;
        cin >> tel;
        cin >> cena;
        cin.get();
        cin.getline(msg, 1000);
        cin >> roam;
        sms1 = new RegularSMS(tel, cena, msg, roam);
        cout << *sms1;

        cin >> tel;
        cin >> cena;
        cin.get();
        cin.getline(msg, 1000);
        cin >> roam;
        cin >> p;
        RegularSMS::set_rProcent(p);
        sms2 = new RegularSMS(tel, cena, msg, roam);
        cout << *sms2;

        delete sms1, sms2;
    }
    if (testCase == 5) {
        cout << "====== Testing SpecialSMS class with a changed percentage======" << endl;
        SMS *sms1, *sms2;
        cin >> tel;
        cin >> cena;
        cin >> hum;
        sms1 = new SpecialSMS(tel, cena, hum);
        cout << *sms1;

        cin >> tel;
        cin >> cena;
        cin >> hum;
        cin >> p;
        SpecialSMS::set_sProcent(p);
        sms2 = new SpecialSMS(tel, cena, hum);
        cout << *sms2;

        delete sms1, sms2;
    }

    return 0;
}
