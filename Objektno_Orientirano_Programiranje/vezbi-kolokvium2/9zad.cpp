//
// Created by Stefan on 5/2/2023.
//
#include <iostream>
#include <cstring>

using namespace std;

class Trud {
private:
    char type;
    int givenYear;
public:
    Trud() {
        this->type = 'N';
        this->givenYear = 2000;
    }

    Trud(char type, int givenYear) : type(type), givenYear(givenYear) {}

    Trud(const Trud &object) {
        this->type = object.type;
        this->givenYear = object.givenYear;
    }

    Trud &operator=(const Trud &object) {
        if (this == &object) {
            return *this;
        }
        this->type = object.type;
        this->givenYear = object.givenYear;

        return *this;
    }

    friend istream &operator>>(istream &is, Trud &object) {
        is >> object.type;
        is >> object.givenYear;

        return is;
    }

    char getType() const {
        return type;
    }

    void setType(char type) {
        Trud::type = type;
    }

    int getGivenYear() const {
        return givenYear;
    }

    void setGivenYear(int givenYear) {
        Trud::givenYear = givenYear;
    }

};

class Student {
protected:
    char name[40];
    int index;
    int yearOfEnter;
    int grades[60];
    int numberOfPassedSubjects;
public:
    Student(char *name, int index, int yearOfEnter, int *grades, int numberOfPassedSubjects) : index(index),
                                                                                               yearOfEnter(yearOfEnter),
                                                                                               numberOfPassedSubjects(
                                                                                                       numberOfPassedSubjects) {
        strcpy(this->name, name);
        for (int i = 0; i < numberOfPassedSubjects; ++i) {
            this->grades[i] = grades[i];
        }
    }

    Student(const Student &object) {
        strcpy(this->name, object.name);
        this->index = object.index;
        this->yearOfEnter = object.yearOfEnter;
        this->numberOfPassedSubjects = object.numberOfPassedSubjects;
        for (int i = 0; i < object.numberOfPassedSubjects; ++i) {
            this->grades[i] = object.grades[i];
        }
    }

    Student &operator=(const Student &object) {
        if (this == &object) {
            return *this;
        }
        strcpy(this->name, object.name);
        this->index = object.index;
        this->yearOfEnter = object.yearOfEnter;
        this->numberOfPassedSubjects = object.numberOfPassedSubjects;
        for (int i = 0; i < object.numberOfPassedSubjects; ++i) {
            this->grades[i] = object.grades[i];
        }

        return *this;
    }

    // methods

    virtual float rang() {
        int sum = 0;
        for (int i = 0; i < this->numberOfPassedSubjects; ++i) {
            sum += this->grades[i];
        }

        return ((float) (sum) / (float) this->numberOfPassedSubjects);
    }

    ostream &print(ostream &os) {
        os << this->index << " " << this->name << " " << this->yearOfEnter << " " << this->rang() << endl;

        return os;
    }

    friend ostream &operator<<(ostream &os, Student &object) {
        return object.print(os);
    }

    const char *getName() const {
        return name;
    }

    int getIndex() const {
        return index;
    }

    int getYearOfEnter() const {
        return yearOfEnter;
    }

    const int *getGrades() const {
        return grades;
    }

    int getNumberOfPassedSubjects() const {
        return numberOfPassedSubjects;
    }

    virtual void addEffort(const Trud &newEffort) {
        cout << "KUR" << endl;
    }

    void operator+=(const Trud &object) {
        this->addEffort(object);
    }
};

class PhDStudent : public Student {
private:
    Trud *workEfforts;
    int numberOfWorkEfforts;
    float points;
    static int confPoints;
    static int journalPoints;
public:
    PhDStudent(char *name, int index, int yearOfEnter, int *grades, int numberOfPassedSubjects, Trud *workEfforts,
               int numberOfWorkEfforts) : Student(name, index, yearOfEnter, grades, numberOfPassedSubjects),
                                          numberOfWorkEfforts(numberOfWorkEfforts) {
        this->workEfforts = new Trud[numberOfWorkEfforts];
        int j = 0;
        for (int i = 0; i < numberOfWorkEfforts; ++i) {
            if (workEfforts[i].getGivenYear() >= yearOfEnter){
                this->workEfforts[j] = workEfforts[i];
                j++;
            }else{
                cout << "Ne moze da se vnese dadeniot trud" << endl;
            }
        }
        this->numberOfWorkEfforts = j;
    }

