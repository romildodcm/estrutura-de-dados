#include <stdio.h>
#include <string.h>
#include <math.h>

struct Funcionario
{
    char nome[255];
    int grauEstudo;
    int quantidadeLinguas;
    int nivelCargo;
    float indiceProdutividade;
    float salario;
};

// busca
int busca(struct Funcionario f[], int len, char nome[255])
{
    int i = 0;
    for (i = 0; i < len; i++)
    {
        // printf("Comparando se %s = %s: ", nome, f[i].nome);
        if (strcmp(f[i].nome, nome) == 0)
        {
            // printf("Sim.\n");
            return i;
        }
        // else
        // {
        //     printf("Nao.\n");
        // }
    }
    return -1;
}

// 4 - Cálculo do salário - formação
int formacao(int grauDeEstudo)
{
    // Calcular o fatorial de grauDeEstudo
    int fatorial = 0;
    if (grauDeEstudo == 1 || grauDeEstudo == 0)
    {
        fatorial = 1;
    }
    else
    {
        for (fatorial = 1; grauDeEstudo > 1; grauDeEstudo--)
        {
            fatorial = fatorial * grauDeEstudo;
        }
    }
    return fatorial;
}

// 5 - poliglota
int poliglota(int linguas)
{
    int cubo = 0;
    cubo = linguas * linguas * linguas;
    return cubo;
}

// 6 - salario base
float salarioBase(int nivel)
{
    float salarioB = 500;
    salarioB += nivel * salarioB;
    return salarioB;
}

// 7 - salario
float salario(struct Funcionario f)
{
    float salarioCalculado = 0;

    if (f.indiceProdutividade > 0.7)
    {
        salarioCalculado += salarioBase(f.nivelCargo);
        salarioCalculado += formacao(f.grauEstudo) * 100;
        salarioCalculado += poliglota(f.quantidadeLinguas) * 100;
        salarioCalculado += salarioBase(f.nivelCargo) * f.indiceProdutividade;
    }
    else if (f.indiceProdutividade <= 0.7 && f.indiceProdutividade >= 0.4)
    {
        salarioCalculado += salarioBase(f.nivelCargo);
        salarioCalculado += formacao(f.grauEstudo) * 100;
        salarioCalculado += poliglota(f.quantidadeLinguas) * 100;
    }
    else if (f.indiceProdutividade < 0.4)
    {
        salarioCalculado += salarioBase(f.nivelCargo);
        salarioCalculado += formacao(f.grauEstudo) * 100;
        salarioCalculado += poliglota(f.quantidadeLinguas) * 100;
        salarioCalculado -= salarioBase(f.nivelCargo) * (0.4 - f.indiceProdutividade);
    }

    return salarioCalculado;
}

// 8 - quantidade de funcionáriso que ganham acima da média
int ganhamAcimaDaMedia(struct Funcionario f[], int n)
{
    int total = 0, i = 0;
    float salarioMedio = 0.0, sum = 0.0;

    // varre o vetor buscando o valor dos salarios e fazendo a média
    for (i = 0; i < n; i++)
        sum += f[i].salario;

    salarioMedio = sum / n;

    // varre novamente para ver o número de salarios acima da media
    for (i = 0; i < n; i++)
    {
        if (f[i].salario > salarioMedio)
            total++;
    }

    return total;
}

int menuAlteraDados()
{
    int operacao = -1;

    // menu
    printf("--------------------- MENU ALTERAR ---------------------\n");
    printf("\t 1 - Nome;\n");
    printf("\t 2 - Grau de estudo;\n");
    printf("\t 3 - Quantidade de linguas que fala;\n");
    printf("\t 4 - Nivel do cargo que ocupa;\n");
    printf("\t 5 - Indice de produtividade;\n");
    printf("\t 0 - Sair;\n\n");
    printf("Digite o numero da alteracao que deseja e tecle enter: ");
    scanf(" %d", &operacao);

    return operacao;
}
// 9 alterar dados
void alteraDados(struct Funcionario f[], int n)
{
    int opcao = 1, i = 0;
    char nome[255];

    printf("------------ Alterar dados de um funcionario -----------\n");
    // busca/tentativas de busca
    while (opcao == 1)
    {
        printf("Digite o nome: ");
        fflush(stdin);
        fgets(nome, sizeof(nome), stdin);
        i = busca(f, n, nome);

        if (i == -1)
        {
            printf("\nNome invalido!\n");
            printf("Tecle 1 para tentar novamente ou 0 para sair: ");
            scanf(" %d", &opcao);
        }
        else
        {
            opcao = -1;
        }
    }

    while (opcao != 0)
    {
        opcao = menuAlteraDados();

        switch (opcao)
        {
        case 1:
            // alterar nome
            printf("--------------------- Alterar Nome ---------------------\n");
            printf("Nome atual: %s", f[i].nome);
            printf("Digite o novo nome: ");
            fflush(stdin);
            fgets(f[i].nome, sizeof(f[i].nome), stdin);
            printf("Nome alterado com sucesso para:\n%s", f[i].nome);
            break;
        case 2:
            // alterar Grau de estudo
            printf("---------------- Alterar Grau de Estudo ----------------\n");
            printf("Grau de estudo atual: %d\n", f[i].grauEstudo);
            printf("Digite o novo grau de estudo (1, 2, 3, 4 ou 5): ");
            scanf(" %d", &f[i].grauEstudo);
            printf("Grau de estudo alterado com sucesso para %d\n", f[i].grauEstudo);
            break;
        case 3:
            // alterar Quantidade de linguas que fala
            printf("------------ Quantidade de Linguas que Fala ------------\n");
            printf("Quantidade atual de linguas que fala: %d\n", f[i].quantidadeLinguas);
            printf("Digite a quantidade atualizada (1, 2, 3...): ");
            scanf(" %d", &f[i].quantidadeLinguas);
            printf("Quantidade alterada com sucesso para %d\n", f[i].quantidadeLinguas);
            break;
        case 4:
            // alterar Nivel do cargo que ocupa
            printf("--------------- Nivel do Cargo que Ocupa ---------------\n");
            printf("Nivel atual do cargo que ocupa: %d\n", f[i].nivelCargo);
            printf("Digite o nivel atualizado (1, 2, 3 ou 4): ");
            scanf(" %d", &f[i].nivelCargo);
            printf("Nivel alterado com sucesso para %d\n", f[i].nivelCargo);
            break;
        case 5:
            // alterar Indice de produtividade
            printf("---------------- Indice de Produtividade ---------------\n");
            printf("Indice de produtividade atual: %f\n", f[i].indiceProdutividade);
            printf("Digite indice atualizado (entre 0.0 e 1.0): ");
            scanf(" %f", &f[i].indiceProdutividade);
            printf("Indice alterado com sucesso para %f\n", f[i].indiceProdutividade);
            break;
        case 0:
            // printf("Saindo...\n")
            break;

        default:
            // valor invalido
            printf("******************** Opcao invalida ********************\n");
            break;
        }
    }
}

