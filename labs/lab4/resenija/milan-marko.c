//
// Created by Stefan on 11/15/2022.
//
#include <stdio.h>

int cardValue(char card){
    char cards[] = {'J','Q','K','A'};
    int cardValue;

    if (card == cards[0]){
        cardValue = 12;
    }
    else if(card == cards[1]){
        cardValue = 13;
    }
    else if(card == cards[2]){
        cardValue = 14;
    }
    else{
        cardValue = 15;
    }


    return cardValue;
}

void printWinners(int winners[], int rounds){
    for (int i = 0; i < rounds; ++i) {
        if(winners[i] == 0){
            printf("Nereseno\n");
        }
        if(winners[i] == 1){
            printf("Milan\n");
        }
        if(winners[i] == 2){
            printf("Marko\n");
        }
    }
}

int main (){
    int rounds;

    scanf("%d", &rounds);

    int winners[100];
    int milanWins = 0;
    int markoWins = 0;

    for (int i = 0; i < rounds; ++i) {

        int milanScore = 0;
        int markoScore = 0;

        char card;
        for (int j = 0; j < 4; ++j) {
            scanf(" %c", &card);
            if (j < 2){
                milanScore += cardValue(card);
            }
            else{
                markoScore += cardValue(card);
            }
        }

        if (milanScore == markoScore){
            winners[i] = 0; // nereseno
        }

        if (milanScore > markoScore){
            winners[i] = 1; // milan
            milanWins++;
        }

        if (milanScore < markoScore){
            winners[i] = 2; // marko
            markoWins++;
        }
    }

    printWinners(winners,rounds);
    printf("%d %d", milanWins, markoWins);

    return 0;
}
//2
//J J K Q
//A K Q K
