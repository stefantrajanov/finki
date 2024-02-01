//
// Created by Stefan on 12/20/2022.
//
#include <stdio.h>

void printFile() {
    FILE *f=fopen("shema.txt","r");
    char line[1000];
    while(!feof(f)){
        fgets(line,1000,f);
        if (feof(f))
            break;
        printf("%s",line);
    }
    fclose(f);
}
void printMatrix(int matrix[100][100], int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

float squareRoot(float number){
    float sqrt = number / 2;
    float temp = 0;

    // Iterate until sqrt is different of temp, that is updated on the loop
    while(sqrt != temp){
        // initially 0, is updated with the initial value of 128
        // (on second iteration = 65)
        // and so on
        temp = sqrt;

        // Then, replace values (256 / 128 + 128 ) / 2 = 65
        // (on second iteration 34.46923076923077)
        // and so on
        sqrt = ( number / temp + temp) / 2;
    }

    return sqrt;
}
float my_ceil(float f)
{
    unsigned input;
    memcpy(&input, &f, 4);
    int exponent = ((input >> 23) & 255) - 127;
    if (exponent < 0) return (f > 0);
    // small numbers get rounded to 0 or 1, depending on their sign

    int fractional_bits = 23 - exponent;
    if (fractional_bits <= 0) return f;
    // numbers without fractional bits are mapped to themselves

    unsigned integral_mask = 0xffffffff << fractional_bits;
    unsigned output = input & integral_mask;
    // round the number down by masking out the fractional bits

    memcpy(&f, &output, 4);
    if (f > 0 && output != input) ++f;
    // positive numbers need to be rounded up, not down

    return f;
}

int main() {
    //Vasiot kod tuka
    int n;
    scanf("%d", &n);
    int matrix[100][100];

    int length = (int)my_ceil(squareRoot((float)n));
    int counter = 0;
    for (int i = 0; i < length; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < length; ++j) {
                if (counter == n) {
                    break;
                }
                counter++;
                matrix[j][i] = counter;
            }
        }else{
            for (int j = length - 1; j>=0; --j) {
                if (counter == n){
                    break;
                }
                counter++;
                matrix[j][i] = counter;
            }
        }
    }

    FILE * filePointer = fopen("shema.txt", "w");

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            fprintf(filePointer, "%d ", matrix[i][j]);
        }
        fputc('\n',filePointer);
    }
    fclose(filePointer);

    // do tuka
    printFile();
    return 0;
}