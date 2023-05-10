//
// Created by Stefan on 4/25/2023.
//
#include<iostream>
#include<cstring>

using namespace std;


class Kurs {
private:
    char name[20];
    int credits;
public:
    Kurs(char *ime, int krediti) {
        strcpy(this->name, ime);
        this->credits = krediti;
    }

    Kurs() {
        strcpy(this->name, "");
        credits = 0;
    }

    bool operator==(const char *ime) const {
        return strcmp(this->name, ime) == 0;
    }

    char const *getIme() const {
        return name;
    }

    void pecati() const { cout << name << " " << credits << "ECTS"; }
};

class Student {
private:
    int *grades;
    int numberOfGrades;

protected:
    int index;

public:
    Student(int indeks, int *ocenki, int brojOcenki) {
        this->index = indeks;
        this->numberOfGrades = brojOcenki;
        this->grades = new int[brojOcenki];
        for (int i = 0; i < brojOcenki; i++) this->grades[i] = ocenki[i];
    }

    Student(const Student &k) {
        this->index = k.index;
        this->numberOfGrades = k.numberOfGrades;
        this->grades = new int[k.numberOfGrades];
        for (int i = 0; i < k.numberOfGrades; i++) this->grades[i] = k.grades[i];
    }

    Student &operator=(const Student &k) {
        if (&k == this) return *this;
        this->index = k.index;
        this->numberOfGrades = k.numberOfGrades;
        delete[] grades;
        this->grades = new int[k.numberOfGrades];
        for (int i = 0; i < k.numberOfGrades; i++) this->grades[i] = k.grades[i];
        return *this;
    }

    ~Student() { delete[] grades; }

    //dopolni ja klasata

};

class Predavach {
private:
    Kurs courses[10];
    int numberOfCourses;

protected:
    char *nameAndSurname;

public:
    Predavach(char *imeIPrezime, Kurs *kursevi, int brojKursevi) {
        this->numberOfCourses = brojKursevi;
        for (int i = 0; i < brojKursevi; i++) this->courses[i] = kursevi[i];
        this->nameAndSurname = new char[strlen(imeIPrezime) + 1];
        strcpy(this->nameAndSurname, imeIPrezime);
    }

    Predavach(const Predavach &p) {
        this->numberOfCourses = p.numberOfCourses;
        for (int i = 0; i < p.numberOfCourses; i++) this->courses[i] = p.courses[i];
        this->nameAndSurname = new char[strlen(p.nameAndSurname) + 1];
        strcpy(this->nameAndSurname, p.nameAndSurname);
    }

    Predavach operator=(const Predavach &p) {
        if (this == &p) return *this;
        this->numberOfCourses = p.numberOfCourses;
        for (int i = 0; i < p.numberOfCourses; i++) this->courses[i] = p.courses[i];
        this->nameAndSurname = new char[strlen(p.nameAndSurname) + 1];
        delete[] nameAndSurname;
        strcpy(this->nameAndSurname, p.nameAndSurname);
        return *this;
    }

    ~Predavach() { delete[] nameAndSurname; }

    int getBrojKursevi() const { return numberOfCourses; }

    char *const getImeIPrezime() const { return nameAndSurname; }

    Kurs operator[](int i) const {
        if (i < numberOfCourses && i >= 0)
            return courses[i];
        else return Kurs();
    }

    void pecati() const {
        cout << nameAndSurname << " (";
        for (int i = 0; i < numberOfCourses; i++) {
            courses[i].pecati();
            if (i < numberOfCourses - 1) cout << ", "; else cout << ")";
        }
    }
};


//mesto za vashiot kod
class Demonstrator : public Student, public Predavach{
private:
    Kurs *courses;

};


