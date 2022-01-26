#include <stdio.h>
#include <math.h>

// Implemente uma função que receba dois números, e retorne a soma dos dois;
float soma(float a, float b)
{
    return a + b;
}

// Implemente uma função que receba dois números, e retorne o produto dos dois;
float produto(float a, float b)
{
    return a * b;
}

// Implemente uma função que receba dois números, e retorne a diferença entre o primeiro e o segundo;
float dif(float a, float b)
{
    return a - b;
}

// Implemente uma função que receba dois números, e retorne o resultado da divisão do primeiro pelo segundo;
float div(float a, float b)
{
    return a / b;
}

// Implemente uma função que receba dois números, e um caracter que indique a operação ("+", "-", "*" ou "/") e calcule o resultado da operação, chamando as funções já implementadas.

float calc(float a, float b, char op)
{
    if (op == '+')
        return soma(a, b);
    else if (op == '-')
        return dif(a, b);
    else if (op == '*')
        return produto(a, b);
    else if (op == '/')
        return div(a, b);
}

int main()
{
    float x, y, resultado;
    char op;

    printf("Digite a operacao desejada (+, -, *, /): ");
    scanf(" %c", &op);
    printf("Digite o primeiro numero: ");
    scanf(" %f", &x);
    printf("Digite o segundo numero: ");
    scanf(" %f", &y);
    printf("\nResultado: %.4f", calc(x, y, op));

    return 1;
}