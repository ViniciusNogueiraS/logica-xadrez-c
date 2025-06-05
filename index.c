#include <stdio.h>

int escolherPeca() {//função para escolher a peça

    int pecaEscolhida = 0;

    printf("Escolha uma peça:\n");
    printf("1. TORRE\n");
    printf("2. BISPO\n");
    printf("3. RAINHA\n");
    printf("4. CAVALO\n");
    scanf("%d", &pecaEscolhida);

    if (pecaEscolhida < 1 || pecaEscolhida > 4) {
        printf("Opção inválida. Tente novamente.\n");
        return escolherPeca();
    }

    printf("Você escolheu a peca %d!\n", pecaEscolhida);
    return pecaEscolhida;
}

void movimentacaoTorre(int nMovimentos) {
    if (nMovimentos > 0) {
        printf("Direita\n");
        movimentacaoTorre(nMovimentos - 1);
    }
}

void movimentacaoBispo(int nMovimentos) {
    for (int i = nMovimentos; i > 0; i--) {
        printf("Cima\n");

        for (int j = 1; j > 0; j--) {//esse loop interno não me parece ter uma aplicação prática, mas segue conforme o exercício
            printf("Direita\n");
        }
    }
}

void movimentacaoRainha(int nMovimentos) {
    if (nMovimentos > 0) {
        printf("Esquerda\n");
        movimentacaoRainha(nMovimentos - 1);
    }
}

void movimentacaoCavalo() {//A movimentação do cavalo não exige um número de movimentos, apenas uma direção
    // o i representa a quantidade de movimentos na vertical (2) e o j representa o terceiro (j=3) e último movimento na horizontal (1)

    for (int i = 0, j = 3; i < 2 || j > 0; i++, j--) {
        if (i < 2) {
            printf("Cima\n");
            continue;//pula para a próxima iteração
        }

        printf("Direita\n");
    }
}

int main(void) {
    
    int peca = escolherPeca();

    printf("::: MOVIMENTAÇÃO :::\n\n");

    if (peca == 1) {// MOVIMENTAÇÃO DA TORRE
        
        movimentacaoTorre(5);

    } else if (peca == 2) {// MOVIMENTAÇÃO DO BISPO
        
        movimentacaoBispo(5);
        
    } else if (peca == 3) {// MOVIMENTAÇÃO DA RAINHA

        movimentacaoRainha(8);

    } else if (peca == 4) {// MOVIMENTAÇÃO DO CAVALO

        movimentacaoCavalo();

    } else {
        printf("Opção inválida.\n");
    }

    return 0;
}
