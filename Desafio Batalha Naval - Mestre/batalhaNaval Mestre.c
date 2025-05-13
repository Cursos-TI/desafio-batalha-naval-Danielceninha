#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Posiciona manualmente navios
void posicionarNavios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Navio horizontal
    tabuleiro[2][1] = NAVIO;
    tabuleiro[2][2] = NAVIO;
    tabuleiro[2][3] = NAVIO;

    // Navio vertical
    tabuleiro[5][5] = NAVIO;
    tabuleiro[6][5] = NAVIO;
    tabuleiro[7][5] = NAVIO;

    // Navio diagonal principal
    tabuleiro[0][0] = NAVIO;
    tabuleiro[1][1] = NAVIO;
    tabuleiro[2][2] = NAVIO;

    // Navio diagonal secundária
    tabuleiro[0][9] = NAVIO;
    tabuleiro[1][8] = NAVIO;
    tabuleiro[2][7] = NAVIO;
}

// Função que gera matriz em forma de cone
void gerarCone(int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Condicional para formar um cone (triângulo invertido)
            if (j >= (2 - i) && j <= (2 + i)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

// Função que gera matriz em forma de cruz
void gerarCruz(int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Cruz com linha e coluna centrais
            if (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

// Função que gera matriz em forma de octaedro (losango)
void gerarOctaedro(int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Distância absoluta do centro
            if (abs(i - 2) + abs(j - 2) <= 2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }
}

// Sobrepõe a habilidade ao tabuleiro, marcando com 5 (área de efeito)
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                       int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                       int origem_linha, int origem_coluna) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int linha = origem_linha + i - 2;
                int coluna = origem_coluna + j - 2;
                // Verifica se está dentro dos limites do tabuleiro
                if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
                    if (tabuleiro[linha][coluna] == AGUA) {
                        tabuleiro[linha][coluna] = HABILIDADE;
                    }
                }
            }
        }
    }
}

// Exibe o tabuleiro com diferentes símbolos
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro (0=água, 3=navio, 5=habilidade):\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // Inicializa o tabuleiro e navios
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    // Gera formas de habilidades
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplica as habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 4, 4);        // Cone centrado em (4,4)
    aplicarHabilidade(tabuleiro, cruz, 7, 7);        // Cruz centrada em (7,7)
    aplicarHabilidade(tabuleiro, octaedro, 6, 2);    // Octaedro centrado em (6,2)

    // Exibe o resultado final
    exibirTabuleiro(tabuleiro);

    return 0;
}