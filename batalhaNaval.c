#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Array para mapear letras de A a Z
char alpha[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Função para simular um ataque em formato de cone
int cone_attack(int water[10][10], int X, int Y)
{
    for (int L = 0; L < 10; L++)
    {
        for (int C = 0; C < 10; C++)
        {
            // Verifica se a posição atual está dentro do padrão de ataque em cone
            if (L == X - 1)
            {
                if (C == Y)
                {
                    water[L][C] = 1; // Marca a posição como atingida
                }
            }
            if (L == X)
            {
                if (C == Y - 1 || C == Y || C == Y + 1)
                {
                    water[L][C] = 1; // Marca a posição como atingida
                }
            }
            if (L == X + 1)
            {
                if (C == Y - 1 || C == Y - 2 || C == Y || C == Y + 1 || C == Y + 2)
                {
                    water[L][C] = 1; // Marca a posição como atingida
                }
            }
        }
        printf("\n");
    }
}

// Função para simular um ataque em formato de octaedro
int octa_attack(int water[10][10], int X, int Y)
{
    for (int L = 0; L < 10; L++)
    {
        for (int C = 0; C < 10; C++)
        {
            // Verifica se a posição atual está dentro do padrão de ataque em octaedro
            if (L == X - 1)
            {
                if (C == Y)
                {
                    water[L][C] = 1; // Marca a posição como atingida
                }
            }
            if (L == X)
            {
                if (C == Y - 1 || C == Y || C == Y + 1)
                {
                    water[L][C] = 1; // Marca a posição como atingida
                }
            }
            if (L == X + 1)
            {
                if (C == Y)
                {
                    water[L][C] = 1; // Marca a posição como atingida
                }
            }
        }
        printf("\n");
    }
}

// Função para simular um ataque em formato de cruz
int acros_attack(int water[10][10], int X, int Y)
{
    for (int L = 0; L < 10; L++)
    {
        for (int C = 0; C < 10; C++)
        {
            // Verifica se a posição atual está dentro do padrão de ataque em cruz
            if (L == X - 1)
            {
                if (C == Y)
                {
                    water[L][C] = 1; // Marca a posição como atingida
                }
            }
            if (L == X)
            {
                if (C == Y - 1 || C == Y - 2 || C == Y || C == Y + 1 || C == Y + 2)
                {
                    water[L][C] = 1; // Marca a posição como atingida
                }
            }
            if (L == X + 1)
            {
                if (C == Y)
                {
                    water[L][C] = 1; // Marca a posição como atingida
                }
            }
        }
        printf("\n");
    }
}

// Função para converter um caractere em um índice numérico (A=0, B=1, ..., Z=25)
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

// Função para exibir o tabuleiro
int show(int water[10][10])
{
    system("clear"); // Limpa a tela do console (funciona em sistemas Unix-like)
    printf("  ");
    for (int i = 0; i < 10; i++)
    {
        printf("%c ", alpha[i]); // Exibe as letras das colunas
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%c ", alpha[i]); // Exibe as letras das linhas
        for (int j = 0; j < 10; j++)
        {
            if (!water[i][j])
                water[i][j] = 0;
            printf("%d ", water[i][j]); // Exibe o estado da posição no tabuleiro
        }
        printf("\n");
    }
}

int main()
{
    int attack;
    int water[10][10] = {0}; // Inicializa o tabuleiro com 0 (água)
    do
    {
        show(water); // Exibe o tabuleiro atual
        printf("Escolha seu ataque: ");
        printf("1 - Cone, 2 - Octa, 3 - Cruz, 9 - SAIR\n");
        scanf("%d", &attack); // Lê a escolha do ataque

        char X = 'A';
        char Y = 'B';
        printf("Onde atacar?\n");
        printf("Linha: ");
        scanf(" %c", &X); // Lê a linha do ataque
        printf("Coluna: ");
        scanf(" %c", &Y); // Lê a coluna do ataque

        printf("\n\n");

        switch (attack)
        {
        case 1:
            cone_attack(water, char_to_int(X), char_to_int(Y)); // Executa o ataque em cone
            break;
        case 2:
            octa_attack(water, char_to_int(X), char_to_int(Y)); // Executa o ataque em octaedro
            break;
        case 3:
            acros_attack(water, char_to_int(X), char_to_int(Y)); // Executa o ataque em cruz
            break;

        default:
            break;
        }
    } while (attack != 9); // Repete até que o usuário escolha sair

    return 0;
}
