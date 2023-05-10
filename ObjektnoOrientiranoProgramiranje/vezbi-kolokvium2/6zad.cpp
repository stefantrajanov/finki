//
// Created by Stefan on 4/27/2023.
//
#include <iostream>
#include <cstring>

using namespace std;

class ExistingGame : public exception {
private:
    char _message[100];
public:
    explicit ExistingGame(char *message) {
        strcpy(this->_message, message);
        cout << message << endl;
    }

    const char *message() const {
        return _message;
    }

    const char *what() const noexcept override {
        return _message;
    }
};

class Game {
protected:
    char name[120];
    float price;
    bool isBought;
public:
    Game() {
        strcpy(this->name, "");
        this->price = 0.0;
        this->isBought = false;
    }

    Game(char *name, float price, bool isBought) : price(price), isBought(isBought) {
        strcpy(this->name, name);
    }

    Game(const Game &object) {
        strcpy(this->name, object.name);
        this->price = object.price;
        this->isBought = object.isBought;
    }

    Game &operator=(const Game &object) {
        if (this == &object) {
            return *this;
        }
        strcpy(this->name, object.name);
        this->price = object.price;
        this->isBought = object.isBought;

        return *this;
    }

    // methods

    bool operator==(const Game &object) {
        if (strcmp(this->name, object.name) == 0) {
            return true;
        }

        return false;
    }

    // output
    virtual ostream &print(ostream &os) const {
        char temp[30];
        if (this->isBought) {
            strcpy(temp, ", bought on sale");
        } else {
            strcpy(temp, "");
        }

        os << "Game: " << this->name << ", " << "regular price: $" << this->price << temp << endl;

        return os;
    }

    friend ostream &operator<<(ostream &os, const Game &object) {
        return object.print(os);
    }


    // input
    virtual istream &scan(istream &is) {
        cin.get();
        cin.getline(this->name, 100);
        cin >> this->price;
        cin >> this->isBought;

        return is;
    }

    virtual float get_price(){
        if (this->isBought){
            return price * 0.3F;
        }

        return price;
    }

    friend istream &operator>>(istream &is, Game &object) {
        return object.scan(is);
    }

    const char *getName() const {
        return name;
    }

    float getPrice() const {
        return price;
    }

    bool isBought1() const {
        return isBought;
    }
};

class SubscriptionGame : public Game {
private:
    float subscriptionPrice;
    int month;
    int year;
public:
    SubscriptionGame() {
        strcpy(this->name, "");
        this->price = 0.0;
        this->isBought = false;
        this->subscriptionPrice = 0.0;
        this->month = 0;
        this->year = 0;
    }

    SubscriptionGame(char *name, float price, bool isBought, float subscriptionPrice, int month, int year)
            : Game(name, price, isBought), subscriptionPrice(subscriptionPrice), month(month), year(year) {}

    SubscriptionGame &operator=(const SubscriptionGame &object) {
        if (this == &object) {
            return *this;
        }
        strcpy(this->name, object.name);
        this->price = object.price;
        this->isBought = object.isBought;
        this->subscriptionPrice = object.subscriptionPrice;
        this->month = object.month;
        this->year = object.year;

        return *this;
    }

    // methods


    //output
    ostream &print(ostream &os) const override {
        char temp[50];
        if (this->isBought) {
            strcpy(temp, ", bought on sale,");
        } else {
            strcpy(temp, ",");
        }

        os << "Game: " << this->name << ", " << "regular price: $" << this->price << temp << " monthly fee: $" <<
           this->subscriptionPrice << ", " << "purchased: " << this->month << "-" << this->year << endl;

        return os;
    }

    friend ostream &operator<<(ostream &os, const SubscriptionGame &object) {
        return object.print(os);
    }


    // input
    istream &scan(istream &is) override {
        cin.get();
        cin.getline(this->name, 100);
        cin >> this->price;
        cin >> this->isBought;
        cin >> this->subscriptionPrice;
        cin >> this->month;
        cin >> this->year;

        return is;
    }

    float get_price() override{
        float price = Game::getPrice();

        int months=0;
        if (year<2018){
            months = (12 - this->month) + (2017 - year)*12 + 5;
        }
        else {
            months = 5 - this->month;
        }

        price += months * this->subscriptionPrice;

        return price;
    }

