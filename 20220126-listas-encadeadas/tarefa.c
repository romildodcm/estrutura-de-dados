#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// definição da estrutura de dados
struct elemento
{
    int dado;              // Conteúdo (inteiro)
    struct elemento *prox; // Ponteiro para o próximo registro
};

// definição de tipo
typedef struct elemento *Lista;

// prototipo das funções
int menu();
Lista criaLista();
Lista inserir();
int retirar();
int buscar();
void imprimir();
int contar();

// Função principal
int main()
{
    int op, cont, item;
    Lista l;
    l = criaLista();

    do
    {
        op = menu();

        switch (op)
        {
        case 1:
            printf("------------------- Inserir elemento -------------------\n");
            break;
        case 2:
            printf("------------------- Retirar elemento -------------------\n");
            break;
        case 3:
            printf("-------------------- Buscar elemento -------------------\n");
            break;
        case 4:
            printf("--------------------- Exibir lista ---------------------\n");
            break;
        case 5:
            printf("------------- Numero de elementos na lista -------------\n");
            break;
        case 0:
            printf("---------------------- Saindo... -----------------------\n");
            break;

        default:
            printf("******************** Opcao invalida ********************\n");
            break;
        }
    } while (op != 0);

    return 0;
}