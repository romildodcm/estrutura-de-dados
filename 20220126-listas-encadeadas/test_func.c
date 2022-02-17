#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// definição da estrutura de dados
typedef struct elemento
{
    int dado;
    struct elemento *prox;
} * Lista;

// função para criar lista;
Lista criaLista()
{
    return NULL;
}

// inser~~ao ordenada
// Lista insereOrdenados(Lista l1, int valorInt)
// {
//     Lista entrada, menorQueEntrada;

//     menorQueEntrada = criaLista();
//     entrada = malloc(sizeof(struct elemento));

//     entrada->dado = valorInt;

//     if (l1 == NULL)
//     {
//         while (l1 != NULL && l1->dado < valorInt)
//         {
//             menorQueEntrada = l1;
//             l1 = l1->prox;
//         }

//         entrada->prox = l1;

//         if (menorQueEntrada != NULL)
//             menorQueEntrada->prox = entrada;
//         else
//             l1 = entrada;
//     }
//     else
//     {
//         entrada->prox = NULL;
//         l1 = entrada;
//     }

//     return l1;
// }

/// alterando
Lista insereOrdenado(Lista l1, int valor)
{
    Lista l, novo, ant;

    l = l1;
    novo = malloc(sizeof(struct elemento));
    novo->dado = valor;
    ant = criaLista();

    if (l != NULL)
    {
        while ((l != NULL) && (l->dado < valor))
        {
            ant = l;
            l = l->prox;
        }

        novo->prox = l;

        if (ant == NULL)
            l1 = novo;
        else
            ant->prox = novo;
    }
    else
    {
        novo->prox = NULL;
        l1 = novo;
    }

    return l1;
}

void imprimir(Lista l)
{
    int i = 0;
    Lista p; // Ponteiro auxiliar, para percorrer a lista

    printf("Itens da lista:\n");
    p = l;            // Fazer p apontar para o início da lista
    while (p != NULL) // Enquanto não chegar ao final da lista
    {
        for (i = 0; i < 20 && p != NULL; i++)
        {
            printf("%d", p->dado); // Imprime o elemento
            p = p->prox;           // Avança o ponteiro para o próximo nodo
            // se não null -> imprime vísgula
            if (p != NULL)
                printf(", ");
        }
        printf("\n"); // Avança para a próxima linha
    }
}

int main()
{
    int valorInt;
    char op = 's';
    Lista l1;
    l1 = criaLista();

    while (op == 's' || op == 'S')
    {
        printf("Insira um valor: ");
        scanf(" %d", &valorInt);
        l1 = insereOrdenado(l1, valorInt);

        printf("Deseja inserir outro? (S/N)\n");
        scanf(" %c", &op);
    }

    imprimir(l1);

    return 0;
}