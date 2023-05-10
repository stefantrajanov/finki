//
// Created by Stefan on 5/8/2023.
//
#include <iostream>
#include <cstring>

using namespace std;

// vashiot kod ovde

class FudbalskaEkipa {
protected:
    char coachName[120];
    int lastGoalsInTen[10];
public:
    virtual ostream &print(ostream &os) const = 0;

    friend ostream &operator<<(ostream &os, const FudbalskaEkipa &ekipa) {
        return ekipa.print(os);
    }

    void operator+=(int goal) {
        int tempArray[10];
        for (int i = 0; i < 10; ++i) {
            tempArray[i] = this->lastGoalsInTen[i];
        }
        int j = 0;
        for (int i = 1; i < 10; ++i) {
            this->lastGoalsInTen[j] = tempArray[i];
            j++;
        }
        this->lastGoalsInTen[9] = goal;
    }

    virtual int uspeh() const = 0;

    bool operator>(const FudbalskaEkipa &object) const {
        if (this->uspeh() > object.uspeh()) {
            return true;
        }

        return false;
    }
};

class Klub : public FudbalskaEkipa {
private:
    char name[150];
    int numberOfTitlesWon;
public:
    Klub(char *coach, int *lastGoalsInTen, char *name, int numberOfTitlesWon) : numberOfTitlesWon(numberOfTitlesWon) {
        strcpy(this->coachName, coach);
        strcpy(this->name, name);
        for (int i = 0; i < 10; ++i) {
            this->lastGoalsInTen[i] = lastGoalsInTen[i];
        }
    }

    ostream &print(ostream &os) const override {
        os << this->name << endl;
        os << this->coachName << endl;
        os << this->uspeh() << endl;

        return os;

    }

    int uspeh() const override {
        int total = 0;

        for (int i = 0; i < 10; ++i) {
            total += this->lastGoalsInTen[i];
        }
        total *= 3;

        int temp = this->numberOfTitlesWon * 1000;

        return (total + temp);
    }
};

class Reprezentacija : public FudbalskaEkipa {
private:
    char country[150];
    int numberOfNationGames;
public:
    Reprezentacija(char *coach, int *lastGoalsInTen, char *country, int numberOfNationGames) : numberOfNationGames(
            numberOfNationGames) {
        strcpy(this->coachName, coach);
        strcpy(this->country, country);
        for (int i = 0; i < 10; ++i) {
            this->lastGoalsInTen[i] = lastGoalsInTen[i];
        }
    }

    ostream &print(ostream &os) const override {
        os << this->country << endl;
        os << this->coachName << endl;
        os << this->uspeh() << endl;

        return os;
    }

    int uspeh() const override {
        int total = 0;

        for (int i = 0; i < 10; ++i) {
            total += this->lastGoalsInTen[i];
        }
        total *= 3;

        int temp = this->numberOfNationGames * 50;

        return (total + temp);
    }
};

void najdobarTrener(FudbalskaEkipa **teams, int n) {
    int max = 0;
    int index;

    for (int i = 0; i < n; ++i) {
        if (max < teams[i]->uspeh()) {
            max = teams[i]->uspeh();
            index = i;
        }
    }

    cout << *teams[index];
}


int main() {
    int n;
    cin >> n;
    FudbalskaEkipa **ekipi = new FudbalskaEkipa *[n];
    char coach[100];
    int goals[10];
    char x[100];
    int tg;
    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        cin.getline(coach, 100);
        cin.getline(coach, 100);
        for (int j = 0; j < 10; ++j) {
            cin >> goals[j];
        }
        cin.getline(x, 100);
        cin.getline(x, 100);
        cin >> tg;
        if (type == 0) {
            ekipi[i] = new Klub(coach, goals, x, tg);
        } else if (type == 1) {
            ekipi[i] = new Reprezentacija(coach, goals, x, tg);
        }
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== DODADI GOLOVI =====" << endl;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        cout << "dodavam golovi: " << p << endl;
        *ekipi[i] += p;
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== NAJDOBAR TRENER =====" << endl;
    najdobarTrener(ekipi, n);
    for (int i = 0; i < n; ++i) {
        delete ekipi[i];
    }
    delete[] ekipi;
    return 0;
}