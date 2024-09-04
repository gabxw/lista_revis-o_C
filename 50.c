#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Função para verificar se o padrão está presente no vetor principal
bool reconhecerPadrao(int vetor[], int tamanhoVetor, int padrao[], int tamanhoPadrao) {
    for (int i = 0; i <= tamanhoVetor - tamanhoPadrao; i++) {
        int j;
        for (j = 0; j < tamanhoPadrao; j++) {
            if (vetor[i + j] != padrao[j]) {
                break;
            }
        }
        if (j == tamanhoPadrao) {
            return true; // Padrão encontrado
        }
    }
    return false; // Padrão não encontrado
}

int main() {
    int vetor[MAX_SIZE];
    int padrao[MAX_SIZE];
    int tamanhoVetor, tamanhoPadrao;

    printf("Digite o tamanho do vetor principal: ");
    scanf("%d", &tamanhoVetor);
    printf("Digite os elementos do vetor principal:\n");
    for (int i = 0; i < tamanhoVetor; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Digite o tamanho do padrão: ");
    scanf("%d", &tamanhoPadrao);
    printf("Digite os elementos do padrão:\n");
    for (int i = 0; i < tamanhoPadrao; i++) {
        scanf("%d", &padrao[i]);
    }

    if (reconhecerPadrao(vetor, tamanhoVetor, padrao, tamanhoPadrao)) {
        printf("Padrão encontrado no vetor principal.\n");
    } else {
        printf("Padrão não encontrado no vetor principal.\n");
    }

    return 0;
}