int main() {

    Kurs kursevi[10];
    int indeks, brojKursevi, ocenki[20], ocenka, brojOcenki, tip, brojCasovi, krediti;
    char ime[20], imeIPrezime[50];

    cin >> tip;

    if (tip == 1) //test class Demonstrator
    {
        cout << "-----TEST Demonstrator-----" << endl;
        cin >> indeks >> brojOcenki;
        for (int i = 0; i < brojOcenki; i++) {
            cin >> ocenka;
            ocenki[i] = ocenka;
        }
        cin >> imeIPrezime >> brojKursevi;
        for (int i = 0; i < brojKursevi; i++) {
            cin >> ime >> krediti;
            kursevi[i] = Kurs(ime, krediti);
        }
        cin >> brojCasovi;

        Demonstrator d(indeks, ocenki, brojOcenki, imeIPrezime, kursevi, brojKursevi, brojCasovi);
        cout << "Objekt od klasata Demonstrator e kreiran";

    } else if (tip == 2) //funkcija pecati vo Student
    {
        cout << "-----TEST pecati-----" << endl;
        cin >> indeks >> brojOcenki;
        for (int i = 0; i < brojOcenki; i++) {
            cin >> ocenka;
            ocenki[i] = ocenka;
        }

        Student s(indeks, ocenki, brojOcenki);
        s.pecati();

    } else if (tip == 3) //funkcija getVkupnaOcenka vo Student
    {
        cout << "-----TEST getVkupnaOcenka-----" << endl;
        cin >> indeks >> brojOcenki;
        for (int i = 0; i < brojOcenki; i++) {
            cin >> ocenka;
            ocenki[i] = ocenka;
        }
        Student s(indeks, ocenki, brojOcenki);
        cout << "Broj na bodovi: " << s.getBodovi() << endl;

    } else if (tip == 4) //funkcija getVkupnaOcenka vo Demonstrator
    {
        cout << "-----TEST getVkupnaOcenka-----" << endl;
        cin >> indeks >> brojOcenki;
        for (int i = 0; i < brojOcenki; i++) {
            cin >> ocenka;
            ocenki[i] = ocenka;
        }
        cin >> imeIPrezime >> brojKursevi;
        for (int i = 0; i < brojKursevi; i++) {
            cin >> ime >> krediti;
            kursevi[i] = Kurs(ime, krediti);
        }
        cin >> brojCasovi;

        Demonstrator d(indeks, ocenki, brojOcenki, imeIPrezime, kursevi, brojKursevi, brojCasovi);
        cout << "Broj na bodovi: " << d.getBodovi() << endl;

    } else if (tip == 5) //funkcija pecati vo Demonstrator
    {
        cout << "-----TEST pecati -----" << endl;
        cin >> indeks >> brojOcenki;
        for (int i = 0; i < brojOcenki; i++) {
            cin >> ocenka;
            ocenki[i] = ocenka;
        }
        cin >> imeIPrezime >> brojKursevi;
        for (int i = 0; i < brojKursevi; i++) {
            cin >> ime >> krediti;
            kursevi[i] = Kurs(ime, krediti);
        }
        cin >> brojCasovi;

        Demonstrator d(indeks, ocenki, brojOcenki, imeIPrezime, kursevi, brojKursevi, brojCasovi);
        d.pecati();

    } else if (tip == 6) //site klasi
    {
        cout << "-----TEST Student i Demonstrator-----" << endl;
        cin >> indeks >> brojOcenki;
        for (int i = 0; i < brojOcenki; i++) {
            cin >> ocenka;
            ocenki[i] = ocenka;
        }
        cin >> imeIPrezime >> brojKursevi;
        for (int i = 0; i < brojKursevi; i++) {
            cin >> ime >> krediti;
            kursevi[i] = Kurs(ime, krediti);
        }
        cin >> brojCasovi;

        Student *s = new Demonstrator(indeks, ocenki, brojOcenki, imeIPrezime, kursevi, brojKursevi, brojCasovi);
        s->pecati();
        cout << "\nBroj na bodovi: " << s->getBodovi() << endl;
        delete s;


    } else if (tip == 7) //funkcija vratiNajdobroRangiran
    {
        cout << "-----TEST vratiNajdobroRangiran-----" << endl;
        int k, opt;
        cin >> k;
        Student **studenti = new Student *[k];
        for (int j = 0; j < k; j++) {
            cin >> opt; //1 Student 2 Demonstrator
            cin >> indeks >> brojOcenki;
            for (int i = 0; i < brojOcenki; i++) {
                cin >> ocenka;
                ocenki[i] = ocenka;
            }
            if (opt == 1) {
                studenti[j] = new Student(indeks, ocenki, brojOcenki);
            } else {
                cin >> imeIPrezime >> brojKursevi;
                for (int i = 0; i < brojKursevi; i++) {
                    cin >> ime >> krediti;
                    kursevi[i] = Kurs(ime, krediti);
                }
                cin >> brojCasovi;
                studenti[j] = new Demonstrator(indeks, ocenki, brojOcenki, imeIPrezime, kursevi, brojKursevi,
                                               brojCasovi);
            }
        }
        Student &najdobar = vratiNajdobroRangiran(studenti, k);
        cout << "Maksimalniot broj na bodovi e:" << najdobar.getBodovi();
        cout << "\nNajdobro rangiran:";
        najdobar.pecati();

        for (int j = 0; j < k; j++) delete studenti[j];
        delete[] studenti;
    } else if (tip == 8) //funkcija pecatiDemonstratoriKurs
    {
        cout << "-----TEST pecatiDemonstratoriKurs-----" << endl;
        int k, opt;
        cin >> k;
        Student **studenti = new Student *[k];
        for (int j = 0; j < k; j++) {
            cin >> opt; //1 Student 2 Demonstrator
            cin >> indeks >> brojOcenki;
            for (int i = 0; i < brojOcenki; i++) {
                cin >> ocenka;
                ocenki[i] = ocenka;
            }
            if (opt == 1) {
                studenti[j] = new Student(indeks, ocenki, brojOcenki);
            } else {
                cin >> imeIPrezime >> brojKursevi;
                for (int i = 0; i < brojKursevi; i++) {
                    cin >> ime >> krediti;
                    kursevi[i] = Kurs(ime, krediti);
                }
                cin >> brojCasovi;
                studenti[j] = new Demonstrator(indeks, ocenki, brojOcenki, imeIPrezime, kursevi, brojKursevi,
                                               brojCasovi);
            }
        }
        char kurs[20];
        cin >> kurs;
        cout << "Demonstratori na " << kurs << " se:" << endl;
        pecatiDemonstratoriKurs(kurs, studenti, k);
        for (int j = 0; j < k; j++) delete studenti[j];
        delete[] studenti;

    }


    return 0;
}

