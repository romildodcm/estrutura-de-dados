#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxItensNaLista 10
#define TamanhoItem 20

typedef char tpLista[MaxItensNaLista][TamanhoItem];

// 0. menu
int menu()
{
    int op = -1;

    // menu
    printf("------------------------- MENU -------------------------\n");

    printf("\t 1 - Inserir elemento;\n");
    printf("\t 2 - Retirar elemento;\n");
    printf("\t 3 - Criar lista;\n");
    printf("\t 4 - Contar elementos da lista;\n");
    printf("\t 5 - Exibir lista;\n");
    printf("\t 0 - Sair;\n\n");
    printf("Digite o numero da opcao desejada e tecle enter: ");
    scanf(" %d", &op);

    return op;
}

// limpar entrada do teclado antes do fgets
void clear()
{
    char ch;
    while (ch = getchar() != '\n' && ch != EOF)
        ;
}

// 1. inserir elemento
int inserir(tpLista L, int n, int max)
{
    clear();
    printf("Digite o nome do item a ser inserido: \n");
    fgets(L[n], sizeof(L[n]), stdin);
    n++;
    return n;
}

// 2. retirar elemento
int retirarItem(tpLista L, int n, int max)
{
    int i = 0;
    char item[TamanhoItem];

    if (n > 0)
    {
        clear();
        printf("Digite o nome do item: ");
        fgets(item, sizeof(item), stdin);

        // acha o item (posição)
        for (i = 0; i < n; i++)
        {
            // verifica existencia
            if (strcmp(L[i], item) == 0)
            {
                // move lista acima para essa posição
                // exemplo:
                // apagou a posição 1
                // 0 - 0 (zero continua o que tinha em zero)
                // 2 -> 1 (2 vai para 1)
                // 3 -> 2 (3 vai para 2)
                // n -> n-1 (n vai para n-1)

                for (i; i < n; i++)
                    strcpy(L[i], L[i + 1]);

                n--;

                for (i = n; i < max; i++)
                    L[i][0] = '\0';

                printf("Item removido com sucesso!\n");

                break;
            }
            else if (i == n - 1)
                printf("O item nao esta na lista.\n");
        }
    }
    else
    {
        printf("Lista vazia.\n");
        return 0;
    }

    return n;
}

// 3. criar lista
int criarLista(tpLista L, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        L[i][0] = '\0';
    }

    return 0;
}

// 4. contar elementos da lista
int contaLista(tpLista L, int n, int max)
{
    int i;

    if (n > 0)
    {
        for (i = 0; i < n && strlen(L[i]) > 0; i++)
            ;
        return (i);
    }
    else
    {
        // printf("Lista vazia.\n");
        return 0;
    }
}

// 5. exibir elementos da lista
void imprimirLista(tpLista L, int n)
{
    int i;

    if (n > 0)
    {
        for (i = 0; i < n && strlen(L[i]) > 0; i++)
            printf("%s", L[i]);
    }
    else
        printf("Lista vazia.\n");
}

int main()
{
    int op = -1, itensNaLista = 0;
    tpLista L1;

    while (op != 0)
    {
        op = menu();

        switch (op)
        {
        case 1:
            printf("------------------- Inserir elemento -------------------\n");
            if (itensNaLista == MaxItensNaLista)
                printf("Lista cheia! Remova itens para inserir novos.\n");
            else
                itensNaLista = inserir(L1, itensNaLista, MaxItensNaLista);

            break;
        case 2:
            printf("------------------- Retirar elemento -------------------\n");
            itensNaLista = retirarItem(L1, itensNaLista, MaxItensNaLista);

            break;
        case 3:
            printf("--------------------- Criar lista ----------------------\n");
            itensNaLista = criarLista(L1, MaxItensNaLista);
            printf("Lista criada com sucesso!\n");

            break;
        case 4:
            printf("--------------- Contar elementos da lista --------------\n");
            printf("Tem %d itens na lista.\n", contaLista(L1, itensNaLista, MaxItensNaLista));

            break;
        case 5:
            printf("--------------------- Exibir lista ---------------------\n");
            imprimirLista(L1, itensNaLista);

            break;
        case 0:
            printf("----------------------- Saindo... ----------------------\n");
            break;
        default:
            printf("******************** Opcao invalida ********************\n");
            break;
        }
    }

    return 0;
}