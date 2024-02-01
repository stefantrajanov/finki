#include <iostream>
#include <cstring>
using namespace std;

struct Dance{
    char danceName[50];
    char countryOfOrigin[50];
};

struct Dancer{
    char nameAndSurname[50];
    Dance canDance[50];

};

void showDetailsAboutDancers(Dancer *dancer, int n, char *country){
    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < 3; ++j) {
            if (strcmp(dancer[i].canDance[j].countryOfOrigin, country) == 0){
                cout << dancer[i].nameAndSurname << " " << dancer[i].canDance[j].danceName << endl;
            }
        }
    }
}

int main() {
    int i, j, n;
    char zemja[10];
    Dancer tanceri[5];
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> tanceri[i].nameAndSurname;
        for(j = 0; j < 3; j++){
            cin >> tanceri[i].canDance[j].danceName;
            cin >> tanceri[i].canDance[j].countryOfOrigin;
        }
    }
    cin >> zemja;
    showDetailsAboutDancers(tanceri, n, zemja);
    return 0;
}
