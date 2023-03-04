//
// Created by Stefan on 3/3/2023.
//
#include <iostream>
#include <cstring>

using namespace std;

typedef struct {
    char username[50];
    int level;
    int points;
} Player;

typedef struct {
    char name[50];
    Player players[50];
    int numberOfPlayers;

} ComputerGame;

void bestPlayer(ComputerGame *game, int n) {
    int mostPopularGameIndex;
    int popularity = 0;

    for (int i = 0; i < n; ++i) {
        if (popularity < game[i].numberOfPlayers){
            popularity = game[i].numberOfPlayers;
            mostPopularGameIndex = i;
        }
    }

    int maxPoints = 0;
    int bestPlayerIndex = 0;
    int biggestLevel = 0;
    for (int i = 0; i <= n; ++i) {

        if (maxPoints < game[mostPopularGameIndex].players[i].points){
            maxPoints = game[mostPopularGameIndex].players[i].points;
            bestPlayerIndex = i;
            biggestLevel = game[mostPopularGameIndex].players[i].level;
        }
        else if(maxPoints == game[mostPopularGameIndex].players[i].points){
            if (biggestLevel < game[mostPopularGameIndex].players[i].level){
                bestPlayerIndex = i;
                biggestLevel = game[mostPopularGameIndex].players[i].level;
            }
        }
    }
    printf("Najdobar igrac e igracot so korisnicko ime %s koj ja igra igrata %s", game[mostPopularGameIndex]
    .players[bestPlayerIndex].username, game[mostPopularGameIndex].name);
}

int main() {
    int n, m;
    char ime[20];
    cin >> n;
    ComputerGame poleigri[100];
    for (int i = 0; i < n; i++) {
        ComputerGame nova;
        cin >> nova.name >> nova.numberOfPlayers;
        for (int j = 0; j < nova.numberOfPlayers; j++) {
            Player nov;
            cin >> nov.username >> nov.level >> nov.points;
            nova.players[j] = nov;
        }
        poleigri[i] = nova;
    }

    bestPlayer(poleigri, n);
    return 0;
}