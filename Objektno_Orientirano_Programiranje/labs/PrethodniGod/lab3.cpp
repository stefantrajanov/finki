//
// Created by Stefan on 2/13/2023.
//
#include <iostream>
#include <string.h>
using namespace std;

class Member {
private:
  char name[100];
  char surname[100];
  int membership;

public:
  Member(char *name = "", char *surname = "", int membership = 0) {
    strcpy(this->name, name);
    strcpy(this->surname, surname);
    this->membership = membership;
  }
  ~Member() = default;

  Member& operator++() {
    membership++;
    return *this;
  }

  Member operator++(int) {
    Member temp(*this);
    ++membership;
    return temp;
  }

  bool operator!=(const Member &obj){
    if (obj.membership != this->membership){
      return true;
    }

    return false;
  }

  friend ostream& operator<<(ostream &os, const Member &object){
    os << object.name << " " << object.surname << ", " << object.membership;
    return os;
  }

  int getMembership() const { return membership; }
};

class Club {
private:
  char name[100];
  int numberOfMembers;
  Member *members = new Member[numberOfMembers];

public:
  Club(char *name="", int numberOfMembers = 0, Member *members = NULL){
      strcpy(this->name, name);
      this->numberOfMembers = numberOfMembers;
      this->members = new Member[numberOfMembers];
      for (int i = 0; i < numberOfMembers; ++i) {
        this->members[i] = members[i];
      }
  }
  Club (const Club &club){
    strcpy(this->name, club.name);
    this->numberOfMembers = club.numberOfMembers;
    members = new Member[numberOfMembers];
    for (int i = 0; i < numberOfMembers; ++i) {
      this->members[i] = club.members[i];
    }
  }
  ~Club() {delete[] members;};


  Club operator+=(const Member object){
    Member *temp = members;

    members = new Member[numberOfMembers + 1];

    for (int i = 0; i < numberOfMembers; ++i) {
      members[i] = temp[i];
    }
    members[numberOfMembers] = object;
    numberOfMembers++;

    return *this;
  }

  friend ostream& operator<< (ostream &os, const Club &object){
    os << object.name << endl;
    for (int i = 0; i < object.numberOfMembers; ++i) {
      os << object.members[i] << endl;
    }

    return os;
  }

  Club newClub (Member &member){
    Club theNewClub;

    strcpy(theNewClub.name, this->name);
    int memberRank = member.getMembership();

    for (int i = 0; i < this->numberOfMembers; ++i) {
      if (memberRank == this->members[i].getMembership()){
        this->members[i]++;
        theNewClub += members[i];
      }
    }

    return theNewClub;
  }

};



int main() {
  Member member("Majstor", "Majstorov", 3);
  Member member0("Stefan", "Trajanov", 20);
  Member member1("Stefan", "Vasilev", 20);
  Member member2("Pero", "Trajkov", 20);
  Member member3("Petar", "Petrevski", 10);

  Member membersArray[] = {member,member0,member1,member2, member3};

  Club club("Tokyo", 5, membersArray);

  Club newClub = club.newClub(member0);

  cout << newClub;

  return 0;
}