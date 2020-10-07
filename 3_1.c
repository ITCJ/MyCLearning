//scanf();
#include <stdio.h>

int main() {
    float weight;
    float jin;
    float a;
    float b;
    float c;

    printf("Are you worth your weight in platinum?\n");
    printf("Let's check it out.\n");
    printf("Please enter your weight in kg:");
    
    scanf("%f", &weight);
    jin = 2 * weight;

    printf("Your weight in 斤 is %.2f\n", jin);

    getchar();
    getchar();


}