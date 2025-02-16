#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

char alpha[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int cone_attack(int water[10][10], int X, int Y)
{
    for (int L = 0; L < 10; L++)
    {
        for (int C = 0; C < 10; C++)
        {
            if (L == X - 1)
            {
                if (C == Y)
                {
                    water[L][C] = 1;
                }
            }
            if (L == X)
            {
                if (C == Y - 1 || C == Y || C == Y + 1)
                {
                    water[L][C] = 1;
                }
            }
            if (L == X + 1)
            {
                if (C == Y - 1 || C == Y - 2 || C == Y || C == Y + 1 || C == Y + 2)
                {
                    water[L][C] = 1;
                }
            }
        }
        printf("\n");
    }
}

int octa_attack(int water[10][10], int X, int Y)
{
    for (int L = 0; L < 10; L++)
    {
        for (int C = 0; C < 10; C++)
        {
            if (L == X - 1)
            {
                if (C == Y)
                {
                    water[L][C] = 1;
                }
            }
            if (L == X)
            {
                if (C == Y - 1 || C == Y || C == Y + 1)
                {
                    water[L][C] = 1;
                }
            }
            if (L == X + 1)
            {
                if (C == Y)
                {
                    water[L][C] = 1;
                }
            }
        }
        printf("\n");
    }
}

int acros_attack(int water[10][10], int X, int Y)
{
    for (int L = 0; L < 10; L++)
    {
        for (int C = 0; C < 10; C++)
        {
            if (L == X - 1)
            {
                if (C == Y)
                {
                    water[L][C] = 1;
                }
            }
            if (L == X)
            {
                if (C == Y - 1 || C == Y - 2 || C == Y || C == Y + 1 || C == Y + 2)
                {
                    water[L][C] = 1;
                }
            }
            if (L == X + 1)
            {
                if (C == Y)
                {
                    water[L][C] = 1;
                }
            }
        }
        printf("\n");
    }
}

int char_to_int(char word)
{
    int index;
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] == word)
        {
            index = i;
        }
    }
    return index;
}

int show(int water[10][10])
{
    system("clear");
    printf("  ");
    for (int i = 0; i < 10; i++)
    {
        printf("%c ", alpha[i]);
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%c ", alpha[i]);
        for (int j = 0; j < 10; j++)
        {
            if (!water[i][j])
                water[i][j] = 0;
            printf("%d ", water[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1

    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    int attack;
    int water[10][10] = {0};
    do
    {
        show(water);
        printf("Escolha seu ataque: ");
        printf("1 - Cone, 2 - Octa, 3 - Cruz, 9 - SAIR\n");
        scanf("%d", &attack);

        char X = 'A';
        char Y = 'B';
        printf("Onde atacar?\n");
        printf("Linha: ");
        scanf(" %c", &X);
        printf("Coluna: ");
        scanf(" %c", &Y);

        printf("\n\n");

        switch (attack)
        {
        case 1:
            cone_attack(water, char_to_int(X), char_to_int(Y));
            break;
        case 2:
            octa_attack(water, char_to_int(X), char_to_int(Y));
            break;
        case 3:
            acros_attack(water, char_to_int(X), char_to_int(Y));
            break;

        default:
            break;
        }
    } while (attack != 9);

    return 0;
}
