#include <stdio.h>
#include <math.h>

void areaRetangulo(float a, float b)
{
    printf("\nArea do retangulo eh: %.2f", a * b);
}

int main()
{
    float altura, base;

    printf("Digite a base do retangulo: ");
    scanf(" %f", &base);
    printf("Digite a altura do retangulo: ");
    scanf(" %f", &altura);

    areaRetangulo(altura, base);

    return 0;
}