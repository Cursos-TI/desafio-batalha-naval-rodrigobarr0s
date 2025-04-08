#include <stdio.h>

#define SIZE 10

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (tabuleiro[i][j] == 0)
                printf("0 ");  // Água
            else if (tabuleiro[i][j] == 3)
                printf("3 ");  // Navio
            else if (tabuleiro[i][j] == 5)
                printf("5 ");  // Área afetada pela habilidade
        }
        printf("\n");
    }
}

// Função para aplicar a habilidade do tipo Cone
void aplicarCone(int tabuleiro[SIZE][SIZE], int x, int y) {
    // Matriz cone (5x5)
    int cone[5][5] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };

    // Sobrepor no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int posX = x + i - 2;  // Ajuste para centralizar
            int posY = y + j - 2;
            if (posX >= 0 && posX < SIZE && posY >= 0 && posY < SIZE && cone[i][j] == 1) {
                tabuleiro[posX][posY] = 5;  // Marca como área afetada
            }
        }
    }
}

// Função para aplicar a habilidade do tipo Cruz
void aplicarCruz(int tabuleiro[SIZE][SIZE], int x, int y) {
    // Matriz cruz (5x5)
    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Sobrepor no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int posX = x + i - 2;  // Ajuste para centralizar
            int posY = y + j - 2;
            if (posX >= 0 && posX < SIZE && posY >= 0 && posY < SIZE && cruz[i][j] == 1) {
                tabuleiro[posX][posY] = 5;  // Marca como área afetada
            }
        }
    }
}

// Função para aplicar a habilidade do tipo Octaedro
void aplicarOctaedro(int tabuleiro[SIZE][SIZE], int x, int y) {
    // Matriz octaedro (5x5)
    int octaedro[5][5] = {
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0}
    };

    // Sobrepor no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int posX = x + i - 2;  // Ajuste para centralizar
            int posY = y + j - 2;
            if (posX >= 0 && posX < SIZE && posY >= 0 && posY < SIZE && octaedro[i][j] == 1) {
                tabuleiro[posX][posY] = 5;  // Marca como área afetada
            }
        }
    }
}

int main() {
    // Inicializa o tabuleiro
    int tabuleiro[SIZE][SIZE] = {0};

    // Coloca alguns navios no tabuleiro (representados por 3)
    tabuleiro[2][2] = 3;
    tabuleiro[3][4] = 3;
    tabuleiro[5][5] = 3;

    // Exibe o tabuleiro inicial
    printf("Tabuleiro Inicial:\n");
    exibirTabuleiro(tabuleiro);

    // Aplica habilidades
    printf("\nAplicando habilidade de Cone (na posição [2, 2]):\n");
    aplicarCone(tabuleiro, 2, 2);
    exibirTabuleiro(tabuleiro);

    printf("\nAplicando habilidade de Cruz (na posição [5, 5]):\n");
    aplicarCruz(tabuleiro, 5, 5);
    exibirTabuleiro(tabuleiro);

    printf("\nAplicando habilidade de Octaedro (na posição [6, 6]):\n");
    aplicarOctaedro(tabuleiro, 6, 6);
    exibirTabuleiro(tabuleiro);

    return 0;
}