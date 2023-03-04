//
// Created by Stefan on 2/19/2023.
//
#include <iostream>
#include <cstring>

using namespace std;

class Team {
protected:
    char teamName[100];
    int wins;
    int losses;

public:
    Team(char *teamName = "", int wins = 0, int losses = 0) : wins(wins), losses(losses) {
        strcpy(this->teamName, teamName);
    }

    ~Team() = default;

    virtual void print() {
        cout << "Ime: " << teamName << ", Pobedi:" << wins << ", Porazi:" << losses << endl;
    }
};

class FootballTeam : public Team {
protected:
    int redCards;
    int yellowCards;
    int draws;

public:
    FootballTeam(char *teamName = "", int wins = 0, int losses = 0, int redCards = 0, int yellowCards = 0,
                 int draws = 0) {
        strcpy(this->teamName, teamName);
        this->wins = wins;
        this->losses = losses;
        this->redCards = redCards;
        this->yellowCards = yellowCards;
        this->draws = draws;
    }

    ~FootballTeam() = default;

    void print() override {
        cout << "Ime: " << teamName << ", Pobedi:" << wins << ", Porazi:" << losses << ", Nereseni: " << draws <<
             "Poeni: " << (wins * 3) + draws << endl;
    }
};


int main() {
    char ime[15];
    int pob, por, ck, zk, ner;
    cin >> ime >> pob >> por >> ck >> zk >> ner;
    FootballTeam f1(ime,pob,por,ck,zk,ner);
    f1.print();
    return 0;
}