#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

// criando a pilha
typedef struct elemento
{
    int dado;
    struct elemento *prox;
} * Pilha;

// Função para criar pilha
Pilha criaPilha()
{
    return NULL;
}

// Verificando se a pilha esta vazia
int pilhaVazia(Pilha p)
{
    if (p == NULL)
        return TRUE;
    else
        return FALSE;
}

// Imprime todos os nodos da pilha p
void imprimePilha(Pilha p)
{
    Pilha ap;
    printf("\nItens da pilha\n");
    ap = p;
    while (ap != NULL)
    {
        printf("%d - ", ap->dado);
        ap = ap->prox;
    }
    printf("\n");
}

// Empilha o elemento e no topo da pilha p
// recebe a pilha e o elemento a ser inserido na pilha

Pilha empilha(Pilha p, int e)
{

    Pilha novo;                             // Cria a pilha a ser usada na função
    novo = malloc(sizeof(struct elemento)); // Aloca o espaço para o elmento
    novo->dado = e;                         // Atribui os dados ao novo elemento
    novo->prox = p;                         // O próximo do novo é o topo anterior
    return (novo);                          // O novo elemento passa a ser o topo
}

Pilha desempilha(Pilha p, int *e)
{
    Pilha ap; // apontador auxiliar

    // Se quiser deixar explicito, só usar if (pilhaVazia(p) != TRUE)
    if (!pilhaVazia(p))
    {
        // foto no celular 20h20 ilustrando essa operçao

        // se a pilha não for vazia
        // Retorna o valor do elemento que está no topo da pilha
        *e = p->dado;
        // Salva o endereço do topo para liberação
        ap = p;
        // Faz o topo apontar para o próximo elemento
        p = p->prox;
        // Libera o espaço ocupado pelo elemento removido
        free(ap);
    }
    else
    { 
        // A pilha está vazia. Retorna valor -1.
        *e = -1;
        printf("\nPilha Vazia");
    }

    return (p);
}

int main()
{
    int valorInt;
    Pilha p1;         // declara a variavel
    p1 = criaPilha(); // inicia pilha vazia

    // adicionando valores na pilha (empilhando)
    valorInt = 3;
    p1 = empilha(p1, valorInt);
    valorInt = 5;
    p1 = empilha(p1, valorInt);
    valorInt = 9;
    p1 = empilha(p1, valorInt);
    valorInt = 4;
    p1 = empilha(p1, valorInt);

    // imprime pilha
    printf("Dados empilhados\n");
    imprimePilha(p1);

    // chamada desempilha
    // e  = vai contrt endereço
    // p1 vai conter p1
    p1 = desempilha(p1, &valorInt);
    if (valorInt == -1)
    {
        printf("\nPilha vazia!\n");
    }
    else
        printf("\nDesempilhou o valor %d\n", valorInt);

    printf("\nDados empilhados:\n");
    imprimePilha(p1);

    return 0;
}