    friend istream &operator>>(istream &is, SubscriptionGame &object) {
        return object.scan(is);
    }

    float getSubscriptionPrice() const {
        return subscriptionPrice;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }
};

class User {
private:
    char username[120];
    Game **games;
    int numberOfGames;
public:
    User(char *username) {
        strcpy(this->username, username);
        this->games = nullptr;
        this->numberOfGames = 0;
    }

    User(const User &object) {
        strcpy(this->username, object.username);
        this->games = new Game *[object.numberOfGames];

        for (int i = 0; i < object.numberOfGames; ++i) {
            this->games[i] = new Game(*(object.games[i]));
        }

        this->numberOfGames = object.numberOfGames;
    }

    User &operator=(const User &object) {
        if (this == &object) {
            return *this;
        }

        delete[] games;
        strcpy(this->username, object.username);
        this->games = new Game *[object.numberOfGames];

        for (int i = 0; i < object.numberOfGames; ++i) {
            this->games[i] = new Game(*(object.games[i]));
        }

        this->numberOfGames = object.numberOfGames;
        return *this;
    }

    ~User() {
        delete[] games;
    }
    // methods

    void operator+=(Game &newGame) {
        for (int i = 0; i < this->numberOfGames; ++i) {
            if ((*(this->games[i])) == newGame) {
                char temp[50] = "The game is already in the collection\0";
                throw ExistingGame(temp);
            }
        }

        Game **tempArray = new Game *[this->numberOfGames + 1];
        for (int i = 0; i < this->numberOfGames; ++i) {
            tempArray[i] = new Game(*(this->games[i]));
        }

        SubscriptionGame *temp = dynamic_cast<SubscriptionGame *>(&newGame);
        if (temp) {
            tempArray[this->numberOfGames] = new SubscriptionGame(*temp);
        } else {
            tempArray[this->numberOfGames] = new Game(newGame);
        }

        delete[] games;
        this->games = tempArray;
        this->numberOfGames++;
    }


    //output
    friend ostream &operator<<(ostream &os, const User &object) {
        os << "\nUser: " << object.username << endl;
        for (int i = 0; i < object.numberOfGames; ++i) {
            os << "- " << *object.games[i];
        }
    }

    float total_spent() {
        float total = 0;
        for (int i = 0; i < this->numberOfGames; ++i) {
            total += this->games[i]->get_price();
        }
//        for (int i = 0; i < this->numberOfGames; ++i) {
//            if (dynamic_cast<Game *>(this->games[i])) {
//                if (this->games[i]->isBought1()) {
//                    total += this->games[i]->getPrice() * 0.3;
//                } else {
//                    total += this->games[i]->getPrice();
//                }
//            } else if (dynamic_cast<SubscriptionGame *>(this->games[i])){
//                SubscriptionGame *temp = dynamic_cast<SubscriptionGame *>(this->games[i]);
//                int totalMonths = (temp->getYear() * 12) + temp->getMonth();
//                int currentMonths = (2018 * 12) + 4;
//
//                int passedMonths = currentMonths - totalMonths;
//
//                total += (passedMonths * temp->getSubscriptionPrice());
//                if (this->games[i]->isBought1()) {
//                    total += this->games[i]->getPrice() * 0.3;
//                } else {
//                    total += this->games[i]->getPrice();
//                }
//            }
//        }

        return total;
    }


};