int cadastrarFuncionarios(struct Funcionario *f, int n, int max)
{
    int op = 1;
    while (op == 1)
    {
        if (n >= max)
        {
            printf("Ja foram cadastrados todos os %d funcionarios.\n", max);
            op = 0;
        }
        else if (n < max)
        {
            printf("Cadastrando(s) %d/%d funcionarios.\n", n + 1, max);
            printf("Nome: ");
            fflush(stdin);
            fgets(f[n].nome, sizeof(f[n].nome), stdin);
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

    return n;
}

int menuPrincipal()
{
    int operacao = -1;

    printf("------------------------- MENU -------------------------\n");
    printf("\t 1 - Cadastrar;\n");
    printf("\t 2 - Calcular salarios;\n");
    printf("\t 3 - Salarios acima da media;\n");
    printf("\t 4 - Editar informacoes de um funcionario;\n");
    printf("\t 5 - Visualizar informacoes de um funcionario;\n");
    printf("\t 0 - Sair;\n\n");
    printf("Digite o numero da opcao que deseja e tecle enter: ");
    fflush(stdin);
    scanf(" %d", &operacao);

    return operacao;
}

// função visualizar
void visualizarDadosFuncionario(struct Funcionario f[], int n)
{
    int i = 0;
    char nome[255];
    printf("Digite o nome: ");
    fflush(stdin);
    fgets(nome, sizeof(nome), stdin);
    i = busca(f, n, nome);

    if (i == -1)
    {
        printf("Nome invalido! Tente novamente.\n");
    }
    else
    {
        // mostrar os dados
        printf("Nome: %s", f[i].nome);
        printf("Grau de estudo: %d\n", f[i].grauEstudo);
        printf("Quantidade de linguas que fala: %d\n", f[i].quantidadeLinguas);
        printf("Nivel do cargo que ocupa: %d\n", f[i].nivelCargo);
        printf("Indice de produtividade: %f\n", f[i].indiceProdutividade);
        printf("Salario: %.2f\n", f[i].salario);
    }
}

int main()
{
    int max = 0, op = -1, op2 = -1, i = 0, controleCalculoSalario = 0, pessoasCadastradas = 0;
    printf("----------------------- SALAR.IO -----------------------\n");
    printf("Quantas pessoas trabalham na empresa?\n");
    scanf(" %d", &max);
    struct Funcionario funcionarios[max];

    while (op != 0)
    {
        op = menuPrincipal();

        if (op != 1 && pessoasCadastradas == 0)
        {
            printf("------------------------- ERRO -------------------------\n");
            printf("Opcao bloqueada, primeiro cadastre funcionarios.\n");
            op = 1;
        }
        // checar mudanças, se os dados mudarem, executar op 2 antes da op 3
        if (controleCalculoSalario != 0)
        {
            printf("------------------------- ERRO -------------------------\n");
            printf("Os dados foram alterados, calculando salarios.\n");
            controleCalculoSalario = 0;
            op2 = op;
            op = 2;
        }

        switch (op)
        {
        case 1:
            printf("---------------- Cadastrar Funcionarios ----------------\n");
            pessoasCadastradas = cadastrarFuncionarios(funcionarios, pessoasCadastradas, max);
            controleCalculoSalario = 1;
            break;
        case 2:
            printf("------------------- Calcular Salarios ------------------\n");
            printf("Calculando...\n");
            for (i = 0; i < pessoasCadastradas; i++)
            {
                funcionarios[i].salario = salario(funcionarios[i]);
            }
            printf("Os salarios de %d funcionarios foram calculados.\n", pessoasCadastradas);
            if (op2 != -1)
            {
                printf("Selecione novamente a opcao desejada...\n");
                op2 = -1;
            }
            break;

        case 3:
            printf("--------- Quantidade de Salarios Acima da Media --------\n");
            printf("%d funcionarios ganham acima da media.\n", ganhamAcimaDaMedia(funcionarios, pessoasCadastradas));
            break;
        case 4:
            printf("--------- Editar Informacoes de um Funcionario ---------\n");
            alteraDados(funcionarios, pessoasCadastradas);
            controleCalculoSalario = 1;
            break;
        case 5:
            printf("------- Visualizar Informacoes de um Funcionario -------\n");
            visualizarDadosFuncionario(funcionarios, pessoasCadastradas);
            break;
        case 0:
            printf("---------------------- Saindo... -----------------------\n");
            break;

        default:
            printf("******************** Opcao invalida ********************\n");
            break;
        }
    }

    return 0;
}