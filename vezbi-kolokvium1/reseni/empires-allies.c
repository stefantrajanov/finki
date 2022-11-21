//
// Created by Stefan on 11/21/2022.
//
#include <stdio.h>

int main(){
    int numberOfGames;
    scanf("%d", &numberOfGames);

    int level;
    int wins;
    int losses;
    int mostPoints = 0;
    int bestPlayerIndex;

    for (int i = 1; i <= numberOfGames; ++i) {
        scanf("%d %d %d", &level, &wins, &losses);
        int points = 0;
        points += (wins * 13);

        if (level > 1){
            points -= (losses * 3);
        }
        else{
            points -= losses;
        }
        if (points >= 0){
            printf("Dobar igrac\n");
        }
        else{
            printf("Los igrac\n");
        }

        if (mostPoints < points){
            mostPoints = points;
            bestPlayerIndex = i;
        }
    }

    printf("Najdobar Igrac: br. %d, %d poeni", bestPlayerIndex, mostPoints);

    return 0;
}