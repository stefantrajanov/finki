//
// Created by Stefan on 3/3/2023.
//
#include <iostream>

using namespace std;

class List {
private:
    int arrayLength = 0;
    int *arr = new int[arrayLength];

public:
    List(int arrayLength = 0, int *numbers = {}) : arrayLength(arrayLength) {
        this->arr = new int[arrayLength];
        for (int i = 0; i < arrayLength; ++i) {
            this->arr[i] = numbers[i];
        }
    }
//    ~List(){
//        delete[] arr;
//    }

    List operator=(List &object) {
        if (this != &object) { // avoid self-assignment
//            delete[] this->arr; // deallocate any existing array
            this->arr = new int[object.arrayLength];
            this->arrayLength = object.getArrayLength();

            for (int i = 0; i < this->arrayLength; ++i) {
                this->arr[i] = (object.getNumbers())[i];
            }
        }
        return *this;
    }

    int getArrayLength() {
        return this->arrayLength;
    }

    int *getNumbers() const {
        return this->arr;
    }

    void print() {
        cout << this->getArrayLength() << ": ";
        for (int i = 0; i < this->getArrayLength(); ++i) {
            cout << this->arr[i] << " ";
        }
        cout << "sum: " << this->sum() << " ";
        cout << "average: " << this->average();
    }

    int sum() {
        int sum = 0;
        for (int i = 0; i < this->arrayLength; ++i) {
            sum += arr[i];
        }

        return sum;
    }

    double average() {
        return ((float) this->sum() / float(this->arrayLength));
    }
};

class ListContainer {
private:
    int numberOfLists = 0;
    List *lists = new List[numberOfLists];
    int addNewListAttempts = 0;
    int failedListAttempts = 0;
public:
    ListContainer(int numberOfLists = 0, List *lists = {}, int addNewListAttempts = 0) :
            numberOfLists(numberOfLists), addNewListAttempts(addNewListAttempts) {
        if (numberOfLists > 0) {
            this->lists = new List[numberOfLists];
            for (int i = 0; i < numberOfLists; ++i) {
                this->lists[i] = lists[i];
            }
        }
    }


//    ~ListContainer() {
//        delete[] lists;
//    }

    ListContainer operator=(ListContainer &object) {
        if (this != &object) {
            delete[] lists;
            this->lists = new List[object.getNumberOfLists()];
            this->numberOfLists = object.getNumberOfLists();
            this->addNewListAttempts = object.getAddNewListAttempts();
            this->failedListAttempts = object.getFailedListAttempts();

            for (int i = 0; i < this->numberOfLists; ++i) {
                this->lists[i] = (object.getLists())[i];
            }
        }


        return *this;
    }

    void print() {
        if (!this->numberOfLists){
            cout << "The list is empty\n";
            return;
        }

        int currentSum = 0;
        for (int i = 0; i < this->numberOfLists; ++i) {
            cout << "List number: " << i+1 << " ";
            cout << "List info: ";
            this->lists[i].print();
            cout << endl;
            currentSum += this->lists[i].sum();
        }
        cout << "Sum: " << this->sum() << " ";
        cout << "Average: "<< this->average()<< endl;
        cout << "Successful attempts: " << this->getAddNewListAttempts();
        cout << " Failed attempts: " << this->getFailedListAttempts() << endl;
    }

    void addNewList(List &list) {
        for (int i = 0; i < this->numberOfLists; ++i) {
            if (list.sum() == lists[i].sum()) {
                failedListAttempts++;
                return;
            }
        }
        numberOfLists++;
        addNewListAttempts++;
        lists[numberOfLists - 1] = list;
    }

    int sum() {
        int sum = 0;
        for (int i = 0; i < this->getNumberOfLists(); ++i) {
            sum += lists[i].sum();
        }

        return sum;
    }

    double average() {
        int totalSum = 0;
        int totalLists = 0;
        for (int i = 0; i < this->numberOfLists; ++i) {
            totalSum += this->lists[i].sum();
            totalLists += this->lists[i].getArrayLength();
        }

        return (double)totalSum/(double)totalLists;
    }

    int getFailedListAttempts() const {
        return failedListAttempts;
    }

    int getNumberOfLists() const {
        return numberOfLists;
    }

    List *getLists() const {
        return lists;
    }

    int getAddNewListAttempts() const {
        return addNewListAttempts;
    }
};

int main() {

    ListContainer lc;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int n;
        int niza[100];

        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> niza[j];

        }

        List l = List(n, niza);

        lc.addNewList(l);
    }


    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "Test case for operator =" << endl;
        ListContainer lc1;
        lc1.print();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1 = lc;
        lc1.print();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1.sum();
        lc1.average();

    } else {
        lc.print();
    }


    return 0;
}