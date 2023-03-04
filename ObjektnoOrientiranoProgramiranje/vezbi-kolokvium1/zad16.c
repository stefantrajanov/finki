#include <stdio.h>
#include <string.h>

#define NEDELI 4
#define DENOVI 5

// ovde strukturata RabotnaNedela

typedef struct {
    int workHours[5];
    int weekNumber;
} WorkWeek;

// ovde strukturata Rabotnik

typedef struct {
    char name[100];
    WorkWeek workWeeks[5];
}
        Workers;

// ovde funkciite
void table(Workers *workers, int n) {

    printf("TABLE\n");
    printf("Rab\t1\t2\t3\t4\tVkupno\n");
    for (int i = 0; i < n; ++i) {
        int totalWorkHours = 0;
        printf("%s\t", workers[i].name);
        for (int j = 0; j < NEDELI; ++j) {
            int workHoursSum = 0;
            for (int k = 0; k < DENOVI; ++k) {
                workHoursSum += workers[i].workWeeks[j].workHours[k];
                totalWorkHours += workers[i].workWeeks[j].workHours[k];
            }
            printf("%d\t", workHoursSum);
        }
        printf("%d\n", totalWorkHours);
    }
}

int maxWeek(Workers *worker) {
    int max = 0;
    int maxIndex = 0;
    for (int j = 0; j < NEDELI; ++j) {
        int workHoursSum = 0;
        for (int k = 0; k < DENOVI; ++k) {
            workHoursSum += worker->workWeeks[j].workHours[k];
        }
        if (max < workHoursSum) {
            max = workHoursSum;
            maxIndex = j;
        }
    }

    return (maxIndex+1);
}

int main() {
    int n;
    scanf("%d", &n);
    Workers rabotnici[n];
    for (int i = 0; i < n; ++i) {
        scanf("%s", rabotnici[i].name);
        for (int j = 0; j < NEDELI; ++j) {
            for (int k = 0; k < DENOVI; ++k) {
                scanf("%d", &rabotnici[i].workWeeks[j].workHours[k]);
            }

        }
    }

    table(rabotnici, n);
    printf("MAX NEDELA NA RABOTNIK: %s\n", rabotnici[n / 2].name);
    printf("%d\n", maxWeek(&rabotnici[n / 2]));

    return 0;
}
