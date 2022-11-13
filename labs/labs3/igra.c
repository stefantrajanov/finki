#include <stdio.h>
#include <stdlib.h>

int main()
{
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

    int tier;
    int totalPoints = 0;

    for (int i = 0; i < 3; i++){
        scanf("%d", &tier);
        int gamePoints = 0;
        if (tier <= 0){
            continue;
        }
        if (tier <= tierOne){
            gamePoints += tier * defaultPoints;
        }
        if(tier > tierOne && tier <= tierTwo){
            gamePoints += tier * tierTwoPoints;
        }
        if(tier > tierTwo){
            gamePoints += tier * tierThreePoints;
        }

        totalPoints += gamePoints;
    }

    printf("%d", totalPoints);

  return 0;
}
