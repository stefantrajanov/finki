#include<iostream>
#include <cstring>
using namespace std;

typedef struct{
    char nameOfDance[100];
    char countryOfOrigin[100];
}Dance;

typedef struct{
    char name[100];
    char surname[100];
    Dance canDance[100];
}Dancer;

int compareStrings(char *string, char *secondString){

    int length = strlen(string);
    int secondLength = strlen(secondString);

    if (length != secondLength){
        return 0;
    }

    for (int i = 0; i < length; ++i) {
        if (string[i] != secondString[i]){
            return 0;
        }
    }

    return 1;
}

void dancing(Dancer *dancers, int n, char *countryOfOrigin){

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
//            char temp[100];
//            strcpy(temp, dancers[i].canDance[j].countryOfOrigin);
            if (strcmp(dancers[i].canDance[j].countryOfOrigin, countryOfOrigin) == 0){
                cout << dancers[i].name << " " << dancers[i].surname << ", "<< dancers[i].canDance[j].nameOfDance <<
                endl;
                break;
            }
        }
    }
}


int main()
{
    int i, j, n;
    char zemja[100];
    Dancer dancers[100];
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> dancers[i].name;
        cin >> dancers[i].surname;
        for(j = 0; j < 3; j++){
            cin >> dancers[i].canDance[j].nameOfDance;
            cin >> dancers[i].canDance[j].countryOfOrigin;
        }
    }
    cin >> zemja;
    dancing(dancers,n,zemja);
    return 0;
}