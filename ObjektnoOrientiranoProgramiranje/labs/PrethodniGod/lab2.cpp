//
// Created by Stefan on 2/11/2023.
//
#include <iostream>
#include <cstring>
using namespace std;

class Musician{
public:
    char name[50];
    float earnings;
    int events;
    char gender;

//    Musician(char *name, float earnings, int events, char gender){
//        strcpy(this->name, name);
//        this->earnings = earnings;
//        this->events = events;
//        this->gender = gender;
//    }
};

class Drummer:public Musician{
public:
    int age;

    int pricePerEvent(){

        return age*50;
    }

    float tax(){
        earnings = (float)pricePerEvent();
        if (gender == 'M'){
            return earnings * 0.12;
        }
        return earnings * 0.1;
    }
};

class Guitarist:public Musician{
public:
    float guitarPrice;

    float pricePerEvent(){
        earnings = guitarPrice*10;
        return earnings;
    }
    float tax(){
        earnings = guitarPrice*10;

        if (events > 30){
            return earnings * 0.08;
        }
        return earnings * 0.1;
    }
};


int main (){
    char ime[50] = "majstor";
    Drummer test;
    strcpy(test.name,ime);
    test.events = 5;
    test.gender = 'M';
    test.age = 18;



    cout << test.name << endl;
//    cout << test.earnings << " denara" << endl;
    cout << test.events << endl;
    cout << test.gender << endl;
    cout << test.pricePerEvent() << endl;
    cout << test.tax() << endl;


    return 0;
}