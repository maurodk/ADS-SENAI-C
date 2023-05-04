#include <stdio.h>

void clean()
{
    // Limpar terminal
    printf("\e[1;1H\e[2J");
}

void main()
{
    int TotalAlunos = 5;

    struct PerfilAluno
    {
        char NomeDoAluno[100];
        int NumeroDaMatricula;
        char CursoDoAluno[50];
    } alunos[TotalAlunos];

    for (int i = 0; i < TotalAlunos; i++)
    {
        printf("Cadastro do %d° aluno: ", i + 1);
        printf("Digite o nome do aluno: ");
        scanf("%s", alunos[i].NomeDoAluno);
        printf("Digite o número da matrícula: ");
        scanf("%d", &alunos[i].NumeroDaMatricula);
        printf("Digite o respectivo curso do aluno: ");
        scanf("%s", alunos[i].CursoDoAluno);
        clean();
    }

    printf("Segue abaixo a lista de alunos: \n");

    for (int i = 0; i < TotalAlunos; i++)
    {
        printf("___________________\n");
        printf("Aluno n° %d\n", i + 1);
        printf("Nome do Aluno: %s\n", alunos[i].NomeDoAluno);
        printf("Numero da Matricula: %d\n", alunos[i].NumeroDaMatricula);
        printf("Cursando: %s\n", alunos[i].CursoDoAluno);
    }
}
