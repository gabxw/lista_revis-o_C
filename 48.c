#include <stdio.h>
#include <stdlib.h>

#define MAX_ANDARES 10

typedef struct {
    int andarAtual;
    int pedidos[MAX_ANDARES];
} Elevador;

void inicializarElevador(Elevador *elevador) {
    elevador->andarAtual = 0;
    for (int i = 0; i < MAX_ANDARES; i++) {
        elevador->pedidos[i] = 0;
    }
}

void fazerPedido(Elevador *elevador, int andar) {
    if (andar >= 0 && andar < MAX_ANDARES) {
        elevador->pedidos[andar] = 1;
    } else {
        printf("Andar inválido!\n");
    }
}

void moverElevador(Elevador *elevador) {
    for (int i = 0; i < MAX_ANDARES; i++) {
        if (elevador->pedidos[i]) {
            printf("Elevador movendo-se para o andar %d.\n", i);
            elevador->andarAtual = i;
            elevador->pedidos[i] = 0;
        }
    }
}

void exibirEstado(Elevador *elevador) {
    printf("Elevador atualmente no andar %d.\n", elevador->andarAtual);
    printf("Pedidos:\n");
    for (int i = 0; i < MAX_ANDARES; i++) {
        if (elevador->pedidos[i]) {
            printf(" - Andar %d\n", i);
        }
    }
}

int main() {
    Elevador elevador;
    inicializarElevador(&elevador);

    int escolha, andar;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Fazer pedido\n");
        printf("2. Mover elevador\n");
        printf("3. Exibir estado\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o andar para fazer o pedido (0 a %d): ", MAX_ANDARES - 1);
                scanf("%d", &andar);
                fazerPedido(&elevador, andar);
                break;
            case 2:
                moverElevador(&elevador);
                break;
            case 3:
                exibirEstado(&elevador);
                break;
            case 4:
                printf("Saindo...\n");
                exit(0);
                break;
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}
