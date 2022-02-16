#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// definição da estrutura de dados
typedef struct elemento
{
    int dado;
    struct elemento *prox;
} * Lista;

// Prototipo das funções
int menu();
Lista criaLista();
Lista insereOrdenado(Lista l1, int valor);
Lista retiraLista(Lista l, int e);
Lista buscaLista(Lista l, int e);
void imprimir();
int contaLista(Lista l);

int main()
{
    int op, cont, item, valorInt;
    Lista l1, busca;
    l1 = criaLista();

    do
    {
        op = menu();

        switch (op)
        {
        case 1:
            printf("------------------- Inserir elemento -------------------\n");
            printf("Digite um valor inteiro para inserir na lista: ");
            scanf(" %d", &valorInt);
            l1 = insereOrdenado(l1, valorInt);
            break;
        case 2:
            printf("------------------- Retirar elemento -------------------\n");
            if (l1 == NULL)
                printf("Lista vazia. Não tem o que retirar.\n");
            else
            {
                printf("Digite um valor inteiro para retirar da lista: ");
                scanf(" %d", &valorInt);
                busca = buscaLista(l1, valorInt);
                if (busca == NULL)
                    printf("O valor %d não esta na lista.\n", valorInt);
                else
                {
                    l1 = retiraLista(l1, valorInt);
                    printf("O valor %d foi retirado da lista.\n", valorInt);
                }
            }
            break;
        case 3:
            printf("-------------------- Buscar elemento -------------------\n");
            if (l1 == NULL)
                printf("Lista vazia. Não tem o que buscar.\n");
            else
            {
                printf("Digite um valor inteiro para buscar na lista: ");
                scanf(" %d", &valorInt);
                busca = buscaLista(l1, valorInt);
                if (busca == NULL)
                    printf("O valor %d não esta na lista.\n", valorInt);
                else
                    printf("O valor %d esta na lista.\n", valorInt);
            }
            break;
        case 4:
            printf("--------------------- Exibir lista ---------------------\n");
            if (l1 == NULL)
                printf("Lista vazia.\n");
            else
                imprimir(l1);
            break;
        case 5:
            printf("------------- Número de elementos na lista -------------\n");
            if (l1 == NULL)
                printf("Lista vazia. 0 elemento.\n");
            else
            {
                valorInt = contaLista(l1);
                if (valorInt == 1)
                    printf("A lista tem %d elemento.\n", valorInt);
                else
                    printf("A lista tem %d elementos.\n", valorInt);
            }
            break;
        case 0:
            printf("---------------------- Saindo... -----------------------\n");
            break;
        default:
            printf("******************** Opção invalida ********************\n");
            break;
        }
    } while (op != 0);

    return 0;
}

// Função menu
int menu()
{
    int op = -1;

    // menu
    printf("------------------------- MENU -------------------------\n");
    printf("\t 1 - Inserir elemento;\n");
    printf("\t 2 - Retirar elemento;\n");
    printf("\t 3 - Buscar elemento;\n");
    printf("\t 4 - Exibir lista;\n");
    printf("\t 5 - Número de elementos na lista;\n");
    printf("\t 0 - Sair.\n\n");
    printf("Digite o numero da opção desejada e tecle enter: ");
    scanf(" %d", &op);

    return op;
}

// função para criar lista;
Lista criaLista()
{
    return NULL;
}

// Função para inserir ordenadamente
Lista insereOrdenado(Lista l1, int valor)
{
    Lista l, novo, ant;

    l = l1;                                 // lista recebe a lista do main
    novo = malloc(sizeof(struct elemento)); // aloca espaço
    novo->dado = valor;                     // novo recebe o valor a ser inserido
    ant = criaLista();                      // lista anterior é criada para comparação

    // verifica se a lista não está vazia
    if (l != NULL)
    {
        // Varre a lista enquanto os valores forem menores
        // que o valor a ser inserido
        while ((l != NULL) && (l->dado < valor))
        {
            ant = l;     // armazena posição anterior
            l = l->prox; // passa para a próxima posição
        }

        novo->prox = l; // ponteiro do novo valor recebe a continuação da lista

        // armazena o valor
        if (ant == NULL)
            l1 = novo;
        else
            ant->prox = novo;
    }
    else
    {
        // se a lista esta vazia, só adicionar o valor nela
        novo->prox = NULL;
        l1 = novo;
    }

    return l1;
}

// Retira o elemento e da lista l, se ele existir.
// Retorna o endereço para o início da lista.
Lista retiraLista(Lista l, int e)
{
    Lista p, // Ponteiro p para o elemento atual
        ant; // Ponteiro ant para o elemento anterior

    p = l;
    ant = l;
    // Procura o elemento e até o fim da lista ou encontrá-lo
    while ((p != NULL) && (p->dado != e))
    { // Procura o elemento e
        ant = p;
        p = p->prox;
    }
    if (p != NULL)
    {                 // Encontrou o elemento e. Remove
        if (p == ant) // Removendo primeiro elemento
        {
            l = p->prox;
            free(p);
        }
        else // Não é o primeiro elemento da lista
        {
            ant->prox = p->prox;
            free(p);
        }
    }
    return (l);
}

//  Procura o elemento e na lista l, retornando o endereço
//  do elemento se ele estiver na lista, ou NULL em caso contrário
Lista buscaLista(Lista l, int e)
{
    Lista p; // Ponteiro para percorrer a lista

    p = l; // Faz o ponteiro apontar para o início da lista
    // Percorre a lista enquanto não chegar ao final da lista
    // e não encontrar o elemento
    while ((p != NULL) && (p->dado != e))
    {
        p = p->prox;
    }
    return (p); // Retorna o endereço do nodo encontrado
                // ou NULL caso tenha chegado ao final sem
                // encontrar o elemento e na lista.
}

// Imprimir a lista
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

// Conta o número de nodos da lista l
int contaLista(Lista l)
{
    Lista p;
    int cont = 0; // inicia o contador com 0

    p = l;            // aponta p para o início da lista
    while (p != NULL) // enquando não acabou a lista
    {
        cont++;      // incrementa o contador
        p = p->prox; // passa para o próximo elemento
    }
    return cont; // retorna o contador
}
