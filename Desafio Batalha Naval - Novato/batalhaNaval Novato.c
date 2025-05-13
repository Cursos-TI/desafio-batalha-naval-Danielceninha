#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Declaração da matriz que representa o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0}; // Todas as posições começam com 0 (água)

    // Coordenadas iniciais dos navios
    int linha_navio_horizontal = 2;
    int coluna_navio_horizontal = 4;

    int linha_navio_vertical = 5;
    int coluna_navio_vertical = 7;

    // Validação se o navio horizontal cabe no tabuleiro
    if (coluna_navio_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Posicionando navio horizontal
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] = 3;
        }
    }

    // Validação se o navio vertical cabe no tabuleiro
    if (linha_navio_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Verificar se há sobreposição com o navio horizontal
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] == 3) {
                sobreposicao = 1;
                break;
            }
        }

        // Posicionando navio vertical se não houver sobreposição
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = 3;
            }
        } else {
            printf("Erro: Sobreposição de navios detectada. Não é possível posicionar o navio vertical.\n");
        }
    }

    // Exibição do tabuleiro
    printf("Tabuleiro Batalha Naval (0 = água, 3 = navio):\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}