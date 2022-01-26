#include <stdio.h>
#include <math.h>

float areaRetangulo(float a, float b)
{
    return a * b;
}

int main()
{
    float altura, base;

    printf("Digite a base do retangulo: ");
    scanf(" %f", &base);
    printf("Digite a altura do retangulo: ");
    scanf(" %f", &altura);

    printf("\nArea do retangulo eh: %.2f", areaRetangulo(altura, base));

    return 0;
}