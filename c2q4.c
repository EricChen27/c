#include <stdio.h>

int main(void){
    float input, final;
    printf("Enter Amount: ");
    scanf("%f", &input);
    final = input * 1.05;
    printf("Amount with five percent tax: %.2f\n", final);
    return 0;
}
