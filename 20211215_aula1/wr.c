#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxAlunos 2
#define tamanhoNome 40

// struct
struct Aluno
{
    char nome[tamanhoNome];
    int matricula;
};

int grava_dados(struct aluno a[], int i)
{
    FILE *p;
    p = fopen("data.txt", "w");

    if (p == NULL)
    {
        printf("Erro na abertura do arquivo.");
        return 1;
    }

    int index = 0;
    for (index = 0; index < i; index++)
    {
        fprintf(p, "%s", *a[index].nome);
        fprintf(p, "%s", &a[index].matricula);
        /* code */
    }

    fclose(p);
}

int main()
{
    int status = 0;
    struct Aluno alunos[maxAlunos];

    strcpy(alunos[0].nome, "Aluno1");
    strcpy(alunos[1].nome, "Aluno2");

    alunos[0].matricula = "001";
    alunos[1].matricula = "002";

    status = grava_dados(alunos, maxAlunos);

    if (status == -1)
    {
        printf("Data.txt err");
    }
    else
    {
        printf("Data.txt ok");
    }

    return 0;
}