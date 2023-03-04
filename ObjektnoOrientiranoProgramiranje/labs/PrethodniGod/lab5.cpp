//
// Created by Stefan on 2/19/2023.
//
#include <iostream>
#include <cstring>
using namespace std;

class Property {
public:
  char *address = new char[strlen(address)+1];
  int size;
  int pricePerSquare;
  
  ~Property() = {
          delete [] address;
  };

  friend istream& operator>>(istream& os, Property &object){

      os >> object.address;
      os >> object.size;
      os >> object.pricePerSquare;

      return os;
  }

  char* getAddress() {
      return this->address;
  }

  int price(){
    return (this->size * this->pricePerSquare);
  }

  virtual void print(){
    cout << this->address << ", " << "Kvadratura: " << this->size << ", Cena po Kvadrat: " << this->pricePerSquare <<
    endl;
  }

  virtual int taxOnProperty(){

    return (this->price() * 0.05);
  }
};

class Vila : public Property{
public:
  int luxuryTax;
  
  ~Vila()= default;

  friend istream& operator>>(istream& os, Vila &object){

      os >> object.address;
      os >> object.size;
      os >> object.pricePerSquare;
      os >> object.luxuryTax;

      return os;
  }

  int taxOnProperty() override{

      return (this->price() * (((float)luxuryTax/100)+0.05));
  }

  void print() override{
    cout << this->address << ", " << "Kvadratura: " << this->size << ", Cena po Kvadrat: " << this->pricePerSquare
    << " Danok na luksuz: " << this->luxuryTax << endl;
  }

};


int main (){

    Property n;
    Vila v;
    cin>>n;
    cin>>v;
    n.print();
    cout<<"Danok za: "<<n.getAddress()<<", e: "<<n.taxOnProperty()<<endl;
    v.print();
    cout<<"Danok za: "<<v.getAddress()<<", e: "<<v.taxOnProperty()<<endl;
    return 0;
}