    PhDStudent &operator=(const PhDStudent &object) {
        if (this == &object) {
            return *this;
        }
        delete[] workEfforts;

        strcpy(this->name, object.name);
        this->index = object.index;
        this->yearOfEnter = object.yearOfEnter;
        this->numberOfPassedSubjects = object.numberOfPassedSubjects;
        for (int i = 0; i < object.numberOfPassedSubjects; ++i) {
            this->grades[i] = object.grades[i];
        }
        this->workEfforts = new Trud[object.numberOfWorkEfforts];
        for (int i = 0; i < object.numberOfWorkEfforts; ++i) {
            this->workEfforts[i] = object.workEfforts[i];
        }

        return *this;
    }

    // methods
    float rang() override {
        int sum = 0;
        for (int i = 0; i < this->numberOfPassedSubjects; ++i) {
            sum += this->grades[i];
        }

        float average = ((float) (sum) / (float) this->numberOfPassedSubjects);

        for (int i = 0; i < this->numberOfWorkEfforts; ++i) {
            if (this->workEfforts[i].getType() == 'c' || this->workEfforts[i].getType() == 'C') {
                average += (float) PhDStudent::confPoints;
            } else if (this->workEfforts[i].getType() == 'j' || this->workEfforts[i].getType() == 'J') {
                average += (float) PhDStudent::journalPoints;
            }
        }

        this->points = average;
        return average;
    }

    void addEffort(const Trud &object) override {

        if (object.getGivenYear() < this->yearOfEnter) {
            cout << "Ne moze da se vnese dadeniot trud" << endl;
            return;
        }

        Trud *tempArray = new Trud[this->numberOfWorkEfforts + 1];

        for (int i = 0; i < this->numberOfWorkEfforts; ++i) {
            tempArray[i] = this->workEfforts[i];
        }
        tempArray[this->numberOfWorkEfforts] = object;

        delete[] workEfforts;

        this->workEfforts = tempArray;
        this->numberOfWorkEfforts++;
    }

    float getPoints() const {
        return points;
    }

    void setPoints(float points) {
        PhDStudent::points = points;
    }

    static void setConfPoints(int _points) {
        confPoints = _points;
    };

    static void setJournalPoints(int _points) {
        journalPoints = _points;
    };

};

int PhDStudent::confPoints = 1;
int PhDStudent::journalPoints = 3;