int main() {
    int test_case_num;

    cin >> test_case_num;

    // for Game
    char game_name[100];
    float game_price;
    bool game_on_sale;

    // for SubscritionGame
    float sub_game_monthly_fee;
    int sub_game_month, sub_game_year;

    // for User
    char username[100];
    int num_user_games;

    if (test_case_num == 1) {
        cout << "Testing class Game and operator<< for Game" << std::endl;
        cin.get();
        cin.getline(game_name, 100);
        //cin.get();
        cin >> game_price >> game_on_sale;

        Game g(game_name, game_price, game_on_sale);

        cout << g;
    } else if (test_case_num == 2) {
        cout << "Testing class SubscriptionGame and operator<< for SubscritionGame" << std::endl;
        cin.get();
        cin.getline(game_name, 100);

        cin >> game_price >> game_on_sale;

        cin >> sub_game_monthly_fee;
        cin >> sub_game_month >> sub_game_year;

        SubscriptionGame sg(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
        cout << sg;
    } else if (test_case_num == 3) {
        cout << "Testing operator>> for Game" << std::endl;
        Game g;

        cin >> g;

        cout << g;
    } else if (test_case_num == 4) {
        cout << "Testing operator>> for SubscriptionGame" << std::endl;
        SubscriptionGame sg;

        cin >> sg;

        cout << sg;
    } else if (test_case_num == 5) {
        cout << "Testing class User and operator+= for User" << std::endl;
        cin.get();
        cin.getline(username, 100);
        User u(username);

        int num_user_games;
        int game_type;
        cin >> num_user_games;

        try {

            for (int i = 0; i < num_user_games; ++i) {

                cin >> game_type;

                Game *g;
                // 1 - Game, 2 - SubscriptionGame
                if (game_type == 1) {
                    cin.get();
                    cin.getline(game_name, 100);

                    cin >> game_price >> game_on_sale;
                    g = new Game(game_name, game_price, game_on_sale);
                } else if (game_type == 2) {
                    cin.get();
                    cin.getline(game_name, 100);

                    cin >> game_price >> game_on_sale;

                    cin >> sub_game_monthly_fee;
                    cin >> sub_game_month >> sub_game_year;
                    g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month,
                                             sub_game_year);
                }

                //cout<<(*g);


                u += (*g);
            }
        } catch (ExistingGame &ex) {
            ex.message();
        }

        cout << u;

//    cout<<"\nUser: "<<u.get_username()<<"\n";

//    for (int i=0; i < u.get_games_number(); ++i){
//        Game * g;
//        SubscriptionGame * sg;
//        g = &(u.get_game(i));

//        sg = dynamic_cast<SubscriptionGame *> (g);

//        if (sg){
//          cout<<"- "<<(*sg);
//        }
//        else {
//          cout<<"- "<<(*g);
//        }
//        cout<<"\n";
//    }

    } else if (test_case_num == 6) {
        cout << "Testing exception ExistingGame for User" << std::endl;
        cin.get();
        cin.getline(username, 100);
        User u(username);

        int num_user_games;
        int game_type;
        cin >> num_user_games;

        for (int i = 0; i < num_user_games; ++i) {

            cin >> game_type;

            Game *g;
            // 1 - Game, 2 - SubscriptionGame
            if (game_type == 1) {
                cin.get();
                cin.getline(game_name, 100);

                cin >> game_price >> game_on_sale;
                g = new Game(game_name, game_price, game_on_sale);
            } else if (game_type == 2) {
                cin.get();
                cin.getline(game_name, 100);

                cin >> game_price >> game_on_sale;

                cin >> sub_game_monthly_fee;
                cin >> sub_game_month >> sub_game_year;
                g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month,
                                         sub_game_year);
            }

            //cout<<(*g);

            try {
                u += (*g);
            }
            catch (ExistingGame &ex) {
                ex.message();
            }
        }

        cout << u;

//      for (int i=0; i < u.get_games_number(); ++i){
//          Game * g;
//          SubscriptionGame * sg;
//          g = &(u.get_game(i));

//          sg = dynamic_cast<SubscriptionGame *> (g);

//          if (sg){
//            cout<<"- "<<(*sg);
//          }
//          else {
//            cout<<"- "<<(*g);
//          }
//          cout<<"\n";
//      }
    } else if (test_case_num == 7) {
        cout << "Testing total_spent method() for User" << std::endl;
        cin.get();
        cin.getline(username, 100);
        User u(username);

        int num_user_games;
        int game_type;
        cin >> num_user_games;

        for (int i = 0; i < num_user_games; ++i) {

            cin >> game_type;

            Game *g;
            // 1 - Game, 2 - SubscriptionGame
            if (game_type == 1) {
                cin.get();
                cin.getline(game_name, 100);

                cin >> game_price >> game_on_sale;
                g = new Game(game_name, game_price, game_on_sale);
            } else if (game_type == 2) {
                cin.get();
                cin.getline(game_name, 100);

                cin >> game_price >> game_on_sale;

                cin >> sub_game_monthly_fee;
                cin >> sub_game_month >> sub_game_year;
                g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month,
                                         sub_game_year);
            }

            //cout<<(*g);


            u += (*g);
        }

        cout << u;

        cout << "\nTotal money spent: $" << u.total_spent() << endl;
    }

    return 0;
}
