#include<stdio.h>
#include <string.h>

typedef struct {
    char name[101];
    int insurance;
    int numberOfCheckUps;

} Patient;

typedef struct {
    char name[100];
    int numberOfPatients;
    Patient patients[200];
    float price;


} Doctor;

void mostSuccesfulDoctor(Doctor *doctors, int n) {
    float maxProfit = 0;
    int maxCheckups = 0;

    char maxDoctorName[150];

    for (int i = 0; i < n; ++i) {
        float currentProfit;
        int currentTotalCheckups_NO_INSURANCE = 0;
        int currentTotalCheckupsALL = 0;

        for (int j = 0; j < doctors[i].numberOfPatients; ++j) {
            if (!doctors[i].patients[j].insurance) {
                currentTotalCheckups_NO_INSURANCE += doctors[i].patients[j].numberOfCheckUps;
            }
            currentTotalCheckupsALL += doctors[i].patients[j].numberOfCheckUps;
        }
        currentProfit = (float)currentTotalCheckups_NO_INSURANCE * doctors[i].price;

        if (maxProfit < currentProfit){
            // zemi go doktorot
            strcpy(maxDoctorName, doctors[i].name);
            maxProfit = currentProfit;
            maxCheckups = currentTotalCheckupsALL;

        } else if (maxProfit == currentProfit){
            if (maxCheckups < currentTotalCheckupsALL){
                // zemi go doktorot
                strcpy(maxDoctorName, doctors[i].name);
                maxCheckups = currentTotalCheckupsALL;
            }
        }
    }

    printf("%s %.2f %d", maxDoctorName, maxProfit, maxCheckups);
}

int main() {
    int i, j, n, broj;
    Doctor doctor[200];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        //ime na doktor
        scanf("%105s", doctor[i].name);
        //broj na pacienti
        scanf("%d", &doctor[i].numberOfPatients);
        //cena na pregled
        scanf("%f", &doctor[i].price);

        for (j = 0; j < doctor[i].numberOfPatients; j++) {
            scanf("%105s", doctor[i].patients[j].name);
            scanf("%d", &doctor[i].patients[j].insurance);
            scanf("%d", &doctor[i].patients[j].numberOfCheckUps);
        }
    }
    mostSuccesfulDoctor(doctor, n);

    return 0;
}
