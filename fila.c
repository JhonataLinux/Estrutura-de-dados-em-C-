#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct {
    int itens[TAM];
    int inicio;
    int fim;
} Fila;

void criar(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
}

int filaCheia(Fila *f) {
    return f->fim == TAM - 1;
}

int filaVazia(Fila *f) {
    return f->inicio > f->fim;
}

void enfileirar(Fila *f, int valor) {
    if (filaCheia(f)) {
        printf("Fila cheia! Nao pode enfileirar.\n");
    } else {
        f->fim++;
        f->itens[f->fim] = valor;
        printf("%d entrou na fila.\n", valor);
    }
}

int desenfileirar(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia! Nada para desenfileirar.\n");
        return -1;
    } else {
        int removido = f->itens[f->inicio];
        f->inicio++;
        printf("%d saiu da fila.\n", removido);
        return removido;
    }
}

void exibirFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
    } else {
        printf("Fila: ");
        for (int i = f->inicio; i <= f->fim; i++) {
            printf("%d ", f->itens[i]);
        }
        printf("\n");
    }
}

int main() {
    Fila f;
    criar(&f);

    int opcao, valor;

    do {
        printf("\n1 - Enfileirar\n");
        printf("2 - Desenfileirar\n");
        printf("3 - Exibir\n");
        printf("0 - Sair\n");
        printf("Escolha a opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o numero a enfileirar: ");
                scanf("%d", &valor);
                enfileirar(&f, valor);
                break;
            case 2:
                desenfileirar(&f);
                break;
            case 3:
                exibirFila(&f);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}