int main() {
    int testCase;
    cin >> testCase;

    int god, indeks, n, god_tr, m, n_tr;
    int izbor; //0 za Student, 1 za PhDStudent
    char ime[30];
    int oceni[50];
    char tip;
    Trud trud[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasite ======" << endl;
        cin >> ime;
        cin >> indeks;
        cin >> god;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> oceni[j];
        Student s(ime, indeks, god, oceni, n);
        cout << s;

        cin >> ime;
        cin >> indeks;
        cin >> god;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> oceni[j];
        cin >> n_tr;
        for (int j = 0; j < n_tr; j++) {
            cin >> tip;
            cin >> god_tr;
            Trud t(tip, god_tr);
            trud[j] = t;
        }
        PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr);
        cout << phd;
    }
    if (testCase == 2) {
        cout << "===== Testiranje na operatorot += ======" << endl;
        Student **niza;
        cin >> m;
        niza = new Student *[m];
        for (int i = 0; i < m; i++) {
            cin >> izbor;
            cin >> ime;
            cin >> indeks;
            cin >> god;
            cin >> n;
            for (int j = 0; j < n; j++)
                cin >> oceni[j];

            if (izbor == 0) {
                niza[i] = new Student(ime, indeks, god, oceni, n);
            } else {
                cin >> n_tr;
                for (int j = 0; j < n_tr; j++) {
                    cin >> tip;
                    cin >> god_tr;
                    Trud t(tip, god_tr);
                    trud[j] = t;
                }
                niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
            }
        }
        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        // dodavanje nov trud za PhD student spored indeks
        Trud t;
        cin >> indeks;
        cin >> t;

        // vmetnete go kodot za dodavanje nov trud so pomos na operatorot +=
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (niza[i]->getIndex() == indeks) {
                if (dynamic_cast<PhDStudent*>(niza[i])) {
                    *niza[i] += t;
                    flag = false;
                    break;
                }
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "Ne postoi PhD student so indeks " << indeks << endl;
        }

        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }
    if (testCase == 3) {
        cout << "===== Testiranje na operatorot += ======" << endl;
        Student **niza;
        cin >> m;
        niza = new Student *[m];
        for (int i = 0; i < m; i++) {
            cin >> izbor;
            cin >> ime;
            cin >> indeks;
            cin >> god;
            cin >> n;
            for (int j = 0; j < n; j++)
                cin >> oceni[j];

            if (izbor == 0) {
                niza[i] = new Student(ime, indeks, god, oceni, n);
            } else {
                cin >> n_tr;
                for (int j = 0; j < n_tr; j++) {
                    cin >> tip;
                    cin >> god_tr;
                    Trud t(tip, god_tr);
                    trud[j] = t;
                }
                niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
            }
        }
        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        // dodavanje nov trud za PhD student spored indeks
        Trud t;
        cin >> indeks;
        cin >> t;

        // vmetnete go kodot za dodavanje nov trud so pomos na operatorot += od Testcase 2
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (niza[i]->getIndex() == indeks) {
                *niza[i] += t;
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << "Ne postoi PhD student so indeks " << indeks << endl;
        }

        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }
    if (testCase == 4) {
        cout << "===== Testiranje na isklucoci ======" << endl;
        cin >> ime;
        cin >> indeks;
        cin >> god;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> oceni[j];
        cin >> n_tr;
        for (int j = 0; j < n_tr; j++) {
            cin >> tip;
            cin >> god_tr;
            Trud t(tip, god_tr);
            trud[j] = t;
        }
        PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr);
        cout << phd;
    }
    if (testCase == 5) {
        cout << "===== Testiranje na isklucoci ======" << endl;
        Student **niza;
        cin >> m;
        niza = new Student *[m];
        for (int i = 0; i < m; i++) {
            cin >> izbor;
            cin >> ime;
            cin >> indeks;
            cin >> god;
            cin >> n;
            for (int j = 0; j < n; j++)
                cin >> oceni[j];

            if (izbor == 0) {
                niza[i] = new Student(ime, indeks, god, oceni, n);
            } else {
                cin >> n_tr;
                for (int j = 0; j < n_tr; j++) {
                    cin >> tip;
                    cin >> god_tr;
                    Trud t(tip, god_tr);
                    trud[j] = t;
                }
                niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
            }
        }
        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        // dodavanje nov trud za PhD student spored indeks
        Trud t;
        cin >> indeks;
        cin >> t;

        // vmetnete go kodot za dodavanje nov trud so pomos na operatorot += i spravete se so isklucokot
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (niza[i]->getIndex() == indeks) {
                *niza[i] += t;
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << "Ne postoi PhD student so indeks " << indeks << endl;
        }

        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }
    if (testCase == 6) {
        cout << "===== Testiranje na static clenovi ======" << endl;
        Student **niza;
        cin >> m;
        niza = new Student *[m];
        for (int i = 0; i < m; i++) {
            cin >> izbor;
            cin >> ime;
            cin >> indeks;
            cin >> god;
            cin >> n;
            for (int j = 0; j < n; j++)
                cin >> oceni[j];

            if (izbor == 0) {
                niza[i] = new Student(ime, indeks, god, oceni, n);
            } else {
                cin >> n_tr;
                for (int j = 0; j < n_tr; j++) {
                    cin >> tip;
                    cin >> god_tr;
                    Trud t(tip, god_tr);
                    trud[j] = t;
                }
                niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
            }
        }
        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        int conf, journal;
        cin >> conf;
        cin >> journal;

        //postavete gi soodvetnite vrednosti za statickite promenlivi
        PhDStudent::setConfPoints(conf);
        PhDStudent::setJournalPoints(journal);

        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }

    return 0;
}