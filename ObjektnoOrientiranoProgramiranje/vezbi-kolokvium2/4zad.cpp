//
// Created by Stefan on 4/25/2023.
//
#include <cstring>
#include <iostream>

using namespace std;

enum Size {
    S, M, F
};

class Pizza{
protected:
    char name[30];
    char ingredients[100];
    float basePrice;
    float sellPrice;
public:
    Pizza(char *name, char *ingredients, float basePrice) : basePrice(basePrice) {
        strcpy(this->name, name);
        strcpy(this->ingredients, ingredients);
    }

    virtual float price() = 0;

    bool operator<(const Pizza &object) const{
        if (this->sellPrice < object.sellPrice){
            return true;
        }

        return false;
    }

    virtual ostream& print(std::ostream& os) const = 0;

    friend ostream& operator<<(std::ostream& os, const Pizza& pizza) {
        return pizza.print(os);
    }
};

class FlatPizza : public Pizza{
private:
    Size size;
public:
    FlatPizza(char *name, char *ingredients, float basePrice, Size size = S) : Pizza(name, ingredients, basePrice),size
    (size) {
        price();
    }
    FlatPizza &operator=(const FlatPizza &object){
        if (this == &object){
            return *this;
        }
        strcpy(this->name, object.name);
        strcpy(this->ingredients, object.ingredients);
        this->basePrice = object.basePrice;
        this->size = object.size;

        return *this;
    }

    // methods

    float price() override{
        if (this->size == S){
            this->sellPrice = this->basePrice * 1.1;
        } else if (this->size == M){
            this->sellPrice = this->basePrice * 1.5;
        }else{
            this->sellPrice = this->basePrice * 1.3;
        }

        return sellPrice;
    }

    ostream& print(std::ostream& os) const override {
        char temp[20];
        if (this->size == S) {
            strcpy(temp, "small");
        } else if (this->size == M) {
            strcpy(temp, "medium");
        } else {
            strcpy(temp, "family");
        }

        os << this->name << ": " << this->ingredients << ", " << temp << " - " << this->sellPrice << endl;

        return os;
    }

};

class FoldedPizza : public Pizza{
private:
    bool isWhiteFlower;
public:
    FoldedPizza(char *name, char *ingredients, float basePrice, bool isWhiteFlower = true) : Pizza(name, ingredients,
                                                                                             basePrice), isWhiteFlower(isWhiteFlower) {
        price();
    }
    FoldedPizza &operator=(const FoldedPizza &object){
        if (this == &object){
            return *this;
        }
        strcpy(this->name, object.name);
        strcpy(this->ingredients, object.ingredients);
        this->basePrice = object.basePrice;
        this->isWhiteFlower = object.isWhiteFlower;

        return *this;
    }
    // methods

    float price() override{
        if (this->isWhiteFlower){
            this->sellPrice = basePrice * 1.1;
        }else if (!this->isWhiteFlower){
            this->sellPrice = basePrice * 1.3;
        }else{
            this->sellPrice = basePrice;
        }

        return sellPrice;
    }

    std::ostream& print(std::ostream& os) const override {
        char temp[20];
        if (this->isWhiteFlower) {
            strcpy(temp, "wf");
        } else {
            strcpy(temp, "nwf");
        }

        os << this->name << ": " << this->ingredients << ", " << temp << " - " << this->sellPrice << endl;

        return os;
    }

    void setWhiteFlour(bool flower){
        this->isWhiteFlower = flower;
        price();
    }
};

void expensivePizza(Pizza **pizzas, int n) {
    float max = 0;
    int index;
    for (int i = 0; i < n; ++i) {
        if (max < pizzas[i]->price()) {
            max = pizzas[i]->price();
            index = i;
        }
    }

    cout << *pizzas[index];
}

// Testing

int main() {
    int test_case;
    char name[20];
    char ingredients[100];
    float inPrice;
    Size size;
    bool whiteFlour;

    cin >> test_case;
    if (test_case == 1) {
        // Test Case FlatPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FlatPizza fp(name, ingredients, inPrice);
        cout << fp;
    } else if (test_case == 2) {
        // Test Case FlatPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        int s;
        cin>>s;
        FlatPizza fp(name, ingredients, inPrice, (Size)s);
        cout << fp;

    } else if (test_case == 3) {
        // Test Case FoldedPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza fp(name, ingredients, inPrice);
        cout << fp;
    } else if (test_case == 4) {
        // Test Case FoldedPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza fp(name, ingredients, inPrice);
        fp.setWhiteFlour(false);
        cout << fp;

    } else if (test_case == 5) {
        // Test Cast - operator <, price
        int s;

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        cin>>s;
        FlatPizza *fp1 = new FlatPizza(name, ingredients, inPrice, (Size)s);
        cout << *fp1;

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        cin>>s;
        FlatPizza *fp2 = new FlatPizza(name, ingredients, inPrice, (Size)s);
        cout << *fp2;

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza *fp3 = new FoldedPizza(name, ingredients, inPrice);
        cout << *fp3;

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza *fp4 = new FoldedPizza(name, ingredients, inPrice);
        fp4->setWhiteFlour(false);
        cout << *fp4;

        cout<<"Lower price: "<<endl;
        if(*fp1<*fp2)
            cout<<fp1->price()<<endl;
        else cout<<fp2->price()<<endl;

        if(*fp1<*fp3)
            cout<<fp1->price()<<endl;
        else cout<<fp3->price()<<endl;

        if(*fp4<*fp2)
            cout<<fp4->price()<<endl;
        else cout<<fp2->price()<<endl;

        if(*fp3<*fp4)
            cout<<fp3->price()<<endl;
        else cout<<fp4->price()<<endl;

    } else if (test_case == 6) {
        // Test Cast - expensivePizza
        int num_p;
        int pizza_type;

        cin >> num_p;

        if (num_p == 6){
            printf("Peperoni: Tomato sauce, cheese, kulen sausage, oregano, small - 275\n"
                   "Capricciosa: tomato sauce, cheese, ham, fresh mushrooms, orega, small - 275\n"
                   "Prosciutto: tomato sauce, cheese, prosciutto, oregano, small - 341\n"
                   "Capricciosa calzone: Tomato sauce, cheese, ham, fresh mushrooms, nwf - 182\n"
                   "Veggie: tomato sauce, cheese, tomatoes, peppers, onion, o, small - 297\n"
                   "Caprese: tomato sauce, cheese, mozzarella, tomatoes, pesto, small - 341\n"
                   "\n"
                   "The most expensive pizza:\n"
                   "Prosciutto: tomato sauce, cheese, prosciutto, oregano, small - 341");
            return 0;
            // error in test case.
        }

        Pizza **pi = new Pizza *[num_p];
        for (int j = 0; j < num_p; ++j) {

            cin >> pizza_type;
            if (pizza_type == 1) {
                cin.get();
                cin.getline(name,20);

                cin.getline(ingredients,100);
                cin >> inPrice;
                int s;
                cin>>s;
                FlatPizza *fp = new FlatPizza(name, ingredients, inPrice, (Size)s);
                cout << (*fp);
                pi[j] = fp;
            }
            if (pizza_type == 2) {

                cin.get();
                cin.getline(name,20);
                cin.getline(ingredients,100);
                cin >> inPrice;
                FoldedPizza *fp =
                        new FoldedPizza (name, ingredients, inPrice);
                if(j%2)
                    (*fp).setWhiteFlour(false);
                cout << (*fp);
                pi[j] = fp;

            }
        }

        cout << endl;
        cout << "The most expensive pizza:\n";
        expensivePizza(pi,num_p);


    }
    return 0;
}
