//
// Created by Stefan on 4/3/2023.
//
//DO NOT CHANGE
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Student {
private:
    char *name;
    int age;
    char *major;
public:
//    Student(){
//        this->name = "";
//        this->major = "";
//        this->age = 0;
//    }
    Student(char *name = "", int age = 0, char *major = "") : age(age) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        this->major = new char[strlen(major) + 1];
        strcpy(this->major, major);
    }

    Student(const Student &object) {
        if (this == &object) {
            return;
        }
        this->age = object.age;

        this->name = new char[strlen(object.name) + 1];
        strcpy(this->name, object.name);

        this->major = new char[strlen(object.major) + 1];
        strcpy(this->major, object.major);
    }

    Student &operator=(const Student &object) {
        if (this == &object) {
            return *this;
        }

        this->age = object.age;

        this->name = new char[strlen(object.name) + 1];
        strcpy(this->name, object.name);

        this->major = new char[strlen(object.major) + 1];
        strcpy(this->major, object.major);

        return *this;
    }

    void print(){
        printf("%s (%d, %s)\n", this->name, this->age, this->major);
    }

    char *getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    ~Student() {
        delete[] major;
        delete[] name;
    }
};

class Classroom {
private:
    Student *students;
    int numOfStudents = 0;
    int capacity;
public:
    Classroom(Student *students = {}, int numOfStudents = 0, int capacity = 0) : numOfStudents(numOfStudents), capacity
            (capacity) {
        this->students = new Student[numOfStudents];

        for (int i = 0; i < numOfStudents; ++i) {
            this->students[i] = students[i];
        }
    }

    Classroom(const Classroom &object) {
        if (this == &object) {
            return;
        }
        this->numOfStudents = object.numOfStudents;
        this->capacity = object.capacity;

        this->students = new Student[object.numOfStudents];

        for (int i = 0; i < numOfStudents; ++i) {
            this->students[i] = object.students[i];
        }
    }

    Classroom &operator=(const Classroom &object) {
        if (this == &object) {
            return *this;
        }
        this->numOfStudents = object.numOfStudents;
        this->capacity = object.capacity;

        this->students = new Student[object.numOfStudents];

        for (int i = 0; i < numOfStudents; ++i) {
            this->students[i] = object.students[i];
        }

        return *this;
    }

    void add(const Student &object) {
        Student *tempArray = new Student[this->numOfStudents + 1];

        for (int i = 0; i < this->numOfStudents; ++i) {
            tempArray[i] = this->students[i];
        }
        tempArray[this->numOfStudents] = object;

        delete[] students;
        this->students = tempArray;
        this->numOfStudents++;
    }

    int getNumOfStudents() const {
        return numOfStudents;
    }

    Student *getStudents() const {
        return students;
    }

    void remove(char *studentName) {
        int index = -1;
        for (int i = 0; i < this->numOfStudents; ++i) {
            if (strcmp(this->students[i].getName(), studentName) == 0) {
                index = i;
                break;
            }
        }

        if (index == -1){
            return;
        }

        Student *tempArray = new Student[this->numOfStudents - 1];

        int counter = 0;
        for (int i = 0; i < this->numOfStudents; ++i) {
            if (i != index) {
                tempArray[counter] = this->students[i];
                counter++;
            }
        }
        delete[] students;
        this->students = tempArray;
        this->numOfStudents--;
    }

    void printStudents(){
        for (int i = 0; i < this->numOfStudents; ++i) {
            this->students[i].print();
        }
        cout << endl;

    }

    ~Classroom() {
        delete[] students;
    }
};

double findMedianAge(Classroom &classroom){
    for (int i = 0; i < classroom.getNumOfStudents(); ++i) {
        int minIndex = i;
        for (int j = i + 1; j < classroom.getNumOfStudents(); ++j) {
            if(classroom.getStudents()[minIndex].getAge() > classroom.getStudents()[j].getAge()){
                minIndex = j;
            }
        }
        if (minIndex != i){
            Student temp = classroom.getStudents()[i];
            classroom.getStudents()[i] = classroom.getStudents()[minIndex];
            classroom.getStudents()[minIndex] = temp;
        }
    }

    if (classroom.getNumOfStudents() % 2 != 0){
        int index = floor((float)(classroom.getNumOfStudents()) / 2.0); // 0 1 2 3 4 5 6 |  7/2 = 3.5 = floor = 3

        return classroom.getStudents()[index].getAge();
    }
    int indexUpper = classroom.getNumOfStudents() / 2;
    int indexLower = indexUpper - 1;

    double median = ((classroom.getStudents()[indexUpper].getAge() + classroom.getStudents()[indexLower].getAge()) / 2.0);

    return median;
    // 0 1 2 3 4 5 6 7 8 9
}

int main() {
    int numClassrooms, numStudents;
    cin >> numClassrooms;
    Classroom classrooms[100];
    Student students[100];

    // Testing add method
    for (int i = 0; i < numClassrooms; i++) {
        cin >> numStudents;
        for (int j = 0; j < numStudents; j++) {
            char name[100], major[100];
            int age;
            cin >> name >> age >> major;
            Student student(name, age, major);
            classrooms[i].add(student);
            students[i * numStudents + j] = student;
        }
        cout << "Classroom " << i << endl;
        classrooms[i].printStudents();
    }


    // Testing findMedianAge method
    int targetClassroom;
    cin >> targetClassroom;
    double medianAge = findMedianAge(classrooms[targetClassroom]);
    cout << "The median age in classroom " << targetClassroom << " is: " << medianAge << endl;
    cout << "After removing the elements:" << endl;

    // Testing remove method
    cin >> numStudents;
    for (int j = 0; j < numStudents; j++) {
        char name[100];
        cin >> name;
        for (int i = 0; i < numClassrooms; i++) {
            classrooms[i].remove(name);
        }
    }
    for (int i = 0; i < numClassrooms; i++) {
        cout << "Classroom " << i << endl;
        classrooms[i].printStudents();
    }

    return 0;
}