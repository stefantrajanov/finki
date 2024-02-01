//
// Created by Stefan on 4/25/2023.
//
#include <iostream>
#include <cstring>

using namespace std;

class Book  {
protected:
    char ISBN[30];
    char title[60];
    char author[40];
    float price;
public:
    Book(char *isbn, char *title, char *author, float price = 0.0) : price(price) {
        strcpy(this->ISBN, isbn);
        strcpy(this->title, title);
        strcpy(this->author, author);
    }

    virtual void bookPrice() = 0;

    bool operator>(const Book &object) {
        if (this->price > object.price) {
            return true;
        }

        return false;
    }

    friend ostream &operator<<(ostream &os, const Book &object) {
        os << object.ISBN << ": " << object.title << ", " << object.author << " " << object.price << endl;

        return os;
    }

    float getPrice() const {
        return price;
    }

    void setISBN(char *_isbn){
        strcpy(this->ISBN, _isbn);
    }
};

class OnlineBook : public Book {
private:
    char *url;
    int size;
public:
    OnlineBook(char *isbn, char *title, char *author, float price, char *url, int size)
            : Book(isbn,
                   title,
                   author,
                   price), size(size) {
        this->url = new char[strlen(url) + 1];
        strcpy(this->url, url);
        bookPrice();
    }

    void bookPrice(){
        if (size > 20) {
            this->price *= 1.2;
        }
    }
};

class PrintBook : public Book {
private:
    float weight;
    bool isAvailiable;
public:
    PrintBook(char *isbn, char *title, char *author, float price, float weight, bool
    isAvailiable) :
            Book
                    (isbn,
                     title,
                     author,
                     price),
            weight(weight),
            isAvailiable(
                    isAvailiable) {
        bookPrice();
    }

    void bookPrice(){
        if (weight > 0.7) {
            this->price *= 1.15;
        }
    }
};

void mostExpensiveBook(Book **books, int n) {
    int onlineBookCounter = 0;
    int paperBookCounter = 0;
    for (int i = 0; i < n; ++i) {
        if (dynamic_cast<OnlineBook *>(books[i])) {
            onlineBookCounter++;
        } else {
            paperBookCounter++;
        }
    }
    cout << "FINKI-Education" << endl;
    cout << "Total number of online books: " << onlineBookCounter << endl;
    cout << "Total number of print books: " << paperBookCounter << endl;
    cout << "The most expensive book is:" << endl;

    float max = 0;
    int index;
    for (int i = 0; i < n; ++i) {
        if (max <= books[i]->getPrice()){
            max = books[i]->getPrice();
            index = i;
        }
    }

    cout << *books[index];
}

int main() {

    char isbn[20], title[50], author[30], url[100];
    int size, tip;
    float price, weight;
    bool inStock;
    Book **books;
    int n;

    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "====== Testing OnlineBook class ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++) {
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> url;
            cin >> size;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new OnlineBook(isbn, title, author, price, url, size);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 2) {
        cout << "====== Testing OnlineBook CONSTRUCTORS ======" << endl;
        cin >> isbn;
        cin.get();
        cin.getline(title, 50);
        cin.getline(author, 30);
        cin >> price;
        cin >> url;
        cin >> size;
        cout << "CONSTRUCTOR" << endl;
        OnlineBook ob1(isbn, title, author, price, url, size);
        cout << ob1 << endl;
        cout << "COPY CONSTRUCTOR" << endl;
        OnlineBook ob2(ob1);
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
        cout << "OPERATOR =" << endl;
        ob1 = ob2;
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
    }
    if (testCase == 3) {
        cout << "====== Testing PrintBook class ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++) {
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> weight;
            cin >> inStock;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 4) {
        cout << "====== Testing method mostExpensiveBook() ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++) {

            cin >> tip >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            if (tip == 1) {

                cin >> url;
                cin >> size;

                books[i] = new OnlineBook(isbn, title, author, price, url, size);

            } else {
                cin >> weight;
                cin >> inStock;

                books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
            }
        }

        mostExpensiveBook(books, n);
    }

    for (int i = 0; i < n; i++) delete books[i];
    delete[] books;
    return 0;
}
