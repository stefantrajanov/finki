#include <stdio.h>

int main(){

    int index;
    int grade;
    float gradeAverage = 0;

    scanf("%d", &index);

    for (int i = 0; i < 6; ++i) {
        scanf("%d", &grade);
        gradeAverage += (float)grade;
    }
    gradeAverage /= 6;
    int year = -((index / 10000) - 23);

    printf("Prosek: %.3f\n", gradeAverage);
    printf("Student: %d\n", index);
    printf("%d godina\n", year);
    printf("Nagraden: %d", gradeAverage >= 9.5);


    return 0;
}