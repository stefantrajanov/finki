//
// Created by Stefan on 11/9/2022.
//
#include <stdio.h>

int main(){
    int defaultPoints;
    int tierTwoPoints;
    int tierThreePoints;

    int tierOne;
    int tierTwo;

    scanf("%d %d %d %d %d",
          &defaultPoints,
          &tierOne,
          &tierTwoPoints,
          &tierTwo,
          &tierThreePoints
          );

    int passedLevels;
    int totalPoints = 0;
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &passedLevels);
        int thisGamePoints = 0;
        if (passedLevels <= 0){continue;}

        if (passedLevels <= tierOne){
            thisGamePoints += passedLevels * defaultPoints;
        }
        else if (passedLevels > tierOne && passedLevels <= tierTwo){
            thisGamePoints += tierOne * defaultPoints;
            thisGamePoints += (passedLevels - tierOne) * tierTwoPoints;
        }
        else
        {
            thisGamePoints += (tierOne) * defaultPoints;
            thisGamePoints += (tierTwo - tierOne) * tierTwoPoints;
            thisGamePoints += ((passedLevels - tierTwo)) * tierThreePoints;
        }
        totalPoints += thisGamePoints;
    }

    printf("%d", totalPoints);

    // 100 3 150 6 200 4 0 0
    // 102 4 131 5 142 4 7 5

    // 408 + (408 + 131 + 142 + 142) + (408 + 131)
    return 0;
}