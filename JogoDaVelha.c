#include <stdio.h>

// JOGO DA VELHA EM C

char tabuleiro[3][3];
int jogador = 1;
int linha, coluna;
int resultado = -1;

void interface(char tabuleiro[3][3])
{
    printf("\n");
    printf("    JOGO DA # VERSÃO FINAL\n");
    printf("\t 0   1   2 \n\n");
    printf("\t %c | %c | %c    0\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("\t---#---#---\n");
    printf("\t %c | %c | %c    1\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("\t---#---#---\n");
    printf("\t %c | %c | %c    2\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    printf("\n");
}

int win(char tabuleiro[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2])
        {
            if (tabuleiro[i][0] == 'X')
                return 1;
            else if (tabuleiro[i][0] == 'O')
                return 2;
        }
    } // linhas

    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i])
        {
            if (tabuleiro[0][i] == 'X')
                return 1;
            else if (tabuleiro[0][i] == 'O')
                return 2;
        }
    } // colunas

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
    {
        if (tabuleiro[0][0] == 'X')
            return 1;
        else if (tabuleiro[0][0] == 'O')
            return 2;
    }

    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
    {
        if (tabuleiro[0][2] == 'X')
            return 1;
        else if (tabuleiro[0][2] == 'O')
            return 2;
    } // diagonais

    int empate = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tabuleiro[i][j] == ' ')
                empate = 0;
        }
    } // empate

    if (empate)
        return 0;

    return -1;
}

int main()
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tabuleiro[i][j] = ' ';
        }
    }

    do
    {
        interface(tabuleiro);

        printf("Jogador %d - digite a linha de acordo o desenho: ", jogador);
        scanf("%d", &linha);
        printf("Jogador %d - digite a coluna de acordo o desenho: ", jogador);
        scanf("%d", &coluna);

        if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == ' ')
        {
            // Marcador
            if (jogador == 1)
                tabuleiro[linha][coluna] = 'X';
            else
                tabuleiro[linha][coluna] = 'O';

            resultado = win(tabuleiro);

            jogador = (jogador % 2) + 1; // 1 % 2 = 1 e 2 % 2 = 0 (somando 1 ele alterna entre jogadores.)
        }
        else
        {
            printf("Algo deu errado, tenta de novo.\n");
        }

    } while (resultado == -1);

    interface(tabuleiro);

    if (resultado == 0)
        printf("Empate!\n");
    else
        printf("O jogador %d venceu!\n", resultado);

    char restart;
    printf("Mais uma rodada? (S/N): ");
    scanf(" %c", &restart);

    if (restart == 'S' || restart == 's')
        main();

    return 0;
}
