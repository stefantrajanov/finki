//
// Created by Stefan on 2/14/2023.
//
#include <cstring>
#include <iostream>
using namespace std;

class Exception {
public:
  Exception(char *message) {
    message = new char[strlen(message) + 1];
    strcpy(this->message, message);
  }
  ~Exception() { delete[] message; }
  void printError() { cout << message << endl; }

protected:
  char *message;
};

class DonationNumber {
public:
  char telNumber[100];
  float balance = 0;
  int numberOfDonations = 0;

  DonationNumber(char *telNumber = "") { strcpy(this->telNumber, telNumber); }
  ~DonationNumber() = default;

  void setTelNumber(char *number) { strcpy(this->telNumber, number); }

  void currentBalance() {
    cout << this->balance;
    cout << ", ";
    cout << this->numberOfDonations;
  }
};

class User {
public:
  char userPhoneNumber[100]{};
  float userBalance;
  User(char *userPhoneNumber, float userBalance) {
    strcpy(this->userPhoneNumber, userPhoneNumber);
    this->userBalance = userBalance;
  }

  void setUserBalance(float balance) { this->userBalance = balance; }

  void setPhoneNumber(char *phoneNumber) {
    strcpy(this->userPhoneNumber, phoneNumber);
  }

  void donate(DonationNumber donationNumber, float donation) {
    try {
      if (donation <= 0) {
        throw Exception("Nevalidna transakcija");
      } else if (this->userBalance < donation) {
        throw Exception("Nemate dovolno kesh");
      }
      {
        donationNumber.balance += donation;
        donationNumber.numberOfDonations += 1;
      }
    } catch (Exception &e) {
      e.printError();
    }
  }
};

int main() {
  DonationNumber number;
  number.setTelNumber("072569155");
  number.balance = 5000;

  cout << number.telNumber;

  return 0;
}