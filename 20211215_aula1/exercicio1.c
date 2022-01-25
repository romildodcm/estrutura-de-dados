#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxAlunos 40
#define tamanhoNome 40

// struct
struct aluno
{
    char nome[tamanhoNome];
    int matricula;
    float notasProvas[2];
    float notaMedia;
    int faltas;
    char resultado[10];
};

// menu principal
int menuPrincipal()
{
    int op = -1;

    // menu
    printf("--------------------- MENU ALTERAR ---------------------\n");
    printf("\t 1 - Inserir alunos;\n");
    printf("\t 2 - Listar alunos;\n");
    printf("\t 3 - Salvar dados;\n");
    printf("\t 4 - Carrega dados;\n");
    printf("\t 5 - Sair;\n\n");
    printf("Digite o numero da opcao desejada e tecle enter: ");
    scanf(" %d", &op);

    return op;
}

// inserir aluno
int inserirAluno(struct aluno *a, int n, int max)
{
    int op = 1;
    while (op == 1)
    {
        if (n >= max)
        {
            printf("Ja foram cadastrados todos os %d alunos.\n", max);
            op = 0;
        }
        else if (n < max)
        {
            printf("Cadastrando(s) %d/%d funcionarios.\n", n + 1, max);
            printf("Nome: ");
            fflush(stdin);
            fgets(a[n].nome, sizeof(a[n].nome), stdin);
            printf("Grau de estudo (1, 2, 3, 4 ou 5): ");
            scanf(" %d", &f[n].grauEstudo);
            printf("Quantidade de linguas que fala (1, 2...): ");
            scanf(" %d", &f[n].quantidadeLinguas);
            printf("Nivel do cargo que ocupa (1, 2, 3 ou 4): ");
            scanf(" %d", &f[n].nivelCargo);
            printf("Indice de produtividade (entre 0.0 e 1.0): ");
            scanf(" %f", &f[n].indiceProdutividade);

            // sobre index para próximo funcionario
            n++;

            printf("\nDigite 1 para inserir mais um funcionario\n");
            printf("ou digite 0 para voltar ao menu principal: ");
            scanf(" %d", &op);
        }
    }
}

// ler arquivo e passar para struct

// Menu inserir
int inserir(int i)
{
    // carrega alunos do arquivo

    // ver até onde tem alunso, permitir cadastrar os restantes
    // le os dados e carrega
    return i;
}
// salvar arquivos bin
/*
fwrite(arquivo, registro, tamanho, quantidade)
*/
// abrir o arquivo

int main()
{
    int opcao = 0, alunosCadastrados = 0;
    struct aluno alunos[maxAlunos];

    while (opcao != 5)
    {
        opcao = menuPrincipal();

        switch (opcao)
        {
        case 1:
            // opção de inserir alunos
            alunosCadastrados = inserir(alunosCadastrados);
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            printf("---------------------- Saindo... -----------------------\n");
            break;

        default:
            printf("******************** Opcao invalida ********************\n");
            break;
        }
    }
}
