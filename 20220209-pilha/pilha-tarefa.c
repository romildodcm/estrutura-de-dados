// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes
#define TRUE 1
#define FALSE 0

// Definição de tipos
typedef struct elemento
{
    int dado;
    struct elemento *prox;
} * Pilha;

// Funções
int menu();
Pilha criaPilha();
int pilhaVazia(Pilha p);
void imprimePilha(Pilha p);
Pilha empilha(Pilha p, int e);
Pilha desempilha(Pilha p, int *e);

// Main
int main()
{
    int op, valorInt;
    Pilha p1;
    p1 = criaPilha();

    do
    {
        op = menu();

        switch (op)
        {
        case 1:
            printf("----------------- Empilhar um elemento -----------------\n");
            printf("Digite o valor (int) que deseja empilhar: ");
            scanf(" %d", &valorInt);
            p1 = empilha(p1, valorInt);
            break;
        case 2:
            printf("--------------- Desempilhar um elemento ----------------\n");
            printf("Desempilhando elemento...\n");
            p1 = desempilha(p1, &valorInt);
            if (valorInt == -1)
                printf("Pilha vazia!\n");
            else
                printf("O elemento foi desempilhado.\n");
            break;
        case 3:
            printf("--------------- Exibir conteudo da pilha ---------------\n");
            if (pilhaVazia(p1) == TRUE)
                printf("Pilha vazia!\n");
            else
            {
                printf("Itens da pilha:\n");
                imprimePilha(p1);
            }
            break;
        case 0:
            printf("----------------------- Saindo... ----------------------\n");
            break;
        default:
            printf("******************** Opcao invalida ********************\n");
            break;
        }
    } while (op != 0);

    return 0;
}

int menu()
{
    int op = -1;

    // menu
    printf("------------------------- MENU -------------------------\n");

    printf("\t 1 - Empilhar um elemento;\n");
    printf("\t 2 - Desempilhar um elemento;\n");
    printf("\t 3 - Exibir conteudo da pilha;\n");
    printf("\t 0 - Sair.\n\n");
    printf("Digite o numero da opcao desejada e tecle enter: ");
    scanf(" %d", &op);

    return op;
}

Pilha criaPilha()
{
    return NULL;
}

int pilhaVazia(Pilha p)
{
    if (p == NULL)
        return TRUE;
    else
        return FALSE;
}

void imprimePilha(Pilha p)
{
    Pilha ap;
    ap = p;

    while (ap != NULL)
    {
        // imprime valor
        printf("%d", ap->dado);
        // passa para o próximo
        ap = ap->prox;
        // se não null -> imprime vísgula
        if (ap != NULL)
            printf(", ");
    }
    printf(".\n");
}

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
    }

    return (p);
}
