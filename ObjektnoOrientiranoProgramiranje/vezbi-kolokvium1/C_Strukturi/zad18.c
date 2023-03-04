#include<stdio.h>
#include<string.h>

typedef struct {
    char name[20];
    int maxCapacity;
    int active; // 0 - not | 1 - yes

}SkiLift;

typedef struct{
    char name[20];
    char countryOfOrigin[50];
    SkiLift skiLifts[50];
    int numberOfSkiLifts;

}SkiCenter;

void maxCapacitySkiCenter(SkiCenter *skicenters, int n){
    int totalMaxCapacity = 0;
    char biggestSkiCenter[100];
    char biggestSkiCenterCountryOfOrigin[100];

    int maxSkiLifts = 0;

    for (int i = 0; i < n; ++i) {
        int currentMaxCapacity = 0;

        for (int j = 0; j < skicenters[i].numberOfSkiLifts; ++j) {
            if (skicenters[i].skiLifts[j].active){
                currentMaxCapacity += skicenters[i].skiLifts[j].maxCapacity;
            }

            if (totalMaxCapacity < currentMaxCapacity){
                strcpy(biggestSkiCenter,skicenters[i].name);
                strcpy(biggestSkiCenterCountryOfOrigin,skicenters[i].countryOfOrigin);
                totalMaxCapacity = currentMaxCapacity;
                maxSkiLifts = skicenters[i].numberOfSkiLifts;
            }
            else if (totalMaxCapacity == currentMaxCapacity){
                if (maxSkiLifts < skicenters[i].numberOfSkiLifts){
                    maxSkiLifts = skicenters[i].numberOfSkiLifts;
                    strcpy(biggestSkiCenter,skicenters[i].name);
                    strcpy(biggestSkiCenterCountryOfOrigin,skicenters[i].countryOfOrigin);
                }
            }
        }
    }

    printf("%s\n", biggestSkiCenter);
    printf("%s\n", biggestSkiCenterCountryOfOrigin);
    printf("%d", totalMaxCapacity);
}


int main()
{
    int n;
	scanf("%d", &n);

    SkiCenter skicenters[100];

	for (int i = 0; i < n; i++){
		//vnesi ime
        scanf("%100s", skicenters[i].name);
		//vnesi drzava
        scanf("%100s", skicenters[i].countryOfOrigin);
		//vnesi broj na liftovi
        scanf("%d", &skicenters[i].numberOfSkiLifts);


        //za sekoj ski lift vnesi:
        for (int j = 0; j < skicenters[i].numberOfSkiLifts; ++j) {
            //vnesi ime
            scanf("%100s", skicenters[i].skiLifts[j].name);
            //vnesi maksimalen broj korisnici
            scanf("%d", &skicenters[i].skiLifts[j].maxCapacity);
            //vnesi dali e pusten vo funkcija
            scanf("%d", &skicenters[i].skiLifts[j].active);
        }
	}

    maxCapacitySkiCenter(skicenters,n);

	return 0;
}
