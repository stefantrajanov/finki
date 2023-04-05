//
// Created by Stefan on 4/3/2023.
//
#include <iostream>
#include <cstring>
using namespace std;

class DisciplinaryAction{
private:
    char *name;
    int studentIndex;
    char *reason;
public:
    DisciplinaryAction(){
        name = "";
        reason = "";
        this->studentIndex = 0;
    }
    DisciplinaryAction(char *name, int studentIndex, char *reason) : studentIndex(studentIndex){
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        this->reason = new char[strlen(reason) + 1];
        strcpy(this->reason, reason);
    }
    DisciplinaryAction(const DisciplinaryAction &object){
        if (this == &object){
            return;
        }
        this->studentIndex = object.studentIndex;

        this->name = new char[strlen(object.name) + 1];
        strcpy(this->name, object.name);

        this->reason = new char[strlen(object.reason) + 1];
        strcpy(this->reason, object.reason);
    }

    DisciplinaryAction& operator=(const DisciplinaryAction &object){
        if (this != &object) {
            this->studentIndex = object.studentIndex;

//            delete[] this->name;      double free() error
            this->name = new char[strlen(object.name) + 1];
            strcpy(this->name, object.name);

//            delete[] this->reason;    double free() error
            this->reason = new char[strlen(object.reason) + 1];
            strcpy(this->reason, object.reason);
        }

        return *this;
    }
    ~DisciplinaryAction(){
        delete [] name;
        delete [] reason;
    }

    int getIndex() const {
        return studentIndex;
    }

    void setIndex(int _studentIndex) {
        DisciplinaryAction::studentIndex = _studentIndex;
    }

    void print(){
        cout << "Student: " << this->name << endl ;
        cout << "Student's index: " << this->studentIndex << endl ;
        cout << "Reason: " << this->reason<< endl ;
    }
};

// 1. main
/// Do NOT edit the main() function

int main() {
    int n;
    cin >> n;

    /// Testing Default constructor and equal operator
    /// Array input

    DisciplinaryAction arr[n];

    for(int i = 0; i < n; i++) {
        char name[100];
        char reason[100];
        int index;

        cin >> name >> index >> reason;

        arr[i] = DisciplinaryAction(name, index, reason);
    }

    cout << "-- Testing operator = & print() --\n";
    arr[0].print();

    /// Testing copy constructor & set index

    DisciplinaryAction merka(arr[0]);
    merka.setIndex(112233);

    cout << "\n-- Testing copy constructor & set index --\n";
    cout << "-------------\n";
    cout << "Source:\n";
    cout << "-------------\n";
    arr[0].print();

    cout << "\n-------------\n";
    cout << "Copied and edited:\n";
    cout << "-------------\n";
    merka.print();

    /// Testing if array is OK

    cout << "\n-- Testing if array was inputted correctly --\n";

    for(int i = 0; i < n; i++)
        arr[i].print();

    return 0;
}



