#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define OCUPADO 3
#define AGUA 0

// Função para verificar se há sobreposição
int verificarSobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int coordenadas[3][2]) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha = coordenadas[i][0];
        int coluna = coordenadas[i][1];
        if (tabuleiro[linha][coluna] == OCUPADO) {
            return 1; // Há sobreposição
        }
    }
    return 0; // Sem sobreposição
}

// Função para posicionar navio
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int coordenadas[3][2]) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha = coordenadas[i][0];
        int coluna = coordenadas[i][1];
        tabuleiro[linha][coluna] = OCUPADO;
    }
}

int main() {
    // Inicializa o tabuleiro com água
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {AGUA};

    // --------------------------
    // Navio 1 - Horizontal (linha 2, coluna 1 a 3)
    int navio1[3][2] = {
        {2, 1}, {2, 2}, {2, 3}
    };

    // Navio 2 - Vertical (linha 5 a 7, coluna 5)
    int navio2[3][2] = {
        {5, 5}, {6, 5}, {7, 5}
    };

    // Navio 3 - Diagonal principal (linha/coluna: 0,1,2)
    int navio3[3][2] = {
        {0, 0}, {1, 1}, {2, 2}
    };

    // Navio 4 - Diagonal secundária (linha/coluna: 0,9 -> 2,7)
    int navio4[3][2] = {
        {0, 9}, {1, 8}, {2, 7}
    };

    // Posicionamento com validações
    if (!verificarSobreposicao(tabuleiro, navio1)) {
        posicionarNavio(tabuleiro, navio1);
    }

    if (!verificarSobreposicao(tabuleiro, navio2)) {
        posicionarNavio(tabuleiro, navio2);
    }

    if (!verificarSobreposicao(tabuleiro, navio3)) {
        posicionarNavio(tabuleiro, navio3);
    }

    if (!verificarSobreposicao(tabuleiro, navio4)) {
        posicionarNavio(tabuleiro, navio4);
    }

    // Exibe o tabuleiro
    printf("Tabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}