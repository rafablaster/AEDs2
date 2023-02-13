#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int valor;
    struct node *esquerda;
    struct node *direita;
}node;

node *criaNodo(int valor) {
    node *novoNodo = (node *) malloc(sizeof(node));
    novoNodo->valor = valor;
    novoNodo->esquerda = NULL;
    novoNodo->direita = NULL;
    return novoNodo;
}

node *insere(node *raiz, int valor) {
    if (raiz == NULL) {
    return criaNodo(valor);
    }if (valor < raiz->valor) {
        raiz->esquerda = insere(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = insere(raiz->direita, valor);
    }
    return raiz;
}

void exibe(node *raiz) {
    if (raiz != NULL) {
        exibe(raiz->esquerda);
        printf("%d ", raiz->valor);
        exibe(raiz->direita);
    }
}

int main() {
    node *raiz = NULL;

    raiz = insere(raiz, 50);
    insere(raiz, 30);
    insere(raiz, 20);
    insere(raiz, 40);
    insere(raiz, 70);
    insere(raiz, 60);
    insere(raiz, 80);

    printf("Arvore de Particao: ");
    exibe(raiz);
    printf("\n");
    return 0;
}

