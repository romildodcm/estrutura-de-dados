#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxAlunos 40
#define tamanhoNome 40

// struct
typedef struct
{
    char nome[tamanhoNome];
    int matricula;
    float notasProvas[2];
    float notaMedia;
    int faltas;
    char resultado[10];
} aluno;

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

// função para calcular resultado
const char *resultadoAluno(float notaMedia, int faltas)
{
    if (notaMedia >= 6 && faltas <= 20)
        return "Aprovado  ";
    else
        return "Reprovado ";
}

// inserir aluno
int inserirAluno(aluno a[], int n, int max)
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
            printf("Cadastrando(s) %d/%d alunos.\n", n + 1, max);

            printf("Nome: ");
            fgets(a[n].nome, sizeof(a[n].nome), stdin);
            printf("Matricula: ");
            scanf(" %d", &a[n].matricula);
            printf("Nota 1: ");
            scanf(" %f", &a[n].notasProvas[0]);
            printf("Nota 2: ");
            scanf(" %f", &a[n].notasProvas[1]);
            printf("Faltas: ");
            scanf(" %d", &a[n].faltas[1]);

            // nota média
            a[n].notaMedia = (a[n].notasProvas[0] + a[n].notasProvas[1]) / 2;

            // calcula resultado do aluno
            a[n].resultado = resultadoAluno(a[n].notaMedia, a[n].faltas);

            // sobre index para próximo aluno
            n++;

            printf("\nDigite 1 para inserir mais um aluno\n");
            printf("ou digite 0 para voltar ao menu principal: ");
            scanf(" %d", &op);
        }
    }
}

// Listar alunos
void listarAlunos(aluno a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\nNome: %s", a[n].nome);
        printf("Matricula: %d\n", a[n].matricula);
        printf("Nota 1: %.2f\n", a[n].notasProvas[0]);
        printf("Nota 2: %.2f\n", a[n].notasProvas[1]);
        printf("Nota media: %.2f\n", a[n].notaMedia);
        printf("Faltas: %d\n", a[n].faltas);
        printf("Resultado: %s\n", a[n].resultado);
    }
}

const char *salvarDados(aluno a[], int n)
{
    int i;
    FILE *f;
    
    f = fopen("alunos.txt", "a+");
    if (f == NULL)
    {
        return "Erro ao abrir o arquivo.";
    }

    for (i = 0; i < n; i++)
    {
        fprintf(f, "%s\t%d\t%.2f\t%.2f\t%.2f\t%d\t%s\n", a[n].nome, a[n].matricula, a[n].notasProvas[0], a[n].notasProvas[1], a[n].notaMedia, a[n].faltas, a[n].resultado);
    }

    fclose(f);
}

// ler arquivo e passar para struct

// Menu inserir

// salvar arquivos bin
/*
fwrite(arquivo, registro, tamanho, quantidade)
*/
// abrir o arquivo

int main()
{
    int op = 0, alunosCadastrados = 0;
    aluno alunos[maxAlunos];
    FILE *p;

    p = fopen("alunos.txt", "a+");

    while (op != 5)
    {
        op = menuPrincipal();

        switch (op)
        {
        case 1:
            // opção de inserir alunos
            printf("-------------------- Inserir Aluno ---------------------\n");
            alunosCadastrados = inserirAluno(alunos, alunosCadastrados, maxAlunos);
            break;
        case 2:
            printf("-------------------- Listar Alunos ---------------------\n");
            listarAlunos(alunos, alunosCadastrados);
            break;
        case 3:
            printf("-------------------- Salvar Dados ----------------------\n");
            salvarDados(alunos, alunosCadastrados);
            /* code */
            break;
        case 4:
            printf("-------------------- Carregar Dados --------------------\n");
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
